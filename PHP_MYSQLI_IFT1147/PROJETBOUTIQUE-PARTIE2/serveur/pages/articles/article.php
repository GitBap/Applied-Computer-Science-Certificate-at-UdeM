<?php

session_start();

echo $_GET["ia"];

//ajout au panier
    $base = new PDO("mysql:host=localhost; dbname=bdboutique","root","");
    
    $requete = $base->prepare("SELECT * FROM membres WHERE courriel = :c");
    $requete -> execute([":c" => $_SESSION['courriel']]);

    $reponse = $requete ->fetch(PDO::FETCH_OBJ);

    $requete1 = $base->prepare("SELECT * FROM panier WHERE ida = :ia AND idm = :im");
    $requete1 -> execute([":ia" => $_GET["ia"], ":im" => $reponse -> idm]);

    $reponse1 = $requete1 ->fetch(PDO::FETCH_OBJ);
    
    $jour = date('y/m/d h:i:s');

    if($reponse1 -> quantite > 0)
    {
        $requete2 = $base->prepare("UPDATE panier SET quantite = :q WHERE ida = :a");
        $requete2 -> execute([":q" => $reponse1 -> quantite + 1, ":a" => $_GET["ia"]]);
    }
    else
    {
        $requete2 = $base->prepare("INSERT INTO panier (idm, ida, quantite,	dates) VALUE (:m, :a, :q, :d)");
        $requete2 -> execute([":m" => $reponse -> idm, ":a" => $_GET["ia"], ":q" => 1, ":d" => $jour ]);
    }
    
    header('Location: ../membre/membres.php');
?>