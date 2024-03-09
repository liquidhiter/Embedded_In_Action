SET PATH=C:\Keil_v5\ARM\ARMCLANG\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\WezTerm;C:\Program Files\dotnet\;C:\Program Files\PowerShell\7\;C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit\;C:\Program Files\CMake\bin;C;C:\Program Files\Git\cmd;C:\Program Files\usbipd-win\;C:\Users\maxin\AppData\Local\Programs\Python\Python312\Scripts\;C:\Users\maxin\AppData\Local\Programs\Python\Python312\;C:\Users\maxin\AppData\Local\Programs\Python\Launcher\;C:\Users\maxin\AppData\Local\Microsoft\WindowsApps;C:\Users\maxin\AppData\Local\Programs\Microsoft VS Code\bin;C:\Users\maxin\AppData\Local\JetBrains\Toolbox\scripts;
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=uart
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\main.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\start._ac"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\uart.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\util.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\mystring.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\led.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\exception.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\systick.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmLink" --Via ".\Objects\uart.lnp"
fromelf  --bin  --output=uart_relocate.bin  Objects\uart.axf
fromelf  --text  -a -c  --output=uart_relocate.dis  Objects\uart.axf
