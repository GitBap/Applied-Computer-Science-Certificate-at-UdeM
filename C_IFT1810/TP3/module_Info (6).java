class Personne {
	
	 private String naissance ; // format "jj/mm/aaaa", ex : "25/12/1990"
	 private int nbCafe ; // nb de tasses de caf� consomm� par jour

	 Personne(String dateNaissance, int nombreCafe){
		 naissance = dateNaissance;
		 nbCafe = nombreCafe;
				 
	 }
	 
	 Personne(String dateNaissance){
		 naissance = dateNaissance;
		 nbCafe = 1;
				 
	 }
	 
	 public String getNaissance(){
		 return naissance;
	 }
	 
	 public int getNbCafe(){
		 return nbCafe;
	 }
	 
	 public void setNaissance(String naissance){
		 this.naissance =  naissance;
	 }
	 
	 public void setNbCafe(int nbCafe){
		 this.nbCafe = nbCafe;
	 }
	 
	 public void afficher(String infos) {
		 
		 System.out.println(infos + ":");
		 System.out.format("Date de naissance: %s\n", naissance);
		 System.out.format("Nombres de caf�: %d\n", nbCafe);
		 
	 }
 }

public class module_Info {

	public static void main(String[] args) {

		
		Personne pers1 = new Personne ("19/05/1997", 4),
		         pers2 = new Personne ("31/12/1990"), // par d�faut 1 tasse de caf�
		         pers3 = new Personne ("08/05/1994", 2);
		
		   pers1.afficher("Informations de la premi�re personne");
		   pers2.afficher("Informations de la deuxi�me personne");
		   pers3.afficher("Informations de la troisi�me personne");
		
	    
		
	}

}