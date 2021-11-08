from data.animal import Animal
import string
import random

from enum import Enum


class Habitat(Enum):
    RIVER = 0
    SEA = 1
    LAKE = 2


class Fish(Animal):
    def __init__(self):
        self.habitat = Habitat.RIVER
        Animal.__init__(self)

    def __init__(self, name, mass_gram, habitat):
        self.habitat = habitat
        Animal.__init__(self, name, mass_gram)

    def get_from_file(file):
        str_line = file.readline().strip()
        if not str_line:
            return None
        (name, mass_gram) = [t(s)
                             for t, s in zip((str, int), str_line.split())]

        habitat_str = file.readline().strip()
        if not habitat_str:
            return None

        habitat = Habitat.RIVER
        if habitat_str == "RIVER":
            habitat = Habitat.RIVER
        elif habitat_str == "SEA":
            habitat = Habitat.SEA
        elif habitat_str == "LAKE":
            habitat = Habitat.LAKE

        return Fish(name, mass_gram, habitat)

    def get_rand():
        rand_mass_gram = random.randint(1, 1000)
        rand_name = ''.join(random.choice(string.ascii_uppercase)
                            for _ in range(11))
        rand_habitat = random.choice(list(Habitat))

        return Fish(rand_name, rand_mass_gram, rand_habitat)

    def print(self, file):
        habitat_str = "UNKNOWN_HABITAT"
        if self.habitat == Habitat.RIVER:
            habitat_str = "RIVER"
        elif self.habitat == Habitat.SEA:
            habitat_str = "SEA"
        elif self.habitat == Habitat.LAKE:
            habitat_str = "LAKE"

        file.write(f"It is Fish: habitat = {habitat_str}.")
        super().print(file)
