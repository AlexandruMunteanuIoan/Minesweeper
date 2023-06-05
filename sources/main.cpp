#include <bits/stdc++.h>
#include "Tabla.h"
#include "Celula.h"

using namespace std;

int main()
{
	int dim, nr;
	system("clear");
	char start;
	cout<<"Minesweeper este un joc clasic de strategie pentru un singur jucător, "<<endl;
    	cout<<"care implică descoperirea și marcarea tuturor celulelor care conțin "<<endl;
    	cout<<"mine într-un câmp de mine, evitând astfel să declanșeze vreo mină. "<<endl;
    	cout<<"Înainte de a începe jocul, jucătorul poate selecta nivelul de "<<endl;
    	cout<<"dificultate: începător, intermediar sau avansat. Fiecare nivel are o "<<endl;
    	cout<<"dimensiune diferită a câmpului de mine și o cantitate diferită de mine "<<endl;
   	cout<<"ascunse în câmp. Scopul jocului este să descoperi toate celulele care "<<endl;
    	cout<<"nu conțin mine, fără să declanșezi nicio mină. Jucătorul poate face "<<endl;
    	cout<<"acest lucru prin alegerea unei celule neexplorate și dezvăluirea "<<endl;
    	cout<<"conținutului acesteia. Dacă celula conține o mină, jocul este pierdut"<<endl;
    	cout<<"și jucătorul trebuie să înceapă din nou. Dacă celula nu conține o mină, "<<endl;
    	cout<<"atunci aceasta va afișa numărul de mine din celulele adiacente. "<<endl;
    	cout<<"Jucătorul poate utiliza această informație pentru a deduce locația "<<endl;
    	cout<<"minelor. Jocul se câștigă atunci când toate celulele care nu conțin "<<endl;
    	cout<<"mine au fost descoperite."<<endl<<endl<<" Apasa orice tasta pentru a incepe jocul!"<<endl;
	
	start = getchar();

	while(1)
	{
		system("clear");
		cout << "Alege dificultatea jocului(1 - usor; 2 - mediu; 3 - greu): ";
		cin >> nr;
		if(nr!=1 && nr!=2 && nr!=3)
			break;
		dim = nr*5;
		if(!(dim>16 || dim <5))
			break;
	}
		
	Tabla tabla(dim, nr);
	tabla.generareMine();
	tabla.generareNumere();
	while(!tabla.gameOver() && !tabla.win())
	{
		system("clear");
		tabla.afisare();
		int lin, col;
		cout << "Introdu linia si coloana: ";
		cin >> lin >> col;
		if(!(lin < dim && col < dim && lin >= 0 && col >= 0))
			cout<<"Linia sau coloana e introdusa gresit!"<<endl;
		tabla.show(lin, col);
	}
	tabla.afisare();
	if (tabla.win())
    	{
        	cout << "Ai CASTIGAT!" << endl;
    	}
    	else
    	{
        	cout << "Ai PIERDUT!" << endl;
    	}
	return 0;
}
