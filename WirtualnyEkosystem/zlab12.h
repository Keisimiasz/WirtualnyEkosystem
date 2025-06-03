#ifndef ZLAB12_H
#define ZLAB12_H

#include <string>
using namespace std;

class ZLab12 {
public:
    void strumienTekstowy();
    void zapisTekstowyDoPliku(string nazwaPliku);
    void odczytPlikuTekstowego(string nazwaPliku);
    void zapisBinarnyDoPliku(string nazwaPliku);
    void odczytPlikuBinarnego(string nazwaPliku);
};


#endif
