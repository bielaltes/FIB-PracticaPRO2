/** @file Torneig.hh
    @brief Especificació de la classe Torneig
*/

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

/** @class Torneig
    @brief Representa un torneig del circuit i totes les operacions que s'hi
     poden fer en ell.
*/

class Torneig {

private:
    int categoria;
    int num_participants;
    vector<string> participants;
    vector<int> punts;
    //vector<vector<int>> estadistiques;
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

/** @brief Imprimeix els emparellaments del torneig
    \pre a és un BinTree, left ens diu si a és fill esquerre, pare ens diu si
     el pare de a és fill esquerre i prof la profunditat a la que ens trobem.
    \post s'han imprès els emparellaments tal com s'especifica al enunciat de
     la pràctica.
*/
    void imprimir_emparellaments(BinTree<pair<int,string>>& a, bool left, bool pare,int prof);

/** @brief Crea els emparellaments del torneig
    \pre a és un BinTreei m representa la profunditat a la que ens trobem.
    \post s'han creat els emparellaments tal com s'especifica al enunciat de
     la pràctica.
*/
    void crear_emparellaments(BinTree<pair<int,string>>& a, int m);

/** @brief Llegeix els emparellaments del torneig
    \pre a és un BinTree i per el canal estàndar d'entrada trobem un string que representa el
     resultat del partit del node en el que ens trobem.
    \post s'ha escrit a cada node el resultat pertinent.
*/
    void llegir_resultats(BinTree<pair<int,string>>& a);

/** @brief Calcula els guanyadors dels partits i actualitza les estadistiques
    \pre a és un BinTree amb un enter i una string per node, nivell representa la profunditat a la que
     ens trobem i la matriu d'estadistiques té dimensio Nx7 on N representa el nombre de participants
     al torneig.
    \post es calculen el guanyadors de cada node a partir de la string resultat,
     seguidament s'acutualitza l'int que representa el guanyador del partit i totes les estadistiques
     pertinents de cadascun dels participants a la matriu d'estadistiques.
*/
    void calcular_guanyadors(BinTree<pair<int,string>>& a, Cjt_categories& categories, int nivell, vector<vector<int>>& estadistiques);

/** @brief Imprimeix els resultats del torneig
    \pre a és un BinTree que representa el torneig.
    \post s'imprimeixen els resultats dels partits tal com es mostra a l'enunciat de la practica.
*/
    void imprimir_resultats(BinTree<pair<int,string>>& a);

/** @brief Imprimeix els resultats del torneig
    \pre cert
    \post s'imprimeix el contingut del vector participants juntament amb els punts que ha guanyat
     cada jugador en cas de que n'hagi guanyat.
*/
    void imprimir_punts();

public:

/** @brief Constructora de la classe
    \pre l'enter cat representa la categoria del mateix.
    \post el resultat es un torneig amb categoria cat.
*/
    Torneig(int cat);

/** @brief Retorna la categoria del torneig
    \pre  cert.
    \post el resultat es la categoria del parametre implicit.
*/
    int consultar_categoria();

/** @brief Elimina els punts que ha guanyat un jugador al torneig
    \pre  nom representa el identificador d'un jugador.
    \post si nom es un jugador del vector participants posa el
     punts que ha guanyat aquell jugador a 0.
*/
    void eliminar_participant(string nom);

/** @brief Resta els punts que han guanyat els jugadors del torneig.
    \pre  cert.
    \post si el torneig s'ha jugat mai, agafa el vector participants i resta
     els punts del jugadors que hi apareixen.
*/
    void restar_punts(Cjt_jugadors& jugadors);

/** @brief Confecciona i imprimeix els emparellaments d'un torneig
    \pre  Al canal habitual d'entrada hi trobem un enter que representa
     el nombre total d'inscrits al torneig i seguidament les seves posicions.
    \post imprimeix el quadre d'emparellaments del torneig.
*/
    void iniciar_torneig(Cjt_jugadors& jugadors);

/** @brief Llegeix els resultats d'un torneig, en calcula els guanyadors, imprimeix els
    partits jugats i els punts guanyats per els jugadors.
    \pre  Al canal habitual d'entrada hi trobem una sequencia de strings que representa
     els resultats dels partits del torneig en preordre.
    \post es calculen els guanyadors, s'imprimeixen els partits i els punts guanyats per cada
     participants.
*/
    void finalitzar_torneig(Cjt_jugadors& jugadors, Cjt_categories& categories);

};
#endif
