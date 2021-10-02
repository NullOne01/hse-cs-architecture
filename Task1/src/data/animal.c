//------------------------------------------------------------------------------
// animal.c - содержит процедуры связанные с обработкой обобщенного животного
// и создания произвольного животного
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "../utilities/rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного животного из файла
struct animal *InAnimal(FILE *ifst) {
    struct animal *an;
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return ((void *) 0);

    int mass;
    char name[256];
    if (fscanf(ifst, "%s %d", name, &mass) == EOF)
        return ((void *) 0);

    switch (k) {
        case 1:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = FISH;
            strcpy(an->name, name);
            an->mass_gram = mass;
            if (InFish(&an->f, ifst) == EOF) {
                free(an);
                return ((void *) 0);
            }
            return an;
        case 2:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = BIRD;
            strcpy(an->name, name);
            an->mass_gram = mass;
            if (InBird(&an->b, ifst) == EOF) {
                free(an);
                return ((void *) 0);
            }
            return an;
        case 3:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = MAMMAL;
            strcpy(an->name, name);
            an->mass_gram = mass;
            if (InMammal(&an->m, ifst) == EOF) {
                free(an);
                return ((void *) 0);
            }
            return an;
        default:return ((void *) 0);
    }
}

// Случайный ввод обобщенного животного
struct animal *InRndAnimal() {
    // +1 - это символ \0
    const int NAME_LENGTH = 10 + 1;

    struct animal *an;
    int k = RandomRange(1, 3);
    switch (k) {
        case 1:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = FISH;
            an->mass_gram = RandomRange(1, 1000);
            RandomString(an->name, NAME_LENGTH);
            InRndFish(&an->f);
            return an;
        case 2:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = BIRD;
            an->mass_gram = RandomRange(1, 1000);
            RandomString(an->name, NAME_LENGTH);
            InRndBird(&an->b);
            return an;
        case 3:an = (struct animal *) malloc(sizeof(struct animal));
            an->k = MAMMAL;
            an->mass_gram = RandomRange(1, 1000);
            RandomString(an->name, NAME_LENGTH);
            InRndMammal(&an->m);
            return an;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего животного в поток
void OutAnimal(struct animal *a, FILE *ofst) {
    switch (a->k) {
        case FISH:OutFish(&a->f, ofst);
            break;
        case BIRD:OutBird(&a->b, ofst);
            break;
        case MAMMAL:OutMammal(&a->m, ofst);
            break;
        default:fprintf(ofst, "Incorrect animal!\n");
            return;
    }

    fprintf(ofst, " Name = %s, mass = %d. Task result: %f\n", a->name, a->mass_gram, CalculateTask(a));
}

//------------------------------------------------------------------------------
// Реализация общей для всех альтернатив функции
double CalculateTask(struct animal *a) {
    double res = 0;
    for (int i = 0; i < strlen(a->name); i++) {
        res += (int) a->name[i];
    }

    res /= (double) a->mass_gram;

    return res;
}
