#include "vect.h"
#include <iostream>
#include <QMessageBox>

Vect::Vect(QString s)
{
    row=0;
    col=0;
    colMax=0;
    int p;
    int t;
    QString s2;
    QString s_old=s;

    t=s.indexOf(" ");
    p=s.indexOf(";");

    while((p>=0)){
        s2=s.left(p);
        while((t>=0)&&(t<p)){
            s2=s2.right(s2.size()-(t+1));
            t=s2.indexOf(" ");
            col++;
        }
        if(colMax<(col)){colMax=col;}
        col=0;
        row++;
        s=s.right(s.size()-(p+1));
        t=s.indexOf(" ");
        p=s.indexOf(";");
    }

    t=s.indexOf(" ");
    while(t>=0){
        s=s.right(s.size()-(t+1));
        t=s.indexOf(" ");
        col++;
    }
    if(colMax<(col)){colMax=col;}
    col=colMax;
////////////////////////////////////////////////////////////////
    row++;
    col++;
    s=s_old;
    c = new double*[row];
    for(int k= 0; k < row; k++)
    {c[k] = new double[col];}

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){c[i][j]=0;}
    }

    row=0;
    col=0;

    t=s.indexOf(" ");
    p=s.indexOf(";");

    while((p>=0)){
            s2=s.left(p);
            while((t>=0)&&(t<p)){
                c[row][col]=QString(s2.left(t)).toDouble();
                s2=s2.right(s2.size()-(t+1));
                t=s2.indexOf(" ");
                col++;
            }
            c[row][col]=QString(s2).toDouble();
            col=0;
            row++;
            s=s.right(s.size()-(p+1));
            t=s.indexOf(" ");
            p=s.indexOf(";");
        }

        t=s.indexOf(" ");
        while(t>=0){

            c[row][col]=QString(s.left(t)).toDouble();
            s=s.right(s.size()-(t+1));
            t=s.indexOf(" ");
            col++;
        }
        c[row][col]=QString(s).toDouble();
        row++;
        col=colMax;
        col++;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            std::cout<<c[i][j]<<" ";
        }
        std::cout<<"\n";
    }




    std::cout<<"Row= "<<row<<std::endl;
    std::cout<<"Col= "<<col<<std::endl;

}


Vect::Vect(const Vect& obj)
{
    c=new double *[obj.row];
    for(int i=0;i<obj.row;i++){
        c[i]=new double[obj.col];
    }
    col=obj.col;
    row=obj.row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            c[i][j]=obj.c[i][j];
        }
    }
}


QString& operator <<(QString& s, Vect r)
{
    for(int i=0;i<r.row;i++)
    {
        for(int j=0;j<r.col;j++){
            s+=QString().setNum(r.c[i][j])+" ";
        }
        s=s.trimmed();
        s+=";";
    }
    s=s.remove(s.size()-1,1);

    return s;
}


Vect Vect:: operator+(Vect r)
{
      if((col==r.col)&&(row==r.row)){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                r.c[i][j]=c[i][j]+r.c[i][j];
            }
        }
       }else{QMessageBox::information(NULL,"Oops:(","Размеры не совпадают!");}

    return r;
}


Vect Vect:: operator-(Vect r)
{
    if((col==r.col)&&(row==r.row)){
      for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              r.c[i][j]=c[i][j]-r.c[i][j];
          }
      }
     }else{QMessageBox::information(NULL,"Oops:(","Размеры не совпадают!");}

    return r;
}


Vect Vect:: operator*(Vect r)
{
    double **a=new double*[row];
    for(int i=0;i<row;i++){a[i]=new double[row];}

    if((col==r.row)){
      for(int i=0;i<row;i++){
          for(int j=0;j<r.col;j++){
              a[i][j]=0;
              for(int k=0;k<col;k++){
                  a[i][j]+=c[i][k]*r.c[k][j];
              }
          }
      }
      r.c=a;
      r.row=row;
    }else{QMessageBox::information(NULL,"Oops:(","Размеры не совпадают!");}
    return r;
}


QString& operator >>(QString& s,Vect r)
{
    for(int i=0;i<r.col;i++)
    {
        for(int j=0;j<r.row;j++){
            s+=QString().setNum(r.c[j][i])+" ";
        }
        s=s.trimmed();
        s+=";";
    }
    s=s.remove(s.size()-1,1);

    return s;
}


Vect::~Vect()
{
    delete[] c;
}
