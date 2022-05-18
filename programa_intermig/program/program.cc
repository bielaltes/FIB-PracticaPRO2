#include "Cjt_categories.hh"
#include "Cjt_jugadors.hh"
#include "Cjt_tornejos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;


int main() {
    
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
            jugadors.nou_jugador(false);
        }
        else if (comanda == "nuevo_torneo" or comanda == "nt") {
            tornejos.nou_torneig(categories.num_categories(),false);
        }
        else if (comanda == "baja_jugador" or comanda == "bj") {
            jugadors.baixa_jugador();
        }
        else if (comanda == "baja_torneo" or comanda == "bt") {
            tornejos.baixa_torneig();
        }
        else if (comanda == "iniciar_torneo" or comanda == "it") {
            tornejos.iniciar_torneig(jugadors);
        }
        else if (comanda == "finalizar_torneo" or comanda == "ft") {
            tornejos.finalitzar_torneig();
        }
        else if (comanda == "listar_ranking" or comanda == "lr") {
            jugadors.imprimir_ranking();
        }
        else if (comanda == "listar_jugadores" or comanda == "lj") {
            jugadors.imprimir_jugadors();        
        }
        else if (comanda == "consultar_jugador" or comanda == "cj") {
            jugadors.consultar_jugador();
        }
        else if (comanda == "listar_torneos" or comanda == "lt") {
            tornejos.imprimir_tornejos(categories);        
        }
        else if (comanda == "listar_categorias" or comanda == "lc") {
            categories.imprimir_categories();        
        }
        cin >> comanda;
    }
}
