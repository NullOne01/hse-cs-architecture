#include <cstring>
#include "Mammal.h"
#include "../utilities/Random.h"

Mammal::Mammal(const char *name, int mass_gram, Mammal::MAMMAL_TYPE type) : Animal(name, mass_gram), type(type) {}

Mammal *Mammal::in(FILE *ifst) {
    int mass;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &mass) == EOF)
        return nullptr;

    char typeStr[20];
    if (fscanf(ifst, "%s", typeStr) == EOF)
        return nullptr;

    MAMMAL_TYPE type;
    if (strcmp(typeStr, "PREDATOR") == 0) {
        type = PREDATOR;
    } else if (strcmp(typeStr, "HERBIVORE") == 0) {
        type = HERBIVORE;
    } else if (strcmp(typeStr, "INSECTIVOROUS") == 0) {
        type = INSECTIVOROUS;
    } else {
        return nullptr;
    }

    return new Mammal(name, mass, type);
}

Mammal *Mammal::inRnd() {
    int mass_gram = Random::RandomRange(1, 1000);
    char name[256];
    Random::RandomString(name, 11);

    int type_num = Random::RandomRange(0, 2);
    MAMMAL_TYPE new_type = static_cast<MAMMAL_TYPE>(type_num);

    return new Mammal(name, mass_gram, new_type);
}

void Mammal::out(FILE *ofst) {
    const char *typeStr;
    if (type == PREDATOR) {
        typeStr = "PREDATOR";
    } else if (type == HERBIVORE) {
        typeStr = "HERBIVORE";
    } else if (type == INSECTIVOROUS) {
        typeStr = "INSECTIVOROUS";
    } else {
        typeStr = "UNKNOWN_TYPE";
    }

    fprintf(ofst, "It is Mammal: type = %s.", typeStr);
    Animal::out(ofst);
}
