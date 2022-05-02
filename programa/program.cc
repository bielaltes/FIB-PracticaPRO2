#include "Cjt_categories.hh"
#include "Cjt_jugadors.hh"
#include "Cjt_tornejos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;


int main() {
    clock_t start,end;
    start = clock();
    int C, K;
    cin >> C >> K;
    Cjt_categories categories(C,K);
    categories.llegir_categories();
    
    Cjt_tornejos tornejos;
    tornejos.llegir_tornejos(C);
    
    Cjt_jugadors jugadors;
    jugadors.llegir_jugadors();
      
    string comanda;
    cin >> comanda;
    
    while (comanda!= "fin") {
        cout << "#" << comanda;
        if (comanda == "nuevo_jugador" or comanda == "nj") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            jugadors.nou_jugador(nom, false);
        }
        else if (comanda == "nuevo_torneo" or comanda == "nt") {
            string nom;
            int cat;
            cin >> nom >> cat;
            cout << " " << nom << " " << cat << endl; 
            tornejos.nou_torneig(nom,cat,categories.num_categories(),false);
        }
        else if (comanda == "baja_jugador" or comanda == "bj") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            jugadors.baixa_jugador(nom);
        }
        else if (comanda == "baja_torneo" or comanda == "bt") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            tornejos.baixa_torneig(nom);
        }
        else if (comanda == "iniciar_torneo" or comanda == "it") {
            string nom;
            cin >>nom;
            cout << " " << nom << endl;
            tornejos.iniciar_torneig(nom,jugadors);
        }
        else if (comanda == "finalizar_torneo" or comanda == "ft") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            tornejos.finalitzar_torneig(nom);
        }
        else if (comanda == "listar_ranking" or comanda == "lr") {
            jugadors.imprimir_ranking();
        }
        else if (comanda == "listar_jugadores" or comanda == "lj") {
            jugadors.imprimir_jugadors();        
        }
        else if (comanda == "consultar_jugador" or comanda == "cj") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            jugadors.consultar_jugador(nom);
        }
        else if (comanda == "listar_torneos" or comanda == "lt") {
            tornejos.imprimir_tornejos(categories);        
        }
        else if (comanda == "listar_categorias" or comanda == "lc") {
            categories.imprimir_categories();        
        }
        cin >> comanda;
    }
    end = clock();
    double time_taken = double(end-start) /double(CLOCKS_PER_SEC);
    cout << time_taken << endl;
}
