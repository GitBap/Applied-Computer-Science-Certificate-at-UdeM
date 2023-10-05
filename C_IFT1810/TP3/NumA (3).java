import java.util.Iterator;

public class NumA {
	public static void main(String[] args) {
		String telUDM = "5143436111", telJean = "4501897654";

//        afficher (telUDM, "Téléphone d'UdeM " );
//        afficher (telJean, "Téléphone de Jean ");

		String tempoTelUdm = "Tel UDM: (";
		tempoTelUdm += telUDM.substring(0, 3) + ") ";
		tempoTelUdm += telUDM.substring(3, 6) + "-";
		tempoTelUdm += telUDM.substring(6, 10);
		System.out.println(tempoTelUdm);

		String tempoTelJean = "Tel Jean: (";
		tempoTelJean += telJean.substring(0, 3) + ")";
		tempoTelJean += telJean.substring(3, 6) + "-";
		tempoTelJean += telJean.substring(6, 10);
		System.out.println(tempoTelJean);

		demo1();
		demo2();
		
		afficherImpairsCommuns(tempoTelUdm, tempoTelJean);
		
	}

	static int nombre(char carVoulu, String chaine) {
		int n = 0, nbCars = chaine.length();
		for (int i = 0; i < nbCars; i++)
			if (chaine.charAt(i) == carVoulu)
				n++;

		return n;
	}

	static void demo1() {

		System.out.printf("Afficher le nombre de fois dont le chiffre se répète:\n");
		String telUDM = "5143436111", telJean = "5146524272";
		System.out.println(telJean.length());
		System.out.printf("\n Il y a %d le nombre 3 dans le numéro de tel udem : %s\n", nombre('3', telUDM), telUDM);
		System.out.printf("\n Il y a : %d le nombre 4 dans le numéro de tel udem : %s\n", nombre('4', telUDM), telUDM);
		System.out.printf("\n Il y a : %d le nombre 2 dans le numéro de tel jean : %s\n", nombre('2', telJean),
				telJean);
	}

	static void demo2() {

		System.out.print("Afficher le nombre de fois les chiffres sont impairs et pairs:\n");
		String telUDM = "5143436111", telJean = "(514) 652-4272";

		System.out.printf("\n Il y a : %d chiffres impairs dans le numéro de tel udem : %s\n", nombre('3', telUDM),
				telUDM);
		System.out.printf("\n Il y a : %d pairs dans le numéro de tel jean : %s\n", nombre('2', telJean), telJean);
	}
	
	 static void afficherImpairsCommuns(String telUDM, String telJean)
	    {
	      System.out.printf("Les chiffres impairs communs des deux tphones : ");
	      for(char c = '1' ; c <= '9'; c+=2)// examiner les chiffres
	                                        // pairs 1', '3', '5', '7', '9'
	      	if (telUDM.indexOf(c) >= 0 && telJean.indexOf(c) >= 0  ) // s'il fait partie de 2 t�l�phones
	      	   System.out.printf("%c ", c); // on l'affiche
	      System.out.printf("\n");
	      
	    }

}
