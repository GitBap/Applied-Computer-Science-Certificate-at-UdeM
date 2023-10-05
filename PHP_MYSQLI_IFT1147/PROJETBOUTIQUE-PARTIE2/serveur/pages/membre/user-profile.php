<!DOCTYPE html>
<html lang="en">
<head>

  <!-- SITE TITTLE -->
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Classimax</title>
  
  <!-- FAVICON -->
  <link href="img/favicon.png" rel="shortcut icon">
  <!-- PLUGINS CSS STYLE -->
  <!-- <link href="plugins/jquery-ui/jquery-ui.min.css" rel="stylesheet"> -->
  <!-- Bootstrap -->
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


  <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
  <!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
  <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
  <![endif]-->

</head>

<body class="body-wrapper" onLoad="chargerArticles('M','../articles/liste.php');">
	
<!--==================================
=            User Profile            =
===================================-->
            <?php
                $base = new PDO("mysql:host=localhost; dbname=bdboutique","root","");
                session_start();
                //informations utilisateur
                $requete1 = $base->prepare("SELECT * FROM membres WHERE courriel = :c");
                $requete1 -> execute([":c" => $_SESSION['courriel']]);
            
                $reponse1 = $requete1 ->fetch(PDO::FETCH_OBJ);

            ?>
<section class="user-profile section">
	<div class="container">
		<div class="row">
			<div class="col-md-10 offset-md-1 col-lg-3 offset-lg-0">
				<div class="sidebar">
					<!-- User Widget -->
					<div class="widget user">
						<!-- User Image -->
						<div class="image d-flex justify-content-center">
							<img src="../public/images/user/user-thumb.jpg" alt="" class="">
						</div>
						<!-- User Name -->
						<h5 class="text-center"><?php echo $reponse1 -> nom." ". $reponse1 -> prenom;?></h5>
					</div>
					<!-- Dashboard Links -->
					<div class="widget dashboard-links">
						<center><a href="membres.php"><img src="back.png" alt="" class="rounded-circle"></a></center>
					</div>
				</div>
			</div>
			<div class="col-md-10 offset-md-1 col-lg-9 offset-lg-0">
				<!-- Edit Profile Welcome Text -->
				<div class="widget welcome-message">
					<h2>Edit profile</h2>
					<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation</p>
				</div>
				<!-- Edit Personal Info -->
					<div class="widget change-password">
						<h3 class="widget-header user">Edit Password</h3>
						<form class="row g-3" id="formEnreg" action="enregistrerMembres.php"
                            method="POST" onSubmit="return validerFormEnreg();">

                            <!-- File chooser -->
									<input type="file"class="fa fa-user text-center px-3" class="form-control-file mt-2 pt-1" name = "pro" id="input-file">
                                 
  </br>
                            <div class="col-md-4">
                                <label for="prenom" class="form-label">Prénom</label>
                                <input type="text" class="form-control" id="prenom" name="prenom" value="<?php echo $reponse1 -> prenom;?>" required>
                            </div>
                            <div class="col-md-4">
                                <label for="nom" class="form-label">Nom</label>
                                <input type="text" class="form-control" id="nom" name="nom" value="<?php echo $reponse1 -> nom;?>" required>
                            </div>
                            <div class="col-md-4">
                                <label for="courriel" class="form-label">Courriel</label>
                                <input type="email" class="form-control" id="courriel" name="courriel" value=""
                                    required>
                            </div>
                            <div class="col-md-6">
                                <label for="pass" class="form-label">Mot Passe</label>
                                <input type="password" class="form-control" id="pass" name="pass" required>
                            </div>
                            <div class="col-md-6">
                                <label for="cpass" class="form-label">Confirmer mot passe</label>
                                <input type="password" class="form-control" id="cpass" name="cpass" required>
                            </div>
                            <center><span class="msgFormEnreg">Pour des raison statistiques</span></center>
                            <div class="form-check mb-3">
                                <input type="radio" class="form-check-input" id="feminin" value="F" name="sexe">
                                <label class="form-check-label" for="feminin">Féminin</label>
                            </div>
							
                            <div class="form-check mb-3">
                                <input type="radio" class="form-check-input" id="masculin" value="M" name="sexe">
                                <label class="form-check-label" for="masculin">Masculin</label>
                            </div>
  							
                            <div class="col-md-7">
                                <label for="date" class="form-label">Date de naissance</label>
                                <input type="date" class="form-control" id="datenaissance" name="datenaissance" value="<?php echo $reponse1 -> datenaissance;?>">
                            </div>
                            
                            <div class="col-12">
                                <button class="btn btn-primary" type="submit" name="action" value= "<?php echo $reponse1 -> idm;?>">Enregister</button>
                            </div>
					</div>
					</div>
					<div class="col-lg-6 col-md-6">
						
					</div>
				</div>
			</div>
		</div>
	</div>
</section>
  
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

</body>

</html>