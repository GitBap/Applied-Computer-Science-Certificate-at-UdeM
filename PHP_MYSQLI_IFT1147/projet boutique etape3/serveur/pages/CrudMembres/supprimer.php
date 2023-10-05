<?php
	require_once("../../includes/configbd.inc.php");
    $base = new PDO("mysql:host=localhost; dbname=bdboutique", "root", "");
	$idMembre=$_POST['idmre'];	
	$requete="SELECT * FROM connexion WHERE idm=:a";
	$stmt = $base->prepare($requete);
	$stmt->execute([":a" => $idMembre]);
    if($reponse = $stmt -> fetch(PDO::FETCH_OBJ))
    {
        if($reponse -> statut == "I")
        {
            $requete="UPDATE connexion SET statut='A' WHERE idm=?";
        }
        else
        {
            $requete="UPDATE connexion SET statut='I' WHERE idm=?";
        }
    }
    else{
        header('Location: ../admin/MembresCRUD.php?.php?msg=ce+Membre+est+introuvable');
		exit;
    }
    
	
	$stmt = $connexion->prepare($requete);
	$stmt->bind_param("i", $idMembre);
	
    if($stmt->execute())
    {
        
        header('Location: ../admin/MembresCRUD.php?msg=le+Membre+est+maintenant+Inactif');
    }
	mysqli_close($connexion);
	
	exit;
?>