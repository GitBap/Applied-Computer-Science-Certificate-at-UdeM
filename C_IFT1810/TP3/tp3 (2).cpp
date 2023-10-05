#include <stdio.h>

int main()
{	const int BORNE1 = 30;
	char poste [] = {'P', 'P', 'O', 'A', 'P', 'A', 'P', 'P'} ;
	int nbCafe [] = { 3, 1, 8, 0, 5, 2, 0, 3 },
	   	age [] = {25, 19, 27, 26, 49, 24, 56, 29 };
	   	 
	   	
	    	/* Affichage du tableau avant le tri */
			printf("Tableaux avant le tri \n") ; 
			printf("Indice  Poste  Cafe  Age\n");
			
			for (i = 0; i <nbPers; i++)
				printf("%5d %5c %5d %5d\n", i ,  poste[i], nbCafe[i], age[i]);
			printf("\n\n\n"); 
			
			/* Comptage et affichage de nombres de personnes pour chaque postes */
			int nbDe;
			
			printf("Le nombre de programmeurs: %d\n", nombre('P', nbDe));
			printf("Le nombre d'opérateurs: %d\n", nombre('O', nbDe));
			printf("Le nombre d'analystes': %d\n", nombre('A', nbDe));
			
			return 0;
			}
			
			/* Comptage et affichage du nombre d'employées de 30 ans et plus */
			int leNombre (int age[], int nbPers, int borne)
			{
				int n=0, i;
				for (i=0 ; i < nbPers ; i++)
					if( age[i]> borne)
						n++; 
						
				printf("Le nombre de personnes ages de 30 ans ou plus est %d\n",
								BORNE1, leNombre(age, nbPers, BORNE1));
				
				return n; 	
			}
			
			/* Comptage et affichage du nombre d'employées qui boivent du cafés */
			int leNombre (int nbCafe[], int nbPers, int borne)
			{
			
				int n=0, i;
				for (i=0 ; i < nbPers ; i++)
					if( nbCafe[i]> borne)
						n++; 
						
				printf("Le nombre de personnes buvant 3 cafes ou plus est %d\n",
								BORNE1, leNombre(age, nbPers, BORNE1));
			
				return n;
			}
			
				
			/* Compatge et affichage de la consommation maximale de café de tous les employés */
			{
			int  consMax = 0.0 
			int i; 
			
			for (i = 0 ; i <nbCafe ; i++)
					if (taille [i]>consMax)
							cafeMax = cafe[i];
							
			return consMax;
			}
			
			/* L'âge maximal de tous les employés */
			int age
			int a = 1, i = 0, k = 1
			while(i!=) 
			
			
			/* Affichage du tableau après le tri */
			void trier (char poste[], int nbCafe[], int age[])
				{
					int i, j, indMin;
					int tempo;
					
						for(i = 0; i < nb)
				}