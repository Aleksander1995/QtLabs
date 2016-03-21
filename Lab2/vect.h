#ifndef VECT_H
#define VECT_H

#include <QObject>

class Vect
{
public:
    Vect(QString);
    Vect(const Vect& );
    int size;
    double *c;
    friend QString& operator << (QString&,Vect);
    friend QString& operator >> (QString&,Vect);
    Vect operator +(Vect);
    Vect operator -(Vect);
    Vect operator *(Vect);
    ~Vect();
};

#endif // VECT_H
