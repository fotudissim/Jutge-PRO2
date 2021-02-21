 
 #include "vectorIOint.hh"
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
	
	parint eval;
	
	int max = v[0];
	int min = v[0];
	
	for (int i = 0; i < v.size(); ++i) {
		
		if (v[i] > max) max = v[i];
		else if (v[i] < min) min = v[i];
		
	}
	
	eval.prim = max;
	eval.seg = min;
	
	return eval;
		
	
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
	pair<int,int> eval2;
	int max = v[0];
	int min = v[0];
	
	for (int i = 0; i < v.size(); ++i) {
		
		if (v[i] > max) max = v[i];
		else if (v[i] < min) min = v[i];
		
	}
	
	eval2.first = max;
	eval2.second = min;
	
	return eval2;
	
 }
 

 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
	int max = v[0];
	int min = v[0];
	
	for (int i = 0; i < v.size(); ++i) {
		
		if (v[i] > max) max = v[i];
		else if (v[i] < min) min = v[i];
		
	}
	
	x = max;
	y = min;
 } 

 
 int main() {
	 
	 int max,min; //pel void
	 parint eval; //pel struct
	 pair<int,int> eval2; //pel pair
	 
	 vector<int> v;
	 leer_vector_int(v);
	 
	 eval = max_min1(v);
	 eval2 = max_min2(v);
	 max_min3(v,max,min);
	 
	 cout << "struc: " << eval.prim << " " << eval.seg << endl;
	 cout << "pair: " << eval2.first << " " << eval2.second << endl;
	 cout << "void: " << max << " " << min << endl;
	 
	 
 }
