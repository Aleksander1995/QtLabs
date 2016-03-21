#include "treal.h"
#include<iostream>
#include "interface.h"
TReal::TReal(double A)
{
    p=0;
    if(A == (long long)A){
                    while((long long)A % 10 == 0 && A>0){
                        A /=10;
                        p=p+1;
                    }
                    m = A;
                }
                else{
                    while(A!= (long long)A){

                        A *= 10;
                        p--;

                    }
                    m = A;
                }


}


 QString& operator <<(QString& s, TReal r)
{

    s+=QString().setNum(r.m)+"*10^"+QString().setNum(r.p);

    return s;
}


TReal TReal:: operator +(TReal r)
{
    if(p < r.p){
                while(p != r.p){
                    r.p--;
                    r.m *= 10;
                }
            }
            else if(p > r.p){
                while(p != r.p){
                    p--;
                    m *= 10;
                }
            }


    r.m=m+r.m;
    r.p=p;
    m=r.m;

return r;
}

TReal& operator >>(TReal& d, TReal r)
{
    d=r;
    return d;
}


TReal TReal::operator >(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m>r.m);
    return r;
}
TReal TReal::operator >=(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m>=r.m);
    return r;
}
TReal TReal::operator <(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m<r.m);
    return r;
}
TReal TReal::operator <=(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m<=r.m);
    return r;
}
TReal TReal::operator ==(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m==r.m);
    return r;
}
TReal TReal::operator !=(TReal r)
{
    std::cout<<"yeappppp!!!";
    r.m=(m!=r.m);
    return r;
}
TReal TReal::operator -(TReal r)
{
    r.m=m;
    r.p=p-1;
    p=r.p;

    return r;
}
