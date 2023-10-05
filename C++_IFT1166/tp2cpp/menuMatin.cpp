#include <iostream>
#include <vector>
#include <fstream>
#include<windows.h>

// Handel Olivier Baptiste //

using namespace std;

typedef struct elemMenuMatin
{
    string elem;
    float prix;
    int qte;
};
vector<elemMenuMatin> menuMatin;
void chargerMenuMatin();
void afficherMenuMatin();
void afficherFacture();

int main()
{
chargerMenuMatin();
afficherMenuMatin();
afficherFacture();
    return 0;
}
void chargerMenuMatin()
{
    ifstream MenuMatinLE1166("MenuMatinLE1166.txt",ios::in);
 float  Prix;
 string Titre;

    std::string line;
    ifstream file_("MenuMatinLE1166.txt");
    if (file_.is_open())
    {
        while (getline(file_, line))
        {
          file_>>Titre>>Prix;

            elemMenuMatin ty;
            ty.elem=Titre;
            ty.prix=Prix;
            menuMatin.push_back(ty);
        }

        file_.close();
    }

}
void afficherMenuMatin()
{

    std::string line;
    ifstream file_("MenuMatinLE1166.txt");
    if (file_.is_open())
    {
        while (getline(file_, line))
        {
            std::cout << line << '\n';
        }

        file_.close();
    }
    else
        std::cout << "Fichier n'est pas ouvert" << '\n';

for (int i = 0; i < menuMatin.size()-1; ++i)
{
    cout<<"indiquez la quantite de "<<menuMatin[i].elem<<" que vous desirez\n";cin>>menuMatin[i].qte;
}
cout<<"\n\n\n";

}
void afficherFacture()
{float T;
    float somme=0;
for (int i = 0; i < menuMatin.size()-1; ++i)
{somme=somme+menuMatin[i].prix*menuMatin[i].qte;
     cout<<menuMatin[i].qte<<" \t| "<<menuMatin[i].elem<<" \t| "<<menuMatin[i].prix*menuMatin[i].qte<<endl;
}
T=somme;
somme=(somme*14.975)/100+T;
cout<<"\tTaxe  :  "<<"\t  14.975%"<<endl<<endl;
cout<<"\t\tmontant a payer :  "<<somme<<endl<<endl;
system("pause");
system("cls");
string c;
cout<<"voulez vous passer une nouvelle commande Y/N??\n\n\n";cin>>c;
if (c=="y")
{
    main();
}
if (c=="n")
{
    system("exit");
}
menuMatin.clear();
}

/* 
indiquez la quantite de Cafe que vous desirez
1
indiquez la quantite de The que vous desirez
0
indiquez la quantite de Cereales que vous desirez
0
indiquez la quantite de Oeuf que vous desirez
3
indiquez la quantite de Muffin que vous desirez
1
indiquez la quantite de Fruits que vous desirez
0
indiquez la quantite de Pain que vous desirez
0



1       | Cafe  | 2
0       | The   | 0
0       | Cereales      | 0
3       | Oeuf  | 10.5
1       | Muffin        | 2
0       | Fruits        | 0
0       | Pain  | 0
        Taxe  :           14.975%

                montant a payer :  16.6714

Press any key to continue . . .
*/
