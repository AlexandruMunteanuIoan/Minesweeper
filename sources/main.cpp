#include <bits/stdc++.h>
#include "Tabla.h"
#include "Celula.h"

using namespace std;

int main()
{
	int dim;
	srand(time(nullptr));
	
	while(1)
	{
		system("clear");
		cout << "Introdu dimensiunea tablei(5 - 10): ";
		cin >> dim;
		if(!(dim>10 || dim <5))
			break;
	}
		
	Tabla tabla(dim);
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
