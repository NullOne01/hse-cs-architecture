#ifndef __rnd__
#define __rnd__

#include <stdlib.h>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел и строк
//------------------------------------------------------------------------------

// Случайное число в диапазоне [min; max]
static inline int RandomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Случайная строка. Использует выделенную память.
char *RandomString(char *str, size_t size);

#endif //__rnd__
