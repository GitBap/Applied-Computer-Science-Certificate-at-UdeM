#ifndef TICTACTOEXO_H
#define TICTACTOEXO_H

// Handel Olivier Baptiste //

enum etat {VICTOIRE, EGALITE,CONTINUER};
class ticTacToeXO
{   private:
        char Table[3][3];

    public:

ticTacToeXO();
void demarrerJeu(); // Declaration de la fonction  Pour demarrer le jeu.
void afficherPlanche() const; // Declaration de la fonction  Pour afficher la planche de jeu.
bool validerMouv(int x, int y) const; // Declaration de la fonction  Pour détermine si un mouvement est valide.
bool xOJoue(char symbolMouv); // Declaration de la fonction  Donne la main au joueur actuel (X ou O) pour realiser un mouvement.
etat etatJeu(); // Declaration de la fonction  Determine letat actuel du jeu. Cette fonction membre doit utiliser le type enumeration suivant :
void recommencer();

};

#endif // TICTACTOEXO_H
