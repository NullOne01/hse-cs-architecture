//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
int InTriangle(struct triangle *t, FILE *ifst) {
    return fscanf(ifst, "%d %d %d", &t->a, &t->b, &t->c);
}

// Случайный ввод параметров треугольника
void InRndTriangle(struct triangle *t) {
    t->a = Random();
    t->b = Random();
    do {
        t->c = Random();
    } while((t->c >= (t->a + t->b))
          || (t->a >= (t->c + t->b))
          || (t->b >= (t->c + t->a)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void OutTriangle(struct triangle *t, FILE *ofst) {
    fprintf(ofst, "It is Triangle: a = %d, b = %d, c = %d. Perimeter = %lf \n", t->a, t->b, t->c,
            PerimeterTriangle(t));
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double PerimeterTriangle(struct triangle *t) {
    return t->a + t->b + t->c;
}
