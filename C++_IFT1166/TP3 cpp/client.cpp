// Handel Olivier Baptiste //
#include <iostream>
#include <string>
#include <list>


#include "compte.h"
#include "client.h"

using namespace std;

/* Début code à compléter*/
    
    
client::client()
{ Numclient=0;
 nom=" ";prenom=" ";

CompBanq banq=new CompBanq();List_des_CompBanq->push_back(banq);
 }

 client::client(int Numclient,string nom,string prenom,list<CompteCheq*>List_des_CompCheq)
        {
        	this->Numclient=Numclient;
        	this->nom=nom;
        	this->prenom=prenom;
        	this->List_des_CompBanq->push_back(List_des_CompCheq);
        }
        client::client(int Numclient,string nom,string prenom,list<CompteBanq*>List_des_CompBanq)
        {

        	    
        	this->Numclient=Numclient;
        	this->nom=nom;
        	this->prenom=prenom;
        	this->List_des_CompBanq->push_back(List_des_CompBanq);
        
        }
        client::client(int Numclient,string nom,string prenom,list<ComptEpargn*>List_des_CompEpargne)
        {
        	        
        	this->Numclient=Numclient;
        	this->nom=nom;
        	this->prenom=prenom;
        	this->List_des_CompBanq->push_back(List_des_CompEpargne);
        
        }
         client::client(const client&cl){nom=cl.nom;prenom=cl.prenom;Numclient=cl.Numclient;
        List_des_CompBanq=List_des_CompBanq;  }

void client::afficheInfosClient()
{
	cout<<"Numero du client: "<<Numclient<<endl;
	cout<<"Nom: Nom"<<nom<<endl;
	cout<<"Prenom: Prenom"<<prenom<<endl;  
	list<CompteBanq>::iterator it_compt
for (it_compt = List_des_CompBanq->begin(); it_comptes != List_des_CompBanq->end(); it_comptes++)
		(it_comptes)->afficheInfosCompte();


}

/*Fin code à compléter */


int main()
{

	list<comptBanq*> a_accounts;
	comptCheque aCheque(1, 100, 120, 10, 20);
	a_accounts.push_back(&aCheque);
	client A(1, "NomA", "PrenomA", a_accounts);

	list<comptBanq*> b_accounts;
	comptEpargne bEpargne(2, 150, 4.45);
	b_accounts.push_back(&bEpargne);
	client B(2, "NomB", "PrenomB", b_accounts);

	list<comptBanq*> c_accounts;
	comptCheque cCheque(31, 400, 200, 10, 20);
	comptEpargne cEpargne(32, 100, 5);
	c_accounts.push_back(&cCheque);
	c_accounts.push_back(&cEpargne);
	client C(3, "NomC", "PrenomC", c_accounts);

	list<comptBanq*> d_accounts;
	comptEpargne dEpargne1(41, 2000, 3.5);
	comptEpargne dEpargne2(42, 300, 2.5);
	d_accounts.push_back(&dEpargne1);
	d_accounts.push_back(&dEpargne2);
	client D(4, "NomD", "PrenomD", d_accounts);

	list<comptBanq*> e_accounts;
	comptCheque eCheque1(51, 1000, 100, 5, 5);
	comptCheque eCheque2(52, 900, 150, 12, 18);
	e_accounts.push_back(&eCheque1);
	e_accounts.push_back(&eCheque2);
	client E(5, "NomE", "PrenomE", e_accounts);

	list<client> clients = { A, B, C, D, E };

	list<client>::iterator it_client;

	cout << "Comptes clients avant operations" << endl;

	cout << "\n";

	for (it_client = clients.begin(); it_client != clients.end(); it_client++)
		(*it_client).afficheInfosClient();

	//set num
	list<comptBanq*>::iterator it_comptes;
	it_comptes = find(A.listComptes.begin(), A.listComptes.end(), &aCheque);
	if (it_comptes != A.listComptes.end()) (*it_comptes)->setNum(19999);

	//depot et retrait
	it_comptes = find(B.listComptes.begin(), B.listComptes.end(), &bEpargne);
	if (it_comptes != B.listComptes.end()) {
		(*it_comptes)->depotRetrait(100);
		(*it_comptes)->depotRetrait(-300);
	}

	it_comptes = find(C.listComptes.begin(), C.listComptes.end(), &cCheque);
	if (it_comptes != C.listComptes.end()) {
		(*it_comptes)->depotRetrait(-200);
		(*it_comptes)->depotRetrait(350);
	}

	//set interets
	it_comptes = find(D.listComptes.begin(), D.listComptes.end(), &dEpargne2);
	if (it_comptes != D.listComptes.end()) {
		dynamic_cast<comptEpargne*> (*it_comptes)->setInterets(5.5);
	}

	//set marge, frais
	it_comptes = find(E.listComptes.begin(), E.listComptes.end(), &eCheque1);

	if (it_comptes != E.listComptes.end()) {
		dynamic_cast<comptCheque*> (*it_comptes)->setSoldeMin(200);
		dynamic_cast<comptCheque*> (*it_comptes)->setFrais(4, 10);
	}

	cout << "\nComptes clients apres operations\n" << endl;

	for (it_client = clients.begin(); it_client != clients.end(); it_client++)
		(*it_client).afficheInfosClient();

	cout << "\n";

	return 0;
}

