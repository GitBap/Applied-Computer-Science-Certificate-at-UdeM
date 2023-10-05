let listeFilm;

let chargerFilms = () => {
    fetch("src/donnees/films.xml")
    .then(reponse => reponse.text())
    .then(stringFilms => {
        const parser = new DOMParser();
        listeFilms = parser.parseFromString(stringFilms, "films/xml");
        //alert(listeLivres);
        lister();
    })
    .catch((error) => {
        alert('Il y a eu un problème avec l\'opération fetch: ' + error.message);
    });
}

let chargerCat = () => {
    fetch("src/donnees/categoriesFilms.xml")
    .then(reponse => reponse.text())
    .then(stringCat => {
        const parser = new DOMParser();
        listeCat = parser.parseFromString(stringCat, "ategoriesFilms/xml");
        //alert(listeLivres);
        lister();
    })
    .catch((error) => {
        alert('Il y a eu un problème avec l\'opération fetch: ' + error.message);
    });
}