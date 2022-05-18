#ifndef CONJ_CAT_HH
#define CONJ_CAT_HH


#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

class Cjt_categories {

private:
    int C, K;
    vector<string> noms;
    vector<vector<int>> puntuacio;


public:

/** @brief Constructora de la classe
    \pre C i K son dos enters no negatius.
    \post el resultat es un conjunt de C categories i K nivells com a maxim.
*/
    Cjt_categories(int C, int K);

/** @brief esborra automaticament els objectes locals en sortir
     d'un ambit de visibilitat.
*/ 
    ~Cjt_categories();

/** @brief Llegeix un conjunt de categories
    \pre  estan preparats al canal estandard d'entrada un enter que representa
     el nombre total de categories i un altre enter que representa el nombre 
     màxim de nivells i les dades d'aquests diferents nivells.
    \post el parametre implicit conte el conjunt de categories llegits
     del canal estandard d'entrada.
*/
    void llegir_categories();

/** @brief Escriu un conjunt de categories
    \pre  cert.
    \post s'han escrit pel canal estandard de sortida les categories del
     parametre implicit en ordre ascendent per identificador, el nom i la 
     taula de punts de cada categoria.
*/
    void imprimir_categories();
    
/** @brief Retorna el numero de categories del conjunt
    \pre  cert.
    \post el resultat es el numero de categories del parametre implicit.    .
*/ 
    int num_categories();
    
    string nom_categoria(int num);
    
  
};
#endif
