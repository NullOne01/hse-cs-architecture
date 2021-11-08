import string
import random

from data.animal import Animal


class Bird(Animal):
    def __init__(self):
        self.is_migrant = False
        Animal.__init__(self)

    def __init__(self, name, mass_gram, is_migrant):
        self.is_migrant = is_migrant
        Animal.__init__(self, name, mass_gram)

    def get_from_file(file):
        str_line = file.readline().strip()
        if not str_line:
            return None
        (name, mass_gram) = [t(s)
                             for t, s in zip((str, int), str_line.split())]

        is_migrant_str = file.readline().strip()
        if not is_migrant_str:
            return None

        is_migrant = is_migrant_str == "TRUE"

        return Bird(name, mass_gram, is_migrant)

    def get_rand():
        rand_mass_gram = random.randint(1, 1000)
        rand_name = ''.join(random.choice(string.ascii_uppercase)
                            for _ in range(11))
        rand_is_migrant = random.choice([True, False])

        return Bird(rand_name, rand_mass_gram, rand_is_migrant)

    def print(self, file):
        is_migrant_str = "YES" if self.is_migrant else "NO"
        file.write(f"It is Bird: isMigrant = { is_migrant_str }.")
        super().print(file)
