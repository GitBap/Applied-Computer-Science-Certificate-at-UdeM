#include <stdio.h>
		
		/*	Auteurs :  Olivier Baptiste IFT 1810 B groupe 2
			              Maxime Yan IFT 1810 B groupe 2
			              
			    But du programme :
			     Ce programme permet
				  - de calculer la somme avec la boucle while 
				  - de calculer la somme avec la boucle  do ... while 
				  - de compter avec la boucle for 
				  
				  Derniere mise a jour : 11 08 2021 
		*/
		
	int main()
	
	{
		int somme1=0;
		int n=15;
		
		
		/* Instruction à répéter de la somme 1 est composée */ 
		while(n<=100)
			{
			somme1+=n;
			n+=5;
			}
			printf("La somme de 15 + 20 + . . . + 95 + 100 = %d\n", somme1);		
	
		/* Somme2 */
	 
	 	float somme2=0.000;
	 	float m=3.000;
			do{
				somme2+=1/m;
				m+=2;
				}
				while(m<999);
				printf("La somme de 1/3 + 1/5 + 1/7 + 1/9 + . . . + 1/999 = %.3f \n", somme2);
return 0;
	}
					
		
	

