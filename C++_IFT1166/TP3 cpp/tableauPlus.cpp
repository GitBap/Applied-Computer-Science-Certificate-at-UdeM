// Handel Olivier Baptiste //
#include <iostream>
#include <typeinfo>

#include "tableauPlus.h"

using namespace std;

/* Début code à compléter*/
template <class  Type>
tableauPlus<Type>:: tableauPlus()
        {
        	Tab=new Type[0];
        }
template <class  Type>
tableauPlus<Type> ::tableauPlus(int a)
        {
        	try{
        		if (a<0)
        		{
        			string err("taille negative"); throw err;
        		}
        		else{Tab=new Type[a]; }
        	}
        	catch(string e){cout<<e;}
        }
template <class  Type>
tableauPlus<Type>:: tableauPlus(int mi, int ma )
        {
        	try{
        		if (mi<0&&ma<0)
        		{
        			string err("taille negative"); throw err;
        		}
        		else if (mi>ma)
        		{
        			string err1("taille minimale superieur a la taille maximale"); throw err1;
        		}
        		else if (mi<0&&ma>0)
        		{Tab=new Type[mi*(-1)+ma];

        		}
        		else{Tab=new Type[mi+ma-1]; }
        	}
        	catch(string e){cout<<e;}
        }
template <class  Type>
Type& tableauPlus<Type> :: operator [](int e)
        {
        	try{
        		if (e>Tab->size())
        		{
        			string err("taile du tableau depassée");throw err;

        		}
        		else{return Tab[e];

        			}
        		}
        		catch(string e){cout<<e;}

        }
template <class  Type>
bool  operator ==(tableauPlus<Type>&t,tableauPlus<Type>&t2)
        	{
        		for (int i = 0; i < t2.Tab->size(); ++i)
        		{
        			if (t2.Tab[i]!=t.Tab[i])
        			{
        				return 0;break;
        			}
        		}

        		return 1;
        	}
template <class  Type>
bool   operator !=(tableauPlus<Type>&t,tableauPlus<Type>&t2)
        {
        	  for (int i = 0; i < t.Tab->size(); ++i)
        		{
        			if (t2.Tab[i]==t.Tab[i])
        			{
        				return 0;break;
        			}
        		}

        		return 1;
        }
template <class  Type>
Type tableauPlus<Type>:: getFin() const
        {
        	return Tab[Tab.size()-1];
        }
template <class  Type>
Type tableauPlus<Type>:: getDebut() const
        {
        	return Tab[0];
        }
 /*Fin code à compléter */

