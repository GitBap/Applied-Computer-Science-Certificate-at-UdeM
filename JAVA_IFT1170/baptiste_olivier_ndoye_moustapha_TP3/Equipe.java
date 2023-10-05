// Olivier Baptiste
// Moustapha Ndoye

public abstract class Equipe extends Resultat {
    private String noms;

    public Equipe(String nms, int pos, String pays, int code) {
        super(pos, pays, code);
        this.noms = nms;
    }

    public String getNoms() {
        return noms;
    }

    public boolean equals(Object o) {
        if (o instanceof Equipe) {
            Equipe r = (Equipe) o;
            return this.noms == r.noms && super.equals(o);
        } else {
            return false;
        }

    }

    public int compareTo(Equipe ind) {
        int val = this.noms.compareTo(ind.noms);
        return val;
    }

}
