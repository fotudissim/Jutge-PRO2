#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
#include <iostream>

using namespace std;

double redondear(double r) {
  return int(10.*(r + 0.05)) / 10.0;
}

void add_est(Cjt_estudiants& cje) {

    Estudiant est;
    est.llegir();
    
    if (cje.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " << est.consultar_DNI() << " ya estaba" << endl << endl;
    else if (cje.mida() == Cjt_estudiants::mida_maxima()) cout << "el conjunto esta lleno" << endl << endl;
    else cje.afegir_estudiant(est);


}

void cons_nota(const Cjt_estudiants& cje) {

    int cons_DNI;
    cin >> cons_DNI;

    if (not cje.existeix_estudiant( cons_DNI )) cout << "el estudiante " << cons_DNI << " no esta";
    else if (cje.consultar_estudiant( cons_DNI ).te_nota()) {

        cout << "el estudiante " << cons_DNI << " tiene nota " <<  cje.consultar_estudiant( cons_DNI ).consultar_nota();

    }
    else cout << "el estudiante " << cons_DNI << " no tiene nota";

    cout << endl;

    cout << endl;

}

void chg_nota(Cjt_estudiants& cje) {

    Estudiant est;
    est.llegir();

    if (not cje.existeix_estudiant( est.consultar_DNI() )) cout << "el estudiante " << est.consultar_DNI() << " no esta" << endl << endl; 
    else cje.modificar_estudiant(est);


}

void arrodonir(Cjt_estudiants& cje) {

    for (int i = 1; i <= cje.mida(); ++i) {
                Estudiant est = cje.consultar_iessim(i);
                if (est.te_nota()) est.modificar_nota(redondear(est.consultar_nota()));
                cje.modificar_iessim(i, est);
            }

}


int main() {

    Cjt_estudiants cje;
    int op; //operació

    cje.llegir();

    //operacions
    while (cin >> op and op != -6) {

        if (op == -1) add_est(cje);
        else if (op == -2) cons_nota(cje);
        else if (op == -3) chg_nota(cje);
        else if (op == -4) arrodonir(cje);
        else if (op == -5) {
         
            cje.escriure();
            cout << endl;

        }
    }

}
