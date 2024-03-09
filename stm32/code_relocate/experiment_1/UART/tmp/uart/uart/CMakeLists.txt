# CMSIS Build CMakeLists generated on 2024-03-04T22:13:22

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET uart)
set(CPU Cortex-M3)
set(PRJ_DIR "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART")
set(OUT_DIR "C:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/out/uart/uart")
set(INT_DIR "C:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/tmp/uart/uart")
set(FPU NO_FPU)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE none)
set(DEBUG on)
set(AS_FLAGS_GLOBAL "-masm=auto")
set(CC_FLAGS_GLOBAL "-std=c99 -fno-rtti -Werror -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality -Wno-covered-switch-default -Wno-unreachable-code-break")
set(CXX_FLAGS_GLOBAL "-xc++ -std=c++11 -fno-rtti -Werror -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality -Wno-covered-switch-default -Wno-unreachable-code-break")
set(LD_FLAGS_GLOBAL "--map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/uart_uart.sct")

set(DEFINES
  STM32F10X_MD
)

set(INC_PATHS
  "C:/Users/maxin/AppData/Local/arm/packs/Keil/STM32F1xx_DFP/2.4.1/Device/Include"
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART"
)

set(AS_ARM_SRC_FILES
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/start.s"
)

set(CC_SRC_FILES
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/main.c"
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/string.c"
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/uart.c"
  "c:/Users/maxin/Desktop/keil_projects/stm32/code_relocate/experiment_1/UART/util.c"
)

# Toolchain config map

set(REGISTERED_TOOLCHAIN_ROOT "c:/Users/maxin/.vcpkg/artifacts/2139c4c6/compilers.arm.armclang/6.21.0/bin")
set(REGISTERED_TOOLCHAIN_VERSION "6.21.0")
set(TOOLCHAIN_VERSION_MIN "6.21.0")
include ("C:/Users/maxin/.vcpkg/artifacts/2139c4c6/tools.open.cmsis.pack.cmsis.toolbox/2.2.1/etc/AC6.6.18.0.cmake")
include ("C:/Users/maxin/.vcpkg/artifacts/2139c4c6/tools.open.cmsis.pack.cmsis.toolbox/2.2.1/etc/CMSIS-Build-Utils.cmake")

# Setup project

project(${TARGET} LANGUAGES AS_ARM C)

cbuild_get_running_toolchain(TOOLCHAIN_ROOT TOOLCHAIN_VERSION C)

# Global Flags

set(CMAKE_AS_ARM_FLAGS "${AS_ARM_CPU} ${AS_ARM_BYTE_ORDER} ${AS_ARM_DEFINES} ${AS_ARM_OPTIONS_FLAGS} ${AS_ARM_FLAGS} ${AS_FLAGS_GLOBAL}")
cbuild_get_system_includes(CC_SYS_INC_PATHS_LIST CC_SYS_INC_PATHS)
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Local Flags

foreach(SRC ${AS_ARM_SRC_FILES})
  set_source_files_properties(${SRC} PROPERTIES LANGUAGE AS_ARM)
endforeach()

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${AS_ARM_SRC_FILES} ${CC_SRC_FILES})
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "uart")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
