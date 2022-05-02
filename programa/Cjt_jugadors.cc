#include "Cjt_jugadors.hh"

Cjt_jugadors::Cjt_jugadors() {
    ranking = vector<pair<int,map<string,Jugador>::iterator>>();
}

Cjt_jugadors::~Cjt_jugadors() {
        
}

void Cjt_jugadors::llegir_jugadors() {
    int P;
    cin >> P;
    for (int i = 0; i < P; ++i) {
        string nom;
        cin >> nom;
        nou_jugador(nom, true);  
    }
}

void Cjt_jugadors::imprimir_jugadors() {
    cout << endl << ranking.size() << endl;
    map<string,Jugador>::iterator end = jugadors.end();
    for (map<string,Jugador>::iterator it = jugadors.begin(); it != end; ++it) {
        (*it).second.escriure_jugador(false, ranking[((*it).second).consultar_posicio() -1].first);
    }
}

void Cjt_jugadors::imprimir_ranking() {
    cout << endl;
    int size = ranking.size();
    for (int i = 0; i < size; ++i) {
        cout << i+1 << " ";
        ((*(ranking[i].second)).second).escriure_jugador(true, ranking[i].first);
    }
}

void Cjt_jugadors::nou_jugador(string nom, bool first) {
    Jugador J(nom, jugadors.size()+1);
    pair<map<string,Jugador>::iterator,bool> trobat = jugadors.insert(pair<string,Jugador>(nom,J));
    if (trobat.second) {
        ranking.push_back(pair<int,map<string,Jugador>::iterator>(0,trobat.first));
        if (not first) cout << ranking.size() << endl;;
    }
    else cout << "error: ya existe un jugador con ese nombre" << endl;
}

void Cjt_jugadors::baixa_jugador(string nom) {
    map<string,Jugador>::iterator trobat = jugadors.find(nom); 
    if (trobat != jugadors.end()) {
        
        int size = ranking.size();
        for (int i = ((*trobat).second).consultar_posicio(); i <size; ++i) {
                ((*(ranking[i].second)).second).sumar_posicio();
                ranking[i-1] = ranking[i];
                
                
        }
        ranking.pop_back();
        
        //map<string,Jugador>::iterator end = jugadors.end();
        //for (map<string,Jugador>::iterator it = trobat;  it != end; ++it) {
        //    ((*it).second).sumar_posicio();
        //}
        jugadors.erase(trobat);
        cout << ranking.size() << endl;
        
    }
    else cout << "error: el jugador no existe" << endl;
}

void Cjt_jugadors::consultar_jugador(string nom) {
    map<string,Jugador>::iterator trobat = jugadors.find(nom);
    if (trobat!=jugadors.end()) {
        ((*trobat).second).escriure_jugador(false, ranking[((*trobat).second).consultar_posicio() -1].first);
    }
    else cout << "error: el jugador no existe" << endl;
}

void Cjt_jugadors::actualitzar_ranking(const vector<pair<int,int>>& v, bool sumar) {
    v.size();
    if (sumar) cout << "hola" << endl;
}

void Cjt_jugadors::actualitzar_estadistiques(vector<pair<int,vector<int> > >& stats) {
    int size = stats.size();
    for (int i = 0; i < size; ++i) {
        (*(ranking[stats[i].first-1].second)).second.modificar_estadistiques(stats[i].second);
    }
}
    
string Cjt_jugadors::nom_jugador(int n) {
    return (*(ranking[n-1].second)).first;
}

