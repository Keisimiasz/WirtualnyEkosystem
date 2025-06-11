#ifndef STEROWANIE_H
#define STEROWANIE_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>

class Sterowanie : public QWidget {
    Q_OBJECT

private:
    QLabel *napis_a;
    QSlider *slider_a;
    QPushButton *przyciskKoniec;
    QVBoxLayout *ukladacz;

public:
    Sterowanie(QWidget *parent = nullptr);
    const QPushButton *przycisk() { return przyciskKoniec; }
    const QSlider *slidera() { return slider_a; }
};

#endif // STEROWANIE_H
