/** @file Cjt_jugadors.cc
    @brief Codi de la classe Cjt_jugadors
*/

#include "Cjt_jugadors.hh"

Cjt_jugadors::Cjt_jugadors() {
    ranking = vector<pair<int,map<string,Jugador>::iterator>>();
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

bool cmp(pair<int,map<string,Jugador>::iterator>& r1, pair<int,map<string,Jugador>::iterator>& r2 ) {
    if (r1.first == r2.first) return ( ((*(r1.second)).second).consultar_posicio() < ((*(r2.second)).second).consultar_posicio() );
    else if (r1.first > r2.first) return true;
    return false;
}

void Cjt_jugadors::actualitzar_ranking(const vector<string>& participants,const vector<int>& punts, bool sumar, bool ordenar) {
   int size = participants.size();
   for (int i = 0; i < size; ++i) {
        map<string,Jugador>::iterator trobat = (jugadors.find(participants[i]));
        if (trobat != jugadors.end()) {
            if (sumar){
    	       ranking[((*trobat).second).consultar_posicio()-1].first += punts[i];
            }
            else {
    		   ranking[((*trobat).second).consultar_posicio()-1].first -= punts[i];
    	    }

        }
   }
   if (ordenar) sort(ranking.begin(), ranking.end(), cmp);

   size = ranking.size();
   for (int i = 0; i< size; ++i) {
	   ((*(ranking[i].second)).second).modificar_posicio(i+1);
   }
}

void Cjt_jugadors::actualitzar_estadistiques(const vector<string>& participants, const vector<vector<int>>& estadistiques) {
    int size = participants.size();
    for (int i = 0; i < size; ++i) {
        ((*(jugadors.find(participants[i]))).second).modificar_estadistiques(estadistiques[i]);
    }
}

string Cjt_jugadors::nom_jugador(int n) {
    return (*(ranking[n-1].second)).first;
}

void Cjt_jugadors::millor_jugador_sets() {
    cout << endl;


    string guanyador  = "a";
    int posicio = ranking.size();
    double percentatge = 0;
    map<string,Jugador>::iterator it = jugadors.begin();

    while (it != jugadors.end()) {
        double percenatge_jugador = ((*(it)).second).consultar_percentatge();
        if (percenatge_jugador == percentatge) {
            if (((*(it)).second).consultar_posicio() < posicio) {
                guanyador = ((*(it)).first);
                percentatge = percenatge_jugador;
                posicio = ((*(it)).second).consultar_posicio();
            }
        }
        else if (percenatge_jugador > percentatge) {
            guanyador = ((*(it)).first);
            percentatge = percenatge_jugador;
            posicio = ((*(it)).second).consultar_posicio();
        }
        ++it;
    }
    if (percentatge - int(percentatge) == 0) {
        cout << guanyador << " " << int(percentatge) << endl;
    }
    else cout << guanyador << " " << percentatge << endl;






}
