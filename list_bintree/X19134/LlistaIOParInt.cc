#include "LlistaIOParInt.hh"

using namespace std;

void LlegirLlistaParInt(list<ParInt>& l){
  ParInt par;
  while (par.llegir() or (not par.primer == 0) and (not par.segon == 0) {

          l.insert(l.end(),par);
   }

}

/*void escriure_llista_int(const list<int>& l) {
  if (not l.empty()) {
    list<int>::const_iterator it;
    cout << "[Primero] ";
    for (it = l.begin(); it != l.end(); ++it){
      cout << *it << " "; // si la lista no es de enteros
    }                     // quedara mejor si hacemos endl para cada elemento
    cout << "[Ultimo]";
  }
  cout << endl;
}*/
