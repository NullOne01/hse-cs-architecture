//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <stdlib.h>
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
        free(c->cont[i]);
    }

    c->len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst) {
    struct animal *newAnimal;
    while ((newAnimal = InAnimal(ifst)) != ((void *) 0)) {
        c->cont[c->len] = newAnimal;
        c->len++;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size) {
    while (c->len < size) {
        if ((c->cont[c->len] = InRndAnimal()) != ((void *) 0)) {
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
        OutAnimal(c->cont[i], ofst);
    }
}

// Сортировка шеллом по возрастанию
void SortShellContainer(struct container *c) {
    for (int s = c->len / 2; s > 0; s /= 2) {
        for (int i = 0; i < c->len; i++) {
            for (int j = i + s; j < c->len; j += s) {
                // Мы здесь пересчитываем каждый раз, но не страшно.
                if (CalculateTask(c->cont[i]) > CalculateTask(c->cont[j])) {
                    struct animal *temp = c->cont[j];
                    c->cont[j] = c->cont[i];
                    c->cont[i] = temp;
                }
            }
        }
    }
}