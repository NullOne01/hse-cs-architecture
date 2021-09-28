//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "shape.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
struct shape *InShape(FILE *ifst) {
    struct shape *sp;
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return ((void *) 0);

    switch (k) {
        case 1:sp = (struct shape *) malloc(sizeof(struct shape));
            sp->k = RECTANGLE;
            if (InRectangle(&sp->r, ifst) == EOF) {
                free(sp);
                return ((void *) 0);
            }
            return sp;
        case 2:sp = (struct shape *) malloc(sizeof(struct shape));
            sp->k = TRIANGLE;
            if (InTriangle(&sp->t, ifst) == EOF) {
                free(sp);
                return ((void *) 0);
            }
            return sp;
        default:return ((void *) 0);
    }
}

// Случайный ввод обобщенной фигуры
struct shape *InRndShape() {
    struct shape *sp;
    int k = rand() % 2 + 1;
    switch (k) {
        case 1:sp = (struct shape *) malloc(sizeof(struct shape));
            sp->k = RECTANGLE;
            InRndRectangle(&sp->r);
            return sp;
        case 2:sp = (struct shape *) malloc(sizeof(struct shape));
            sp->k = TRIANGLE;
            InRndTriangle(&sp->t);
            return sp;
        default:return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void OutShape(struct shape *s, FILE *ofst) {
    switch (s->k) {
        case RECTANGLE:OutRectangle(&s->r, ofst);
            break;
        case TRIANGLE:OutTriangle(&s->t, ofst);
            break;
        default:fprintf(ofst, "Incorrect figure!\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double PerimeterShape(struct shape *s) {
    switch (s->k) {
        case RECTANGLE:return PerimeterRectangle(&s->r);
        case TRIANGLE:return PerimeterTriangle(&s->t);
        default:return 0.0;
    }
}
