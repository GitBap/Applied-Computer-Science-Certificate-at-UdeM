/* Olivier Baptiste */
public class numeroA {

	/* Affichage */
	public static void main(String[] args) {
		
		double methode1Max99, methode1Max999, methode2Max99, methode2Max999;
		
		methode1Max99 = Methode1(99);
		System.out.println("La somme de 1 + 1/2 + 1/3 ... + 1/99 = " + methode1Max99  );
		
		methode1Max999 = Methode1(999);
		System.out.println("La somme de 1 + 1/2 + 1/3 ... + 1/999 = " + methode1Max999);
		
		methode2Max99 = Methode2(99);
		System.out.println("La somme de 1 + 1/2 + 1/3 ... + 1/99 = " + methode2Max99);
		
		methode2Max999 = Methode2(999);
		System.out.println("La somme de 1 + 1/2 + 1/3 ... + 1/999 = " + methode2Max999);
		

	}
	
	/* Calculs */
	public static double Methode1(int max) {
		
		int i = 1;
		double somme = 0;
		do {
			somme += 1.0/i;
			i++;
			
		} while (i <= max);
		
		
		return somme;
	}
	
	public static double Methode2(int max) {
		int i = 1;
		double somme = 0;
		
		while (i <= max) {
			somme += 1.0/i;
			i++;
			
		}
		return somme;
	}

}


/* 
La somme de 1 + 1/2 + 1/3 ... + 1/99 = 5.177377517639621
La somme de 1 + 1/2 + 1/3 ... + 1/999 = 7.484470860550343
La somme de 1 + 1/2 + 1/3 ... + 1/99 = 5.177377517639621
La somme de 1 + 1/2 + 1/3 ... + 1/999 = 7.484470860550343
*/