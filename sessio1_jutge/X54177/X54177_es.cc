#include <iostream>

using namespace std;


int main() {
	
	int n,x,k;
	
	
	cin >> n >> x;
	
	for (int i = 1; i <= n; ++i) {
		
		int count = 0;
		while ( cin >> k and k != x ) count += k;
		
		string s;
		getline(cin,s);
		
		cout << "La suma de la secuencia " << i << " es " << count << endl;
		
	}
	
}
			
			
			
	
