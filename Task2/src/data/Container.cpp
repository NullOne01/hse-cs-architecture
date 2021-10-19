#include "Container.h"

Container::Container() {
    cont = new Animal *[MAX_LEN];
}

Container::~Container() {
    for (int i = 0; i < len_; i++) {
        delete cont[i];
    }

    delete[] cont;
}

void Container::in(FILE *ifst) {
    Animal *newAnimal;
    while ((newAnimal = Animal::in(ifst)) != nullptr) {
        cont[len_] = newAnimal;
        len_++;
    }
}

void Container::inRnd(int size) {
    while (len_ < size) {
        if ((cont[len_] = Animal::inRnd()) != nullptr) {
            len_++;
        }
    }
}

void Container::out(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len_);
    for (int i = 0; i < len_; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->out(ofst);
    }
}

void Container::sortShellContainer() {
    for (int s = len_ / 2; s > 0; s /= 2) {
        for (int i = 0; i < len_; i++) {
            for (int j = i + s; j < len_; j += s) {
                // Мы здесь пересчитываем каждый раз, но не страшно.
                if (cont[i]->calculateTask() > cont[j]->calculateTask()) {
                    Animal *temp = cont[j];
                    cont[j] = cont[i];
                    cont[i] = temp;
                }
            }
        }
    }
}
