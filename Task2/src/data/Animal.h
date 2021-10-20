#ifndef TASK2_ANIMAL_H
#define TASK2_ANIMAL_H

#include <cstdio>

class Animal {
private:
    char name_[256];
    int mass_gram_;

public:
    Animal(const char *name, int mass_gram);

    const char *getName() const;

    int getMassGram() const;

    // Ввод параметров обобщенного животного из файла
    static Animal *in(FILE *ifst);

    // Случайный ввод обобщенного животного
    static Animal *inRnd();

    // Вывод параметров текущего животного в поток
    virtual void out(FILE *ofst);

    // Общая для всех альтернатив функция
    double calculateTask() const;
};


#endif //TASK2_ANIMAL_H
