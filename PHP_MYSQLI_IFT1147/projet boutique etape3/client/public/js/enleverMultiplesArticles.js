function enleverMultiplesArticles() {
	
	let listeCheckBoxes = document.getElementsByName("options[]");
	const formulaire = document.getElementById("formulaire1");
	
	//Vérifier s'il y a au moins une option de cochée;
	let listeArticles = "";
	//formulaire.submit();
	for (let uneOption of listeCheckBoxes) {
		if (uneOption.checked) {
			listeArticles += (uneOption.value + ";"); //9;13;50;
		}
	}
	//alert(listeArticles);
	if (listeArticles.length > 0) {
		listeArticles = listeArticles.substring(0, listeArticles.length - 1); //Enlever dernier ;
		document.getElementById("idaM").value = listeArticles;
		formulaire.submit();
	}
	
}


