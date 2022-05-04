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

bool cmp(pair<int,map<string,Jugador>::iterator> r1, pair<int,map<string,Jugador>::iterator> r2 ) {
    if (r1.first > r2.first) return true;
    return false;
}

void Cjt_jugadors::actualitzar_ranking(vector<string>& participants, vector<int> punts, bool sumar) {
   int size = participants.size();
   if (sumar){
	   for (int i = 0; i < size; ++i) {
	       ranking[((*(jugadors.find(participants[i]))).second).consultar_posicio()-1].first += punts[i];
	   }
   }
   else {
	   for (int i = 0; i < size; ++i) {
		   ranking[((*(jugadors.find(participants[i]))).second).consultar_posicio()-1].first -= punts[i];
	   }

   }
   sort(ranking.begin(), ranking.end(), cmp);

   size = ranking.size();
   for (int i = 0; i< size; ++i) {
	   ((*(ranking[i].second)).second).modificar_posicio(i+1);
   }
}

void Cjt_jugadors::actualitzar_estadistiques(vector<string>& participants, vector<vector<int>>& estadistiques) {
    int size = participants.size();
    for (int i = 0; i < size; ++i) {
        ((*(jugadors.find(participants[i]))).second).modificar_estadistiques(estadistiques[i]);
    }
}

string Cjt_jugadors::nom_jugador(int n) {
    return (*(ranking[n-1].second)).first;
}
