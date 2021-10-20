#include <cstdio>
#include <cstring>
#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Mammal.h"
#include "../utilities/Random.h"

Animal::Animal(const char *name, int mass_gram) : mass_gram_(mass_gram) {
    strcpy(name_, name);
}

const char *Animal::getName() const {
    return name_;
}

int Animal::getMassGram() const {
    return mass_gram_;
}

Animal *Animal::in(FILE *ifst) {
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return nullptr;

    switch (k) {
        case 1:
            return Fish::in(ifst);
        case 2:
            return Bird::in(ifst);
        case 3:
            return Mammal::in(ifst);
        default:
            return nullptr;
    }
}

Animal *Animal::inRnd() {
    int k = Random::RandomRange(1, 3);
    switch (k) {
        case 1:
            return Fish::inRnd();
        case 2:
            return Bird::inRnd();
        case 3:
            return Mammal::inRnd();
        default:
            return nullptr;
    }
}

void Animal::out(FILE *ofst) {
    fprintf(ofst, " Name = %s, mass = %d. Task result: %f\n", name_, mass_gram_, calculateTask());
}

double Animal::calculateTask() const {
    double res = 0;
    for (int i = 0; i < strlen(name_); i++) {
        res += static_cast<int>(name_[i]);
    }

    res /= (double) mass_gram_;

    return res;
}
