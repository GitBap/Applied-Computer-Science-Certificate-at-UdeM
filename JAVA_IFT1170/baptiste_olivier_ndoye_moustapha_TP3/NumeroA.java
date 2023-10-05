
// Ficher NumeroA.java
// Olivier Baptiste
// Moustapha Ndoye

import java.util.Date;

public class NumeroA {

    public static void main(String[] args) {
        final int BORNE = 50;
        int n;
        long départ = System.currentTimeMillis();
        long fin;

        // #1 récursivité
        afficherTemps("\nCalcul des 50 premiers termes de la version récursive: ", départ);
        for (n = 0; n <= BORNE; n++)
            System.out.printf(" %d) : %d\n", n, fiboRecursif(n));

        finTemps = System.currentTimeMillis();
        afficherTemps("\nFin du calcul des 50 ers termes de la version récursive.\n", finTemps);
        System.out.printf("\nDuree du calcul : %d ms\n\n", fin - départ);

        // #2 iterative
        afficherTemps("\nCalcul des 50 premiers termes de la version itérative: ", départ);
        for (n = 0; n <= BORNE; n++)
            System.out.printf(" %d) : %d\n", n, fiboIteration(n));

        finTemps = System.currentTimeMillis();
        afficherTemps("\nFin du calcul des 50 ers termes de la version itérative.\n", fin);
        System.out.printf("\nDuree du calcul : %d ms\n\n", fin - départ);
    }

    // suite Fibonacci
    public static long fiboIteration(int n) {
        long avantDernier = 1, dernier = 1, résultat;
        for (int i = 2; i <= n; i++) {
            resultat = avantDernier + dernier;
            avantDernier = dernier;
            dernier = résultat;
        }
        return dernier;
    }

    public static long fiboRecursif(int n) {
        if (n <= 1)
            return 1;
        else
            return fiboRecursif(n - 2) + fiboRecursif(n - 1);
    }

    static void afficherTemps(String message, long temps) {
        temps = System.currentTimeMillis();
        Date datePrésent = new Date(temps);
        System.out.printf(message + " " + datePrésent + " ms\n\n");

    }

}

/* Execution:

Calcul des 50 premiers termes de la version récursive: 

 0) : 1
 1) : 1
 2) : 2
 3) : 3
 4) : 5
 5) : 8
 6) : 13
 7) : 21
 8) : 34
 9) : 55
 10) : 89
 11) : 144
 12) : 233
 13) : 377
 14) : 610
 15) : 987
 16) : 1597
 17) : 2584
 18) : 4181
 19) : 6765
 20) : 10946
 21) : 17711
 22) : 28657
 23) : 46368
 24) : 75025
 25) : 121393
 26) : 196418
 27) : 317811
 28) : 514229
 29) : 832040
 30) : 1346269
 31) : 2178309
 32) : 3524578
 33) : 5702887
 34) : 9227465
 35) : 14930352
 36) : 24157817
 37) : 39088169
 38) : 63245986
 39) : 102334155
 40) : 165580141
 41) : 267914296
 42) : 433494437
 43) : 701408733
 44) : 1134903170
 45) : 1836311903
 46) : 2971215073
 47) : 4807526976
 48) : 7778742049
 49) : 12586269025
 50) : 20365011074

 Fin du calcul des 50 ers termes de la version recursive.

 Duree du calcul : 122 ms

Calcul des 50 premiers termes de la version itérative:  

 0) : 1   
 1) : 1   
 2) : 2   
 3) : 3   
 4) : 5   
 5) : 8   
 6) : 13  
 7) : 21  
 8) : 34  
 9) : 55  
 10) : 89 
 11) : 144
 12) : 233   
 13) : 377   
 14) : 610   
 15) : 987   
 16) : 1597  
 17) : 2584  
 18) : 4181  
 19) : 6765  
 20) : 10946 
 21) : 17711 
 22) : 28657 
 23) : 46368 
 24) : 75025 
 25) : 121393
 26) : 196418
 27) : 317811
 28) : 514229
 29) : 832040
 30) : 1346269
 31) : 2178309
 32) : 3524578
 33) : 5702887
 34) : 9227465
 35) : 14930352
 36) : 24157817
 37) : 39088169
 38) : 63245986
 39) : 102334155
 40) : 165580141
 41) : 267914296
 42) : 433494437
 43) : 701408733
 44) : 1134903170
 45) : 1836311903
 46) : 2971215073
 47) : 4807526976
 48) : 7778742049
 49) : 12586269025
 50) : 20365011074

 Fin du calcul des 50 ers termes de la version iterative.

 Duree du calcul : 178758 ms

 */