/*
Comptes clients avant operations

Numero du client: 1
Nom: NomA
Prenom: PrenomA

Informations compte cheque #1
Solde: 100.00$
Solde minumum requis: 120.00 $
Frais mensuels: 10.00$
Frais de service: 20.00$

Numero du client: 2
Nom: NomB
Prenom: PrenomB

Informations compte epargne #2
Solde: 150.00$
Taux interets: 4.45%


Numero du client: 3
Nom: NomC
Prenom: PrenomC

Informations compte cheque #31
Solde: 400.00$
Solde minumum requis: 200.00 $
Frais mensuels: 10.00$
Frais de service: 20.00$

Informations compte epargne #32
Solde: 100.00$
Taux interets: 5.00%


Numero du client: 4
Nom: NomD
Prenom: PrenomD

Informations compte epargne #41
Solde: 2000.00$
Taux interets: 3.50%


Informations compte epargne #42
Solde: 300.00$
Taux interets: 2.50%


Numero du client: 5
Nom: NomE
Prenom: PrenomE

Informations compte cheque #51
Solde: 1000.00$
Solde minumum requis: 100.00 $
Frais mensuels: 5.00$
Frais de service: 5.00$

Informations compte cheque #52
Solde: 900.00$
Solde minumum requis: 150.00 $
Frais mensuels: 12.00$
Frais de service: 18.00$

Compte numero #1 : mise a jour du numero de compte a 19999

Compte numero #2 : debut depot / retrait d'un montant de 100.00$

Compte numero #2 : depot / retrait complete

Compte numero #2 : debut depot / retrait d'un montant de -300.00$

Compte numero #2 : Retrait impossible, montant inferieur au solde disponible.

Compte numero #31 : debut depot / retrait d'un montant de -200.00$

Compte numero #31 : depot / retrait complete

Compte numero #31 : debut depot / retrait d'un montant de 350.00$

Compte numero #31 : depot / retrait complete

Compte numero #42 : mise a jour du taux d'interet a: 5.50%

Compte numero #51 : mise a jour du solde minimum a 200.00$

Compte numero #51 : mise a jour des frais mensuels a: 4.00$ et des frais de service a 10.00$


Comptes clients apres operations

Numero du client: 1
Nom: NomA
Prenom: PrenomA

Informations compte cheque #19999
Solde: 100.00$
Solde minumum requis: 120.00 $
Frais mensuels: 10.00$
Frais de service: 20.00$

Numero du client: 2
Nom: NomB
Prenom: PrenomB

Informations compte epargne #2
Solde: 250.00$
Taux interets: 4.45%


Numero du client: 3
Nom: NomC
Prenom: PrenomC

Informations compte cheque #31
Solde: 550.00$
Solde minumum requis: 200.00 $
Frais mensuels: 10.00$
Frais de service: 20.00$

Informations compte epargne #32
Solde: 100.00$
Taux interets: 5.00%


Numero du client: 4
Nom: NomD
Prenom: PrenomD

Informations compte epargne #41
Solde: 2000.00$
Taux interets: 3.50%


Informations compte epargne #42
Solde: 300.00$
Taux interets: 5.50%


Numero du client: 5
Nom: NomE
Prenom: PrenomE

Informations compte cheque #51
Solde: 1000.00$
Solde minumum requis: 200.00 $
Frais mensuels: 4.00$
Frais de service: 10.00$

Informations compte cheque #52
Solde: 900.00$
Solde minumum requis: 150.00 $
Frais mensuels: 12.00$
Frais de service: 18.00$
*/
