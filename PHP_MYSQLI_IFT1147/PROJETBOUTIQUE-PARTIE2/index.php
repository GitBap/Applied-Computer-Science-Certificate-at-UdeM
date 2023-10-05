<?php
  session_start();
?>
<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="client/utilitaires/jquery-3.6.0.min.js"></script>
    <script src="client/utilitaires/bootstrap-5.1.3-dist/js/bootstrap.min.js"></script>
    <script src="client/public/js/monJS.js"></script>
    <script src="client/public/js/requetes.js"></script>
    <script src="client/public/js/langues.js"></script>
    <link rel="stylesheet" href="client/utilitaires/icons-1.8.1/bootstrap-icons.css">
    <link rel="stylesheet" href="client/public/css/style.css">
  <!-- Bootstrap -->
  <link rel="stylesheet" href="client/utilitaires/bootstrap/css/bootstrap.min.css">
  <link rel="stylesheet" href="client/utilitaires/bootstrap/css/bootstrap-slider.css">
  <!-- Font Awesome -->
  <link href="client/utilitaires/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <!-- Owl Carousel -->
  <link href="client/utilitaires/slick-carousel/slick/slick.css" rel="stylesheet">
  <link href="client/utilitaires/slick-carousel/slick/slick-theme.css" rel="stylesheet">
  <!-- Fancy Box -->
  <link href="client/utilitaires/fancybox/jquery.fancybox.pack.css" rel="stylesheet">
  <link href="client/utilitaires/jquery-nice-select/css/nice-select.css" rel="stylesheet">
  <!-- CUSTOM CSS -->
  <link href="client/public/css/style1.css" rel="stylesheet">
    <title id="titre"></title>
</head>

<body onLoad="chargerArticles('I','serveur/pages/articles/liste.php');">
    <?php
      include_once('serveur/includes/menu_accueil.inc.php');
  ?>
    <br>
    Catégories
    <select id="categ" onChange="alert(this.options[this.selectedIndex].text);">
    </select>
    <div class="container" id="contenu"></div>

    <!-- Fin de menu de navigation -->
    <div class="container">
        <!-- Modal Enregistrer -->
        <div class="modal fade" id="modalEnreg" tabindex="-1" aria-labelledby="ModalEnregLabel" aria-hidden="true">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="ModalEnregLabel">Nouveau membre</h5>
                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                        <form class="row g-3" id="formEnreg" action="serveur/pages/membre/enregistrerMembres.php"
                            method="POST" onSubmit="return validerFormEnreg();">
                            <div class="col-md-4">
                                <label for="prenom" class="form-label">Prénom</label>
                                <input type="text" class="form-control" id="prenom" name="prenom" value="" required>
                            </div>
                            <div class="col-md-4">
                                <label for="nom" class="form-label">Nom</label>
                                <input type="text" class="form-control" id="nom" name="nom" value="" required>
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
                            <span class="msgFormEnreg">Pour des raison statistiques</span>
                            <div class="form-check mb-3">
                                <input type="radio" class="form-check-input" id="feminin" value="F" name="sexe">
                                <label class="form-check-label" for="feminin">Féminin</label>
                            </div>
                            <div class="form-check mb-3">
                                <input type="radio" class="form-check-input" id="masculin" value="M" name="sexe">
                                <label class="form-check-label" for="masculin">Masculin</label>
                            </div>
                            <div class="col-md-6">
                                <label for="date" class="form-label">Date de naissance</label>
                                <input type="date" class="form-control" id="datenaissance" name="datenaissance">
                            </div>
                            <div class="col-12">
                                <button class="btn btn-primary" type="submit">Enregister</button>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <!-- Modal Connexion -->
        <div class="modal fade" id="modalConnexion" tabindex="-1" aria-labelledby="ModalConnexionLabel"
            aria-hidden="true">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="ModalConnexionLabel">Connexion</h5>
                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                        <form class="row g-3" id="formConnexion" action="serveur/pages/connexion/connexion.php"
                            method="POST">
                            <div class="col-md-4">
                                <label for="courriel" class="form-label">Courriel</label>
                                <input type="email" class="form-control" id="courrielc" name="courrielc" value=""
                                    required>
                            </div>
                            <div class="col-md-6">
                                <label for="pass" class="form-label">Mot Passe</label>
                                <input type="password" class="form-control" id="passc" name="passc" required>
                            </div>
                            <div class="col-12">
                                <button class="btn btn-primary" type="submit">Connexion</button>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <!--===============================
