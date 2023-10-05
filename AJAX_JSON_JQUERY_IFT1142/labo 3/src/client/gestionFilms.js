let ligneFilms="";

let remplirCard = (unFilm)=> {
     
                  let rep =    ' <div class="col">';
                  rep +='<div class="card">';
                               rep +=' <img src="'+unFilm.posterUrl+'" class="card-img-top tailleImg" alt="...">';
                               rep +=' <div class="card-body">';
                               rep +=' <h5 class="card-title">'+unFilm.title+'</h5>';
                               rep +=' <p class="card-text">Année : '+unFilm.year+'</p>';
                               rep +=' <p class="card-text">Durée : '+unFilm.runtime+'</p>';
                               rep +=' <p class="card-text">'+unFilm.plot+'</p>';
                               rep +=' <a href="#" class="btn btn-primary">Bande annonce</a>';
                               rep +=' <a href="#" onClick="enleverFilm(this,'+unFilm.id+');" class="btn btn-danger"><span style="font-size:18px; color:white;">-</span></a>';
                               rep +=' <!--<button style="float:right;margin-right: 12px;" type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#exampleModal">';
                               rep +=' <span style="font-size:18px; color:white;">-</span>';
                               rep +=' </button> -->';
                               rep +=' </div>';
                               rep +=' </div>';
                               rep +=' </div>';
                           
                      return rep;
}

let listerTousLesFilms = (duree,titre, annee,ordeDeTri) => {
    if (listeFilmsDisponible){
        let contenu = `<div class="row row-cols-4">`;
        if (annee >= 0){
             if (ordeDeTri == 'D'){
                listeFilms.sort((a,b) => parseInt(b.year)-parseInt(a.year));//ordre décroissant
             }else { 
                listeFilms.sort((a,b) => parseInt(a.year)-parseInt(b.year));// cas ordreDeTri == 'C' ordre croissant
             }
                // Par année
                for (unFilm of listeFilms){
                    if (parseInt(unFilm.year) > annee){
                        contenu+=remplirCard(unFilm);
                    }else if (annee == 0) {
                        contenu+=remplirCard(unFilm);
                    }
                }   
        }else if(titre != null){// if (titre == true)
            if (ordeDeTri == 'D'){
                listeFilms.sort((a,b) => (b.title > a.title)?1:-1);//ordre décroissant
             }else { 
                listeFilms.sort((a,b) => (b.title < a.title)?1:-1);// cas ordreDeTri == 'C' ordre croissant
             }
            // Par titre
            for (unFilm of listeFilms){
                    contenu+=remplirCard(unFilm);
            }
           
        } else if(duree >= 0){
            if (ordeDeTri == 'D'){
                listeFilms.sort((a,b) => parseInt(b.runtime)-parseInt(a.runtime));//ordre décroissant
             }else { 
                listeFilms.sort((a,b) => parseInt(a.runtime)-parseInt(b.runtime));// cas ordreDeTri == 'C' ordre croissant
             }
                // Par année
                for (unFilm of listeFilms){
                    if (parseInt(unFilm.runtime) > duree){
                        contenu+=remplirCard(unFilm);
                    }else if (duree == 0) {
                        contenu+=remplirCard(unFilm);
                    }
                }   
           
        }
        contenu+= `</div>`;

        $('#contenu').html(contenu);//document.getElementById('contenu').innerHTML=contenu;
    }
    else { alert("SVP vous devez charger la liste des films en premier"); }
}


let listerLesPlusRecents = (annee) => {

}

let ajouterFilm = () => {

    let num = document.getElementById('num').value;
    let titre = document.getElementById('titre').value;
    let duree = document.getElementById('duree').value;

    let unFilm ={"num":num,"titre":titre,"duree":duree};
    listeFilms.push(unFilm);
    console.log(listeFilms);

}

let enleverFilm = (leFilm, id) => {
    alert(id);
    leFilm.parentNode.parentNode.parentNode.remove(leFilm.parentNode.parentNode);
    console.log("LISTE AVANT");
    console.log(listeFilms); //Liste de départ
    let indice;
    listeFilms.find((element, index) => { indice=index; return element.id == id;});
    alert(JSON.stringify(listeFilms[indice]));
    listeFilms.splice(indice,1);//À partir de cette indice (inclusivement) supprime 1 élément
    console.log("LISTE APRÈS");
    console.log(listeFilms); //Liste après suppression
}
let changer = () => {
    let previous = document.getElementById('trier').value;

    if(previous == "Titre"){
        listerTousLesFilms(-1,'titre',-1,'C')
    }else if(previous == "Annee"){
        listerTousLesFilms(-1,null,2010,'C')
    }else{
       listerTousLesFilms(120,null,-1,'C')
    }
}
let search = () => {
    let val = document.getElementById('val').value;
    listerTousLesFilms(-1,val,0,'C')
}