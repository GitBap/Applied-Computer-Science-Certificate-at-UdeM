// Olivier Baptiste et Franck-Alexandre Ilboudo //

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
    float m , ft;
    cout << "BIENVENUE \n" ; 
    cout << "Veuiller entrer une distance en metre \n"  ;
    cin >> m ;
    ft = m*3.28084;
    cout << m ; 
	cout << " metre(s) correspond a : " ;
    cout <<  ft; 
	cout << " en pied(s)" ;
    return 0;
}

/* BIENVENUE
Veuiller entrer une distance en metre
20
20 metre(s) correspond a : 65.6168 en pied(s)
--------------------------------
Process exited after 2.489 seconds with return value 0
Press any key to continue . . . */



