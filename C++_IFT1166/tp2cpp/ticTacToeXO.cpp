#include "ticTacToeXO.h"
#include <iostream>
#include<windows.h>
#include <iomanip>

// Handel Olivier Baptiste //

using namespace std;
int main(int argc, char const *argv[])
{
   ticTacToeXO partie;

partie.demarrerJeu();


    return 0;
}
using namespace std;

char a11=' ',a12=' ',a13=' ',a01=' ',a02=' ',a03=' ',a21=' ',a22=' ',a23=' ';int d1=-1,dx=-1,dxx=-1,d11=-1;
ticTacToeXO::ticTacToeXO()
{  for (int i = 0; i < 3; ++i)
{
for (int j = 0; j < 3; ++j)
{
    Table[i][j]=' ';
}
}


}



void ticTacToeXO::demarrerJeu()//Definition de la fonction Pour démarrer le jeu.
{ char ox;int d=-1;

do
{
    cout<<"le jeu se joue  avec le couple (x,y)\n\n  qui commence  X /O?\n\n\n"; cin>>ox;
    if(ox=='o'){d=1;}
     if(ox=='O'){d=1;}
      if(ox=='x'){d=1;}
       if(ox=='X'){d=1;}
} while (d==-1);
    system("cls");
afficherPlanche();
xOJoue(ox);

}
void ticTacToeXO::afficherPlanche() const//Definition de la fonction Pour afficher la planche de jeu.
 {         cout<<"\n"<<"  |"<<setw(13)<<"0 |"<<setw(13)<<"1 |"<<setw(13)<<"2 |"<<endl;
          cout<<"__________________________________________\n";
          cout<<setw(49)<<setfill(' ');

          cout<<"\n0 |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<endl;
          cout<<"__________________________________________\n";
          cout<<setw(49)<<setfill(' ');
          cout<<"\n1 |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<endl;
          cout<<"__________________________________________\n";
          cout<<setw(49)<<setfill(' ');
          cout<<"\n2 |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<setw(13)<<"  |"<<endl;
          cout<<"__________________________________________\n";
          cout<<setw(49)<<endl;

}
bool ticTacToeXO::validerMouv(int x, int y) const//Definition de la fonction Pour détermine si un mouvement est valide.
{
if (x<0||x>2)
{return 0;
    }
else if (y<0||y>2)
{
  return 0;
}
else{return 1;}

}

bool ticTacToeXO::xOJoue(char symbolMouv_)//Definition de la fonction Donne la main au joueur actuel (X ou O) pour réaliser un mouvement.
    {


   static int nombre_d_appelle=0; char symbolMouv=toupper(symbolMouv_);
         char o,x;int abs,ord ,i=0;
       cout<<"\njoueur "<<symbolMouv<<"   : entrez la position de  "<<symbolMouv<<"  dans la grille"<<endl;
       cout<< "ligne"<<endl;cin>>abs;cout<<"colonne"<<endl;cin>>ord;
       if (validerMouv(abs,ord)==0)
       {

            while (abs<0||abs>2)
            {
                cout<<"position non valide la ligne est comprise dans [0;2]\n entrez la ligne a nouveau  \n"; cin>>abs;
            }
            while (ord<0||ord>2)
            {
                cout<<"position non valide la colonne est  comprise dans [0;2] \n entrez la colonne a nouveau \n"; cin>>ord;
            }

        }

            Table[abs][ord]=symbolMouv;
                  cout<<"  |"<<setw(13)<<"0 |"<<setw(13)<<"1 |"<<setw(13)<<"2 |"<<endl;
                  cout<<"__________________________________________\n ";

        if (abs==0)
        {
            if (ord==0)
            {a01=symbolMouv;

            }
            if (ord==1)
            {a02=symbolMouv;

            }
            if (ord==2)
            {a03=symbolMouv;

            }

        }
        if (abs==1)
        {
            if (ord==0)
            {a11=symbolMouv;

            }
            if (ord==1)
            {a12=symbolMouv;

            }
            if (ord==2)
            {a13=symbolMouv;

            }
        }
        if (abs==2)
        {
            if (ord==0)
            {a21=symbolMouv;
            }
            if (ord==1)
            {a22=symbolMouv;
            }
            if (ord==2)
            {a23=symbolMouv;

            }
        }

               cout<<"\n0 |"<<setw(10)<<a01<<"  |"<<setw(10)<<a02<<"  |"<<setw(10)<<a03<<"  |"<<endl;
               cout<<"__________________________________________\n ";
               cout<<"\n1 |"<<setw(10)<<a11<<"  |"<<setw(10)<<a12<<"  |"<<setw(10)<<a13<<"  |"<<endl;
               cout<<"__________________________________________\n ";
               cout<<"\n2 |"<<setw(10)<<a21<<"  |"<<setw(10)<<a22<<"  |"<<setw(10)<<a23<<"  |"<<endl;
               cout<<"__________________________________________\n ";
              etatJeu();
nombre_d_appelle++;
if (symbolMouv=='o'||symbolMouv=='O')
{
  xOJoue('X');
}
if (symbolMouv=='x'||symbolMouv=='X')
{
  xOJoue('O');
}
    }


