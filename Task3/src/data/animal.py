import random


class Animal:
    def __init__(self):
        self.name = ""
        self.mass_gram = 0

    def __init__(self, name, mass_gram):
        self.name = name
        self.mass_gram = mass_gram

    def get_animal_file(file):
        line_str = file.readline()
        if not line_str:
            return None

        animal_type = int(line_str)

        if (animal_type == 1):
            from data.fish import Fish
            return Fish.get_from_file(file)
        elif (animal_type == 2):
            from data.bird import Bird
            return Bird.get_from_file(file)
        elif (animal_type == 3):
            from data.mammal import Mammal
            return Mammal.get_from_file(file)

    def get_rand_animal():
        animal_type = random.randint(1, 3)
        if (animal_type == 1):
            from data.fish import Fish
            return Fish.get_rand()
        elif (animal_type == 2):
            from data.bird import Bird
            return Bird.get_rand()
        elif (animal_type == 3):
            from data.mammal import Mammal
            return Mammal.get_rand()

    def print(self, file):
        file.write(
            f" Name = {self.name}, mass = {self.mass_gram}. Task result: {self.calculate_task()}\n")

    def calculate_task(self):
        res = 0
        for i in range(len(self.name)):
            res += ord(self.name[i])

        res /= self.mass_gram
        return res
