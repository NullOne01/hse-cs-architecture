#ifndef __rnd__
#define __rnd__

#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел и строк
//------------------------------------------------------------------------------

// Случайное число в диапозоне [min; max]
static inline int RandomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Случайная строка. Использует выделенную память.
static inline char *RandomString(char *str, size_t size) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = RandomRange(0, strlen(charset) - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

// Случайная строка. Выделяет память для себя.
static inline char *RandomStringAlloc(size_t size) {
    char *s = malloc(size + 1);
    if (s) {
        RandomString(s, size);
    }
    return s;
}

#endif //__rnd__
