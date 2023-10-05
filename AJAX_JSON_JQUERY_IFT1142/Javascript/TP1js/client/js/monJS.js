//ES5
// function listerFilms(){
    
    // let titre = listeFilms[0]["title"];
  //  let titre = listeFilms[0].title;
   // let titre = listeFilms[0].year;

  //  let rep="<br><b>TITRE =<b>"+titre+"<br><b>ANNÉE = "+annee;
   // document.getElementById('contenu').innerHTML = rep;
    //document.getElementById('fenetre').style.display = 'block'; //Montrer la fenetre
  //  montrerElem('fenetre');
// }

// let montrerElem = function(idElem){
//    document.getElementById(idElem).style.display = 'block';
// }

//function montrerElem(idElem){
 //   document.getElementById('idElem').style.display = 'block';
//}

// let montrerElem = function(idElem){
  //   document.getElementById(idElem).style.display = 'block';
// }

// function cacherElem(idElem){
//    document.getElementById('idElem').style.display = 'none';
// }

//ES6
let listerFilms = () => {
    
    let rep="";
    // let taille = listeFilms.length;
    // for(let i=0; i < taille; i++){
    //    rep += "<br><b>TITRE =<b>"+listeFilms[i].title+"<br><b>ANNÉE = "+listeFilms[i].year;
    //   rep += "<br>*****************88";
    // }
    // for(let unFilm of listeFilms){
    //    rep += "<br><b>TITRE =<b>"+unFilm.title+"<br><b>ANNÉE = "+unFilm.year;
    //   rep += "<br>*****************88";
    // }

    // mettre row colun (3-4) par lignes
    for(let unFilm of listeFilms){
        rep += `<div class="card" style="width: 18rem;">
        <img src="${unFilm.posterUrl}" class="card-img-top" alt="...">
        <div class="card-body">
            <h5 class="card-title">${unFilm.title}</h5>
            <h3 class="card-title">${unFilm.year}</h3>
            <h3 class="card-title">${unFilm.genres}</h3>
            <p class="card-text">${unFilm.plot}</p>
            <a href="#" class="btn btn-primary" onClick="">Bande annonce</a>
            <a href="#" class="btn btn-primary">Panier</a>
        </div>
        </div>`;
    }    
    document.getElementById('contenu').innerHTML = rep;
    // montrerElem('fenetre');
}

let montrerElem = (idElem) => {
    document.getElementById(idElem).style.display = 'block';
}

let cacherElem = (idElem) => {
    document.getElementById('idElem').style.display = 'none';
}