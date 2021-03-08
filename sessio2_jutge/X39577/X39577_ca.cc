#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;


void mitjana(vector<bool>& assigs, const int& n, const int& s) {
	
	int dni;
	cin >> dni;
	Estudiant est(dni);
	
	double notes;
	double mitjana = 0;
	
	for (int j = 0; j < n; ++j) {
		
		cin >> notes;
		if (assigs[j]) mitjana += notes;
		
	}
	
	mitjana /= double(s);
	est.afegir_nota(mitjana);
	est.escriure();
	
	
}
	
void llegir_vect(vector<bool>& assigs, int s) {
	
	int k; //subindex
	for (int j = 0; j < s; ++j) {
		
		cin >> k;
		assigs[k-1] = true;
		
	}
} 

int main() {
	
	//On M és la quantitat d'alumnes, N la quantitat d'assignatures i S la quantitat d'assignatures a evaluar
	int m,n,s;
	
	cin >> m >> n >> s;
	
	vector<bool> assigs(n,false);
	llegir_vect(assigs,s);
	for (int i = 0; i < m; ++i) {
		
		mitjana(assigs,n,s);
		
	}
}
