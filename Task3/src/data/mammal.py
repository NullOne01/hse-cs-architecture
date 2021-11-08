from data.animal import Animal
import string
import random

from enum import Enum


class MammalType(Enum):
    PREDATOR = 0
    HERBIVORE = 1
    INSECTIVOROUS = 2


class Mammal(Animal):
    def __init__(self):
        self.type = MammalType.PREDATOR
        Animal.__init__(self)

    def __init__(self, name, mass_gram, type):
        self.type = type
        Animal.__init__(self, name, mass_gram)

    def get_from_file(file):
        str_line = file.readline().strip()
        if not str_line:
            return None
        (name, mass_gram) = [t(s)
                             for t, s in zip((str, int), str_line.split())]

        type_str = file.readline().strip()
        if not type_str:
            return None

        type = MammalType.PREDATOR
        if type_str == "PREDATOR":
            type = MammalType.PREDATOR
        elif type_str == "HERBIVORE":
            type = MammalType.HERBIVORE
        elif type_str == "INSECTIVOROUS":
            type = MammalType.INSECTIVOROUS

        return Mammal(name, mass_gram, type)

    def get_rand():
        rand_mass_gram = random.randint(1, 1000)
        rand_name = ''.join(random.choice(string.ascii_uppercase)
                            for _ in range(11))
        rand_type = random.choice(list(MammalType))

        return Mammal(rand_name, rand_mass_gram, rand_type)

    def print(self, file):
        type_str = "UNKNOWN_TYPE"
        if self.type is MammalType.PREDATOR:
            type_str = "PREDATOR"
        elif self.type is MammalType.HERBIVORE:
            type_str = "HERBIVORE"
        elif self.type is MammalType.INSECTIVOROUS:
            type_str = "INSECTIVOROUS"

        file.write(f"It is Mammal: type = {type_str}.")
        super().print(file)
