#include <cstring>
#include "Bird.h"
#include "../utilities/Random.h"

Bird::Bird(const char *name, int mass_gram, bool is_migrant) : Animal(name, mass_gram), is_migrant_(is_migrant) {}

Bird *Bird::in(FILE *ifst) {
    int mass;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &mass) == EOF)
        return nullptr;

    char migrant_str[10];
    if (fscanf(ifst, "%s", migrant_str) == EOF)
        return nullptr;

    bool is_migrant;
    if (strcmp(migrant_str, "TRUE") == 0) {
        is_migrant = true;
    } else if (strcmp(migrant_str, "FALSE") == 0) {
        is_migrant = false;
    } else {
        return nullptr;
    }

    return new Bird(name, mass, is_migrant);
}

Bird *Bird::inRnd() {
    int mass_gram = Random::RandomRange(1, 1000);
    char name[256];
    Random::RandomString(name, 11);
    bool is_migrant = Random::RandomRange(0, 1);

    return new Bird(name, mass_gram, is_migrant);
}

void Bird::out(FILE *ofst) {
    const char *migrantStr;
    if (is_migrant_) {
        migrantStr = "YES";
    } else {
        migrantStr = "NO";
    }

    fprintf(ofst, "It is Bird: isMigrant = %s.", migrantStr);
    Animal::out(ofst);
}
