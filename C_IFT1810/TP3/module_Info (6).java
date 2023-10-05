class Personne {
	
	 private String naissance ; // format "jj/mm/aaaa", ex : "25/12/1990"
	 private int nbCafe ; // nb de tasses de café consommé par jour

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
		 System.out.format("Nombres de café: %d\n", nbCafe);
		 
	 }
 }

public class module_Info {

	public static void main(String[] args) {

		
		Personne pers1 = new Personne ("19/05/1997", 4),
		         pers2 = new Personne ("31/12/1990"), // par défaut 1 tasse de café
		         pers3 = new Personne ("08/05/1994", 2);
		
		   pers1.afficher("Informations de la première personne");
		   pers2.afficher("Informations de la deuxième personne");
		   pers3.afficher("Informations de la troisième personne");
		
	    
		
	}

}