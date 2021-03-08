#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const Estudiant& a, const Estudiant& b) {
	
	if (a.consultar_nota() == b.consultar_nota()) return a.consultar_DNI() < b.consultar_DNI();
	
	return a.consultar_nota() > b.consultar_nota();
}

void mitjana(vector<bool>& assigs, vector<Estudiant>& estudiants, int n, int s) {
	
	
	for (int i = 0; i < estudiants.size(); ++i) {
		
		int dni;
		cin >> dni;
		Estudiant est(dni);
		estudiants[i] = est;
		
		double notes;
		double mitjana = 0;
		
		for (int j = 0; j < n; ++j) {
			
			cin >> notes;
			if (assigs[j]) mitjana += notes;
			
		}
		
		mitjana /= double(s);
		estudiants[i].afegir_nota(mitjana);
		
	}
	
	sort (estudiants.begin(), estudiants.end(), cmp);
	
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
	
	vector<Estudiant> estudiants(m);
	
	mitjana(assigs,estudiants,n,s);
	
	for (int i = 0; i < m; ++i) estudiants[i].escriure();
	
}
