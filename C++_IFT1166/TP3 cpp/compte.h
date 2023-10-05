// Handel Olivier Baptiste //
#ifndef COMPTE_H
#define COMPTE_H

//***************************************************************************************************************************************************

class CompteBanq
{
 protected:

int numero_de_compte;
double sold_de_compte;

public:
	CompteBanq();
 	CompteBanq(int,double);
 	CompteBanq(const CompteBanq&);

void setNum(int);	//fonction pour Attribuer un numéro de compte à un nouveau compte;

int getNum()const;	//fonction pour Retourner le numéro de compte;

double get_sold()const;		//fonction pour Retourner le solde du compte;

virtual void depotRetrait(double );		//fonction pour Effectuer des dépôts et des retraits;

virtual void afficheInfosCompte()=0;		//fonction pour Afficher les informations du compte.
	//c'est cette fonction qui fait de cette classe une classe virtuelle/abstraite
};
//***************************************************************************************************************************************************



//****************************************************************definition de la classe CompteCheq***********************************************************************************
class CompteCheq :public CompteBanq
{
protected:

double Solde_minumum ;
double Frais_mensuels;
double Frais_de_service;
public:
	CompteCheq();
	CompteCheq(int,double, double,double,double);
	CompteCheq(const CompteCheq &);
void setSoldeMin(double);	//Déterminer le solde minimum du compte;
double getSoldeMin();	//Retourner le solde minimum du compte;
void setFrais(double,double);	//Déterminer les frais mensuels;
void depotRetrait(double);	//Effectuer des dépôts et des retraits (redéfinir la fonction de la classe de base pour prendre en considération les découverts);
void afficheInfosCompte();	//Afficher les informations du compte-chèques.

	
};

//***************************************************************************************************************************************************


//*****************************************************************definition de la classe ComptEpargn**********************************************************************************

class ComptEpargn : public CompteBanq
{
protected:
	double taux;
public:
	ComptEpargn();
	ComptEpargn(int ,double,double);
	ComptEpargn(const ComptEpargn&);
void setInterets(double);// Déterminer le taux d’intérêt;
void afficheInfosCompte();//Afficher les informations du compte épargne
	
};
#endif // COMPTE_H
