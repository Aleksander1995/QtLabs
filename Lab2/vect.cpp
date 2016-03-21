#include "vect.h"
#include <iostream>
#include <QMessageBox>

Vect::Vect(QString s)
{
    QString s_old;
    s_old=s;
    bool sw=true;

    size =0;
    int p;
    while(sw==true){
        p=s.indexOf(" ");
        if(p>=0){
            s=s.right(s.size()-(p+1));
            size++;
        }else{sw=false;}
    }

    sw=true;
    size++;
    std::cout<<"size= "<<size<<std::endl;
    c=new double[size];
    int k=0;
    s=s_old;
    while(sw==true){
        p=s.indexOf(" ");
        if(p>=0){
            c[k]=QString(s.left(p)).toDouble();
            s=s.right(s.size()-(p+1));
            k++;

        }else{sw=false;}
    }
    std::cout<<"k= "<<k<<std::endl;
    c[k]=QString(s).toDouble();
    s.clear();
}


Vect::Vect(const Vect& obj)
{
    c=new double[obj.size];
    size=obj.size;
    for(int i=0;i<size;i++){
        c[i]=obj.c[i];
    }
}


QString& operator <<(QString& s, Vect r)
{
    for(int i=0;i<r.size;i++)
    {
        s+=QString().setNum(r.c[i])+" ";
    }
    //s+=QString().setNum(r.c[r.size]);
    s=s.trimmed();
    return s;
}


Vect Vect:: operator+(Vect r)
{

    std::cout<<size<<std::endl;
    std::cout<<r.size<<std::endl;

    for(int i=0;i<r.size;i++)
    {
      std::cout<<c[i]<<" "<<r.c[i]<<std::endl;
    }

   if(size==r.size){
        for(int i=0;i<r.size;i++){r.c[i]=r.c[i]+c[i];}
    }
    if(size>r.size){
        for(int i=0;i<r.size;i++){r.c[i]=r.c[i]+c[i];}
        for(int i=r.size+1;i<size;i++){r.c[i]=c[i];}
        r.size=size;
    }
    if(size<r.size){
        for(int i=0;i<size;i++){r.c[i]=r.c[i]+c[i];}
    }

    return r;
}


Vect Vect:: operator-(Vect r)
{
    std::cout<<size<<std::endl;
    std::cout<<r.size<<std::endl;

    for(int i=0;i<r.size;i++)
    {
      std::cout<<c[i]<<" "<<r.c[i]<<std::endl;
    }

   if(size==r.size){
        for(int i=0;i<r.size;i++){r.c[i]=c[i]-r.c[i];}
    }
    if(size>r.size){
        for(int i=0;i<=r.size;i++){r.c[i]=c[i]-r.c[i];}
        for(int i=r.size+1;i<=size;i++){r.c[i]=c[i];}
        r.size=size;
    }
    if(size<r.size){
        for(int i=0;i<=size;i++){r.c[i]=c[i]-r.c[i];}
        for(int i=size+1;i<=r.size;i++){r.c[i]=-r.c[i];std::cout<<"yeeea"<<std::endl;}
    }

    return r;
}


Vect Vect:: operator*(Vect r)
{
    std::cout<<size<<std::endl;
    std::cout<<r.size<<std::endl;
    if(size==r.size){
         for(int i=0;i<r.size;i++){r.c[i]=c[i]*r.c[i];}
     }else{QMessageBox::information(0,"Упс:(","Размеры векторов не совпадают!");}

    return r;
}


QString& operator >>(QString& s,Vect r)
{

    for(int i=0;i<r.size;i++)
    {
        if(r.c[i]<0){r.c[i]=r.c[i]*(-1);}
        s+=QString().setNum(r.c[i])+" ";
    }
    if(r.c[r.size]<0){r.c[r.size]=r.c[r.size]*(-1);}
    s+=QString().setNum(r.c[r.size]);

    return s;
}


Vect::~Vect()
{
    delete[] c;
}
