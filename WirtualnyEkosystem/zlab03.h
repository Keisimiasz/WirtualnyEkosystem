#ifndef LABCPP_ZLAB03_H
#define LABCPP_ZLAB03_H

#include <string>
#include <iostream>

class Prostokat {
private:
    std::string nazwa;
    double bok1, bok2;
    bool poprawny;
    double obwod, pole;

    bool czyPoprawny(double bok1, double bok2);
    void obliczObwod();
    void obliczPole();

public:
    Prostokat(std::string n = "?", double a = 1, double b = 2);
    ~Prostokat();

    bool czyPoprawny() const;
    const std::string& jakaNazwa() const;
    double podajPole() const;
    double podajObwod() const;
    bool zmienBoki(double a, double b);
    std::string do_tekstu() const;

    Prostokat & operator++(int);   // postfix
    Prostokat & operator++();       // prefix
    bool operator!() const { return !czyPoprawny(); }
    bool operator<(const Prostokat &p) const;
};

std::istream &operator>>(std::istream &strumien, Prostokat &prostokat);
std::ostream &operator<<(std::ostream &strumien, const Prostokat &prostokat);

class Kwadrat {
private:
    std::string nazwa;
    double bok;
    bool poprawny;
    double obwod, pole;

    bool czy_poprawny(double bok);
    void oblicz_obwod();
    void oblicz_pole();

public:
    Kwadrat(std::string n = "?", double a = 1);
    ~Kwadrat();

    bool czy_poprawny() const;
    const std::string& jaka_nazwa() const;
    double podaj_pole() const;
    double podaj_obwod() const;
    bool zmien_boki(double a);
    std::string do_tekstu() const;

    friend std::ostream& operator<<(std::ostream& os, const Kwadrat& k);
};

#endif // LABCPP_ZLAB03_H
