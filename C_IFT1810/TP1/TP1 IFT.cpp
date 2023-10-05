#include <stdio.h>
/* Fichier taille.c

   Auteurs :  Olivier Baptiste IFT 1810 B groupe 2
              Maxime Yan IFT 1810 B groupe 2
			 
   But du programme :
     Ce programme permet, pour un patient sédentaire,
	  - de saisir son poids en nombre de kg
	  - de saisir sa taille en mètre
	  - calculer son indice de masse corporelle
		 
	Derniere mise a jour : 10/10/2021
*/	
			   
	
	int main()
	{
		float poids,taille,imc;
		char reponse;
		int nbPers=0;
			//Début du loop
			do 
			{
				nbPers++;
			
				//Prise des donnes
	
				printf("Tapez le poids(kg) et la taille(m):");
				scanf("%f%f",&poids,&taille);
				
				//Calcul de imc
				imc=(poids/(taille*taille));
				
				//Affichage des donnés
				printf("Poids: %.1f kg\n", poids); 
				printf("Taille : %.2f m\n", taille);
				printf("Indice de masse corporelle: %.1f \n",imc);
				
				//Reponse selon le imc calculé
				if (imc<18.5)
					printf("MAIGREUR,RISQUE ELEVE A ACCRU");
				else if (imc<25)
					printf("POIDS NORMAL, RISQUE FAIBLE");
				else if (imc<30)
					printf("EMBONPOINT, RISQUE ELEVE");
				else
					printf("OBESITE,RISQUE TRES ELEVE");
				
			  
		      	printf("\nVoulez-vous continuer (o/n) ");
		     	scanf(" %c", &reponse);
	     	}while(reponse == 'o' || reponse == 'O');//Fin du loop
	      
     	 		printf("Au total on a traite %d personne(s)\n", nbPers);}
		
		
	return 0;	
		
	}