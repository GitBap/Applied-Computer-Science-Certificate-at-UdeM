// Handel Olivier Baptiste //
#include <iostream>
#include <typeinfo>

#include "rectangle.h"

using namespace std;

/* Début code à compléter*/
rectangle:: rectangle():Longueur(0.0),largeur(0.0){}
rectangle:: rectangle( double LLong,double larg):Longueur(LLong),largeur(larg){}
rectangle:: rectangle( const rectangle&r):Longueur(r.Longueur),largeur(r.largeur){}
void rectangle:: setDimension(double Longueur, double largeur){this->Longueur=Longueur;this->largeur=largeur;}
double rectangle:: getLong() const {return Longueur;}
double rectangle:: getLarg() const{return largeur;}
double rectangle:: getSurface() const{return largeur*Longueur;}
double rectangle:: getPerimetre() const {return (largeur+Longueur)*2;}
rectangle rectangle:: operator  +(rectangle&R) {rectangle RR(Longueur+R.Longueur,largeur+R.largeur);return RR;}

 bool  operator ==(rectangle&R1,rectangle&R2)
{if (R1.getLong()==R2.getLong()&&R1.getLarg()==R2.getLarg())
{ return 1;}
 else {return 0;}
}

/* Tableaux avant le tri
Indice  Poste  Cafe  Age
    0     P     3    25
    1     P     1    19
    2     O     8    27
    3     A     0    26
    4     P     5    49
    5     A     2    24
    6     P     0    56
    7     P     3    29




--------------------------------
Process exited after 0.03731 seconds with return value 0
Press any key to continue . . .
*/

 bool  operator != (rectangle&R1,rectangle&R2)
 {if (R1.getLong()!=R2.getLong()&&R1.getLarg()!=R2.getLarg())
{ return 1;}
 else {return 0;}
}

ostream&  operator  <<  ( ostream&affiche,rectangle R1)
{
	affiche<<" Longueur "<<R1.getLong()<<"\nlargeur "<<R1.getLarg()<<endl;
	return affiche;
}

istream&  operator >> ( istream&entre,rectangle R1)
{double l,L;
	cout<<"Longueur "<<endl; entre>>L;cout<<"\nlargeur"<<endl; entre>>l;cout<<endl;
	R1.setDimension(L,l);
	return entre;
}

rectangle& rectangle:: operator ++ (){Longueur++;largeur++;
return *this;}

rectangle& rectangle:: operator ++ (int e){
rectangle t=*this;
	++Longueur;++largeur;
return t;}

 /*Fin code à compléter */


int main()
{ rectangle r(2,2);
cout<<++r;
	cout <<"SURCHARGE EFFECTUEE AVEC SUCCES";
}
