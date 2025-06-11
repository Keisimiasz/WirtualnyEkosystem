 #include "model.h"

     void Model::wygenerujPunkty()
     {
     double tmax = a < b ? 4*M_PI/a : 4*M_PI/b, t=0;

         punkty.clear();
     while(t<tmax){
         p.setX(skala * sin(a*t+d));
         p.setY(skala * sin(b*t));
         punkty.push_back(p);
         t+=dt;
         }
     }

     void Model::ustawParemery(double _a, double _b, double _d)
     {
     a = _a;
     b = _b;
     d = _d;
     wygenerujPunkty();
     }

     void Model::ustawSkale(double _skala)
     {
     if(skala > 0){
         skala = _skala;
         dt = 1.0/skala;
         wygenerujPunkty();
         }
     }
