/** @file Jugador.hh
    @brief Especificació de la classe Jugador
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;

/** @class Jugador
    @brief Representa un jugador del circuit amb tots els seus atributs.
*/

class Jugador {

private:

    string nom;
    int pos;
    int tornejos_disputat;
    int partits_guanyat;
    int partits_perdut;
    int sets_guanyat;
    int sets_perdut;
    int jocs_guanyat;
    int jocs_perdut;

public:


/** @brief Constructora de la classe
    \pre cert.
    \post el resultat es un jugador amb nom i zero a les estadístiques.
*/
    Jugador(string n, int ultima_pos);


/** @brief Escriu un jugador
    \pre  cert.
    \post s'han escrit els atributs del parametre implicit al canal estandard
     de sortida.
*/
    void escriure_jugador(bool ranking, int punts);

/** @brief Retorna la posicio d'un jugador
    \pre  J és un jugador amb posició.
    \post es retorna la posició de J.
*/
    int consultar_posicio();

    void sumar_posicio();

    void modificar_posicio(int posicio);

/** @brief Modifica les estadistiques d'un jugador
    \pre  el vector te 7 enters que indiquen com s'han de modificar les estadistiques.
    \post s'han modificat correctament les estadístiques del paràmetre implícit.
*/
    void modificar_estadistiques(const vector<int>& stats);
};
#endif
