// Olivier Baptiste
// Moustapha Ndoye

public class Saut extends Individuel {

    private double hauteur;

    public Saut(double hts, String nom, int pos, String pays, int code) {
        super(nom, pos, pays, code);
        this.hauteur = hts;
    }

    public double getHauteur() {
        return hauteur;
    }

    public String getResultat() {
        String hts = "";
        String numb = String.valueOf(hauteur);
        char[] val = numb.toCharArray();

        for (int i = 0; i < val.length; i++) {
            if (val[i] == '.' && (i + 1) <= val.length) {
                hts += '.' + val[i + 1] + '0';

            } else if (val[i] == '.' && (i + 2) <= val.length) {
                hts += '.' + val[i + 1] + val[i + 2];
            } else {
                hts += val[i];
            }
        }
        return hts;
    }

    public String toString() {
        return "code: " + super.getCode() + " ;position: " + super.getClassement() +
                " ;pays: " + super.getPays() + " ;nom: " + super.getNom() + " ;hauteur: " +
                this.hauteur;
    }

    public boolean equals(Object o) {
        if (o instanceof Saut) {
            Saut r = (Saut) o;
            return this.hauteur == r.hauteur && super.equals(o);
        } else {
            return false;
        }
    }

}
