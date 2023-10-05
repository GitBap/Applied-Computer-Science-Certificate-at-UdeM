// Olivier Baptiste
// Moustapha Ndoye

public class Relais extends Equipe {

    private double temps;

    public Relais(double tps, String nom, int position, String pays, int cde) {
        super(nom, position, pays, cde);
        this.temps = tps;
    }

    public double getTemps() {
        return temps;
    }

    public String getResultat() {
        String tps = "";
        String numb = String.valueOf(temps);
        char[] val = numb.toCharArray();

        for (int i = 0; i < val.length; i++) {
            if (val[i] == '.' && (i + 1) <= val.length) {
                tps += '.' + val[i + 1] + '0';

            } else if (val[i] == '.' && (i + 2) <= val.length) {
                tps += '.' + val[i + 1] + val[i + 2];
            } else {
                tps += val[i];
            }
        }
        return tps;
    }

    public String toString() {
        return "code: " + super.getCode() + " ;position: " + super.getClassement() +
                " ;pays: " + super.getPays() + " ;nom: " + super.getNoms() + " ;temps: " +
                this.temps;
    }

    public boolean equals(Object o) {
        if (o instanceof Relais) {
            Relais r = (Relais) o;
            return this.temps == r.temps && super.equals(o);
        } else {
            return false;
        }
    }

}
