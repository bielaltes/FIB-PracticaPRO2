/** @file Cjt_tornejos.hh
    @brief Especificació de la classe Cjt_tornejos
*/

#ifndef CONJ_TOR_HH
#define CONJ_TOR_HH

#include "Cjt_jugadors.hh"
#include "Cjt_categories.hh"
#include "Torneig.hh"


#ifndef NO_DIAGRAM
#include <list>
#endif

using namespace std;

/** @class Cjt_tornejos
    @brief Representa el conjunt de tornejos del circuit.
*/

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


/** @brief Llegeix un conjunt de tornejos
    \pre  num_cat representa el nombre de categories al circuit i esta preparat
     al canal estandard d'entrada un enter que representa el nombre total de tornejos
     i seguidament les dades que defineixen aquests diferents tornejos.
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
    void imprimir_tornejos(Cjt_categories& categories);



/** @brief Afegeix un torneig al conjunt
    \pre  nom representa el nom del nou torneig, cat la seva categoria,
     num_categories el nombre total de categories i first si és la lectura
     inicial de tornejos.
    \post s'ha afegit el torneig al parametre implicit si les dades eren correctes
     i s'ha imprès el nomnbre total de tornejos. Altrament s'ha impres un missatge
     d'error.
*/
    void nou_torneig(string nom, int cat, int num_categories, bool first);

/** @brief Dona de baixa un torneig del conjunt
    \pre  nom representa el nom del possible torneig a eliminar i jugadors es un
     Cjt_jugadors.
    \post s'ha eliminat el torneig "nom" al parametre implicit i s'ha imprès el
     nomnbre total de tornejos si el nom és correcte. Altrament s'imprimeix
     un missatge d'error.
*/
    void baixa_torneig(string nom, Cjt_jugadors& jugadors);

    void eliminar_jugador(string nom);

/** @brief Inicia un torneig
    \pre  nom representa el torneig a iniciar, hi ha preparat per el canal d'entrada
     un enter que representa el nombre total d'inscrits i seguidament les posicions
     en el ranking dels inscrits.
    \post el parametre implicit passa a tenir un torneig amb l'estructura
     d'escrita per els inscrits i s'imprimeix el quadre d'emparellaments.
*/
    void iniciar_torneig(string nom, Cjt_jugadors& jugadors);

/** @brief Finalitza un torneig
    \pre  hi ha preparats al canal estandard el nom i els resultats del torneig del
     paràmetre implicit i el torneig ha estat iniciat anteriorment.
    \post s'ha imprès el quadre oficial de resultats, s'ha actualiztat
     el ranking conforme els punts que han guanyat i perdut tots els jugadors
     del torneig i s'ha impres els punts guanyats per els participants.
*/
    void finalitzar_torneig(string nom, Cjt_jugadors& jugadors, Cjt_categories& categories);

    void consultar_torneig(string nom);





};
#endif
