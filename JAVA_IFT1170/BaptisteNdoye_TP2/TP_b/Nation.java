//20200298
//Moustapha Ndoye
package com.demo;

import java.util.Arrays;

public class Nation {
	private char continent;
	private String nom;
	private String capitale;
	private long superficie;
	private long population;

	public Nation(char continent, String nom, String capitale, long superficie, long population) {
		this.continent = continent;
		this.nom = nom;
		this.capitale = capitale;
		this.superficie = superficie;
		this.population = population;
	}

	@Override
	public String toString() {
		String superficieString = Long.toString(superficie);
		String populationString = Long.toString(population);
		char[] infos = new char[80];

		Arrays.fill(infos, ' ');
		infos[0] = continent;
		nom.getChars(0, nom.length(), infos, 1);
		capitale.getChars(0, capitale.length(), infos, 36);
		superficieString.getChars(0, superficieString.length(), infos, 55);
		populationString.getChars(0, populationString.length(), infos, 64);

		return new String(infos);
	}

	public char getContinent() {
		return continent;
	}

	public void setContinent(char continent) {
		this.continent = continent;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getCapitale() {
		return capitale;
	}

	public void setCapitale(String capitale) {
		this.capitale = capitale;
	}

	public long getSuperficie() {
		return superficie;
	}

	public void setSuperficie(long superficie) {
		this.superficie = superficie;
	}

	public long getPopulation() {
		return population;
	}

	public void setPopulation(long population) {
		this.population = population;
	}

}
