<?php
    if(!isset($_SESSION['usager'])){
        echo "Oups! Vous devez vous connecter avant";
       // exit;
    }
?>
<!-- Menu de navigation -->
<nav class="navbar navbar-expand-lg navbar-light bg-perso">
    <div class="container-fluid">
        <a class="navbar-brand" href="#">Admin</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav"
            aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
                
                    <a  data-bs-target="#modalConnexion" href="admin.php">
                        <li class="nav-item">Gérer les
                        articles
                        </li>
                    </a>
                    &nbsp; &nbsp; &nbsp;
                    <a   data-bs-target="#modalConnexion" href="MembresCRUD.php" >
                        <li class="nav-item">Gérer les
                        membres
                        </li>
                    </a>
            </ul>
        </div>
    </div>
    <button class="btn btn-danger" onClick="deconnecter();">
        Déconnexion
    </button>
</nav>
<!-- Fin de menu de navigation -->