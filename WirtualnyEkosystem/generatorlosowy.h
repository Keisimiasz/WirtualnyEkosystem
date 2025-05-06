#ifndef WIRTUALNYEKOSYSTEM_GENERATORLOSOWY_H
#define WIRTUALNYEKOSYSTEM_GENERATORLOSOWY_H

#include <random>

class GeneratorLosowy {
private:
    static std::random_device device;

    GeneratorLosowy() {}

public:
    static unsigned short losujPomiedzy
            (unsigned short min, unsigned short max);

    static long losujPomiedzy(long min, long max);

    static int losujOdZeraDo(int max);
};

typedef GeneratorLosowy GEN; //Poza definicją klasy

#endif