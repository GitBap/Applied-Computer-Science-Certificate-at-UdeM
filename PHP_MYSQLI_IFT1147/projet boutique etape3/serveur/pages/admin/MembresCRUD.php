<?php
session_start();
if (!isset($_SESSION['usager'])) {
    header('Location: ../../../index.php?msg=Problème+avec+votre+connexion');
    exit;
}
if (isset($_GET['msg'])) {
    $msg = $_GET['msg'];
}
else {
    $msg = null;
}
?>
<!-- Basé sur le modèle
    https://www.tutorialrepublic.com/snippets/preview.php?topic=bootstrap&file=crud-data-table-for-database-with-modal-form
    -->
<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Admin</title>
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto|Varela+Round">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
    <script type="text/javascript" src="../../../client/utilitaires/jquery-3.6.0.min.js"></script>
    <script type="text/javascript" src="../../../client/utilitaires/bootstrap-5.1.3-dist/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="../../../client/public/js/requetes.js"></script>
    <script type="text/javascript" src="../../../client/public/js/jquery.twbsPagination.min.js"></script>
    <script type="text/javascript" src="../../../client/public/js/CrudMembres.js"></script>
    <script type="text/javascript" src="../../../client/public/js/monJS.js"></script>
    <script type="text/javascript" src="../../../client/public/js/enleverMultiplesArticles.js"></script>
    <link rel="stylesheet" href="../../../client/utilitaires/bootstrap-5.1.3-dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="../../../client/utilitaires/icons-1.8.1/bootstrap-icons.css">
    <link rel="stylesheet" href="../../../client/public/css/admin.css">
    <link rel="stylesheet" href="../../../client/public/css/style.css">
</head>

<body  onLoad='initialiser(<?php echo "\"" . $msg . "\""; ?>);chargerArticles("A","../articles/liste.php"); initialisation()'>
    <?php
require_once("../../includes/menu_admin.inc.php");
?>
    <div id='contenu' onload="menuHide()"></div>
    <div class="container-xl">
        <div class="table-responsive">
            <div class="table-wrapper">
                <div class="table-title">
                    <div class="row">
                        <center><div class="">
                            <h2>Gestion des membres de la Boutique</h2>
                        </div></center>
                        
                        
                    </div>
                </div>
                <table id = "tableau" class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>
                                <span class="custom-checkbox">
                                    <input type="checkbox" id="selectAll" onclick="checkAll()">
                                    <label for="selectAll"></label>
                                </span>
                            </th>
                            <th>Numéro</th>
                            <th>Nom</th>
                            <th>Prenom</th>
                            <th>Courriel</th>
                            <th>Sexe</th>
                            <th>Date de nissance</th>
                        </tr>
                    </thead>
                    <tbody id="emp_body3" >
                    </tbody>
                    <tfooter>
                        <tr>
                            <th colspan="11"> 
                                <div id="pager">
                                    <ul id="pagination" class="pagination-sm"></ul>
                                </div>
                            </th>
                        </tr>
                    </tfooter> 
            </table>

        </div>
    </div>
    </div>
    
    
    <!-- Delete Modal HTML -->
    <div class="modal fade" id="supprimerMembreModal" tabindex="-1" aria-labelledby="exampleModalLabel"
        aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="exampleModalLabel">Confirmation</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <p>Êtes-vous sûr que vous voulez désactiver ce membre ?</p>

                    <input type="button" class="btn btn-default" data-bs-dismiss="modal" value="Annuler">
                    <input type="button" onClick="supprimer2();" class="btn btn-danger" value="Désactiver">


                </div>
            </div>
        </div>
    </div>

    <div class="modal fade" id="supprimerMembreModal1" tabindex="-1" aria-labelledby="exampleModalLabel"
        aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="exampleModalLabel">Confirmation</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <p>Êtes-vous sûr que vous voulez Réactiver ce membre ?</p>

                    <input type="button" class="btn btn-default" data-bs-dismiss="modal" value="Annuler">
                    <input type="button" onClick="supprimer2();" class="btn btn-danger" value="Réactiver">


                </div>
            </div>
        </div>
    </div>
    <!-- Formulaires -->

    <form id="formEnlever2" action="../CrudMembres/supprimer.php" method="POST">
        <input type="hidden" id="idmre" name="idmre" value="">
    </form>

    <form id="formulaire1" action="../articles/enleverMultiples.php" method="POST">
        <input type="hidden" id="idaM" name="idaM" value="">
    </form>

    <div class="toast-container posToast">
        <div id="toast" class="toast  align-items-center text-white bg-danger border-0" data-bs-autohide="false"
            role="alert" aria-live="assertive" aria-atomic="true">
            <div class="toast-header">
                <img src="../../../client/public/images/message.png" width=24 height=24 class="rounded me-2"
                    alt="message">
                <strong class="me-auto">Messages</strong>
                <small class="text-muted"></small>
                <button type="button" class="btn-close" data-bs-dismiss="toast" aria-label="Close"></button>
            </div>
            <div id="textToast" class="toast-body">
                <!-- texte du Toast -->
            </div>
        </div>
    </div>
    <form id="dc" action="../connexion/deconnecter.php" method="POST"></form>
</body>

</html>