#ifndef __fish__
#define __fish__

//------------------------------------------------------------------------------
// fish.h - содержит описание рыбы  и его интерфейса
//------------------------------------------------------------------------------

#include <stdio.h>
#include "rnd.h"

// рыба
struct fish {
    enum HABITAT {RIVER, SEA, LAKE} habitat; //место обитания
};

// Ввод параметров рыбы из файла
int InFish(struct fish *f, FILE *ifst);

// Случайный ввод параметров рыбы
void InRndFish(struct fish *f);

// Вывод параметров рыбы в форматируемый поток
const char* OutFish(struct fish *f, FILE *ofst);

#endif //__fish__
