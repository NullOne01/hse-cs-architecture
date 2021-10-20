#ifndef TASK2_CONTAINER_H
#define TASK2_CONTAINER_H

#include <cstdio>
#include "Animal.h"

class Container {
private:
    const int MAX_LEN = 10000; // максимальная длина
    int len_ = 0; // текущая длина
    Animal **cont;

public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void in(FILE *ifst);

    // Случайный ввод содержимого контейнера
    void inRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void out(FILE *ofst);

    // Сортировка шеллом по возрастанию
    void sortShellContainer();
};


#endif //TASK2_CONTAINER_H
