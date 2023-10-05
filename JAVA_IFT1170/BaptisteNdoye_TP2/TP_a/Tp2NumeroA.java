//20200298
//Moustapha Ndoye
package com.demo;

public class Tp2NumeroA {

	public static void main(String[] args) {
		Personne pers[] = new Personne[5];

		pers[0] = new Personne("Jo", "16/11/1992", 2);
		pers[1] = new Personne("Paul", "02/05/1990");
		pers[2] = new Personne("Lucie", "23/05/1990", 5);
		pers[3] = new Personne("Bob", "19/02/1985", 0);
		pers[4] = new Personne("Carole", "30/06/1991", 2);

		afficher(pers);
		afficheQuiConsommePlus(pers);
		reduireCafes(pers);
		afficher(pers);
		trierParAnneeNaissance(pers);

		System.out.println("\nAprés tri");
		afficher(pers);
		System.out.println("\nLe nombre de personnes nés en Mai : " + nesEnMai(pers));
	}

	public static void afficher(Personne personnes[]) {
		System.out.println("\n\tIndice\tTableau pers");
		System.out.println("-----------------------------------------------");
		for (int i = 0; i < personnes.length; i++) {
			System.out.println("\t" + i + "\t" + personnes[i].toString());
		}
	}

	public static void afficheQuiConsommePlus(Personne personnes[]) {
		Personne accro = personnes[0];
		for (Personne personne : personnes) {
			if (accro.getNbCafe() < personne.getNbCafe()) {
				accro = personne;
			}
		}
		System.out.println("\nVoici la personne qui consomme plus de café :");
		System.out.println(accro.toString());
	}

	public static void reduireCafes(Personne personnes[]) {
		for (Personne personne : personnes) {
			personne.reduireCafe();
		}
	}

	public static void trierParAnneeNaissance(Personne personnes[]) {
		Personne tmp;
		for (int i = 0; i < personnes.length - 1; i++) {
			for (int j = i + 1; j < personnes.length; j++) {
				int annee1 = Integer.valueOf(personnes[i].getNaissance().substring(6));
				int annee2 = Integer.valueOf(personnes[j].getNaissance().substring(6));
				if (annee1 > annee2) {
					tmp = personnes[j];
					personnes[j] = personnes[i];
					personnes[i] = tmp;
				}
			}
		}
	}

	public static int nesEnMai(Personne personnes[]) {
		int nbPersonnes = 0;
		for (Personne personne : personnes) {
			if (personne.getNaissance().substring(3, 5).equals("05")) {
				nbPersonnes++;
			}
		}
		return nbPersonnes;
	}
}
/*Indice	Tableau pers
-----------------------------------------------
	0	"Jo" "16/11/1992" 2 tasses
	1	"Paul" "02/05/1990" 1 tasse
	2	"Lucie" "23/05/1990" 5 tasses
	3	"Bob" "19/02/1985" 0 tasse
	4	"Carole" "30/06/1991" 2 tasses

Voici la personne qui consomme plus de café :
"Lucie" "23/05/1990" 5 tasses

	Indice	Tableau pers
-----------------------------------------------
	0	"Jo" "16/11/1992" 1 tasse
	1	"Paul" "02/05/1990" 0 tasse
	2	"Lucie" "23/05/1990" 4 tasses
	3	"Bob" "19/02/1985" 0 tasse
	4	"Carole" "30/06/1991" 1 tasse

Aprés tri

	Indice	Tableau pers
-----------------------------------------------
	0	"Bob" "19/02/1985" 0 tasse
	1	"Lucie" "23/05/1990" 4 tasses
	2	"Paul" "02/05/1990" 0 tasse
	3	"Carole" "30/06/1991" 1 tasse
	4	"Jo" "16/11/1992" 1 tasse

Le nombre de personnes nés en Mai : 2
*/
