// Handel Olivier Baptiste //
#include "compte.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

   CompteBanq:: CompteBanq():numero_de_compte(0),sold_de_compte(0.0){}
   CompteBanq:: CompteBanq(int nu,double sold):numero_de_compte(nu),sold_de_compte(sold){}
   CompteBanq:: CompteBanq(const CompteBanq&e):numero_de_compte(e.numero_de_compte),sold_de_compte(e.sold_de_compte){}

void CompteBanq::setNum(int nu){numero_de_compte=nu;} //fonction pour Attribuer un numéro de compte à un nouveau compte;

int CompteBanq::getNum()const{return numero_de_compte;}  //fonction pour Retourner le numéro de compte;

void CompteBanq::depotRetrait(double sold){
if (sold>0){sold_de_compte=sold_de_compte+sold;}else{sold_de_compte=sold_de_compte-sold;}}
double CompteBanq::get_sold()const{return sold_de_compte;}    //fonction pour Retourner le solde du compte;

//**************************************fin definitions de la classe CompteBanq****************************************************



//****************************************************************definition des fonction de  la classe CompteCheq***********************************************************************************

    CompteCheq::CompteCheq():Solde_minumum(0.0),Frais_mensuels(0.0),Frais_de_service(0.0){numero_de_compte=0;sold_de_compte=0.0;}
    CompteCheq::CompteCheq(int nu,double sold, double sold_min ,double frais_men,double Frais_deservice):Solde_minumum(Solde_minumum),Frais_mensuels(Frais_mensuels),Frais_de_service(Frais_deservice){numero_de_compte=nu;sold_de_compte=sold;}
    CompteCheq::CompteCheq(const CompteCheq & e):Solde_minumum(e.Solde_minumum),Frais_mensuels(e.Frais_mensuels),Frais_de_service(e.Frais_de_service){numero_de_compte=e.numero_de_compte;sold_de_compte=e.sold_de_compte;}
void CompteCheq::setSoldeMin(double sold_min){Solde_minumum=sold_min; }  //Déterminer le solde minimum du compte;
double CompteCheq::getSoldeMin(){return Solde_minumum;}   //Retourner le solde minimum du compte;
void CompteCheq::setFrais(double frais_men,double Frais_deservice){Frais_mensuels=frais_men; Frais_de_service=Frais_deservice;}   //Déterminer les frais mensuels;
void CompteCheq::depotRetrait(double sold){
if (sold>0){sold_de_compte=sold_de_compte+sold;}else{sold_de_compte=sold_de_compte-sold;}}    //Effectuer des dépôts et des retraits (redéfinir la fonction de la classe de base pour prendre en considération les découverts);
void CompteCheq::afficheInfosCompte(){   //Afficher les informations du compte-chèques.
cout<<"Informations compte cheque #"<<numero_de_compte<<endl;
cout<<"Solde:               "<<sold_de_compte<<endl;
cout<<"Solde minumum requis:"<<Solde_minumum<<endl;
cout<<"Frais mensuels:      "<<Frais_mensuels<<endl;
cout<<"Frais de service:    "<<Frais_de_service<<endl;
}



//***************************************************************************************************************************************************


//************************************************************************************************************************************
    ComptEpargn::ComptEpargn():taux(0.0){numero_de_compte=0;sold_de_compte=0.0;}
    ComptEpargn::ComptEpargn(int nu,double sold,double t):taux(t ){numero_de_compte=nu;sold_de_compte=sold;}
    ComptEpargn::ComptEpargn(const ComptEpargn&e):taux(e.taux){numero_de_compte=e.numero_de_compte;sold_de_compte= e.sold_de_compte;}
void ComptEpargn::setInterets(double t){this->taux=t;}// Déterminer le taux d’intérêt;
void ComptEpargn::afficheInfosCompte(){//Afficher les informations du compte épargne

cout<<"Informations compte epargne #"<<numero_de_compte<<endl;
cout<<"Solde:                  "<<sold_de_compte<<endl;
cout<<"Taux interets:           "<<taux<<"%"<<endl;
    }
