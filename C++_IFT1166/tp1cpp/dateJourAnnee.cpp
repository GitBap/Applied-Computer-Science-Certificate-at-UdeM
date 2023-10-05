// Olivier Baptiste et Franck-Alexandre Ilboudo //

#include <iostream>
#include <iostream>
#include <cmath>

using namespace std;


// Verifier si annee bissextile //
bool anneeBissextile(int annee){
    //les annee divisible par 4 mais pas divisibles par 100
	if (annee % 4 == 0 && annee % 100 != 0){ 
        return true;
    }
    //les annees divisibles par 100 et par 400
	else if (annee % 100 == 0 && annee % 400 == 0){
        return true;
    }  
	else return false;
}

// Nb de jours dans un mois //
int joursDuMois(int mois, int annee){
    switch(mois){ 
        case 1:   return 31;
        case 2:  if(anneeBissextile(annee)==true){
                    return 29;
                 }    
                else{
                    return 28;
                }       
        case 3:return 31;   
         case 4: return 30;        
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8:return 31;
        case 9: return 30;
        case 10:return 31;
        case 11: return 30;
        case 12: return 31; 
        default: 
        cout<<"entrez un nombre de mois valide";   
        return 0;
        break;
    }
}
//retourne le nombre de jours ecoules dans cette annee jusqua cette date
int jourAnnee(int jour, int mois, int annee) {

    int i=1,som=0,total;

while(i < mois){
    som = som + joursDuMois(i, annee);
    i = i+1;
}

 total = som + jour;

return total;

}

int main()
{
	int jour, mois, annee;
	char x= '1';
    while( x != '0'){
    cout<<"Entrez une date selon le format jour/mois/annee. \n" ;
    cout<<"jour: \n";
    
    cin>> jour; 
    cout<<"mois: \n";
    cin>> mois;
    
    cout<<"annee: \n";
    cin>> annee;
    

    if(mois>0 && mois<=12){
        if(jour>0 && jour<=31){
            if(annee>0){
                int rs = jourAnnee(jour,mois,annee);
                cout<< " le nombre de jours ecoules est: " << rs  << "\n";
            }else cout<< " ERREUR !!!!! Lannee doit etre superieur a  0 : annee > 0 \n";
        } else cout<< " ERREUR !!!!! Le jour doit etre compris entre 1 et 31 \n";
    }else cout<< "Le mois doit etre compris entre 1 et 12 \n";
        
  cout<< "cliquez sur 0 pour quitter ou sur tout autres touches pour continuer :";
  cin >> x;
}
    
    // cin << jour/mois/annee; 

    return 0 ;
}

/* Entrez une date selon le format jour/mois/annee.
jour:
01
mois:
12
annee:
1999
 le nombre de jours ecoules est: 335
cliquez sur 0 pour quitter ou sur tout autres touches pour continuer :
*/ 
