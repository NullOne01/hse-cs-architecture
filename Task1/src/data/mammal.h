#ifndef __mammal__
#define __mammal__

//------------------------------------------------------------------------------
// mammal.h - содержит описание млекопитающего и его интерфейса
//------------------------------------------------------------------------------

#include <stdio.h>

// млекопитающее
struct mammal {
    enum MAMMAL_TYPE {PREDATOR, HERBIVORE, INSECTIVOROUS} type; //тип зверя
};

// Ввод параметров млекопитающего из потока
int InMammal(struct mammal *m, FILE *ifst);

// Случайный ввод параметров млекопитающего
void InRndMammal(struct mammal *m);

// Вывод параметров млекопитающего в форматируемый поток
void OutMammal(struct mammal *m, FILE *ofst);

#endif //__mammal__