int main()
{

	tableauPlus<bool> tabBool1(3);
	tableauPlus<bool> tabBool2(0, 3);
	tableauPlus<bool> tabBool3(1, 4);

	cout << "tabBool1(3) == tabBool2(0, 3): " << (tabBool1 == tabBool2) << "\n";
	cout << "tabBool1(3) != tabBool2(0, 3): " << (tabBool1 != tabBool2) << "\n";
	cout << "tabBool1(3) == tabBool3(1, 4): " << (tabBool1 == tabBool3) << "\n";
	cout << "tabBool1(3) != tabBool3(1, 4): " << (tabBool1 != tabBool3) << "\n";
	cout << "\n";

	tableauPlus<char> tabChar1(-2, 3);
	tableauPlus<char> tabChar2(-3, 3);

	cout << "tabChar1(-2, 3) == tabChar2(-3, 3): " << (tabChar1 == tabChar2) << "\n";
	cout << "tabChar1(-2, 3) != tabChar2(-3, 3): " << (tabChar1 != tabChar2) << "\n";
	cout << "\n";

	tableauPlus<double> tabDouble1(-2, 3);
	tableauPlus<double> tabDouble2(-2, 4);

	cout << "tabDouble1(-2, 3) == tabDouble2(-2, 4): " << (tabDouble1 == tabDouble2) << "\n";
	cout << "tabDouble1(-2, 3) != tabDouble2(-2, 4): " << (tabDouble1 != tabDouble2) << "\n";
	cout << "\n";


	tableauPlus<int> tabInt1(-4, -1);
	tableauPlus<int> tabInt2(-4, -1);
	tableauPlus<int> tabInt3(-4, -1);
	tableauPlus<double> tabDouble3(-4, -1);
	tableauPlus<short> tabShort(-4, -1);



	tabInt1[-4] = -1;
	tabInt1[-3] = 12;
	tabInt1[-2] = 123;


	tabInt2[-4] = -1;
	tabInt2[-3] = 12;
	tabInt2[-2] = 123;


	tabInt3[-4] = -1;
	tabInt3[-3] = 12;
	tabInt3[-2] = 1234;

	tabDouble3[-4] = -1;
	tabDouble3[-3] = 12;
	tabDouble3[-2] = 123;

	tabShort[-4] = -1;
	tabShort[-3] = 12;
	tabShort[-2] = 123;

	int i;

	for (i = tabShort.getDebut(); i <= tabShort.getFin(); i++)
	{
		cout << "tabInt1[" << i << "]: " << tabInt1[i] << "\t";
		cout << "tabInt2[" << i << "]: " << tabInt2[i] << "\t";
		cout << "tabInt3[" << i << "]: " << tabInt3[i] << "\n";
	}

	cout << "\n";

	for (i = -4; i < -1; i++)
	{
		cout << "tabShort[" << i << "]: " << tabShort[i] << "\t";
		cout << "tabDouble3[" << i << "]: " << tabDouble3[i] << "\n";

	}

	cout << "\n";

	cout << "tabIntl == tabInt2: " << (tabInt1 == tabInt2) << "\n";
	cout << "tabIntl != tabInt2: " << (tabInt1 != tabInt2) << "\n";
	cout << "\n";


	cout << "tabIntl == tabInt3: " << (tabInt1 == tabInt3) << "\n";
	cout << "tabIntl != tabInt3: " << (tabInt1 != tabInt3) << "\n";
	cout << "\n";

	cout << "tabIntl == tabDouble3: " << (tabInt1 == tabDouble3) << "\n";
	cout << "tabIntl != tabDouble3: " << (tabInt1 != tabDouble3) << "\n\n";

	cout << "tabIntl == tabShort: " << (tabInt1 == tabShort) << "\n";
	cout << "tabIntl != tabShort: " << (tabInt1 != tabShort) << "\n\n";

	cout << "tabDouble3 == tabShort: " << (tabDouble3 == tabShort) << "\n";
	cout << "tabDouble3 != tabShort: " << (tabDouble3 != tabShort) << "\n\n";

	tableauPlus<int> tabInt4(3);
	tableauPlus<char> tabChar3(3);


	cout << "tabInt4 == tabChar3: " << (tabInt4 == tabChar3) << "\n";
	cout << "tabInt4 != tabChar3: " << (tabInt4 != tabChar3) << "\n\n";

	cout << "Si on accede a tabChar1[0]\n";
	tabChar1[0];
	cout << "\nSi on accede a tabInt3[-1]\n";
	tabInt3[-1];


	return 0;


}

/*
tabBool1(3) == tabBool2(0, 3): 1
tabBool1(3) != tabBool2(0, 3): 0
tabBool1(3) == tabBool3(1, 4): 0
tabBool1(3) != tabBool3(1, 4): 1

tabChar1(-2, 3) == tabChar2(-3, 3): 0
tabChar1(-2, 3) != tabChar2(-3, 3): 1

tabDouble1(-2, 3) == tabDouble2(-2, 4): 0
tabDouble1(-2, 3) != tabDouble2(-2, 4): 1

tabInt1[-4]: -1 tabInt2[-4]: -1 tabInt3[-4]: -1
tabInt1[-3]: 12 tabInt2[-3]: 12 tabInt3[-3]: 12
tabInt1[-2]: 123        tabInt2[-2]: 123        tabInt3[-2]: 1234

tabShort[-4]: -1        tabDouble3[-4]: -1
tabShort[-3]: 12        tabDouble3[-3]: 12
tabShort[-2]: 123       tabDouble3[-2]: 123

tabIntl == tabInt2: 1
tabIntl != tabInt2: 0

tabIntl == tabInt3: 0
tabIntl != tabInt3: 1

tabIntl == tabDouble3: 0
tabIntl != tabDouble3: 1

tabIntl == tabShort: 0
tabIntl != tabShort: 1

tabDouble3 == tabShort: 0
tabDouble3 != tabShort: 1

tabInt4 == tabChar3: 0
tabInt4 != tabChar3: 1

Si on accede a tabChar1[0]

Si on accede a tabInt3[-1]
-1 depasse la taille du tableau.

*/

