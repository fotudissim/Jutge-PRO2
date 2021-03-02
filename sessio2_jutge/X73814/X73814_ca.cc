#include "Estudiant.hh"
#include <iostream>
#include <vector>


using namespace std;


vector <Estudiant> llegir_vect() {
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for (int i=0; i<n; ++i) v[i].llegir();
    return v;
}

vector <Estudiant> simplificar_notes(const vector <Estudiant>& v) {
	
    vector<Estudiant> vout;
    
    for (int i = 0; i < v.size(); ++i) {
		
        if ( i == 0 or ( v[i].consultar_DNI() != v[i-1].consultar_DNI() ) ) vout.push_back(v[i]);
        
        else if (v[i].te_nota()){
			
            if ((not vout[vout.size()-1].te_nota()) or vout[vout.size()-1].consultar_nota() < v[i].consultar_nota()) {
				
				vout[vout.size()-1] = v[i];
				
			}
        }
    }
    
    return vout;
}

void print_notes(const vector <Estudiant>& vout) {
    for (int i=0; i<vout.size(); ++i) vout[i].escriure();
}


int main() {
	
	vector<Estudiant> v = llegir_vect();
	vector<Estudiant> vout = simplificar_notes(v);
	print_notes(vout);
	
	
	
}
