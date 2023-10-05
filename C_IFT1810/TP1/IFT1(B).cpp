/* Fichier taille.c

   Auteurs :  Olivier Baptiste IFT 1810 B groupe 
              Maxime Yan	IFT 1810 B groupe 2
			 
   But du programme :
     Ce programme permet, pour un patient sédentaire,
	  - de saisir son poids en nombre de kg
	  - de saisir sa taille en mètre
	  - calculer son indice de masse corporelle
		 
	Derniere mise a jour : 10/10/2021
*/	
			   

#include <stdio.h> 
#include <ctype.h> 

int main()
{

  const float PI = 3.14159;	
  char codeFig, reponse;
  float rayon, longeur, largeur, cote, perimetre, surface,
  		perimPGC = 0.0,//Plus grand perimetre des cercles traités
		surfPGR=0.0,//Plus grande surface des rectangles traités
		cotePPK=999999999,//Plus petit cotés des carrées traités
		somPerimRectangle=0;//Somme des perimetres des rectangles traités
  int nbCercle = 0, nbRectangle=0, nbCarre=0;
//Début du loop    
  do
  {
  	//Affichage des types de figures
  	printf("Tapez c ou C pour un cercle\n");
  	printf("Tapez r ou R pour un rectangle\n");
  	printf("Tapez k ou K pour un carre\n");
  	printf("Quel est le code de la figure ? ");
  	scanf(" %c", &codeFig);
  	
  	// conversion en lettre MAJUSCULE
  	codeFig = toupper(codeFig);
  	
	//Affichage selon la figure choisit
  	switch (codeFig)
  	{
  	   case 'C'	:
  	   	  nbCercle++;//Ajout au nombre de cerlce traités
  	   	  printf("Tapez le rayon du cercle ");
  	   	  scanf("%f", &rayon);
  	   	  perimetre = 2 * PI * rayon;
  	   	  surface = PI * rayon * rayon;
  	   	  printf("Infos du cercle traite :\n");
  	   	  printf(" - rayon      : %.1f\n", rayon);
  	   	  printf(" - perimetre  : %.2f\n", perimetre);
  	   	  printf(" - surface    : %.2f\n", surface);
  	   	  
  	   	  //Enregistrement du plus grand perimetre calculé
  	   	  if (perimetre > perimPGC)
  	   	      perimPGC = perimetre;
  	   	 
		break;
  	   	  
  	   case 'R'	  : 
		  nbRectangle++;//Ajout au nombre de rectangle traités
  	   	  printf("Tapez la longeur et la largeur du rectangle ");
  	   	  scanf("%f%f", &longeur,&largeur);
  	   	  perimetre = 2*(longeur+largeur);
  	   	  surface = longeur*largeur;
  	   	  printf("Infos du rectangle traite :\n");
  	   	  printf(" - longeur      : %.1f\n", longeur);
  	   	  printf(" - largeur      : %.1f\n", largeur);
  	   	  printf(" - perimetre  : %.2f\n", perimetre);
  	   	  printf(" - surface    : %.2f\n", surface);
  	   	  somPerimRectangle+=perimetre;
  	   	  
  	   	  	//Enregistrement de la plus grande surface calculée
  	   		if (surface > surfPGR)
  	   	       surfPGR = surface;
		break;
			
  	    case 'K'  :   
		  nbCarre++;	      
  	   	  printf("Tapez le cote du carre ");
  	   	  scanf("%f", &cote);
  	   	  perimetre=4*cote;
		  surface=cote*cote;
  	   	  printf("Infos du carre traite :\n");
  	   	  printf(" - cote      : %.1f\n", cote);
  	   	  printf(" - perimetre  : %.2f\n", perimetre);
  	   	  printf(" - surface    : %.2f\n", surface);
  	   	  //Enregistrement du plus petit coté traités 
			if ( cote < cotePPK )
  	   	       cotePPK = cote;
  	    	break;
  	    
		default: printf(" Code imprevu\n");	   	  
  		
	}	
			printf("\nAvez-vous une autre figure a traiter ? (o/n) ");
			scanf(" %c", &reponse);
	  	
  	} while(toupper(reponse) == 'O');//Fin du loop
        
        //Affichage des données calculés
        
			if(nbCercle > 0)        
    		printf("Le perimetre le plus grand des cercles traites : %.2f\n",perimPGC);
			else    
			printf("Pas de cercle traite => pas de perimPGC a calculer\n"); 
               	 
			if(nbRectangle > 0)	
			{
			printf("La surface la plus grandes des rectangles traites : %.2f\n", surfPGR);	
			printf("Le perimetre moyen des rectangles traites : %6.2f\n",
	        somPerimRectangle/nbRectangle);	
			}	      
	    	else
	    	printf("Pas de rectangle traite => pas de surfPGR a calculer\n");
	
			if(nbCarre > 0)        
	    	printf("Le cote le plus petit des carres traites : %.1f\n", cotePPK);
			else
	    	printf("Pas de carre traite => pas de cotePPK a calculer\n");    	
	        		
		            
return 0;   
}