#ifndef __animal__
#define __animal__

//------------------------------------------------------------------------------
// animal.h - содержит описание обобщающего животного,
//------------------------------------------------------------------------------

#include "fish.h"
#include "bird.h"
#include "mammal.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct animal {
    // значения ключей для каждой из фигур
    enum KEY {FISH, BIRD, MAMMAL} k; // ключ

    const char* name;
    int mass_gram;

    // используемые альтернативы
    union { // используем простейшую реализацию
        struct fish f;
        struct bird b;
        struct mammal m;
    };
};

// Ввод обобщенной фигуры
struct animal *InAnimal(FILE *ifst);

// Случайный ввод обобщенной фигуры
struct animal *InRndAnimal();

// Вывод обобщенной фигуры
void OutAnimal(struct animal *s, FILE *ofst);

// Вычисление периметра обобщенной фигуры
double PerimeterShape(struct animal *s);

#endif //__animal__
