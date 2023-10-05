<?php
	$base = new PDO("mysql:host=localhost; dbname=bdboutique", "root", "");

	$idMembre=$_POST['idm_m'];
	$nom=$_POST['nom_m']; 
	$prenom=$_POST['prenom_m'];
	$cour=$_POST['cour_m'];
	$sexe = $_POST['sex_m'];
	$date = $_POST['date_m'];
	
	$requette="UPDATE membres SET nom=:a,prenom=:b,courriel=:c,sexe=:d, datenaissance=:e WHERE idm=:f";
	$stmt = $base->prepare($requette);
	
	
    if($stmt->execute([":a" => $nom, ":b" => $prenom, ":c" => $cour, ":d" => $sexe, ":e" => $date,  ":f" => $idMembre]))
    {
        header('Location: ../admin/MembresCRUD.php?msg=Article+a+été+modifié');
    }
    else
    {
        header('Location: ../admin/MembresCRUD.php?msg=Erreur+de+connexion+à+la+base+de+donnée');
    }
	
?>