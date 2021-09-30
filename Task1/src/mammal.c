//------------------------------------------------------------------------------
// mammal.c - содержит процедуру ввода параметров
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include <string.h>
#include "mammal.h"

//------------------------------------------------------------------------------
// Ввод параметров млекопитающего из файла
int InMammal(struct mammal *m, FILE *ifst) {
    char typeStr[20];
    if (fscanf(ifst, "%s", typeStr) == EOF)
        return EOF;

    if (strcmp(typeStr, "PREDATOR") == 0) {
        m->type = PREDATOR;
    } else if (strcmp(typeStr, "HERBIVORE") == 0) {
        m->type = HERBIVORE;
    } else if (strcmp(typeStr, "INSECTIVOROUS") == 0) {
        m->type = INSECTIVOROUS;
    } else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров млекопитающего
void InRndMammal(struct mammal *m) {
    int randNum = RandomRange(0, 2);

    // Случайный тип млекопитающего
    m->type = randNum;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void OutMammal(struct mammal *m, FILE *ofst) {
    char* typeStr;
    if (m->type == PREDATOR) {
        typeStr = "PREDATOR";
    } else if (m->type == HERBIVORE) {
        typeStr = "HERBIVORE";
    } else if (m->type == INSECTIVOROUS) {
        typeStr = "INSECTIVOROUS";
    } else {
        typeStr = "UNKNOWN_TYPE";
    }

    fprintf(ofst, "It is Mammal: type = %s.", typeStr);
}
