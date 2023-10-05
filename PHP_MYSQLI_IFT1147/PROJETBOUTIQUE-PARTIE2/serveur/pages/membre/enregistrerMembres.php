<?php
    session_start();
    require_once("../../includes/configbd.inc.php");

    if(array_key_exists("action", $_POST))
    {
        if(isset($_POST["action"]))
        {
            $prenom = $_POST['prenom'];
            $nom = $_POST['nom'];
            $courriel = $_POST['courriel'];
            $pass = $_POST['pass'];
            $sexe = $_POST['sexe'];
            $datenaissance = $_POST['datenaissance'];
            $id = $_POST["action"];
            $link = $_POST["pro"];

            $requete = "UPDATE membres SET prenom = ?, nom = ?, courriel = ?, sexe = ?, datenaissance = ? WHERE idm = ?";
            $stmt = $connexion->prepare($requete);
            $stmt->bind_param("sssssi", $prenom,$nom,$courriel,$sexe,$datenaissance, $id);
            $stmt->execute();

            $requete = "UPDATE connexion SET courriel = ?, pass = ? WHERE idm = ?";
            $stmt = $connexion->prepare($requete);
            $stmt->bind_param("ssi", $courriel,$pass,$id);
            $stmt->execute();
            mysqli_close($connexion);
            //copy($link, "imgM/".$id.".png");
            header('Location:../../../index.php');
            exit;
        }
    }
    
    $prenom = $_POST['prenom'];
    $nom = $_POST['nom'];
    $courriel = $_POST['courriel'];
    $pass = $_POST['pass'];
    $sexe = $_POST['sexe'];
    $datenaissance = $_POST['datenaissance'];

    $requete = "INSERT INTO membres VAlUES (0,?,?,?,?,?)";
    $stmt = $connexion->prepare($requete);
    $stmt->bind_param("sssss", $prenom,$nom,$courriel,$sexe,$datenaissance);
    $stmt->execute();
    $idm = $connexion->insert_id;

    $requete = "INSERT INTO connexion VAlUES (?,?,?,'M','A')";
    $stmt = $connexion->prepare($requete);
    $stmt->bind_param("iss", $idm,$courriel,$pass);
    $stmt->execute();
    mysqli_close($connexion);
    header('Location:../../../index.php');
    exit;
?>