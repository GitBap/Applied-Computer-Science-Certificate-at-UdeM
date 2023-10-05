<?php
    $base = new PDO("mysql:host=localhost; dbname=bdboutique", "root", "");

    $requete = $base->prepare("SELECT * FROM articles");
    $requete -> execute();
    $article = array();
    $nbr = 0;
    while($resultat = $requete->fetch(PDO::FETCH_OBJ))
    {
        $article["id"][] = $resultat->ida;
        $article["nom"][] = $resultat->nomarticle;
        $article["description"][] = $resultat->description;
        $article["image"][] = $resultat->imageart;
        $article["categorie"][] = $resultat->categorie;
        $article["quantite"][] = $resultat->qteinventaire;
        $article["seuil"][] = $resultat->seuil;
        $article["prix"][] = $resultat->prix;
        $nbr++;
    }
    for($i = 0; $i < $nbr; $i++)
    {
        
        include "../../includes/CRUD_actions.inc.php";
    }
?>