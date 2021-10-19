#ifndef TASK2_MAMMAL_H
#define TASK2_MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
public:
    enum MAMMAL_TYPE {
        PREDATOR, HERBIVORE, INSECTIVOROUS
    }; //тип зверя

    Mammal(const char *name, int mass_gram, MAMMAL_TYPE type);

    MAMMAL_TYPE type;

    // Ввод параметров млекопитающего из файла
    static Mammal *in(FILE *ifst);

    // Случайный ввод параметров млекопитающего
    static Mammal *inRnd();

    // Вывод параметров млекопитающего в форматируемый поток
    void out(FILE *ofst) override;
};


#endif //TASK2_MAMMAL_H
