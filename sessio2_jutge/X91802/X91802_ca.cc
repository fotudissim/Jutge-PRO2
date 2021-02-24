
#include "Estudiant.hh"
#include <vector>
#include <iostream>

using namespace std;

bool millor (Estudiant a, Estudiant b) {
	
	double x = a.consultar_nota();
	double y = b.consultar_nota();
	
	return ( (x > y) or ( (x == y) and (a.consultar_DNI() < b.consultar_DNI()) ) );
	
}

bool pitjor (Estudiant a, Estudiant b) {
	
	double x = a.consultar_nota();
	double y = b.consultar_nota();
	
	return ( (x < y) or ( (x == y) and (a.consultar_DNI() < b.consultar_DNI()) ) );
	
}

pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
    
    pair<int,int> p(-1,-1);
    
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
		
		if (v[i].te_nota()) {
			if (p.first == -1) p.first = p.second = i;
			else if ( millor(v[i],v[p.first]) ) p.first = i;
			else if ( pitjor(v[i],v[p.second]) ) p.second = i;
		}
	}
	return p;
    
}

