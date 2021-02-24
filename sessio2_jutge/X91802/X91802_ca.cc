#include "Estudiant.hh"
//#include ""
#include <vector>
#include <iostream>

using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
	
	pair<int,int> posv;
	double max = v[0].consultar_nota();
	double min = v[0].consultar_nota();
	int max_id = v[0].consultar_DNI();
	int min_id = v[0].consultar_DNI();
	int max_pos = 0;
	int min_pos = 0;
	double mu = -1;
	
	for (int i = 0; i < v.size(); ++i) {
		
		if (v[i].te_nota()) {
			
			if (v[i].consultar_nota() > max) {
				max = v[i].consultar_nota();
				max_id = v[i].consultar_DNI();
				max_pos = i;
			}
			if (v[i].consultar_nota() < min) {
				 min = v[i].consultar_nota();
				 min_id = v[i].consultar_DNI();
				 min_pos = i;
			}
			
			else {
				if ( v[i].consultar_nota() == max) {
					if (v[i].consultar_DNI() < max_id) {
						max_id = v[i].consultar_DNI();
						max_pos = i;
					}
				}
				else if (v[i].consultar_nota() == min) {
					if (v[i].consultar_DNI() < min_id) {
						min_id = v[i].consultar_DNI();
						min_pos = i;
					}
				}
			}
		}
		else if (not v[i].te_nota()) v[i].afegir_nota(mu);	
	}
	
	posv.first = max_pos + 1;
	posv.second = min_pos + 1;
	
	return posv;
	
    
}

