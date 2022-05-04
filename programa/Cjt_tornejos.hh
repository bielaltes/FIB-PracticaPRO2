#ifndef CONJ_TOR_HH
#define CONJ_TOR_HH

#include "Cjt_jugadors.hh"
#include "Cjt_categories.hh"
#include "Torneig.hh"


#ifndef NO_DIAGRAM
#include <list>
#endif

using namespace std;

class Cjt_tornejos {

private:
    int num_tornejos;
    map<string,Torneig> tornejos;



public:

/** @brief Constructora de la classe
    \pre cert.
    \post el resultat es un conjunt de tornejos buit.
*/
    Cjt_tornejos();

/** @brief esborra automaticament els objectes locals en sortir
     d'un ambit de visibilitat.
*/
    ~Cjt_tornejos();

/** @brief Llegeix un conjunt de tornejos
    \pre  esta preparat al canal estandard d'entrada un enter que representa
     el nombre total de tornejos i seguidament les dades que defineixen aquests
     diferents tornejos.
    \post el parametre implicit conte el conjunt de tornejos llegits
     del canal estandard d'entrada.
*/
    void llegir_tornejos(int num_cat);


/** @brief Imprimeix un conjunt de tornejos
    \pre  cert.
    \post s'han escrit pel canal estandard de sortida els tornejos del
     parametre implicit en ordre ascendent per identificador, el nom i la
     categoria de cada torneig del circuit.
*/

    int consultar_participants(string nom);

    void imprimir_tornejos(Cjt_categories& categories);

/** @brief Afegeix un torneig al conjunt
    \pre  està preparat per el canal d'entrada la informació d'un nou torneig T.
    \post s'ha afegit el torneig T al parametre implicit i s'ha imprès el
     nomnbre total de tornejos.    .
*/
    void nou_torneig(string nom, int cat, int num_categories, bool first);

/** @brief Dona de baixa un torneig del conjunt
    \pre  està preparat per el canal d'entrada el nom d'un torneig T.
    \post s'ha afegit el torneig T al parametre implicit i s'ha imprès el
     nomnbre total de tornejos si el nom de T és correcte. Altrament s'imprimeix
     un missatge d'error.
*/
    void baixa_torneig(string nom, Cjt_jugadors& jugadors);

/** @brief Inicia un torneig
    \pre  hi ha preparats al canal estandard un string que representa el
     torneig a iniciar, un enter que representa el nombre total d'inscrits
     i seguidament les posicions en el ranking dels inscrits.
    \post el parametre implicit passa a tenir un torneig amb l'estructura
     d'escrita per els inscrits i s'imprimeix el quadre d'emparellaments.    .
*/
    void iniciar_torneig(string nom, Cjt_jugadors& jugadors);

/** @brief Finalitza un torneig
    \pre  hi ha preparats al canal estandard el nom i els resultats del torneig del
     paràmetre implicit i el torneig ha estat iniciat anteriorment.
    \post s'ha imprès el quadre oficial de resultats i s'haactualiztat
     el ranking conforme els punts que han guanyat i perdut tots els jugadors
     del torneig.    .
*/
    void finalitzar_torneig(string nom, Cjt_jugadors& jugadors, Cjt_categories& categories,vector<string>& participants,vector<int>& punts, vector<vector<int>>& estadistiques);





};
#endif
