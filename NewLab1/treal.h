#ifndef TREAL_H
#define TREAL_H

#include <QObject>

class TReal
{

public:
    qint64 m;
    int p;
    TReal(double);
    friend QString& operator <<(QString&, TReal);
    TReal conv(TReal);
    TReal operator +(TReal);
    friend TReal& operator >>(TReal&, TReal);
    TReal operator >(TReal);
    TReal operator >=(TReal);
    TReal operator <(TReal);
    TReal operator <=(TReal);
    TReal operator ==(TReal);
    TReal operator !=(TReal);
    TReal operator -(TReal);

};




#endif // TREAL_H
