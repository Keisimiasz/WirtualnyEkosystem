#include "zlab03.h"
#include <iostream>

// ----------- Prostokat ------------

bool Prostokat::czyPoprawny(double bok1, double bok2) {
    return bok1 > 0 && bok2 > 0;
}

void Prostokat::obliczObwod() {
    obwod = 2 * (bok1 + bok2);
}

void Prostokat::obliczPole() {
    pole = bok1 * bok2;
}

Prostokat::Prostokat(std::string n, double a, double b) : nazwa(n) {
    poprawny = czyPoprawny(a, b);

    if (poprawny) {
        bok1 = a;
        bok2 = b;
        obliczPole();
        obliczObwod();
    }
    else {
        bok1 = bok2 = pole = obwod = 0;
    }
}

Prostokat::~Prostokat() {
    std::cout << "Prostokąt: " << nazwa << " znika." << std::endl;
}

bool Prostokat::czyPoprawny() const {
    return poprawny;
}

const std::string& Prostokat::jakaNazwa() const {
    return nazwa;
}

double Prostokat::podajPole() const {
    return pole;
}

double Prostokat::podajObwod() const {
    return obwod;
}

bool Prostokat::zmienBoki(double a, double b) {
    if (czyPoprawny(a, b)) {
        poprawny = true;
        bok1 = a;
        bok2 = b;
        obliczPole();
        obliczObwod();
        return true;
    }
    return false;
}

std::string Prostokat::do_tekstu() const {
    std::string napis = "Prostokąt o nazwie: " + nazwa +
        " bok1=" + std::to_string(bok1) +
        " bok2=" + std::to_string(bok2);

    if (poprawny) {
        napis += " obwód=" + std::to_string(obwod) +
            " pole=" + std::to_string(pole);
    }
    else {
        napis += " !Figura niepoprawna.";
    }

    return napis;
}

std::ostream& operator<<(std::ostream& strumien, const Prostokat& prostokat) {
    strumien << prostokat.do_tekstu();
    return strumien;
}

std::istream& operator>>(std::istream& strumien, Prostokat& prostokat) {
    double a, b;
    strumien >> a >> b;
    prostokat.zmienBoki(a, b);
    return strumien;
}

Prostokat& Prostokat::operator++(int) {
    bok1 *= 2;
    bok2 *= 2;
    obliczPole();
    obliczObwod();
    return *this;
}

Prostokat& Prostokat::operator++() {
    bok1 *= 2;
    bok2 *= 2;
    obliczPole();
    obliczObwod();
    return *this;
}

bool Prostokat::operator<(const Prostokat &p) const {
    return pole < p.pole;
}

// ----------- Kwadrat ------------

bool Kwadrat::czy_poprawny(double bok) {
    return bok > 0;
}

void Kwadrat::oblicz_obwod() {
    obwod = 4 * bok;
}

void Kwadrat::oblicz_pole() {
    pole = bok * bok;
}

Kwadrat::Kwadrat(std::string n, double a) : nazwa(n) {
    poprawny = czy_poprawny(a);

    if (poprawny) {
        bok = a;
        oblicz_pole();
        oblicz_obwod();
    }
    else {
        bok = pole = obwod = 0;
    }
}

Kwadrat::~Kwadrat() {
    std::cout << "Kwadrat: " << nazwa << " znika." << std::endl;
}

bool Kwadrat::czy_poprawny() const {
    return poprawny;
}

const std::string& Kwadrat::jaka_nazwa() const {
    return nazwa;
}

double Kwadrat::podaj_pole() const {
    return pole;
}

double Kwadrat::podaj_obwod() const {
    return obwod;
}

bool Kwadrat::zmien_boki(double a) {
    if (czy_poprawny(a)) {
        poprawny = true;
        bok = a;
        oblicz_pole();
        oblicz_obwod();
        return true;
    }
    return false;
}

std::string Kwadrat::do_tekstu() const {
    std::string napis = "Kwadrat o nazwie: " + nazwa +
        " bok=" + std::to_string(bok);

    if (poprawny) {
        napis += " obwod=" + std::to_string(obwod) +
            " pole=" + std::to_string(pole);
    }
    else {
        napis += " !Figura niepoprawna.";
    }

    return napis;
}

std::ostream& operator<<(std::ostream& os, const Kwadrat& k) {
    os << k.do_tekstu();
    return os;
}
