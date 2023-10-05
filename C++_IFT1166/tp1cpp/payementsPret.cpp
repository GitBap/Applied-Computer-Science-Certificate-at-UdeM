// Olivier Baptiste  et Franck-Alexandre Ilboudo //

#include <iostream>
#include <cmath>

using namespace std;

float TauxInteretMois(float taux)
{
    return taux / 12 / 100;
}
int main()
{

    std::cout << "Bienvenue\n\n";
    int mois = 0;
    bool valid = true;
    float tauxInteretAns, montantPret, payementMensuel, tauxIntMois, portionInteret, payementMensuelCalcule;
    cout << "Veuillez saisir le montant du pret \n" ;
    // recupere la valeur saisi
    cin >> montantPret;

    if (!cin.fail())
        cout << "Veuillez saisir le taux d'interet par an \n" ;
    // recupere la valeur saisi
    cin >> tauxInteretAns;

    if (!cin.fail())
        cout << "Veuillez saisir le payement mensuel \n" ;
    // recupere la valeur saisi
    cin >> payementMensuel;

    if (!cin || cin.fail())
    {
        cout << "Veuillez saisir un nombre \n";
    }

    // calcule du taux d'interet par mois
    tauxIntMois = TauxInteretMois(tauxInteretAns);
    // calcule du nombre de mois pour rembourser l'interet
    do
    {
        portionInteret = montantPret * tauxIntMois;
        payementMensuelCalcule = payementMensuel - portionInteret;
        montantPret = montantPret - payementMensuelCalcule;

        // verifie si le payement mensuel est inférieur à l'intérêt du premier mois,
        if (payementMensuel < portionInteret && mois == 0)
        {
            valid = false;

            cout << "Le payement mensuel est trop faible, et avec ce payement mensuel saisi, \n le montant du pret ne pourra jamais etre rembourse \n" ;
        }
        else
            // incremente le mois tant que ca entre dans la boucle
            mois++;
    } while (montantPret > 0 && valid);

    if (!cin.fail())
        if (montantPret <= 0)
            cout << "Le nombre de mois necessaires pour rembourser totalement le pret est de : "
                 << mois << " mois \n" ;
}

/* Bienvenue

Veuillez saisir le montant du pret
500
Veuillez saisir le taux d'interet par an
3.5
Veuillez saisir le payement mensuel
50
Le nombre de mois necessaires pour rembourser totalement le pret est de : 11 mois

--------------------------------
Process exited after 18.02 seconds with return value 0
Press any key to continue . . . 
*/ 
