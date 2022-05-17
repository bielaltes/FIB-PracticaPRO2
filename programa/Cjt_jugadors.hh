/** @file Cjt_jugadors.hh
    @brief Especificació de la classe Cjt_jugadors
*/

#ifndef CONJ_JUG_HH
#define CONJ_JUG_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#include <algorithm>
#endif

using namespace std;


/** @class Cjt_jugadors
    @brief Representa el conjunt de jugadors inscrits al circuit.
*/

class Cjt_jugadors {

private:

    map<string,Jugador> jugadors;
    vector<pair<int,map<string,Jugador>::iterator>> ranking;


public:

/** @brief Constructora de la classe
    \pre cert.
    \post el resultat es un conjunt de jugadors buit.
*/
    Cjt_jugadors();


/** @brief Llegeix un conjunt de jugadors
    \pre  esta preparat al canal estandard d'entrada un enter que representa
     el nombre total de jugadors i les dades d'aquests diferents jugadors.
    \post el parametre implicit conte el conjunt de jugadors llegits
     del canal estandard d'entrada.    .
*/
    void llegir_jugadors();

/** @brief Imprimeix un conjunt de jugadors ordenats lexicograficament
    \pre  cert.
    \post s'han escrit pel canal estandard de sortida els jugadors del
     parametre implicit en ordre ascendent per identificador, el ranking, la posició,
     el nom i els punts de cada jugador del paràmetre implicit.    .
*/
    void imprimir_jugadors();

/** @brief Imprimeix un conjunt de jugadors ordenats per ranking
    \pre  cert.
    \post s'han escrit pel canal estandard de sortida els jugadors del
     parametre implicit en ordre descendent per punts, el nom la posició
     del ranking, els punts i la resta d'estadistiques de cada jugador del paràmetre
     implicit.
*/
    void imprimir_ranking();

/** @brief Afegeix un nou jugador al conjunt
    \pre  nom representa el identificador del nou Jugador i first s'hi es tracta de la lectura
     inicial.
    \post s'ha afegit el jugador J al ranking i conjunt de jugadors del  parametre implicit
     i s'ha imprès el nombre total de jugadors en cas de que el nom sigui vàlid i first sigui fals.
     Si el nom no es vàlid s'imprimeix un missatge d'error.
*/
    void nou_jugador(string nom, bool first);

/** @brief Dona de baixa a un jugador del conjunt
    \pre  nom és l'identificador del jugador J a donar de baixa.
    \post s'ha esborrat el jugador J del parametre implicit i s'ha imprès el nombre
     total de jugadors en cas de que el nom sigui vàlid. En cas contrari s'imprimeix
     un missatge d'error.
*/
    void baixa_jugador(string nom);

/** @brief Es consulta un jugador del conjunt
    \pre  nom representa el identificador del jugador J.
    \post s'han impres el nom, els punts, la posició al ranking i les estadístiques
     del jugador amb identificador de J, en cas de que sigui correcte. En cas contrari
     s'imprimeix un missatge d'error.
*/
    void consultar_jugador(string nom);

/** @brief Suma o resta punts als jugadors del ranking i n'actualitza el ordre
    \pre  participants representa el nom dels jugadors a actualitzar els punts que trobem al vector punts.
     Els punts els sumem o restem depenent si sumar es true o false. El bool ordenar ens diu si hem d'actualitzar
     les posicions o no.
    \post s'ha actualitzar el ranking i s'ha ordenat el vector en cas de que ordenar sigui cert.
*/
    void actualitzar_ranking(const vector<string>& participants,const vector<int>& punts, bool sumar, bool ordenar);

/** @brief Actualitza les estadistiques d'un conjunt de jugadors
    \pre  participants es un vector amb els identificadors d'un seguit de jugadors i estadistiques una matriu de Nx7
     que representa les estadistiques a actualitzar i on N representa la mida del vector participants.
    \post s'han actualitzat les estadístiques dels jugadors.
*/
    void actualitzar_estadistiques(const vector<string>& participants,const vector<vector<int>>& estadistiques);

/** @brief Retorna el nom d'un jugador del parametre implicit.
    \pre  Existeix un jugador amb posició n.
    \post el resultat es el nom del jugador amb posició n.
*/
    string nom_jugador(int n);


};
#endif
