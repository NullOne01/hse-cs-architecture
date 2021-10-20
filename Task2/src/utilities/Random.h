#ifndef HSE_CS_ARCHITECTURE_RANDOM_H
#define HSE_CS_ARCHITECTURE_RANDOM_H

#include <stdlib.h>

class Random {
public:
    // Возвращает случайное число в диапазоне [min, max]
    static int RandomRange(int min, int max);

    // Случайная строка. Сама выделяет память.
    static char *RandomString(char *str, size_t size);
};


#endif //HSE_CS_ARCHITECTURE_RANDOM_H
