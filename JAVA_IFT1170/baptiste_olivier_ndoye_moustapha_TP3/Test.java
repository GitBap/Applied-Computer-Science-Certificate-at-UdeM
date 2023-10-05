// Olivier Baptiste
// Moustapha Ndoye

import java.util.*;
import java.io.*;
import java.text.Collator;
import java.util.stream.*;

public class Test {

    public static void main(String[] args) {
        Individuel indiv;
        Equipe equip;

        LinkedList<Resultat> results = new LinkedList<Resultat>(); // creation de la liste doublement chainee

        // lecture des donnees dans le fichier test.txt et ajout dans la liste

        try (BufferedReader br = new BufferedReader(
                new FileReader("C:\\Users\\LEMOGO MBEUMO RIC\\eclipse-workspace\\Resultat\\src\\test.txt"))) {
            String line;
            while ((line = br.readLine()) != null) { // lecture de chaque ligne du fichier
                String[] split = line.split("-");
                if (Integer.parseInt(split[0]) == 1 || Integer.parseInt(split[0]) == 2) { // la ligne trouver est une
                                                                                          // course
                    indiv = new Course(split[4], split[3], Integer.parseInt(split[1]), split[2],
                            Integer.parseInt(split[0]));
                    results.add(indiv); // ajout d'une course dans laliste
                } else if (Integer.parseInt(split[0]) == 3) { // la ligne trouve est un Saut
                    indiv = new Saut(Double.parseDouble(split[4]), split[3], Integer.parseInt(split[1]), split[2],
                            Integer.parseInt(split[0]));
                    results.add(indiv); // ajout d'un saut dans la liste
                } else {
                    equip = new Relais(Double.parseDouble(split[4]), split[3], Integer.parseInt(split[1]), split[2],
                            Integer.parseInt(split[0]));
                    results.add(equip); // ajout d'un relais a la liste
                }
            }
        } catch (IOException e) {
            System.out.println("An error occured.");
            e.printStackTrace();
        }
        // affichage des elements de la liste
        System.out.println("############### affichage des informations de la liste ##################");
        ListIterator li = results.listIterator();
        while (li.hasNext()) {
            System.out.println(li.next().toString());
        }
        // affichage des elements avec indexOf
        int id1 = results.indexOf(new Course(null, "gelete burka", 0, "ETH", 1));
        System.out.println("############### affichage des informations sequentielle ##################");
        System.out.println(id1);

        // tri de la liste
        Collections.sort(results);

        // recherche valeur BinarySearch()
        int ind1 = Collections.binarySearch(results, new Course(null, "gelete burka", 2, null, 2));
        int ind2 = Collections.binarySearch(results, new Saut(0, "renaud lavillenie", 2, null, 3));
        int ind3 = Collections.binarySearch(results, new Saut(0, "alonso edward", 6, null, 3));
        System.out.println("############### affichage des informations dichotomique ##################");
        System.out.println(results.get(ind1).toString());
        System.out.println(results.get(ind2).toString());
        System.out.println(results.get(ind3).toString());

        // compter et afficher le nombre d'athlete aux USA et au Canada
        System.out.println("############### Nombre total d'athletes ##################");
        int nb1 = 0, nb2 = 0;
        for (int i = 0; i < results.size(); i++) {
            if (results.get(i).getPays().equals("CAN")) {
                nb1++;
            } else if (results.get(i).getPays().equals("USA")) {
                nb2++;
            }
        }
        System.out.println("le nombre d'athlete au Canada est: " + nb1);
        System.out.println("le nombre d'athlete au USA est: " + nb2);
    }

}
