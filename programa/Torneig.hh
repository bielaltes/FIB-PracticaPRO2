#ifndef TORNEIG_HH
#define TORNEIG_HH

#include "Cjt_jugadors.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include "BinTree.hh"
#endif

using namespace std;

class Torneig {

private:
    int categoria;
    int num_participants;
    vector<string> participants;
    vector<vector<int>> estadistiques;  
    vector<int> punts;
    BinTree<int> partits;

/** @brief Llegeix la inscripcio a un torneig
    \pre Per el canal habitual d'entrada trobem un int que representa
     el numero d'inscrits i seguidament n enters que representen la seva
    posició al ranking.
    \post s'ha omplert el vector participants amb el ranking i el nom de
     tots els participants.
*/
    void llegir_inscripcio(Cjt_jugadors& jugadors);

    void imprimir_torneig(BinTree<int>& a, bool left, bool pare,int prof);

    void crear_imprimir_emparellaments(BinTree<int>& a, int profunditat);

public:

/** @brief Constructora de la classe
    \pre l'enter cat representa la categoria del mateix.
    \post el resultat es un torneig amb categoria cat.
*/
    Torneig(int cat);

/** @brief esborra automaticament els objectes locals en sortir
     d'un ambit de visibilitat.
*/
    ~Torneig();

/** @brief Retorna la categoria d'un torneig
    \pre  cert.
    \post el resultat es la categoria del parametre implicit.
*/
    int consultar_categoria();

/** @brief Confecciona i imprimeix els emparellaments d'un torneig
    \pre  Al canal habitual d'entrada hi trobem un enter que representa
     el nombre total d'inscrits al torneig i seguidament les seves posicions.
    \post imprimeix el quadre d'emparellaments del torneig.
*/
    void iniciar_torneig(Cjt_jugadors& jugadors);


};
#endif
