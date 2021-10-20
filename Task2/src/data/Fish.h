#ifndef TASK2_FISH_H
#define TASK2_FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    enum HABITAT {
        RIVER, SEA, LAKE
    }; //место обитания

    Fish::HABITAT habitat;

    Fish(const char *name, int mass_gram, HABITAT habitat);

    // Ввод параметров рыбы из файла
    static Fish *in(FILE *ifst);

    // Случайный ввод параметров рыбы
    static Fish *inRnd();

    // Вывод параметров рыбы в форматируемый поток
    void out(FILE *ofst) override;
};


#endif //TASK2_FISH_H
