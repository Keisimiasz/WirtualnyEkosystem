#include <iostream>
#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "zlab10.h"
#include "zlab03.h"
#include <windows.h>
#include "nisza.h"
#include "osobniki.h"

using namespace std;

/*int main() {
    Nisza nisza;
    nisza.przyjmijLokatora(new Bakteria());

    cout << "Kto w niszy: "
        << nisza.ktoTuMieszka() << endl;
    cout << "Czy żywy: "
        << nisza.lokatorZywy() << endl;

    Sasiedztwo sasiedztwo;
    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    ZamiarMieszkanca zamiar =
        nisza.aktywujLokatora(sasiedztwo);

    cout << "Akjca: " << zamiar.akcja << " gdzie: "
        << zamiar.gdzie << endl;

    cout << endl;
    return 0;
}*/


/*
static Nisza n1, n2, n3;
static char sep = UstawieniaSymulacji::
    pobierzUstawienia().znakSeparator;

void wyswietlNisze() {
    cout << n1.jakiSymbol() << sep
        << n2.jakiSymbol() << sep
        << n3.jakiSymbol() << endl;
}

int main() {
    cout << "Puste nisze: ";
    wyswietlNisze();

    cout << "Lokowanie mieszkańców: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    cout << "Przesuwanie lokatorów: ";
    n2 = n1;
    wyswietlNisze();

    cout << "Przesuwanie lokatorów:";
    n3 = n2;
    wyswietlNisze();

    cout << endl;
    return 0;
}*/

