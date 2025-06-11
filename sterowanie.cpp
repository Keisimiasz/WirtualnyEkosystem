#include "sterowanie.h"

Sterowanie::Sterowanie(QWidget *parent)
    : QWidget(parent)
{
    przyciskKoniec = new QPushButton("KONIEC", this);
    napis_a = new QLabel("Parametr_a", this);
    slider_a = new QSlider(Qt::Horizontal, this);

    slider_a->setRange(1, 20);
    slider_a->setValue(1);

    ukladacz = new QVBoxLayout();

    ukladacz->addWidget(napis_a);
    ukladacz->addWidget(slider_a);
    ukladacz->addWidget(przyciskKoniec);

    setLayout(ukladacz);
}
