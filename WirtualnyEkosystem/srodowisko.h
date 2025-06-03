#ifndef SRODOWISKO_H
#define SRODOWISKO_H

#include <string>
#include "ustawienia.h"
#include "sasiedztwo.h"
using namespace std;
class Nisza;
class Mieszkaniec;
class Sasiedztwo;

class Srodowisko {
public:
    const unsigned int wiersze, kolumny;
    const unsigned long liczbaNisz;
    void operator++(int) { wykonajKrokSymulacji(); }
    bool operator!() { return !martwy(); }

private:
    Nisza** nisza;

public:
    Srodowisko(unsigned int _wiersze,
               unsigned int _kolumny);

    ~Srodowisko();

    void lokuj(Mieszkaniec* mieszkaniec,
               unsigned int wiersz, unsigned int kolumna);


    Sasiedztwo ustalSasiedztwo(unsigned int wiersz,
                               unsigned int kolumna) const;

    unsigned long liczba(RodzajMieszkanca rodzaj) const;

    bool martwy();

    void wykonajSkok(unsigned int wiersz,
                     unsigned int kolumna);

    void wykonajAkcje(unsigned int wiersz,
                      unsigned int kolumna);

    void wykonajKrokSymulacji();

    string doTekstu() const;
};

ostream & operator<<(ostream & strumien, const Srodowisko & srodowisko);


#endif