=            Hero Area            =
================================-->

<section class="hero-area bg-1 text-center overly">
	<!-- Container Start -->
	<div class="container">
		<div class="row">
			<div class="col-md-12">
				<!-- Header Contetnt -->
				<div class="content-block">
					<h1>Acheter & Vendre Pres de chez Vous </h1>
					<p>Rejoignez les millions qui achètent et vendent les uns des autres <br> tous les jours dans les communautés locales à travers le monde</p>
					<div class="short-popular-category-list text-center">
						<h2>Catégorie populaire</h2>
						<ul class="list-inline">
							<li class="list-inline-item">
								<a href="client/pages/category.html"><i class="fa fa-bed"></i>Hôtel</a></li>
							<li class="list-inline-item">
								<a href="client/pages/category.html"><i class="fa fa-grav"></i>Aptitude</a>
							</li>
							<li class="list-inline-item">
								<a href="client/pages/category.html"><i class="fa fa-car"></i> Voitures</a>
							</li>
							<li class="list-inline-item">
								<a href="client/pages/category.html"><i class="fa fa-cutlery"></i> Restaurants</a>
							</li>
							<li class="list-inline-item">
								<a href="client/pages/category.html"><i class="fa fa-coffee"></i> Cafe</a>
							</li>
						</ul>
					</div>
					
				</div>
				<!-- Advance Search -->
				<div class="advance-search">
						<div class="container">
							<div class="row justify-content-center">
								<div class="col-lg-12 col-md-12 align-content-center">
										<form>
											<div class="form-row">
												<div class="form-group col-md-4">
													<input type="text" class="form-control my-2 my-lg-1" id="inputtext4" placeholder="Que cherchez-vous">
												</div>
												<div class="form-group col-md-3">
													<select class="w-100 form-control mt-lg-1 mt-md-2">
														<option>Catégorie</option>
														<option value="1">Les mieux notés</option>
														<option value="2">Prix ​​le plus bas</option>
														<option value="4">Prix ​​le plus haut</option>
													</select>
												</div>
												<div class="form-group col-md-3">
													<input type="text" class="form-control my-2 my-lg-1" id="inputLocation4" placeholder="Location">
												</div>
												<div class="form-group col-md-2 align-self-center">
													<button type="submit" class="btn btn-primary">
														Rechercher</button>
												</div>
											</div>
										</form>
									</div>
								</div>
					</div>
				</div>
				
			</div>
		</div>
	</div>
	<!-- Container End -->
</section>

<!--===================================
=            Client Slider            =
====================================-->


<!--===========================================
=            Popular deals section            =
============================================-->

<section class="popular-deals section bg-gray">
	<div class="container">
		<div class="row">
			<div class="col-md-12">
				<div class="section-title">
					<h2>Ajouts tendance</h2>
					<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quas, magnam.</p>
				</div>
			</div>
		</div>
		<div class="row">
			<!-- offer 01 -->
			<div class="col-lg-12">
				<div class="trending-ads-slide">
					<div class="col-sm-12 col-lg-4">
						<!-- product card -->
<div class="product-item bg-light">
	<div class="card">
		<div class="thumb-content">
			<!-- <div class="price">$200</div> -->
			<a href="client/pages/single.html">
				<img class="card-img-top img-fluid" src="client/public/images/products/products-1.jpg" alt="Card image cap">
			</a>
		</div>
		<div class="card-body">
		    <h4 class="card-title"><a href="client/pages/single.html">11inch Macbook Air</a></h4>
		    <ul class="list-inline product-meta">
		    	<li class="list-inline-item">
		    		<a href="client/pages/single.html"><i class="fa fa-folder-open-o"></i>Electronic</a>
		    	</li>
		    	<li class="list-inline-item">
		    		<a href="#"><i class="fa fa-calendar"></i>26 Decembre</a>
		    	</li>
		    </ul>
		    <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Explicabo, aliquam!</p>
		    <div class="product-ratings">
		    	<ul class="list-inline">
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item"><i class="fa fa-star"></i></li>
		    	</ul>
		    </div>
		</div>
	</div>
