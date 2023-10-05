<?php
  $base = new PDO("mysql:host=localhost; dbname=bdboutique","root","");
    session_start();    
    if(!isset($_SESSION['usager'])){
        header('Location: ../../../index.php?msg=Problème+avec+votre+connexion');
        exit;
    }


    
    
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin</title>
    <script src="../../../client/utilitaires/jquery-3.6.0.min.js"></script>
    <script src="../../../client/utilitaires/bootstrap-5.1.3-dist/js/bootstrap.min.js"></script>
    <script src="../../../client/public/js/monJS.js"></script>
    <script src="../../../client/public/js/requetes.js"></script>
    <link rel="stylesheet" href="../../../client/utilitaires/bootstrap-5.1.3-dist/css/bootstrap.min.css">
    <link rel="stylesheet"  href="../../../client/utilitaires/icons-1.8.1/bootstrap-icons.css">
    <link rel="stylesheet" href="../../../client/public/css/style.css">


    <link rel="stylesheet" href="../utilitaires/plugins/bootstrap/css/bootstrap.min.css">
  <link rel="stylesheet" href="../utilitaires/plugins/bootstrap/css/bootstrap-slider.css">
  <!-- Font Awesome -->
  <link href="../utilitaires/plugins/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <!-- Owl Carousel -->
  <link href="../utilitaires/plugins/slick-carousel/slick/slick.css" rel="stylesheet">
  <link href="../utilitaires/plugins/slick-carousel/slick/slick-theme.css" rel="stylesheet">
  <!-- Fancy Box -->
  <link href="../utilitaires/plugins/fancybox/jquery.fancybox.pack.css" rel="stylesheet">
  <link href="../utilitaires/plugins/jquery-nice-select/css/nice-select.css" rel="stylesheet">
  <!-- CUSTOM CSS -->
  <link href="../public/css/style.css" rel="stylesheet">


  <meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Arial, Helvetica, sans-serif;}

/* The Modal (background) */
.modal {
  display: none; /* Hidden by default */
  position: fixed; /* Stay in place */
  z-index: 1; /* Sit on top */
  padding-top: 100px; /* Location of the box */
  left: 0;
  top: 0;
  width: 100%; /* Full width */
  height: 100%; /* Full height */
  overflow: auto; /* Enable scroll if needed */
  background-color: rgb(0,0,0); /* Fallback color */
  background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
}

/* Modal Content */
.modal-content {
  background-color: #fefefe;
  margin: auto;
  padding: 20px;
  border: 1px solid #888;
  width: 80%;
}

/* The Close Button */
.close {
  color: #aaaaaa;
  float: right;
  font-size: 28px;
  font-weight: bold;
}

.close:hover,
.close:focus {
  color: #000;
  text-decoration: none;
  cursor: pointer;
}
</style>

</head>
<body onLoad="chargerArticles('I','../articles/liste.php');">
    <?php
         require_once("../../includes/menu_membre.inc.php");
    ?>
    
     <br><br><br>
  <div class="container" id="contenu"></div>
  <!-- Modal du panier -->
  <div class="modal fade" id="idModPanier" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-xl">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
        <div id="contenuPanier"></div>
      </div>
    </div>
  </div>
</div>
 <!-- Fin du modal du panier -->
  <form id="dc" action="../connexion/deconnecter.php" method="POST"></form>
  <script src="../../../client/public/js/panier.js"></script>

<?php
$requete = $base->prepare("SELECT * FROM articles");
$requete -> execute();

while($reponse = $requete ->fetch(PDO::FETCH_OBJ))
{
?>
						<!-- product card -->
<div class="col-sm-12 col-lg-3">
	<div class="card">

  <center>
        <div class="thumb-content">
          <!-- <div class="price">$200</div> -->
          <a href="client/pages/single.html">
            <img class="card-img-top img-fluid" src="../../../client/public/images/products/<?php echo $reponse -> ida;?>" alt="Card image cap">
          </a>
        </div>

        <div class="card-body">
          <h4 class="card-title"><a href="client/pages/single.html"><?php  echo $reponse -> nomarticle;   ?></a></h4>
          <p class="card-text"><b>Description:</b> <?php  echo $reponse -> description;    ?></p>
          <div class="product-ratings">
            <p class="card-text"><b>Prix :</b> <?php  echo $reponse -> prix." €";    ?></p>
		      </div>
    </center>
          <div align="rigth">
            <a href="../articles/article.php?ia=<?php echo $reponse -> ida; ?>"><i class="fa fa-cart-plus fa-2x"></i></a>
          </div>
		</div>

</div>
<?php
}
?>

  <!-- JAVASCRIPTS -->
<script src="../utilitaires/plugins/jQuery/jquery.min.js"></script>
<script src="../utilitaires/plugins/bootstrap/js/popper.min.js"></script>
<script src="../utilitaires/plugins/bootstrap/js/bootstrap.min.js"></script>
<script src="../utilitaires/plugins/bootstrap/js/bootstrap-slider.js"></script>
  <!-- tether js -->
<script src="../utilitaires/plugins/tether/js/tether.min.js"></script>
<script src="../utilitaires/plugins/raty/jquery.raty-fa.js"></script>
<script src="../utilitaires/plugins/slick-carousel/slick/slick.min.js"></script>
<script src="../utilitaires/plugins/jquery-nice-select/js/jquery.nice-select.min.js"></script>
<script src="../utilitaires/plugins/fancybox/jquery.fancybox.pack.js"></script>
<script src="../utilitaires/plugins/smoothscroll/SmoothScroll.min.js"></script>
<!-- google map -->
<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCcABaamniA6OL5YvYSpB3pFMNrXwXnLwU&libraries=places"></script>
<script src="../utilitaires/plugins/google-map/gmap.js"></script>
<script src="../public/js/script.js"></script>
</html>