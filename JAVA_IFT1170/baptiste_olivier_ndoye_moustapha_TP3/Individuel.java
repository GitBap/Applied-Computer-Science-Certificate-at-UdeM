// Olivier Baptiste
// Moustapha Ndoye

public abstract class Individuel extends Resultat {
    private String nom;

    public Individuel(String nom, int pos, String pays, int code) {
        super(pos, pays, code);
        this.nom = nom;
    }

    public Individuel() {
        super();
        this.nom = "";
    }

    public String getNom() {
        return nom;
    }

    public boolean equals(Object o) {
        Individuel r = (Individuel) o;
        if (this.nom == r.nom && super.equals(o)) {
            return true;
        } else {
            return false;
        }
    }

    public int compareTo(Individuel ind) {
        int val = this.nom.compareTo(ind.nom);
        return val;
    }

}