</div>



					</div>
					<div class="col-sm-12 col-lg-4">
						<!-- product card -->
<div class="product-item bg-light">
	<div class="card">
		<div class="thumb-content">
			<!-- <div class="price">$200</div> -->
			<a href="client/pages/single.html">
				<img class="card-img-top img-fluid" src="client/public/images/products/products-2.jpg" alt="Card image cap">
			</a>
		</div>
		<div class="card-body">
		    <h4 class="card-title"><a href="client/pages/single.html">Combo table d'étude complète</a></h4>
		    <ul class="list-inline product-meta">
		    	<li class="list-inline-item">
		    		<a href="client/pages/single.html"><i class="fa fa-folder-open-o"></i>Meubles</a>
		    	</li>
		    	<li class="list-inline-item">
		    		<a href="#"><i class="fa fa-calendar"></i>26 Decembre</a>
		    	</li>
		    </ul>
		    <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Explicabo, aliquam!</p>
		    <div class="product-ratings">
		    	<ul class="list-inline">
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item"><i class="fa fa-star"></i></li>
		    	</ul>
		    </div>
		</div>
	</div>
</div>



					</div>
					<div class="col-sm-12 col-lg-4">
						<!-- product card -->
<div class="product-item bg-light">
	<div class="card">
		<div class="thumb-content">
			<!-- <div class="price">$200</div> -->
			<a href="client/pages/single.html">
				<img class="card-img-top img-fluid" src="client/public/images/products/products-3.jpg" alt="Card image cap">
			</a>
		</div>
		<div class="card-body">
		    <h4 class="card-title"><a href="client/pages/single.html">11inch Macbook Air</a></h4>
		    <ul class="list-inline product-meta">
		    	<li class="list-inline-item">
		    		<a href="client/pages/single.html"><i class="fa fa-folder-open-o"></i>Electronic</a>
		    	</li>
		    	<li class="list-inline-item">
		    		<a href="#"><i class="fa fa-calendar"></i>26 Decembre</a>
		    	</li>
		    </ul>
		    <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Explicabo, aliquam!</p>
		    <div class="product-ratings">
		    	<ul class="list-inline">
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item"><i class="fa fa-star"></i></li>
		    	</ul>
		    </div>
		</div>
	</div>
</div>



					</div>
					<div class="col-sm-12 col-lg-4">
						<!-- product card -->
<div class="product-item bg-light">
	<div class="card">
		<div class="thumb-content">
			<!-- <div class="price">$200</div> -->
			<a href="client/pages/single.html">
				<img class="card-img-top img-fluid" src="client/public/images/products/products-2.jpg" alt="Card image cap">
			</a>
		</div>
		<div class="card-body">
		    <h4 class="card-title"><a href="client/pages/single.html">Combo table d'étude complète</a></h4>
		    <ul class="list-inline product-meta">
		    	<li class="list-inline-item">
		    		<a href="client/pages/single.html"><i class="fa fa-folder-open-o"></i>Fournitures</a>
		    	</li>
		    	<li class="list-inline-item">
		    		<a href="#"><i class="fa fa-calendar"></i>26 Decembre</a>
		    	</li>
		    </ul>
		    <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Explicabo, aliquam!</p>
		    <div class="product-ratings">
		    	<ul class="list-inline">
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item selected"><i class="fa fa-star"></i></li>
		    		<li class="list-inline-item"><i class="fa fa-star"></i></li>
		    	</ul>
		    </div>
		</div>
	</div>
</div>



					</div>
				</div>
			</div>
			
			
		</div>
	</div>
</section>



<!--==========================================
=            All Category Section            =
===========================================-->

