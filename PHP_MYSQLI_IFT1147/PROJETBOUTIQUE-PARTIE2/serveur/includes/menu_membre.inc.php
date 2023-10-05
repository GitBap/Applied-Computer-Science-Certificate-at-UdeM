<!-- Menu de navigation -->
<nav class="navbar navbar-expand-lg navbar-light bg-perso">
    <div class="container-fluid">
        <a id="idmt" class="navbar-brand" href="#">Membres</a>

            <?php
                //informations utilisateur
                $requete1 = $base->prepare("SELECT * FROM membres WHERE courriel = :c");
                $requete1 -> execute([":c" => $_SESSION['courriel']]);
            
                $reponse1 = $requete1 ->fetch(PDO::FETCH_OBJ);

            ?>
            <?php

                //nombre d'article dans le panier de l'utilisateur

                $requete2 = $base->prepare("SELECT * FROM panier WHERE idm = :im");
                $requete2 -> execute([":im" => $reponse1 -> idm]);
                $nbr = 0;
                while($reponse2 = $requete2 ->fetch(PDO::FETCH_OBJ))
                {
                    $nbr = $reponse2 -> quantite + $nbr;
                }

                

            ?>

        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
                <li class="nav-item dropdown">
                    <a id="cat" class="nav-link dropdown-toggle" href="#" id="navbarDarkDropdownMenuLink" role="button"
                        data-bs-toggle="dropdown" aria-expanded="false">
                        Catégories
                    </a>
                    <ul id="selCategs" class="dropdown-menu dropdown-menu-dark"
                        aria-labelledby="navbarDarkDropdownMenuLink">
                    </ul>
                </li>
                <li class="nav-item">
                    <a id="pr" class="nav-link" data-bs-toggle="modal" data-bs-target="#modalEnreg" href="#">Profil</a>
                    
                </li>
                <li class="nav-item">

                </li>
            </ul>
            <!-- User Image -->
                    <div>
                        <div class="profile-thumb">
                            <img src="imgM/<?php echo $reponse1 -> idm;?>" alt="" class="rounded-circle">
                        </div>
                    </div>
                    <!-- User Image -->
                    <div>
                        <div>
                            <!-- User Name -->
                            <center><b><?php echo $reponse1 -> nom." ". $reponse1 -> prenom; ?></b></center>
                            <center><p class="text-center"><?php echo date("D M Y");?> </p></center>
                            <center><a class="text-center" href="user-profile.php" class="btn btn-main-sm">Edit Profile</a></center>
                        </div>
                    </div>
        </div>
        

    </div>
<!-- Trigger/Open The Modal -->
<a id="myBtn" class="nav-link" ><i class="bi bi-cart panierPlus"></i></a><?php echo "(".$nbr.")" ?>

<!-- The Modal -->
<div id="myModal" class="modal">

  <!-- Modal content -->
  <div class="modal-content">
    <span class="close">&times;</span>
    <p>
    <div class="card">
            <div class="row">
                <div class="col-md-8">
                    <div class="title">
                        <div class="row">
                            <div class="col">
                                <h4><b>Panier d'achats</b></h4>
                            </div>
                            <div class="col align-self-center text-right text-muted"><?php echo $nbr;?> articles</div>
                        </div>
                    </div>
                    <div class="row border-top border-bottom">
                        <?php
                        $requete3 = $base->prepare("SELECT * FROM panier INNER JOIN articles ON articles.ida = panier.ida WHERE panier.idm = :im");
                        $requete3 -> execute([":im" => $reponse1 -> idm]);
                        $total = 0;
                        while($reponse3 = $requete3 ->fetch(PDO::FETCH_OBJ))
                        {
                        ?>
                        <div class="row align-items-center">
                            <div class="col-2"><img class="img-fluid" src="../../../client/public/images/products/<?php echo $reponse3 -> ida;?>"/></div>
                            <div class="col">
                                <div class="row text-muted"><?php echo $reponse3 -> nomarticle ;?></div>
                            </div>
                            <div class="col"> <?php echo "qté: ".$reponse3 -> quantite ;?></div>
                            <div class="col"><?php echo "P.U: ".$reponse3 -> prix ." €" ;?></div>
                            <div class="col"><?php echo "T = ".$reponse3 -> prix * $reponse3 -> quantite ." €" ;?></div>
                            <div class="col"><div class="close closeBtn" onClick="enleverArticle(this,${unArticle.ida});">&#10005;</div></div>
                        </div>
                        <?php
                            $total = $total+$reponse3 -> prix * $reponse3 -> quantite;
                        }?>
                    </div>
                    </div>
                    <div class="col-md-4 bg-info text-dark">
                        <div>
                            <h5><b>Facture</b></h5>
                        </div>
                        <hr>
                        <br/>
                        <div class="row">
                            <div class="col" style="padding-left:10;"><?php echo $nbr." " ;?> ARTICLES</div>
                            <div id="totalAchat" class="col text-right"><?php echo $total." €" ;?></div>
                        </div>
                        <br/>
                        <div class="row">
                            <div class="col" style="padding-left:10;">MONTANT TAXES</div>
                            <div id="idTaxes" class="col text-right">${montantTaxes.toFixed(2)}$</div>
                        </div>
                        <br/>
                        <div class="row">
                            <div class="col" style="padding-left:10;">MONTANT À PAYER</div>
                            <div id="totalPayer" class="col text-right">${totalPayer.toFixed(2)}$</div>
                        </div> 
                        </br>
                        <button class="btn btn-dark" onclick="payer();">PAYER</button>
                        <span id="payer"></span>
                        <br/> 
                    </div>
                </div>
            </div>

    </p>
  </div>

</div>

<script>
// Get the modal
var modal = document.getElementById("myModal");

// Get the button that opens the modal
var btn = document.getElementById("myBtn");

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal 
btn.onclick = function() {
  modal.style.display = "block";
}

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
  modal.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}
</script>





    
    <a id="bdc" class="nav-link" onClick="deconnecter();"><i class="bi bi-forward-fill deconnexion"></i></a>
    <a id="bdc" class="nav-link" onClick="deconnecter();"><i class="fa fa-sign-out fa-2x" aria-hidden="true"></i></a>
</nav>
<!-- Fin de menu de navigation -->