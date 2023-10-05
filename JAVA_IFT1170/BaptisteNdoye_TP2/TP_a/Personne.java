//20200298
//Moustapha Ndoye
package com.demo;

class Personne {
	private String nom;
	private String naissance; // format "jj/mm/aaaa", ex : "25/12/1990"
	private int nbCafe; // nb de tasses de café consommé par jour

	public Personne(String nom, String naissance, int nbCafe) {
		this.nom = nom;
		this.naissance = naissance;
		this.nbCafe = nbCafe;
	}

	public Personne(String nom, String naissance) {
		this(nom, naissance, 1);
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getNaissance() {
		return naissance;
	}

	public void setNaissance(String naissance) {
		this.naissance = naissance;
	}

	public int getNbCafe() {
		return nbCafe;
	}

	public void setNbCafe(int nbCafe) {
		this.nbCafe = nbCafe;
	}

	@Override
	public String toString() {
		return "\"" + nom + "\" \"" + naissance + "\" " + nbCafe + (nbCafe > 1 ? " tasses" : " tasse");
	}

	public void reduireCafe() {
		if (nbCafe > 0) {
			nbCafe--;
		}
	}

} // fin de la classe Personne