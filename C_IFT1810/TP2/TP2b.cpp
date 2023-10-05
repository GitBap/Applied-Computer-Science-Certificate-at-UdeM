#include <stdio.h>

		/*	Auteurs :  Olivier Baptiste IFT 1810 B groupe 2
			              Maxime Yan IFT 1810 B groupe 2
			              
			    But du programme :
			     Ce programme permet
				  - de declarer et initialiser des petits tableaux
				  - manipuler les tableaux 
				  - trier les tableaux 
				  
				  Derniere mise a jour : 11 08 2021 
		*/

int main()
{
	char poste [] = {'P', 'P', 'O', 'A', 'P', 'A', 'P', 'P'} ;
	int nbCafe [] = { 3, 1, 8, 0, 5, 2, 0, 3 },
    	age [] = {25, 19, 27, 26, 49, 24, 56, 29 },
    	nbPers=(sizeof(age)/sizeof(int));
   int i, j, indMin, tempo;
   char tempo2;
	
	/* Affichage du tableau avant le tri */
	printf("Tableau avant le tri :\n");
	printf("Indice  Poste  Cafe  Age\n");
	for (i = 0; i <nbPers; i++) 
		printf("%5d %5c %5d %5d\n", i ,  poste[i], nbCafe[i], age[i]);
	printf("\n\n\n");
	
	/* Triage du tableau */
		for(i = 0; i < nbPers-1; i++)
		{ int indMin = i;
		  int j;
		  for(j = i+1; j < nbPers; j++)
		     if (age[j]< age[indMin])
		          indMin = j;
		  if(indMin != i) // permuter
		  {
	          tempo = age[i]	  	;
		  	  age[i] = age[indMin];
		  	  age[indMin]=tempo;
		  	  
		  	  tempo = nbCafe[i];
		  	  nbCafe[i]=nbCafe[indMin];
		  	  nbCafe[indMin] = tempo;
		  	  
		  	  char tempo2 = poste[i];
		  	  poste[i]= poste[indMin];
		  	  poste[indMin]=tempo2;
		 }       
		}
			 
	
	
	
		
		
	/* Comptage et affichage des programmeurs */
	int nbProg=0,
    	ageMaxProg=0;
	float sumAgeProg=0.00;
    for(i = 0; i < nbPers; i++) 
    	if(poste[i]=='P')
    	{
    		sumAgeProg+=age[i];
			nbProg++;
			if(age[i]>ageMaxProg)
				ageMaxProg = age[i];
		}
		if(nbProg>0){
			printf("Le nombre de programeurs : %d \n", nbProg);
			printf("L'age maximal des programmeurs : %d \n", ageMaxProg);
		}
		else
			printf("Aucune donnees,pas de programmeurs traitees");	
	
    
    
	float sumAgeA=0.000;
    int	minCafeA=57,nbA=0;
    	
	/* Détermination et affichafe de la consomation minimale de cafe */
	  for(i = 0; i < nbPers; i++) 
    	if(poste[i]=='A')
    	{	
    		nbA++;
    		sumAgeA+=age[i];
			if(nbCafe[i] < minCafeA)
				minCafeA = nbCafe[i];
		}
		if(nbA>0)
			printf("La consommation minimale de cafe des analystes est de %d tasse(s) \n", minCafeA);
		else
			printf("Aucune donnees,pas d'analyste traitees");	
			
		
		
		
	/*  Calcule et affichage de la consommation moyenne de cafe */
	float sumAgeOp=0.00,
		sumConsOp=0.00;
	int nbOp=0;
		for(i = 0; i < nbPers; i++) 
	    	if(poste[i]=='O')
	    	{	
	    		nbOp++;
				sumAgeOp+=age[i];
	    		sumConsOp+=nbCafe[i];
			}
			if(nbOp>0)
				printf("La consommation moyenne de cafe des operateurs est de %.2f tasse(s) \n", sumConsOp/nbOp);
			else
				printf("Aucune donnees,pas d'operateurs traitees");
			
	/* Calcul et affichage de l'âge moyen des employes */ 
	int	nbSec=0;
	float sumAgeSec=0.00;
		
		for(i = 0; i < nbPers; i++) 
	    	if(poste[i]=='S')
	    	{	
	    		nbSec++;
	    		sumAgeSec+=age[i];
	    	
			}
			if(nbSec>0)
				printf("Le nombre de secretaires est de : %d \n",nbSec);
			else
				printf("Aucune donnees, pas de secretaires traitees\n");

					
			printf("L'age moyen de tous les employes est de %.2f ans \n", (sumAgeOp+sumAgeA+sumAgeProg+sumAgeSec)/nbPers);
			
	/* Affichage des tableaux après le tri */
	printf("\n\n\n");
	printf("Tableau apres le tri :\n");
	printf("Indice  Poste  Cafe  Age\n");
	for (i = 0; i <nbPers; i++) 
		printf("%5d %5c %5d %5d\n", i ,  poste[i], nbCafe[i], age[i]);
	
	
	
	
			
	
	
	
			
			
return 0;		
    
}


 
