//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "data/Container.h"

void errMessage1() {
    printf("incorrect command line!\n");
    printf("  Waited:\n");
    printf("     command -f infile outfile01 outfile02\n");
    printf("  Or:\n");
    printf("     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n");
    printf("  Waited:\n");
    printf("     command -f infile outfile01 outfile02\n");
    printf("  Or:\n");
    printf("     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Container c;

    if (!strcmp(argv[1], "-f")) {
        FILE *ifst = fopen(argv[2], "r");
        c.in(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of animals = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int) (time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.inRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    c.out(ofst1);

    // The 2nd part of task
    c.sortShellContainer();

    FILE *ofst2 = fopen(argv[4], "w");
    fprintf(ofst2, "Sorted container:\n");
    c.out(ofst2);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed (seconds): %f\n", cpu_time_used);
    printf("Stop\n");
    return 0;
}
