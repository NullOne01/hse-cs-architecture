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
void OutFish(struct fish *f, FILE *ofst);

// Вычисление периметра рыбы
double PerimeterRectangle(struct fish *f);

#endif //__fish__
