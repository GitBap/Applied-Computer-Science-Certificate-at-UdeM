tableauM = [];
i = 0;


function generate_table2(x, unMembre) {
    
    $('#emp_body3').html('');
	let rep="";
    for(let z = 0; z < x; z++)
    {
        tableauM[z] = unMembre[z];
        rep+=`
			<tr name = "AllArt[]">
				<td>
				<span>
					<input type="checkbox" id="opt" name="options[]" value="`+unMembre[z].idm+`" />
				</span>
				</td>
				<td>`+unMembre[z].idm+`</td>
				<td>`+unMembre[z].nom+`</td>
				<td>`+unMembre[z].prenom+`</td>
				<td>`+unMembre[z].courriel+`</td>
				<td>`+unMembre[z].sexe+`</td>
				<td>`+unMembre[z].datenaissance+`</td>`;
                if(unMembre[z].statut === "I")
                    {
                        rep+=`<td>Inactif</td><td>`;
                    }
                    else
                    {
                        rep+=`<td>Actif</td><td>`;

                    }

                    if(unMembre[z].statut === "I")
                    {
                        rep+=`<a href="#" onClick='supprimerArticle1(`+unMembre[z].idm+`)' class="edit" data-toggle="modal"><i class="bi bi-unlock" data-toggle="tooltip" title="Activer"></i></a>`;
                    }
                    else
                    {
                        rep+=`<a href="#" onClick='supprimerArticle2(`+unMembre[z].idm+`)' class="delete" data-toggle="modal"><i class="bi bi-lock" data-toggle="tooltip" title="Désactiver"></i></a>`;

                    }
				rep+=`
				</td>
			</tr>`;
    }
    $('#emp_body3').html(rep);

    $("#modification").click(function() {
        editerArticle2(unMembre);
    }); 
}	
function editerArticle2(x){
	
	document.getElementById('idm_m').value=x.idm;
	document.getElementById('nom_m').value=x.nom;
	document.getElementById('prenom_m').value=x.prenom;
	document.getElementById('cour_m').value=x.courriel;
	document.getElementById('sex_m').value=x.sexe;
	document.getElementById('date_m').value=x.datenaissance;
	$('#modalEditerArticles').modal('show');
}

idArticleSupprimer = 0;

function supprimerArticle2(idm){
	idArticleSupprimer = idm;
	$('#supprimerMembreModal').modal('show');
}
function supprimerArticle1(idm){
	idArticleSupprimer = idm;
	$('#supprimerMembreModal1').modal('show');
}

function supprimer2(){
     let formEnlever = document.getElementById('formEnlever2');
	 document.getElementById('idmre').value = idArticleSupprimer;
	 formEnlever.submit();
}

function initialisation()
{
    $.ajax({
    //L'URL de la requête 
    url: "this.php",
    //La méthode d'envoi
    method: "GET",
    //Le format de réponse attendu
    dataType : "json",
    })
    //Ce code sera exécuté en cas de succès
    .done(function(response){
        console.log(response["listeArticles"]);
        tableauM = response["listeArticles"];
        generate_table2(tableauM.length, tableauM);
    })

    //Ce code sera exécuté en cas d'échec 
    .fail(function(error){
        alert("Erreur : " +error);
    })

    //Ce code sera exécuté que la requête soit un succès ou un échec
    .always(function(){
        console.log("StackTrace l'univers des développeurs ");
    });
}
