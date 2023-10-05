<?php 
    try{
        $bdd = new PDO('mysql:host=localhost;dbname=bdboutique','root','');
    }catch(Exception $e){
        die('Erreur ' . $e->getMessage());
    }
    $courriel=$_POST['courriel'];
    $password=$_POST['password'];
    if(!empty($courriel) && !empty($password)){
        $res=$bdd->prepare('SELECT COUNT(*) AS nbre FROM `connexion` WHERE `courriel` = ? AND `password` = ?');
        $res->execute(array($courriel,$password));
        $val = $res->fetch();
        $res->closeCursor();
        if($val['nbre'] == "1"){
            $res=$bdd->prepare('SELECT `statut` FROM `connexion` WHERE `courriel` = ? AND `password` = ?');
            $res->execute(array($courriel,$password));
            $val = $res->fetch();
            $res->closeCursor();
            if($val['statut'] = "M"){
                header('Location:menbre.php');
            }else{
                header('Location:../administrateur/administrateur.php');
            }
        }
        
    }else{
        echo 'erreur';
    }
    
  
?>