/* string nazwaRodzaju(RodzajMieszkanca rodzaj) {
    /*switch (rodzaj) {
        case GLON:
            return "GLON";
        case GRZYB:
            return "GRZYB";
        case BAKTERIA:
            return "BAKTERIA";
        case PUSTKA:
            return "PUSTKA";
        case SCIANA:
            return "ŚCIANA";
        case TRUP:
            return "TRUP";
        case NIEZNANE:
            return "NIEZNANE";
    }
}

void drukujOrganizm(const Organizm &o) {
    cout << "licznikZycia: "
         << o.stanLicznikaZycia()
         << " licznikPosilkow: "
         << o.stanLicznikaPosilkow() << endl
         << "limitPosilkow: "
         << o.limitPosilkow
         << " kosztPotomka: "
         << o.kosztPotomka << endl
         << "głodny: " << o.glodny()
         << " pączkujący: "
         << o.paczkujacy() << endl << endl;
}

void wyswietl(UstawieniaSymulacji &UST) {
    cout << "Znak glon:" << UST.znakGlon
         << " zycieMin=" << UST.glonZycieMin
         << " zycieMax=" << UST.glonZycieMax << endl;
}

int main() {
    //1. Test kreacji obiektów
    Organizm organizm1(8, 3, 2);
    Organizm organizm2 = organizm1;
    Organizm organizm3(organizm1);

    cout << "Wynik testu kreacji obiektów:"
         << endl << endl;
    cout << "Organizm1:" << endl;
    drukujOrganizm(organizm1);
    cout << "Organizm2" << endl;
    drukujOrganizm(organizm2);
    cout << "Organizm3" << endl;
    drukujOrganizm(organizm3);

    //2. Test niezależności obiektów
    organizm1.posilek();
    organizm1.posilek();
    organizm2.posilek();
    organizm3.krokSymulacji();

    cout << "Wynik testu niezależności obiektów:"
         << endl << endl;

    cout << "Organizm1:" << endl;
    drukujOrganizm(organizm1);
    cout << "Organizm2" << endl;
    drukujOrganizm(organizm2);
    cout << "Organizm3" << endl;
    drukujOrganizm(organizm3);

    //3. Test symulacji
    Organizm organizm4(8, 3, 2);

    cout << "Wynik testu symulacji:"
         << endl << endl;
    cout << "Stan początkowy:" << endl;
    drukujOrganizm(organizm4);

    for (int i = 1; i < 11; i++) {
        organizm4.krokSymulacji();

        if (organizm4.paczkujacy()) {
            organizm4.potomek();
            cout << "---> Potomek" << endl;
        } else organizm4.posilek();

        cout << "Po wykonaniu kroku symulacji: "
             << i << endl;
        drukujOrganizm(organizm4);
    }

    //1. Dostęp do obiektu klasy UstawienaSymulacji
    UstawieniaSymulacji &UST1
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji &UST2
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji &UST3
            = UstawieniaSymulacji::pobierzUstawienia();

    cout << "Pobranie ustawien 3x" << endl;
    cout << "UST1: ";
    wyswietl(UST1);
    cout << "UST2: ";
    wyswietl(UST2);
    cout << "UST3: ";
    wyswietl(UST3);

    cout << endl << "Zmiana wartości tylko 1x" << endl;
    UST2.glonZycieMax = 100;
    cout << "UST1: ";
    wyswietl(UST1);
    cout << "UST2: ";
    wyswietl(UST2);
    cout << "UST3: ";
    wyswietl(UST3);

    cout << "Liczby losowe typu int:" << endl;
    cout << " od 0 do 5: ";
    for (int i = 0; i < 10; i++)
        cout << GEN::losujOdZeraDo(5) << " ";
    cout << endl << " od 0 do 3: ";
    for (int i = 0; i < 10; i++)
        cout << GEN::losujOdZeraDo(3) << " ";
    cout << endl << " od 0 do 20: ";
    for (int i = 0; i < 10; i++)
        cout << GEN::losujOdZeraDo(20) << " ";

    cout << endl << endl;

    cout << "Liczby losowe typu long: " << endl;
    cout << " od -2 do 2:";
    for (int i = 0; i < 10; i++)
        cout << GEN::losujPomiedzy(-2L, 2L) << " ";

    cout << endl << endl
         << "Liczby losowe typu unsigned short: " << endl;
    cout << " od 2 do 6: ";
    unsigned short min = 2, max = 6;

    for (int i = 0; i < 10; i++)
        cout << GEN::losujPomiedzy(max, min) << " ";

    cout << endl << endl;

    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    cout << "Przegląd sąsiedztwa:" << endl;

    for (int i = 0; i < 8; i++) {

        Polozenie p = static_cast<Polozenie>(i);
        RodzajMieszkanca
                r = sasiedztwo.ktoJestSasiadem(p);

        cout << "polozenie=" << p << " rodzaj="
             << nazwaRodzaju(r) << endl;
    }

    cout << endl << "Policzenie sasiadów"
         << "określonego rodzaju:" << endl
         << " glony=" << sasiedztwo.ile(GLON) << endl
         << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
         << " trupy=" << sasiedztwo.ile(TRUP) << endl;

    cout << endl << "Wylosowanie sasiada:" << endl
         << " glon -> "
         << sasiedztwo.losujSasiada(GLON) << endl
         << " pustka -> "
         << sasiedztwo.losujSasiada(PUSTKA) << endl
         << " trup -> "
         << sasiedztwo.losujSasiada(TRUP) << endl;


    long wiersz, kolumna;
    cout << endl
         << "Zmiana indeksów [5][7] "
         << "wg polozenia:" << endl;

    for (int i = 0; i < 8; i++) {

        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 5;
        kolumna = 7;

        Sasiedztwo::
        zmienIdeksyWgPolozenia(p, wiersz, kolumna);

        cout << " położenie: " << p << " ->[" << wiersz
             << "][" << kolumna << "]" << endl;
    }

    cout << endl;

    return 0;
}*/

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Prostokat p0("Prostokat", 2, 3);
    cout << "!p0=" << !p0 << endl;
    Prostokat p1("Prostokat", 0, 0);
    cout << "!p1=" << !p1 << endl;

    return 0;
}
