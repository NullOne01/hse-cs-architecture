#ifndef TASK2_BIRD_H
#define TASK2_BIRD_H

#include "Animal.h"

class Bird : public Animal {
private:
    bool is_migrant_; //перелётная ли птица
public:
    Bird(const char *name, int mass_gram, bool is_migrant);

    // Ввод параметров птицы из файла
    static Bird *in(FILE *ifst);

    // Случайный ввод параметров птицы
    static Bird *inRnd();

    // Вывод параметров птицы в форматируемый поток
    void out(FILE *ofst) override;
};


#endif //TASK2_BIRD_H
