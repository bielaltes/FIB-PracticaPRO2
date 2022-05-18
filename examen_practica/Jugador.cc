/** @file Jugador.cc
    @brief Codi de la classe Jugador
*/

#include "Jugador.hh"

Jugador::Jugador(string n, int ultima_pos) {
    nom = n;
    pos = ultima_pos;
    tornejos_disputat = 0;
    partits_guanyat = 0;
    partits_perdut = 0;
    sets_guanyat = 0;
    sets_perdut = 0;
    jocs_guanyat = 0;
    jocs_perdut = 0;

}



void Jugador::escriure_jugador(bool ranking, int punts) {
    if (ranking) {
        cout << nom << " " << punts << endl;
    }
    else {
        cout << nom << " Rk:" << pos << " Ps:" << punts << " Ts:" << tornejos_disputat << " WM:";
        cout << partits_guanyat << " LM:" << partits_perdut << " WS:" << sets_guanyat << " LS:";
        cout << sets_perdut << " WG:" << jocs_guanyat << " LG:" << jocs_perdut <<endl;
    }

}

int Jugador::consultar_posicio(){
    return pos;
}

double Jugador::consultar_percentatge(){
    return 100*( double(sets_guanyat)/double(sets_guanyat+sets_perdut));
}

void Jugador::sumar_posicio() {
    pos -=1;
}

void Jugador::modificar_posicio(int posicio) {
    pos = posicio;
}


void Jugador::modificar_estadistiques(const vector<int>& stats) {
    tornejos_disputat += 1;
    partits_guanyat += stats[1];
    partits_perdut += stats[2];
    sets_guanyat += stats[3];
    sets_perdut += stats[4];
    jocs_guanyat += stats[5];
    jocs_perdut += stats[6];
}
