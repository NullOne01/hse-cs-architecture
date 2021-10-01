//------------------------------------------------------------------------------
// bird.c - содержит функции обработки птицы
//------------------------------------------------------------------------------

#include <string.h>
#include "bird.h"
#include "../utilities/rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров птицы из потока
int InBird(struct bird *b, FILE *ifst) {
    char migrantStr[10];
    if (fscanf(ifst, "%s", migrantStr) == EOF)
        return EOF;

    if (strcmp(migrantStr, "TRUE") == 0) {
        b->isMigrant = true;
    } else if (strcmp(migrantStr, "FALSE") == 0) {
        b->isMigrant = false;
    } else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров птицы
void InRndBird(struct bird *b) {
    b->isMigrant = RandomRange(0, 1);
}

//------------------------------------------------------------------------------
// Вывод параметров птицы в поток
void OutBird(struct bird *b, FILE *ofst) {
    char *migrantStr;
    if (b->isMigrant) {
        migrantStr = "YES";
    } else {
        migrantStr = "NO";
    }

    fprintf(ofst, "It is Bird: isMigrant = %s.", migrantStr);
}
