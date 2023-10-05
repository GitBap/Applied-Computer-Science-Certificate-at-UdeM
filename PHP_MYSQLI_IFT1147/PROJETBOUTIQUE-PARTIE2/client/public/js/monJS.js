let contenu;
let deconnecter = () => {
    //fetch('serveur/pages/deconnecter.php').then(alert("FINI"));
    document.getElementById('dc').submit();
}

let validerFormEnreg = () => {
    let pass = document.getElementById('pass').value;
    let cpass = document.getElementById('cpass').value;
    if (pass === cpass) {
        return true;
    } else {
        return false;
    }
}

function rendreVisible(elem){
	document.getElementById(elem).style.display='block';
}

function rendreInvisible(elem){
	document.getElementById(elem).style.display='none';
}

function lister(){
	document.getElementById('formLister').submit();
}

function validerNum(elem){
	var num=document.getElementById(elem).value;
	var numRegExp=new RegExp("^[0-9]{1,4}$");
	if(num!="" && numRegExp.test(num))
		return true;
	return false;
}

function valider(){
	var num=document.getElementById('num').value;
	var titre=document.getElementById('titre').value;
	var duree=document.getElementById('duree').value;
	var res=document.getElementById('res').value;
	var numRegExp=new RegExp("^[0-9]{1,4}$");
	if(num!="" && titre!="" && duree!="" && res!="")
		if(numRegExp.test(num))
			return true;
	return false;
}

let initialiser = (msg) =>{
	if(msg.length > 0){
		let textToast = document.getElementById("textToast");
		let toastElList = [].slice.call(document.querySelectorAll('.toast'))
		let toastList = toastElList.map(function (toastEl) {
			return new bootstrap.Toast(toastEl)
		})
		textToast.innerHTML = msg;
		toastList[0].show();
	}
}