<section class=" section">
	<!-- Container Start -->
	<div class="container">
		<div class="row">
			<div class="col-12">
				<!-- Section title -->
				<div class="section-title">
					<h2>Toutes les Categories</h2>
					<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Perferendis, provident!</p>
				</div>
				<div class="row">
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-laptop icon-bg-1"></i> 
								<h4>Electronique</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Laptops <span>93</span></a></li>
								<li><a href="client/pages/category.html">Iphone <span>233</span></a></li>
								<li><a href="client/pages/category.html">Microsoft  <span>183</span></a></li>
								<li><a href="client/pages/category.html">Ecran <span>343</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-apple icon-bg-2"></i> 
								<h4>Restaurants</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Café <span>393</span></a></li>
								<li><a href="client/pages/category.html">Fast food <span>23</span></a></li>
								<li><a href="client/pages/category.html">Restaurants  <span>13</span></a></li>
								<li><a href="client/pages/category.html">Piste alimentaire<span>43</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-home icon-bg-3"></i> 
								<h4>Immobilier</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Fermes <span>93</span></a></li>
								<li><a href="client/pages/category.html">Gym <span>23</span></a></li>
								<li><a href="client/pages/category.html"> Hôpitaux  <span>83</span></a></li>
								<li><a href="client/pages/category.html">Parolures <span>33</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-shopping-basket icon-bg-4"></i> 
								<h4>Shoppings</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Chemises hommes <span>53</span></a></li>
								<li><a href="client/pages/category.html">Accessoires <span>212</span></a></li>
								<li><a href="client/pages/category.html">Chemise femmes <span>133</span></a></li>
								<li><a href="client/pages/category.html">Informatique et logiciels <span>143</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-briefcase icon-bg-5"></i> 
								<h4>Emploies</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Secretaire bureautique <span>93</span></a></li>
								<li><a href="client/pages/category.html">Nettoyage et Lavage <span>233</span></a></li>
								<li><a href="client/pages/category.html">Management  <span>183</span></a></li>
								<li><a href="client/pages/category.html">Voluntaire <span>343</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-car icon-bg-6"></i> 
								<h4>Véhicules</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Bus <span>193</span></a></li>
								<li><a href="client/pages/category.html">Voitures <span>23</span></a></li>
								<li><a href="client/pages/category.html">motos  <span>33</span></a></li>
								<li><a href="client/pages/category.html"> Louer une voiture<span>73</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							<div class="header">
								<i class="fa fa-paw icon-bg-7"></i> 
								<h4>Animaux domestiques</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Chats <span>65</span></a></li>
								<li><a href="client/pages/category.html">Chien <span>23</span></a></li>
								<li><a href="client/pages/category.html">Oiseau  <span>113</span></a></li>
								<li><a href="client/pages/category.html">Autres <span>43</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					<!-- Category list -->
					<div class="col-lg-3 offset-lg-0 col-md-5 offset-md-1 col-sm-6 col-6">
						<div class="category-block">
							
							<div class="header">
								<i class="fa fa-laptop icon-bg-8"></i> 
								<h4>Services</h4>
							</div>
							<ul class="category-list" >
								<li><a href="client/pages/category.html">Nettoyage <span>93</span></a></li>
								<li><a href="client/pages/category.html">Lavage de voitures <span>233</span></a></li>
								<li><a href="client/pages/category.html">Vêtements  <span>183</span></a></li>
								<li><a href="client/pages/category.html">Business <span>343</span></a></li>
							</ul>
						</div>
					</div> <!-- /Category List -->
					
					
				</div>
			</div>
		</div>
	</div>
	<!-- Container End -->
</section>


<!--====================================
=            Call to Action            =
=====================================-->

<section class="call-to-action overly bg-3 section-sm">
	<!-- Container Start -->
	<div class="container">
		<div class="row justify-content-md-center text-center">
			<div class="col-md-8">
				<div class="content-holder">
					<h2>Commencez dès aujourd'hui pour obtenir plus d'exposition et
						développer votre entreprise</h2>
					<ul class="list-inline mt-30">
						<li class="list-inline-item"><a class="btn btn-main" href="client/pages/ad-listing.html">Ajouter une annonce</a></li>
						<li class="list-inline-item"><a class="btn btn-secondary" href="client/pages/category.html">Liste des produits</a></li>
					</ul>
				</div>
			</div>
		</div>
	</div>
	<!-- Container End -->
</section>

<!--============================
=            Footer            =
=============================-->

