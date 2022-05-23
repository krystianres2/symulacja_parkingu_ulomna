#include <iostream>
#include <vector>
using namespace std;

struct parking {
	string nazwisko;
	long long int rejestracja;
	bool abonament;
	int czas=6;
	int miejsca=0;
	int maksimum=20;
	int ile;
	
	vector<parking>ludzie;
	void parkingAuto() {
		miejsca++;
		cout << "Nowe auto na parkingu " << endl;
		cout << "Zajętych miejsc: " << miejsca << endl;
	}
	void opuscAuto() {
		miejsca--;
		cout << "Auto odjechalo z parkingu " << endl;
		cout << "Zajetych miejsc: " << miejsca << endl;
	}
	void przedluz() {
		cout << "O ile chcesz przedluzyc abonament: " << endl;
		cin >> ile;
		czas = +ile;
		cout << "Abonament bedzie trwal jeszcze: " << czas << " godzin " << endl;
		cout << endl;

	}
	void  dodaj()
	{
		if (miejsca <= maksimum) {
			cout << "Podaj nazwisko: " << endl;
			cin >> nazwisko;
			cout << "Podaj numer rejstracyjny: " << endl;
			cin >> rejestracja;
			cout << "Czy ma abonament: " << endl;
			cin >> abonament;
			cout << "Ile trwa abonament: " << endl;
			cin >> czas;
		}
	}
	void usun() {
		if (miejsca > 0) {
			cout << "Usunieta auto " << endl;
		}
	}


	friend void usunAuto(parking& p);
};
void usunAuto(parking& p) {
	p.miejsca--;
	cout << "Usunieta auto " << endl;
	cout << "Zajetych miejsc " << p.miejsca << endl;
}




int main()
{

	int x=0;
	
	int i = 0;
	int ufo=0;
	parking tab[99];
	while (x != 5) {
		
		cout << "1. Dodaj uzytkownika parkingu. " << endl;
		cout << "2. Usun uzytkownika parkingu. " << endl;
		cout << "3. Przedluz abonament. " << endl;
		cout << "4. Wyjdz. " << endl;
		cout << "Co chcesz zrobic: " << endl;
		cin >> x;
		switch (x) {
			case 1:
			tab[i].dodaj();
			tab[i].parkingAuto();
			i++;
			break;
			case 2:
			tab[i].usun();
			tab[i].opuscAuto();
			i--;
			break;
		case 3:
			cout << "Komu chcesz przedluzyc abonament " << endl;
			cin >> ufo;
			tab[ufo].przedluz();
			break;
		case 4:
			usunAuto(tab[i]);
			break;
		}




	}

	return 0;


	
}

