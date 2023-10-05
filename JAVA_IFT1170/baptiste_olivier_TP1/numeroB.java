/* Olivier Baptiste */
public class numeroB {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String telUdeM = "5143436111", telJean = "4501897654";

		formaterTel(telJean, "Tel Jean: (");
		formaterTel(telUdeM, "Tel UDM: (");
		
		chiffresPairs(telUdeM, "UdeM");
		chiffresImpairs(telUdeM, "UdeM");
		
		chiffresPairs(telJean, "Jean");
		chiffresImpairs(telJean, "Jean"); 

	}

	static void formaterTel(String tel, String nomPrsn) {

		String tempoTel = nomPrsn;
		tempoTel += tel.substring(0, 3) + ") ";
		tempoTel += tel.substring(3, 6) + "-";
		tempoTel += tel.substring(6, 10);
		System.out.println(tempoTel);

	}

	/* Calcul chiffres impairs */
	static void chiffresImpairs(String tel, String nomPrsn) {

		int cptChiffreImpair = 0;
		String chiffreImpair = "";

		for (int i = 0; i <= 9; i++) {
			if (tel.charAt(i) == '1' || tel.charAt(i) == '3' || tel.charAt(i) == '5' || tel.charAt(i) == '7'
					|| tel.charAt(i) == '9') {
				cptChiffreImpair++;
				chiffreImpair += tel.charAt(i);

			}
			

		}
		if (nomPrsn == "Jean") {
			System.out.println("Il y a " + cptChiffreImpair + " chiffres pairs dans le numéro de téléphone de Jean"
					+ "\n Ce sont : " + chiffreImpair);
			
		}else {
			System.out.println("Il y a " + cptChiffreImpair + " chiffres pairs dans le numéro de téléphone d'UdeM"
					+ "\n Ce sont : " + chiffreImpair);
			
		}
	}

	/* Calcul chiffres pairs */
	static void chiffresPairs(String tel, String nomPrsn) {

		int cptChiffrePair = 0;
		String chiffrePair = "";

		for (int i = 0; i <= 9; i++) {
			if (tel.charAt(i) == '0' || tel.charAt(i) == '2' || tel.charAt(i) == '4' || tel.charAt(i) == '6'
					|| tel.charAt(i) == '8') {

				cptChiffrePair++;
				chiffrePair += tel.charAt(i);

			}
			
			
		}
		if (nomPrsn == "Jean") {
			System.out.println("Il y a " + cptChiffrePair + " chiffres pairs dans le numéro de téléphone de Jean"
					+ "\n Ce sont : " + chiffrePair);
			
		}else {
			System.out.println("Il y a " + cptChiffrePair + " chiffres pairs dans le numéro de téléphone d'UdeM"
					+ "\n Ce sont : " + chiffrePair);
			
		}
		
		
	}

}

/* 
Tel Jean: (450) 189-7654
Tel UDM: (514) 343-6111
Il y a 3 chiffres pairs dans le numéro de téléphone d'UdeM
 Ce sont : 446
Il y a 7 chiffres pairs dans le numéro de téléphone d'UdeM
 Ce sont : 5133111
Il y a 5 chiffres pairs dans le numéro de téléphone de Jean
 Ce sont : 40864
Il y a 5 chiffres pairs dans le numéro de téléphone de Jean
 Ce sont : 51975
 */