#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct partit {
	
	int x;
	int y;
	
};

struct equip {
	
	int id = 0; //número identificador de l'equip
	int gols = 0; //quantitat total de gols de l'equip
	int rebuts = 0; //quantitat total de gols rebuts
	int punts = 0; //quantitat total de punts
	
};

void infoequips (int i, int j, partit prt, vector<equip>& v) {	//introduim les dades del partit al vector d'equips
	
	if (i != j) {
			
		if ( prt.x	> prt.y ) v[i].punts += 3;
		else if (prt.x < prt.y) v[j].punts += 3;
		else {
			v[i].punts++;
			v[j].punts++;
		}
		
		v[i].gols += prt.x;
		v[j].gols += prt.y;
		v[i].rebuts += prt.y;
		v[j].rebuts += prt.x;
	}
	
}

void lopartit (int n, vector<equip>& v) {
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			
				partit prt;
				cin >> prt.x >> prt.y;
				infoequips(i,j,prt,v);
			}
		}			
} 

bool cmp(equip a, equip b) {
	
	if ( a.punts == b.punts ) {
		
		int m = a.gols - a.rebuts;
		int n = b.gols - b.rebuts;
		
		if ( m == n ) return a.id < b.id;
		
		return m > n;
		
	}
	
	return a.punts > b.punts;
	
}

void printtot(const vector<equip>& v) {
	
	for (int i = 0; i < v.size(); i++) cout << v[i].id << ' ' << v[i].punts << ' ' << v[i].gols << ' ' << v[i].rebuts << endl;
	
}

int main() {
	
	int n;
	cin >> n;
	
	vector<equip> v(n);
	lopartit(n,v);
	for (int i = 1; i <= n; i++) v[i-1].id = i;
	sort (v.begin(),v.end(), cmp);
	printtot(v);
	
	
}
