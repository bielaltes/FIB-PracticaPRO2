/** @file Cjt_tornejos.cc
    @brief Codi de la classe Cjt_tornejos
*/

#include "Cjt_tornejos.hh"

Cjt_tornejos::Cjt_tornejos() {
    num_tornejos = 0;
}


void Cjt_tornejos::llegir_tornejos(int num_cat) {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string nom;
        int cat;
        cin >> nom >> cat;
        nou_torneig(nom,cat, num_cat,true);
    }
}

void Cjt_tornejos::imprimir_tornejos(Cjt_categories& categories) {
    cout << endl;
    cout << num_tornejos << endl;
    map<string,Torneig>::iterator it = tornejos.begin();
    for (int i = 0; i < num_tornejos; ++i) {
        cout << (*it).first << " " << categories.nom_categoria(((*it).second).consultar_categoria()) << endl;
        ++it;
    }
}

void Cjt_tornejos::nou_torneig(string nom, int cat, int num_cat,bool first) {
    if ( cat > 0 and cat <= num_cat) {
        Torneig t(cat);
        pair<map<string,Torneig>::iterator,bool> trobat = tornejos.insert(pair<string,Torneig>(nom, t));
        if ( trobat.second) {
            ++num_tornejos;
            if (not first) cout << num_tornejos << endl;
        }
        else cout << "error: ya existe un torneo con ese nombre" << endl;
    }
    else cout << "error: la categoria no existe" << endl;

}

void Cjt_tornejos::baixa_torneig(string nom, Cjt_jugadors& jugadors) {
    map<string,Torneig>::iterator trobat = tornejos.find(nom);
    if ( trobat != tornejos.end()) {
        //ACTUALITZAR RANKING
        ((*(trobat)).second).restar_punts(jugadors);
        tornejos.erase(trobat);
        --num_tornejos;
        cout << num_tornejos << endl;
    }
    else cout << "error: el torneo no existe" << endl;
}

void Cjt_tornejos::eliminar_jugador(string nom) {
    map<string,Torneig>::iterator it;
    map<string,Torneig>::iterator end = tornejos.end();
    for (it = tornejos.begin(); it != end; ++it){
        ((*(it)).second).eliminar_participant(nom);
    }

}

void Cjt_tornejos::iniciar_torneig(string nom, Cjt_jugadors& jugadors) {
    map<string,Torneig>::iterator it = tornejos.find(nom);
    ((*it).second).iniciar_torneig(jugadors);
}

void Cjt_tornejos::finalitzar_torneig(string nom, Cjt_jugadors& jugadors, Cjt_categories& categories) {
    map<string,Torneig>::iterator it = tornejos.find(nom);
    ((*it).second).finalitzar_torneig(jugadors,categories);
}
