// Olivier Baptiste
// Moustapha Ndoye

public class Course extends Individuel {
    private String temps;

    public Course(String tps, String nom, int pos, String pays, int code) {
        super(nom, pos, pays, code);
        this.temps = tps;
    }

    public Course() {
        super();
        this.temps = "";
    }

    public String getResultat() {
        return temps;
    }

    public String toString() {
        return "code: " + super.getCode() + " ;position: " + super.getClassement() +
                " ;pays: " + super.getPays() + " ;nom: " + super.getNom() + " ;temps: " +
                this.temps;
    }

    public boolean equals(Object o) {
        if (o instanceof Course) {
            Course r = (Course) o;
            return this.temps == r.temps && super.equals(o);
        } else {
            return false;
        }
    }
}
