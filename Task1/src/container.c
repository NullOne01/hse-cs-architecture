//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void InitContainer(struct container *c) {
    c->len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(struct container *c) {
    for (int i = 0; i < c->len; i++) {
        free(&c->cont[i]);
    }

    c->len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst) {
    struct shape *newShape;
    while ((newShape = InShape(ifst)) != ((void *) 0)) {
        c->cont[c->len] = newShape;
        c->len++;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size) {
    while (c->len < size) {
        if ((c->cont[c->len] = InRndShape()) != ((void *) 0)) {
            c->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void OutContainer(struct container *c, FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", c->len);
    for (int i = 0; i < c->len; i++) {
        fprintf(ofst, "%d: ", i);
        OutShape(c->cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы периметров всех фигур в контейнере
double PerimeterSumContainer(struct container *c) {
    double sum = 0.0;
    for (int i = 0; i < c->len; i++) {
        sum += PerimeterShape(c->cont[i]);
    }
    return sum;
}
