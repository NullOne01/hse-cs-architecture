#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <stdio.h>

# include "rnd.h"

// прямоугольник
struct rectangle {
    int x, y; // ширина, высота
};

// Ввод параметров прямоугольника из файла
int InRectangle(struct rectangle *r, FILE *ifst);

// Случайный ввод параметров прямоугольника
void InRndRectangle(struct rectangle *t);

// Вывод параметров прямоугольника в форматируемый поток
void OutRectangle(struct rectangle *r, FILE *ofst);

// Вычисление периметра прямоугольника
double PerimeterRectangle(struct rectangle *r);

#endif //__rectangle__
