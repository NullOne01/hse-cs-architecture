#ifndef __animal__
#define __animal__

//------------------------------------------------------------------------------
// animal.h - содержит описание обобщающего животного,
//------------------------------------------------------------------------------

#include "fish.h"
#include "bird.h"
#include "mammal.h"

//------------------------------------------------------------------------------
// структура, обобщающая всех животных
struct animal {
    enum { max_name_len = 256 }; // максимальная длина имени

    // значения ключей для каждого из животных
    enum KEY { FISH, BIRD, MAMMAL } k; // ключ

    char name[max_name_len];
    int mass_gram;

    // используемые альтернативы
    union { // используем простейшую реализацию
        struct fish f;
        struct bird b;
        struct mammal m;
    };
};

// Ввод обобщенного животного
struct animal *InAnimal(FILE *ifst);

// Случайный ввод обобщенного животного
struct animal *InRndAnimal();

// Вывод обобщенного животного
void OutAnimal(struct animal *a, FILE *ofst);

// Общая для всех альтернатив функция
double CalculateTask(struct animal *a);

#endif //__animal__