etat ticTacToeXO::etatJeu() //Definition de la fonction Détermine l’état actuel du jeu. Cette fonction membre doit utiliser le type énumération suivant :
{

int o=0,x=0,o1=0,x1=0; etat e;


    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
          if (Table[i][j]=='O')
          {

            if (o==2)
            {
               cout<<"VICTOIRE   DE   O  \n"; recommencer(); break;
            }
            o++;
          }


      }
      o=0;
    }

    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
          if (Table[i][j]=='X')
          {

            if (x==2)
            {
              cout<<"VICTOIRE     DE X \n";  recommencer();break;
            }
            x++;
          }

      }
      x=0;
    }




    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
          if (Table[j][i]=='O')
          {

            if (o1==2)
            {
               cout<<"VICTOIRE   DE   O  \n";recommencer(); break;
            }
            o1++;
          }

      }
      o1=0;
    }

    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
          if (Table[j][i]=='X')
          {

            if (x1==2)
            {
              cout<<"VICTOIRE     DE X \n"; recommencer(); break;
            }
            x1++;
          }

      }
      x1=0;
    }
int temoin=1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if(Table[i][j]!=' ')
                { temoin++;}

        }temoin=0;
        }
    if (temoin==5)
    {
       cout<<"EGALITE    \n"; recommencer();
    }

}
void ticTacToeXO::recommencer()
{
a11=' '; a12=' '; a13=' '; a01=' '; a02=' '; a03=' '; a21=' '; a22=' '; a23=' ';

 for (int i = 0; i < 3; ++i)
{
for (int j = 0; j < 3; ++j)
{
    Table[i][j]=' ';
}
}
demarrerJeu();
}

/*
  |          0 |          1 |          2 |
__________________________________________

0 |            |            |            |
__________________________________________

1 |            |            |            |
__________________________________________

2 |            |            |            |
__________________________________________


joueur O   : entrez la position de  O  dans la grille
ligne

1
colonne
1
  |          0 |          1 |          2 |
__________________________________________

0 |            |            |            |
__________________________________________

1 |            |         O  |            |
__________________________________________

2 |            |            |            |
__________________________________________

joueur X   : entrez la position de  X  dans la grille
ligne
1
colonne
0
  |          0 |          1 |          2 |
__________________________________________

0 |            |            |            |
__________________________________________

1 |         X  |         O  |            |
__________________________________________

2 |            |            |            |
__________________________________________

joueur O   : entrez la position de  O  dans la grille
ligne
1
colonne
2
  |          0 |          1 |          2 |
__________________________________________

0 |            |            |            |
__________________________________________

1 |         X  |         O  |         O  |
__________________________________________

2 |            |            |            |
__________________________________________

joueur X   : entrez la position de  X  dans la grille
ligne
0
colonne
1
  |          0 |          1 |          2 |
__________________________________________

0 |            |         X  |            |
__________________________________________

1 |         X  |         O  |         O  |
__________________________________________

2 |            |            |            |
__________________________________________

joueur O   : entrez la position de  O  dans la grille
ligne
2
colonne
2
  |          0 |          1 |          2 |
__________________________________________

0 |            |         X  |            |
__________________________________________

1 |         X  |         O  |         O  |
__________________________________________

2 |            |            |         O  |
__________________________________________

joueur X   : entrez la position de  X  dans la grille
ligne
0
colonne
0
  |          0 |          1 |          2 |
__________________________________________

0 |         X  |         X  |            |
__________________________________________

1 |         X  |         O  |         O  |
__________________________________________

2 |            |            |         O  |
__________________________________________

joueur O   : entrez la position de  O  dans la grille
ligne
0
colonne
2
  |          0 |          1 |          2 |
__________________________________________

0 |         X  |         X  |         O  |
__________________________________________

1 |         X  |         O  |         O  |
__________________________________________

2 |            |            |         O  |
__________________________________________
 VICTOIRE   DE   O
le jeu se joue  avec le couple (x,y)

  qui commence  X /O? 
  */

