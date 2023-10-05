// Ficher NumeroB.java
// Olivier Baptiste
// Moustapha Ndoye

package com.demo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;

public class Tp2NumeroB {
	private static Vector<Nation> nations = new Vector<Nation>();
	static String currentDir = System.getProperty("user.dir") + "/src/com/demo/";
	static File fichier = new File(currentDir + "tp2_pays_h22.txt");

	public static void main(String[] args) {

		int paysLus = lire();
		System.out.println("Pays lus : " + paysLus);
		afficherPremiersPays(15);
		modifierNations();
		afficherPremiersPays(10);
		memeNomQueCapitale(nations, 3);
		//densiteMin('2');
		//densiteMin('5');
		//populationMax('3');
		//populationMax('4');
		//commenceParVoyelle();
		//plusLongNomCapitale('3');
		//trierParCapitale(nations);
		//afficherPremiersPays(10);
		//enregistrerPays('1', "Afrique.txt");
		//enregistrerPays('5', "Europe.txt");
		creerFichierBinaire(nations);
		Stack<Nation> nat = lireBinaire();
		paysPlusPeuple(nat);
		NombrePays(nat);
		superficieMoyenne(nat);
		paysPlusGrand(nat);
		paysPlusGrandNom(nat);
		paysPlusGrandCapitale(nat);
		
		
	}

