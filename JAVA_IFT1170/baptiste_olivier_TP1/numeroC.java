/* Olivier Baptiste */
public class numeroC {

	public static void main(String[] args) {

		int[] age = { 30, 11, 14, 32, 17, 19, 35, 8, 15 }; 
		int[]	cafe = { 3, 0, 1, 1, 4, 2, 1, 0, 1, };
		
		int nbPrsn; 

		/* Affichage */
		nbPrsn = Methode1(age, 12, 17); 
		System.out.println("Il y a " + nbPrsn + " adolescents" );
		
		nbPrsn = Methode1(age, 0, 11);
		System.out.println("Il y a " + nbPrsn + " enfants" );
		
		nbPrsn = Methode1(cafe, 2, 4);
		System.out.println("Il y a " + nbPrsn + " consommant entre 2 et 4 tasses de café par jour");
		
		int indiceMax; 

		indiceMax = Methode2(age);
		System.out.println("La personne la plus âgée a " + age[indiceMax]  + " ans et elle consomme " + cafe[indiceMax] + " tasse(s) de café");
		
	    indiceMax = Methode2(cafe);
		System.out.println("La personne buvant le plus de café : " + cafe[indiceMax] + " tasse(s) et a " + age[indiceMax] + " ans");
	}

	/* Compteurs du nbr de personnes */
	public static int Methode1(int[] tableau, int valMin, int valMax) {

		int compteurs = 0;

		for (int i = 0; i < tableau.length; i++) {

			if (tableau[i] >= valMin && tableau[i] <= valMax) {
				compteurs++;

			}

		}
		return compteurs; 
	}
	
	/* Compteurs du max */
	public static int Methode2(int[] tableau) {
		
		int max = tableau[0];
		int indiceMax = 0;
		for (int i = 1; i < tableau.length; i++) {
			
			if(tableau[i] > max) {
				max = tableau[i];
				indiceMax = i;
			}
			
		}
		
		return indiceMax;
	}
}

/*
Il y a 3 adolescents
Il y a 2 enfants
Il y a 3 consommant entre 2 et 4 tasses de café par jour
La personne la plus âgée a 35 ans et elle consomme 1 tasse(s) de café
La personne buvant le plus de café : 4 tasse(s) et a 17 ans
*/