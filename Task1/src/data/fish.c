//------------------------------------------------------------------------------
// fish.c - содержит процедуру ввода параметров
// для уже созданной рыбы
//------------------------------------------------------------------------------

#include <string.h>
#include "fish.h"
#include "../utilities/rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров рыбы из файла
int InFish(struct fish *f, FILE *ifst) {
    char habitatStr[10];
    if (fscanf(ifst, "%s", habitatStr) == EOF)
        return EOF;

    if (strcmp(habitatStr, "RIVER") == 0) {
        f->habitat = RIVER;
    } else if (strcmp(habitatStr, "SEA") == 0) {
        f->habitat = SEA;
    } else if (strcmp(habitatStr, "LAKE") == 0) {
        f->habitat = LAKE;
    } else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров рыбы
void InRndFish(struct fish *f) {
    int randNum = RandomRange(0, 2);

    // Случайное место обитания
    f->habitat = randNum;
}

//------------------------------------------------------------------------------
// Вывод параметров рыбы в форматируемый поток
const char* OutFish(struct fish *f, FILE *ofst) {
    char* habitatStr;
    if (f->habitat == RIVER) {
        habitatStr = "RIVER";
    } else if (f->habitat == SEA) {
        habitatStr = "SEA";
    } else if (f->habitat == LAKE) {
        habitatStr = "LAKE";
    } else {
        habitatStr = "UNKNOWN_HABITAT";
    }

    fprintf(ofst, "It is Fish: habitat = %s.", habitatStr);
}
