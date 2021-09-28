//------------------------------------------------------------------------------
// animal.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "animal.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
struct animal *InAnimal(FILE *ifst) {
    struct animal *sp;
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return ((void *) 0);

    switch (k) {
        case 1:sp = (struct animal *) malloc(sizeof(struct animal));
            sp->k = RECTANGLE;
            if (InFish(&sp->f, ifst) == EOF) {
                free(sp);
                return ((void *) 0);
            }
            return sp;
        case 2:sp = (struct animal *) malloc(sizeof(struct animal));
            sp->k = TRIANGLE;
            if (InBird(&sp->b, ifst) == EOF) {
                free(sp);
                return ((void *) 0);
            }
            return sp;
        default:return ((void *) 0);
    }
}

// Случайный ввод обобщенной фигуры
struct animal *InRndAnimal() {
    struct animal *sp;
    int k = rand() % 2 + 1;
    switch (k) {
        case 1:sp = (struct animal *) malloc(sizeof(struct animal));
            sp->k = RECTANGLE;
            InRndFish(&sp->f);
            return sp;
        case 2:sp = (struct animal *) malloc(sizeof(struct animal));
            sp->k = TRIANGLE;
            InRndBird(&sp->b);
            return sp;
        default:return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void OutAnimal(struct animal *a, FILE *ofst) {
    switch (a->k) {
        case RECTANGLE:OutFish(&a->f, ofst);
            break;
        case TRIANGLE:OutBird(&a->b, ofst);
            break;
        default:fprintf(ofst, "Incorrect figure!\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double PerimeterShape(struct animal *a) {
    switch (a->k) {
        case RECTANGLE:return PerimeterRectangle(&a->f);
        case TRIANGLE:return PerimeterTriangle(&a->b);
        default:return 0.0;
    }
}
