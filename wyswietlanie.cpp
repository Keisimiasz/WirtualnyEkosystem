#include "wyswietlanie.h"

Wyswietlanie::Wyswietlanie(QWidget *parent)
    : QGraphicsView(parent)
{
    poligon = new QPolygonF();
    polItem = new QGraphicsPolygonItem();
    scene = new QGraphicsScene();

    scene->addItem(polItem);
    setScene(scene);
    setFixedSize(600, 600);
    fitInView(0, 0, 220, 220, Qt::KeepAspectRatio);
}

Wyswietlanie::~Wyswietlanie()
{
    delete poligon;
    delete polItem;
    delete scene;
}

void Wyswietlanie::show()
{
    przerysuj(0);
    QGraphicsView::show();
}

void Wyswietlanie::przerysuj(int a)
{
    double aa = model->wartosc_a();
    double bb = model->wartosc_b();
    double dd = model->wartosc_d();

    if (a > 0) aa = static_cast<double>(a);

    model->ustawParemery(aa, bb, dd);
    *poligon = model->getQPolygnF();
    polItem->setPolygon(*poligon);
}
