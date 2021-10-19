#include <cstring>
#include "Fish.h"
#include "../utilities/Random.h"

Fish::Fish(const char *name, int mass_gram, Fish::HABITAT habitat) : Animal(name, mass_gram), habitat(habitat) {}

Fish *Fish::in(FILE *ifst) {
    int mass;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &mass) == EOF)
        return nullptr;

    char habitatStr[10];
    if (fscanf(ifst, "%s", habitatStr) == EOF)
        return nullptr;

    Fish::HABITAT new_habitat;
    if (strcmp(habitatStr, "RIVER") == 0) {
        new_habitat = RIVER;
    } else if (strcmp(habitatStr, "SEA") == 0) {
        new_habitat = SEA;
    } else if (strcmp(habitatStr, "LAKE") == 0) {
        new_habitat = LAKE;
    } else {
        return nullptr;
    }

    return new Fish(name, mass, new_habitat);
}

Fish *Fish::inRnd() {
    int mass_gram = Random::RandomRange(1, 1000);
    char name[256];
    Random::RandomString(name, 11);

    int habitat_num = Random::RandomRange(0, 2);
    HABITAT new_habitat = static_cast<HABITAT>(habitat_num);

    return new Fish(name, mass_gram, new_habitat);
}

void Fish::out(FILE *ofst) {
    const char* habitat_str;
    if (habitat == RIVER) {
        habitat_str = "RIVER";
    } else if (habitat == SEA) {
        habitat_str = "SEA";
    } else if (habitat == LAKE) {
        habitat_str = "LAKE";
    } else {
        habitat_str = "UNKNOWN_HABITAT";
    }

    fprintf(ofst, "It is Fish: habitat = %s.", habitat_str);
    Animal::out(ofst);
}
