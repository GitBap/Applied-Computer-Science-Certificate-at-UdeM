// Olivier Baptiste et Franck-Alexandre Ilboudo //

#include <iostream>
#include <cmath>

using namespace std;

float TauxInteretMois(float taux)
{
    return taux / 12 / 100;
}
int main()
{

    std::cout << "Bienvenue:\n\n";
    int mois = 0;
    bool valid = true;
    float tauxInteretAns, montantPret, payementMensuel,
        sumInteretTotal = 0, MontantDernierPayement, payementMensuelMin,
        tauxIntMois, portionInteret, payementMensuelCalcule;
    cout << "Veuillez saisir le montant du pret \n" ;
    // recupere la valeur saisi
    cin >> montantPret;

    if (!cin.fail())
        cout << "Veuillez saisir le taux d'interet par an \n" ;
    // recupere la valeur saisi
    cin >> tauxInteretAns;

    if (!cin.fail())
    {
        // calcule du taux d'interet par mois
        tauxIntMois = TauxInteretMois(tauxInteretAns);
        // calcule payement mensuel minimum
        payementMensuelMin = montantPret * tauxIntMois;
        cout << "Le payement mensuel minimum est de: " << payementMensuelMin << "$.\n";
        cout << "Veuillez saisir le payement mensuel \n"; 
    }
    // recupere la valeur saisi
    cin >> payementMensuel;

    if (!cin || cin.fail())
    {
        cout << "Veuillez saisir un nombre \n";
    }

    // calcule du nombre de mois pour rembourser l'interet
    do
    {
        // calcul portion interet par mois
        portionInteret = montantPret * tauxIntMois;
        // calcul interet total
        sumInteretTotal += portionInteret;

        // payement mensuel
        payementMensuelCalcule = payementMensuel - portionInteret;

        montantPret = montantPret - payementMensuelCalcule;

        // verifie si le payement mensuel est inférieur à l'intérêt du premier mois,
        if (payementMensuel < portionInteret && mois == 0)
        {
            valid = false;

            cout << "Le payement mensuel est trop faible, et avec ce payement mensuel saisi, \nle montant du pret ne pourra jamais etre remboursable. \n";
        }
        else
            // incremente le mois tant que ca entre dans la boucle
            mois++;

    } while (montantPret > 0 && valid);

    if (!cin.fail())
        if (montantPret <= 0)
        {
            cout << "Le nombre de mois necessaires pour rembourser \n totalement le pret est de : "
                 << mois << " mois.\n";
            cout << "Le montant exact du dernier payement est de : "
                 << payementMensuelCalcule << "$.\n";
            cout << "L'interet total paye apres avoir rembourse le pret est de : "
                 << sumInteretTotal << "$.\n";
        }
}

/*Bienvenue:

Veuillez saisir le montant du pret
200
Veuillez saisir le taux d'interet par an
5.9
Le payement mensuel minimum est de: 0.983333$.
Veuillez saisir le payement mensuel
30
Le nombre de mois necessaires pour rembourser
 totalement le pret est de : 7 mois.
Le montant exact du dernier payement est de : 29.8832$.
L'interet total paye apres avoir rembourse le pret est de : 3.86269$.

--------------------------------
Process exited after 20.34 seconds with return value 0
Press any key to continue . . .
*/

