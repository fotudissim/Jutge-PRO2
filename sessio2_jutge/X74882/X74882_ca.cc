#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void la_modalitat(Cjt_estudiants& C1, const Cjt_estudiants& C2) {
	
	for (int i = 1; i <= C1.mida(); ++i) {
		
		Estudiant es1 = C1.consultar_iessim(i);
		Estudiant es2 = C2.consultar_iessim(i);
		
		if (es1.te_nota() and es2.te_nota()) {
			
			if (es1.consultar_nota() < es2.consultar_nota()) C1.modificar_iessim(i,es2);
		
		}
		
		else if (not es1.te_nota() and es2.te_nota()) C1.modificar_iessim(i,es2);
		
	}
	
}

int main() {
	
	Cjt_estudiants C1;
	C1.llegir();
	
	Cjt_estudiants C2;
	C2.llegir();
	
	la_modalitat(C1,C2);
	
	C1.escriure();
	
}
