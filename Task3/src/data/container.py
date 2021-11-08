
from data.animal import Animal


class Container:
    def __init__(self):
        self.store = []

    def fill_file(self, file):
        new_animal = Animal.get_animal_file(file)
        while (new_animal != None):
            self.store.append(new_animal)
            new_animal = Animal.get_animal_file(file)

    def fill_rand(self, size):
        for i in range(size):
            self.store.append(Animal.get_rand_animal())

    def print(self, file):
        file.write(f"Container contains {len(self.store)} elements.\n")
        for i in range(len(self.store)):
            file.write(f"{i}: ")
            self.store[i].print(file)

    def sort_shell(self):
        length = len(self.store)
        s = length // 2
        while (s > 0):
            for i in range(length):
                for j in range(i + s, length, s):
                    # Мы здесь пересчитываем каждый раз, но не страшно.
                    if (self.store[i].calculate_task() > self.store[j].calculate_task()):
                        self.store[i], self.store[j] = self.store[j], self.store[i]
            s //= 2
