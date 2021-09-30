#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "animal.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 10000 }; // максимальная длина
    int len; // текущая длина
    struct animal *cont[max_len];
};

// Инициализация контейнера
void InitContainer(struct container *c);

// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(struct container *c);

// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size);

// Вывод содержимого контейнера в указанный поток
void OutContainer(struct container *c, FILE *ofst);

// Сортировка шеллом по возрастанию
void SortShellContainer(struct container *c);

#endif