	private static int lire() {

		Scanner sc;
		int paysLus = 0;

		try {
			sc = new Scanner(fichier);
			while (sc.hasNextLine()) {
				String line = sc.nextLine();
				char continent = line.charAt(0);
				String pays = line.substring(1, 20).trim();
				String capitale = line.substring(36, 49).trim();
				long superficie = Long.valueOf(line.substring(55, 62).trim());
				long population = Long.valueOf(line.substring(64).trim());

				Nation nation = new Nation(continent, pays, capitale, superficie, population);
				nations.add(nation);
				paysLus++;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return paysLus;
	}
	private static Stack lireBinaire() {
		Stack<Nation> pile = new Stack();
		Scanner sc;
		int paysLus = 0;

		try {
			File f = new File("");
			f = creerFichierBinaire(nations);
			sc = new Scanner(f);
			while (sc.hasNextLine()) {
				StringBuilder chaine = new StringBuilder(sc.nextLine());
				String result = BinaireTochaine(chaine);
				char continent = result.charAt(0);
				String pays = result.substring(1, 20).trim();
				String capitale = result.substring(36, 49).trim();
				long superficie = Long.valueOf(result.substring(55, 62).trim());
				long population = Long.valueOf(result.substring(64).trim());

				Nation nation = new Nation(continent, pays, capitale, superficie, population);
				pile.add(nation);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return pile;
	}

	private static void afficherPremiersPays(int nombre) {
		System.out.println("\nListe des " + nombre + " premiers pays :");
		System.out.println("01234567890123456789012345678901234567890123456789012345678901234567890123456");
		int cpt=0;
		for(Nation n:nations) {
			System.out.println(n.toString());
			cpt++;
			if(cpt==nombre)
				break;
		}
	}

	private static void modifierNations() {
		
		nations.get(1).setContinent('3');
		nations.get(4).setCapitale("TOKYO");
		nations.get(6).setPopulation(nations.get(6).getPopulation() * 10);
		nations.remove(5);
	}

	private static void memeNomQueCapitale(Vector<Nation> nations, int nbPays) {
		int cpt = 1;
		System.out.println("\nListe des pays ayant le même nom que leur capitale :");
		for (Nation nation : nations) {
			if (cpt <= nbPays) {
				if (nation.getNom().equals(nation.getCapitale())) {
					System.out.println(nation.toString());
					cpt++;
				}
			} else {
				break;
			}
		}
	}
	static StringBuilder ChaineToBinaire(String chaine){
	    byte[] bytes = chaine.getBytes();
	    StringBuilder binary = new StringBuilder();
	    for (byte b : bytes) {
	        int val = b;
	        for (int i = 0; i < 8; i++) {
	            binary.append((val & 128) == 0 ? 0 : 1);
	            val <<= 1;
	        }
	        //binary.append(' ');
	    }
	    return binary;
	}
 
	static String BinaireTochaine(StringBuilder a2){
	     
	    String res="";
        for(int i=1;i<a2.length();i++){
            if(i%8==0){
            	char a=(char)Integer.parseInt(a2.substring(i-8,i),2);
                res=res+a;
            }  
        }
        res=res+(char)Integer.parseInt(a2.substring(a2.length()-8,a2.length()),2);
        return res;
	}
	
	private static File creerFichierBinaire(Vector<Nation> nations) {
		
		//FileOutputStream file = new FileOutputStream("Amerique.bin");
		File fichier = new File(currentDir + "Amerique.bin");
		try {
			fichier.createNewFile();
			try {
				FileWriter f = new FileWriter(fichier);
				for(Nation n: nations) {
					if(n.getContinent() == '2') {
						f.write(ChaineToBinaire(n.toString()).toString()+"\n");
					}
				}
				f.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
		return fichier;
	}
	private static void densiteMin(char continent) {
		Nation n = null;
		float min = 100000000;
		for (Nation nation : nations) {
			if (nation.getContinent() == continent) {
				float densite = nation.getPopulation() / nation.getSuperficie();
				if (densite < min) {
					min = densite;
					n = nation;
				}
			}
		}
		System.out.println("\nPays dont la densité est la plus petite (continent : " + continent + ")");
		System.out.println(n.toString());
	}

	private static void populationMax(char continent) {
		Nation n = null;
		long max = 0;
		for (Nation nation : nations) {
			if (nation.getContinent() == continent) {
				if (nation.getPopulation() > max) {
					max = nation.getPopulation();
					n = nation;
				}
			}
		}
		System.out.println("\nPays le plus peuplé (continent : " + continent + ")");
		System.out.println(n.toString());
	}

	private static void commenceParVoyelle() {
		char voyelles[] = new char[] { 'A', 'E', 'Y', 'U', 'I', 'O' };
		System.out.println("\nListe des pays dont le nom commence par une voyelle :");
		for (Nation nation : nations) {
			for (char c : voyelles) {
				if (nation.getNom().charAt(0) == c) {
					System.out.println(nation.toString());
					break;
				}
			}
		}
	}

	private static void plusLongNomCapitale(char continent) {
		Nation n = null;
		int max = 0;
		for (Nation nation : nations) {
			if (nation.getContinent() == continent) {
				int taille = nation.getCapitale().length();
				if (taille > max) {
					max = taille;
					n = nation;
				}
			}
		}
		System.out.println(
				"\nPays dont la capitale contient le plus de caractères alphabétiques (continent : " + continent + ")");
		System.out.println(n.toString());
	}

	private static void trierParCapitale(Nation nations[]) {
		Nation tmp;
		for (int i = 0; i < nations.length - 1; i++) {
			for (int j = i + 1; j < nations.length; j++) {
				char c1 = Character.valueOf(nations[i].getCapitale().charAt(0));
				char c2 = Character.valueOf(nations[j].getCapitale().charAt(0));
				if (c1 > c2) {
					tmp = nations[j];
					nations[j] = nations[i];
					nations[i] = tmp;
				}
			}
		}
	}

	private static void enregistrerPays(char continent, String nomFichier) {
		try {

			Path path = Paths.get(currentDir + nomFichier);
			List<String> lines = new ArrayList<String>();
			for (Nation nation : nations) {
				if (nation.getContinent() == continent) {
					lines.add(nation.toString());
				}
			}
			Files.write(path, lines);
			System.out.println("Pays enregistrés dans " + nomFichier + " (continent " + continent + ") !");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void paysPlusPeuple(Stack<Nation> nations) {
		Nation max = new Nation();
		max = nations.get(0);
		for(Nation n:nations) {
			if(n.getPopulation()>max.getPopulation())
				max = n;
		}
		System.out.println("Pays le plus peupl�:\n"+max.toString());
	}
	private static void NombrePays(Stack<Nation> nations) {
		int cpt = 0;
		for(Nation n:nations) {
			cpt++;
		}
		System.out.println("Il y a "+cpt+" pays dans le fichier");
	}
	private static void superficieMoyenne(Stack<Nation> nations) {
		int cpt = 0;
		long somme = 0;
		for(Nation n:nations) {
			somme += n.getSuperficie();
			cpt++;
		}
		System.out.println("La superficie moyenne est de "+somme/cpt);
	}
	private static void paysPlusGrand(Stack<Nation> nations) {
		Nation max = new Nation();
		max = nations.get(0);
		for(Nation n:nations) {
			if(n.getSuperficie()>max.getSuperficie())
				max = n;
		}
		System.out.println("Pays avec la plus grande superficie:\n"+max.toString());
	}
	private static void paysPlusGrandNom(Stack<Nation> nations) {
		Nation max = new Nation();
		max = nations.get(0);
		for(Nation n:nations) {
			if(n.getNom().length()>max.getNom().length())
				max = n;
		}
		System.out.println("Pays avec le plus de lettre dans son nom:\n"+max.toString());
	}
	private static void paysPlusGrandCapitale(Stack<Nation> nations) {
		Nation max = new Nation();
		max = nations.get(0);
		for(Nation n:nations) {
			if(n.getCapitale().length()>max.getCapitale().length())
				max = n;
		}
		System.out.println("Pays avec le plus de lettre dans sa capitale:\n"+max.toString());
	}
}


/*Pays lus : 198

Liste des 15 premiers pays :
01234567890123456789012345678901234567890123456789012345678901234567890123456
2ETATS-UNIS                         WASHINGTON         962904   291289535       
4CHINE                              PEKIN              959696   1273111290      
5RUSSIE                             MOSCOU             1707540  143954573       
4AUSTRALIE                          CANBERRA           768685   19834248        
3JAPON                              KYOTO              377835   12761000        
4DES OURAGANS                       TEMPETE            1        1               
5ALLEMAGNE                          BERLIN             357027   8253700         
5FRANCE                             MARSEILLE          543964   61387038        
5ITALIE                             ROME               301230   57715620        
3COREE DU SUD                       SEOUL              99274    48324000        
5ROYAUME-UNI                        LONDRES            244101   58789194        
2CUBA                               LA HAVANE          100860   11184023        
5UKRAINE                            KIEV               603700   48396470        
5HONGRIE                            BUDAPEST           93030    10106017        
5ROUMANIE                           BUCAREST           238390   22272000        

Liste des 10 premiers pays :
01234567890123456789012345678901234567890123456789012345678901234567890123456
2ETATS-UNIS                         WASHINGTON         962904   291289535       
3CHINE                              PEKIN              959696   1273111290      
5RUSSIE                             MOSCOU             1707540  143954573       
4AUSTRALIE                          CANBERRA           768685   19834248        
3JAPON                              TOKYO              377835   12761000        
5ALLEMAGNE                          BERLIN             357027   82537000        
5FRANCE                             MARSEILLE          543964   61387038        
5ITALIE                             ROME               301230   57715620        
3COREE DU SUD                       SEOUL              99274    48324000        
5ROYAUME-UNI                        LONDRES            244101   58789194        

Liste des pays ayant le même nom que leur capitale :
1DJIBOUTI                           DJIBOUTI           22000    460700          
3KOWEIT                             KOWEIT             17820    2041961         
5LUXEMBOURG                         LUXEMBOURG         2586     442972          

Pays dont la densité est la plus petite (continent : 2)
2SURINAME                           PARAMARIBO         163270   433998          

Pays dont la densité est la plus petite (continent : 5)
5ISLANDE                            REYKJAVIC          103125   288201          

Pays le plus peuplé (continent : 3)
3CHINE                              PEKIN              959696   1273111290      

Pays le plus peuplé (continent : 4)
4PHILIPPINES                        MANILLE            300000   86241697        

Liste des pays dont le nom commence par une voyelle :
2ETATS-UNIS                         WASHINGTON         962904   291289535       
4AUSTRALIE                          CANBERRA           768685   19834248        
5ALLEMAGNE                          BERLIN             357027   82537000        
5ITALIE                             ROME               301230   57715620        
5UKRAINE                            KIEV               603700   48396470        
5ESPAGNE                            MADRID             504782   40037995        
5AUTRICHE                           VIENNE             83858    8150835         
1ETHIOPIE                           ADDIS-ABEBA        112712   67673031        
3IRAN                               TEHERAN            164800   76000000        
3OUZBEKISTAN                        TACHKENT           447400   25563441        
2ARGENTINE                          BUENOS AIRES       276689   37812817        
1AFRIQUE DU SUD                     PRETORIA           121991   42718530        
1EGYPTE                             LE CAIRE           995450   74718797        
3INDONESIE                          DJAKARTA           191944   228437870       
3AZERBAIDJAN                        BAKU               86100    7830764         
5ISRAEL                             JERUSALEM          20770    6116533         
3EMIRATS ARABES UNIS                ABOU DHABI         82880    2407460         
5ESTONIE                            TALINN             45226    1401945         
3INDE                               NEW DELHI          328759   1029991145      
1ERYTHREE                           ASMARA             121320   4465651         
3AFGHANISTAN                        KABOUL             652225   29547078        
5ALBANIE                            TIRANA             28748    3510484         
1ALGERIE                            ALGER              238174   31763053        
5ANDORRE                            ANDORRA LA VE      468      67627           
1ANGOLA                             LUANDA             124670   10766471        
2ANTIGUA-ET-BARBUDA                 SAINT-JOHNS        442      67448           
2ANTILLES NEERLANDAI                WILLEMSTAD         800      210000          
3ARABIE SAOUDITE                    RIYAD              196058   23513330        
3ARMENIE                            EREVAN             29800    3326448         
2ARUBA                              ORANJESTAD         193      69000           
2EL SALVADOR                        SAN SALVADOR       21041    6122075         
2EQUATEUR                           QUITO              283560   13183978        
2ILES CAIMANS                       GEORGE TOWN        262      39000           
4ILES SALOMON                       HONIARA            28450    480442          
2ILES VIERGES BRITAN                ROAD TOWN          153      19000           
3IRAK                               BAGDAD             437072   23331985        
5IRLANDE                            DUBLIN             70273    3917336         
5ISLANDE                            REYKJAVIC          103125   288201          
3OMAN                               MASCATE            212460   2622198         
1OUGANDA                            KAMPALA            236040   24699073        
2URUGUAY                            MONTEVIDEO         176220   3360105         
3YEMEN                              SANAA              527970   19349881        

Pays dont la capitale contient le plus de caractères alphabétiques (continent : 3)
3BRUNEI                             BANDAR SERI B      5770     343653          

Liste des 10 premiers pays :
01234567890123456789012345678901234567890123456789012345678901234567890123456
5GRECE                              ATHENES            131940   10623835        
5PAYS-BAS                           AMSTERDAM          41526    16135992        
5TURQUIE                            ANKARA             780580   67308928        
1ETHIOPIE                           ADDIS-ABEBA        112712   67673031        
3KAZAKHSTAN                         ASTANA             271730   16741519        
3EMIRATS ARABES UNIS                ABOU DHABI         82880    2407460         
2PARAGUAY                           ASUNCIO            406750   5734139         
1NIGERIA                            ABUJA              923768   133881703       
1ERYTHREE                           ASMARA             121320   4465651         
1ALGERIE                            ALGER              238174   31763053        
Pays enregistrés dans Afrique.txt (continent 1) !
Pays enregistrés dans Europe.txt (continent 5) !
*/
