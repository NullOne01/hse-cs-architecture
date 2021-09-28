#ifndef __bird__
#define __bird__

//------------------------------------------------------------------------------
// bird.h - содержит описание птицы
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// птица
struct bird {
    bool isMigrant; //перелётная ли птица
};

// Ввод параметров птицы из файла
int InBird(struct bird *b, FILE *ifst);

// Случайный ввод параметров птицы
void InRndBird(struct bird *b);

// Вывод параметров птицы в форматируемый поток
void OutBird(struct bird *b, FILE *ofst);

// Вычисление периметра птицы
double PerimeterTriangle(struct bird *b);

#endif //__bird__