<footer class="footer section section-sm">
  <!-- Container Start -->
  <div class="container">
    <div class="row">
      <div class="col-lg-3 col-md-7 offset-md-1 offset-lg-0">
        <!-- About -->
        <div class="block about">
          <!-- footer logo -->
          <img src="client/publicimages/logo-footer.png" alt="">
          <!-- description -->
          <p class="alt-color">Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor
            incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco
            laboris nisi ut aliquip ex ea commodo consequat.</p>
        </div>
      </div>
      <!-- Link list -->
      <div class="col-lg-2 offset-lg-1 col-md-3">
        <div class="block">
          <h4>Pages du site</h4>
          <ul>
            <li><a href="#">Boston</a></li>
            <li><a href="#">Comment ça fonctionne</a></li>
            <li><a href="#">Offres et coupons</a></li>
            <li><a href="#">Articles et astuces</a></li>
            <li><a href="client/pages/terms-condition.html">
				termes et conditions</a></li>
          </ul>
        </div>
      </div>
      <!-- Link list -->
      <div class="col-lg-2 col-md-3 offset-md-1 offset-lg-0">
        <div class="block">
          <h4>Pages Administrateur</h4>
          <ul>
            <li><a href="client/pages/category.html">Categories</a></li>
            <li><a href="client/pages/single.html">Une seule page</a></li>
            <li><a href="client/pages/store.html">Magasin Unique</a></li>
            <li><a href="client/pages/single-blog.html">Message unique</a>
            </li>
            <li><a href="client/pages/blog.html">Blog</a></li>



          </ul>
        </div>
      </div>
      <!-- Promotion -->
      <div class="col-lg-4 col-md-7">
        <!-- App promotion -->
        <div class="block-2 app-promotion">
          <div class="mobile d-flex">
            <a href="">
              <!-- Icon -->
              <img src="client/public/images/footer/phone-icon.png" alt="mobile-icon">
            </a>
            <p>Obtenez l'application mobile Dealsy et économisez davantage</p>
          </div>
          <div class="download-btn d-flex my-3">
            <a href="#"><img src="client/public/images/apps/google-play-store.png" class="img-fluid" alt=""></a>
            <a href="#" class=" ml-3"><img src="client/public/images/apps/apple-app-store.png" class="img-fluid" alt=""></a>
          </div>
        </div>
      </div>
    </div>
  </div>
  <!-- Container End -->
</footer>
<!-- Footer Bottom -->
<footer class="footer-bottom">
  <!-- Container Start -->
  <div class="container">
    <div class="row">
      <div class="col-sm-6 col-12">
        <!-- Copyright -->
        <div class="copyright">
          <p>Copyright © <script>
              var CurrentYear = new Date().getFullYear()
              document.write(CurrentYear)
            </script>. All Rights Reserved, theme by <a class="text-primary" href="https://themefisher.com" target="_blank">themefisher.com</a></p>
        </div>
      </div>
      <div class="col-sm-6 col-12">
        <!-- Social Icons -->
        <ul class="social-media-icons text-right">
          <li><a class="fa fa-facebook" href="https://www.facebook.com/themefisher" target="_blank"></a></li>
          <li><a class="fa fa-twitter" href="https://www.twitter.com/themefisher" target="_blank"></a></li>
          <li><a class="fa fa-pinterest-p" href="https://www.pinterest.com/themefisher" target="_blank"></a></li>
          <li><a class="fa fa-vimeo" href=""></a></li>
        </ul>
      </div>
    </div>
  </div>
  <!-- Container End -->
  <!-- To Top -->
  <div class="top-to">
    <a id="top" class="" href="#"><i class="fa fa-angle-up"></i></a>
  </div>
</footer>

<!-- JAVASCRIPTS -->
<script src="client/utilitaires/jQuery/jquery.min.js"></script>
<script src="client/utilitaires/bootstrap/js/popper.min.js"></script>
<script src="client/utilitaires/bootstrap/js/bootstrap.min.js"></script>
<script src="client/utilitaires/bootstrap/js/bootstrap-slider.js"></script>
  <!-- tether js -->
<script src="client/utilitaires/tether/js/tether.min.js"></script>
<script src="client/utilitaires/raty/jquery.raty-fa.js"></script>
<script src="client/utilitaires/slick-carousel/slick/slick.min.js"></script>
<script src="client/utilitaires/jquery-nice-select/js/jquery.nice-select.min.js"></script>
<script src="client/utilitaires/fancybox/jquery.fancybox.pack.js"></script>
<script src="client/utilitaires/smoothscroll/SmoothScroll.min.js"></script>
<!-- google map -->
<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCcABaamniA6OL5YvYSpB3pFMNrXwXnLwU&libraries=places"></script>
<script src="client/utilitaires/google-map/gmap.js"></script>
<script src="client/public/js/script.js"></script>
</body>

</html>