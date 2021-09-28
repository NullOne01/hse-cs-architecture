#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <stdio.h>

# include "rnd.h"

//------------------------------------------------------------------------------
// треугольник
struct triangle {
    int a, b, c; // стороны
};

// Ввод параметров треугольника из файла
int InTriangle(struct triangle *t, FILE *ifst);

// Случайный ввод параметров треугольника
void InRndTriangle(struct triangle *t);

// Вывод параметров треугольника в форматируемый поток
void OutTriangle(struct triangle *t, FILE *ofst);

// Вычисление периметра треугольника
double PerimeterTriangle(struct triangle *t);

#endif //__triangle__
