<?php 
    try{
        $bdd = new PDO('mysql:host=localhost;dbname=bdboutique','root','');
    }catch(Exception $e){
        die('Erreur ' . $e->getMessage());
    }
    $prenom=$_POST['prenom'];
    $nom=$_POST['nom'];
    $courriel=$_POST['courriel'];
    $password=$_POST['password'];
    $sexe=$_POST['sexe'];
    $naissance=$_POST['naiss'];
    $req = $bdd->query('SELECT Idm FROM menbres ORDER BY Idm DESC LIMIT 1');
    $dernier = $req->fetch();
    $req->closeCursor();
    if(!empty($dernier) && !empty($prenom) && !empty($nom) && !empty($courriel) && !empty($password) && !empty($sexe) && !empty($naissance)){
        $id = (int)$dernier['Idm'] += 1;
        $res=$bdd->prepare('INSERT INTO `menbres`(`Idm`,`nom`, `prenom`, `courriel`, `sexe`, `date_naiss`) VALUES (?,?,?,?,?,?)');
        $res->execute(array($id,$nom,$prenom,$courriel,$sexe,$naissance));
        $resl=$bdd->prepare('INSERT INTO `connexion`(`Idcm`, `courriel`, `password`, `role`, `statut`) VALUES (?,?,?,?,?)');
        $resl->execute(array($id,$courriel,$password,'M','A'));
        header('Location:../../../index.php');
    }
    
  
?>