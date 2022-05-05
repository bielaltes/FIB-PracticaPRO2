#ifndef TORNEIG_HH
#define TORNEIG_HH

#include "Cjt_jugadors.hh"
#include "Cjt_categories.hh"

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
    vector<int> punts;
    BinTree<pair<int, string>> partits;
    bool jugat;
    vector<string> anteriors_participants;

/** @brief Llegeix la inscripcio a un torneig
    \pre Per el canal habitual d'entrada trobem un int que representa
     el numero d'inscrits i seguidament n enters que representen la seva
    posició al ranking.
    \post s'ha omplert el vector participants amb el ranking i el nom de
     tots els participants.
*/
    void llegir_inscripcio(Cjt_jugadors& jugadors);

    void imprimir_emparellaments(BinTree<pair<int,string>>& a, bool left, bool pare,int prof);

    void crear_emparellaments(BinTree<pair<int,string>>& a, int m);

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

    void eliminar_participant(string nom);

    int consultar_participants();

    void restar_punts(Cjt_jugadors& jugadors);

/** @brief Confecciona i imprimeix els emparellaments d'un torneig
    \pre  Al canal habitual d'entrada hi trobem un enter que representa
     el nombre total d'inscrits al torneig i seguidament les seves posicions.
    \post imprimeix el quadre d'emparellaments del torneig.
*/
    void iniciar_torneig(Cjt_jugadors& jugadors);

    void llegir_resultats(BinTree<pair<int,string>>& a);

    void calcular_guanyadors(BinTree<pair<int,string>>& a, Cjt_categories& categories, int nivell, vector<vector<int>>& estadistiques);

    void imprimir_resultats(BinTree<pair<int,string>>& a);

    void imprimir_punts();

    void finalitzar_torneig(Cjt_jugadors& jugadors, Cjt_categories& categories, vector<string>& participants_estadistiques, vector<int>& punts_estadistiques,vector<vector<int>>& estadistiques);


};
#endif
