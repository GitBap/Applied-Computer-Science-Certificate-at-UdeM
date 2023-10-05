// Olivier Baptiste
// Moustapha Ndoye

public abstract class Resultat implements Comparable<Resultat> {

    private int pos;
    private String pays;
    private int code;

    public Resultat(int p, String pay, int cde) {
        this.pos = p;
        this.pays = pay;
        this.code = cde;
    }

    public Resultat() {
        this(0, "", 0);
    }

    public int getClassement() {
        return pos;
    }

    public String getPays() {
        return pays;
    }

    public int getCode() {
        return code;
    }

    @Override
    public int compareTo(Resultat r) {
        if (this.code == r.code) {
            if (this.pos == r.pos) {
                return 0;
            } else {
                return this.pos > r.pos ? 1 : -1;
            }
        } else {
            return this.code > r.code ? 1 : -1;
        }
    }

    public boolean equals(Object o) {
        if (o instanceof Resultat) {
            Resultat r = (Resultat) o;
            return this.pos == r.pos && this.pays == r.pays && this.code == r.code;
        } else {
            return false;
        }
    }

    public abstract String getResultat();

}
