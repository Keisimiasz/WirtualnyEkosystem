#ifndef MODEL_H
#define MODEL_H

#include <cmath>
#include <QVector>
#include <QPointF>
#include <QPolygonF>

class Model {
private:
    double a=1, b=2, d = M_PI/2, skala = 100,
        dt = 1/skala;
    QPointF p;
    QVector<QPointF> punkty;
    void wygenerujPunkty();

public:
    Model(){ wygenerujPunkty();}
    void ustawParemery(double _a, double _b, double _d);
    void ustawSkale(double _skala);
    double wartosc_a() const {return a;}
    double wartosc_b() const {return b;}
    double wartosc_d() const {return d;}

    QPolygonF getQPolygnF() const
    {return QPolygonF(punkty);}
};

#endif // MODEL_H
