#ifndef UTIL_H_
#define UTIL_H_

/* ======================= prototypes ========================== */
void uart_print(const char*, unsigned int len);
void relocate_memcpy(void* dest, void* src, unsigned int len);
void relocate_memset(void* dest, unsigned int len);
#endif