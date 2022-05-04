#include "Torneig.hh"

Torneig::Torneig(int cat) {
    categoria = cat;
    participants = vector<string>(0);
}

Torneig::~Torneig() {

}

void Torneig::llegir_inscripcio( Cjt_jugadors& jugadors) {
    int n;
    cin >> n;
    num_participants = n;
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        participants.push_back(jugadors.nom_jugador(pos));
    }
}

void Torneig::crear_emparellaments(BinTree<pair<int,string>>& a, int m) {
    if (m+1-((a.value()).first) <= num_participants) {
        BinTree<pair<int,string>> l(pair<int,string>((a.value()).first, " "));
        BinTree<pair<int,string>> r(pair<int,string>((m+1-((a.value()).first)), " "));
        crear_emparellaments(l,2*m);
        crear_emparellaments(r,2*m);
        a = BinTree<pair<int,string>>(pair<int,string>(((a.value()).first), ""),l,r);
    }
}

void Torneig::imprimir_emparellaments(BinTree<pair<int,string>>& a, bool left, bool pare,int prof) {
    if (not a.empty()) {
        BinTree<pair<int,string>> l = a.left();
        BinTree<pair<int,string>> r = a.right();
        if (not l.empty()) cout << "(";
        else {
            cout << (a.value()).first << "." << participants[(a.value()).first -1];
            if (left) cout << " ";
        }
        imprimir_emparellaments(l, true, left ,prof+1);
        imprimir_emparellaments(r, false, not left,prof+1);
        if (not left) {
            cout << ")";
            if (not pare and prof!=2) cout << " ";
        }
    }
}

int Torneig::consultar_categoria() {
    return categoria;
}

int Torneig::consultar_participants() {
    return participants.size();
}

void Torneig::restar_punts(Cjt_jugadors& jugadors) {
    jugadors.actualitzar_ranking(participants,punts,false);
}

void Torneig::iniciar_torneig(Cjt_jugadors& jugadors) {
    llegir_inscripcio(jugadors);

    partits = BinTree<pair<int,string>>(pair<int,string>(1, " "));
    crear_emparellaments(partits,2);
    imprimir_emparellaments(partits, true, true, 1);
    cout << endl;
}



void Torneig::llegir_resultats(BinTree<pair<int,string>>& a) {
    string resultat;
    cin >> resultat;
    if (resultat != "0") {
        BinTree<pair<int,string>> l = a.left();
        BinTree<pair<int,string>> r = a.right();
        llegir_resultats(l);
        llegir_resultats(r);
        a = BinTree<pair<int,string>>(pair<int,string> ((a.value()).first, resultat), l, r);
    }
}

void Torneig::calcular_guanyadors(BinTree<pair<int,string>>& a, Cjt_categories& categories, int nivell, vector<vector<int>>& estadistiques) {
    if (not (a.left()).empty()) {
        BinTree<pair<int,string>> l = a.left();
        BinTree<pair<int,string>> r = a.right();
        calcular_guanyadors(l, categories, nivell +1, estadistiques);
        calcular_guanyadors(r, categories, nivell +1, estadistiques);

        //GUANYA DRET
        if ( (((a.value()).second).back()-'0') >= ((a.value()).second[((a.value()).second).size() - 3]-'0') ) {
            a = BinTree<pair<int,string>>(pair<int,string> ((((a.right()).value()).first), (a.value()).second), l, r);
            punts[(((a.left()).value()).first)-1] = categories.consultar_punts(categoria, nivell);

            //partits
            estadistiques[(((a.right()).value()).first) -1][1] +=1;
            estadistiques[(((a.left()).value()).first) -1][2] +=1;

            if ( (((a.value()).second).size()) == 11 ) {
                //sets
                estadistiques[(((a.right()).value()).first) -1][3] +=2;
                estadistiques[((((a.left())).value()).first) -1][3] +=1;

                estadistiques[(((a.right()).value()).first) -1][4] +=1;
                estadistiques[((((a.left())).value()).first) -1][4] +=2;

                //jocs
                estadistiques[(((a.left()).value()).first) -1][5] += (((a.value()).second)[0]-'0')  + (((a.value()).second)[4]-'0') + (((a.value()).second)[8]-'0');
                estadistiques[((((a.right())).value()).first) -1][5] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0') + (((a.value()).second)[10]-'0');

                estadistiques[(((a.left()).value()).first) -1][6] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0') + (((a.value()).second)[10]-'0');
                estadistiques[((((a.right())).value()).first) -1][6] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0') + (((a.value()).second)[8]-'0');

            }
            else if ( (((a.value()).second).size()) == 7) {
                //sets
                estadistiques[(((a.right()).value()).first) -1][3] +=2;
                estadistiques[(((a.left()).value()).first) -1][4] +=2;

                //jocs
                estadistiques[(((a.left()).value()).first) -1][5] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0');
                estadistiques[((((a.right())).value()).first) -1][5] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0');

                estadistiques[(((a.left()).value()).first) -1][6] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0');
                estadistiques[((((a.right())).value()).first) -1][6] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0');

            }

        }
        //GUANYA ESQUERRE
        else {
            a = BinTree<pair<int,string>>(pair<int,string> ((((a.left()).value()).first), (a.value()).second), l, r);
            punts[(((a.right()).value()).first)-1] = categories.consultar_punts(categoria, nivell);

            //partits
            estadistiques[(((a.right()).value()).first) -1][2] +=1;
            estadistiques[(((a.left()).value()).first) -1][1] +=1;

            if ( (((a.value()).second).size()) == 11 ) {
                //sets
                estadistiques[(((a.right()).value()).first) -1][3] +=1;
                estadistiques[(((a.left()).value()).first) -1][3] +=2;

                estadistiques[(((a.right()).value()).first) -1][4] +=2;
                estadistiques[(((a.left()).value()).first) -1][4] +=1;

                //jocs
                estadistiques[(((a.left()).value()).first) -1][5] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0') + (((a.value()).second)[8]-'0');
                estadistiques[(((a.right()).value()).first) -1][5] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0') + (((a.value()).second)[10]-'0');

                estadistiques[(((a.left()).value()).first) -1][6] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0') + (((a.value()).second)[10]-'0');
                estadistiques[(((a.right()).value()).first) -1][6] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0') + (((a.value()).second)[8]-'0');

            }
            else if ( (((a.value()).second).size()) == 7) {
                //sets
                estadistiques[(((a.right()).value()).first) -1][4] +=2;
                estadistiques[(((a.left()).value()).first) -1][3] +=2;

                //jocs
                estadistiques[(((a.left()).value()).first) -1][5] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0');
                estadistiques[(((a.right()).value()).first) -1][5] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0');

                estadistiques[(((a.left()).value()).first) -1][6] += (((a.value()).second)[2]-'0') + (((a.value()).second)[6]-'0');
                estadistiques[(((a.right()).value()).first) -1][6] += (((a.value()).second)[0]-'0') + (((a.value()).second)[4]-'0');
            }
        }


    }
}

void Torneig::imprimir_resultats(BinTree<pair<int,string>>& a){
    if (not (a.left()).empty()) {
        cout << "(" << ((a.left()).value()).first << "."<< participants[((a.left()).value()).first-1]<< " vs "<< ((a.right()).value()).first << "." <<participants[((a.right()).value()).first-1]<<" " << (a.value()).second;
        BinTree<pair<int,string>> l = a.left();
        BinTree<pair<int,string>> r = a.right();
        imprimir_resultats(l);
        imprimir_resultats(r);
        cout << ")";
    }
}

void Torneig::imprimir_punts() {
    int size = participants.size();
    for (int i = 0; i < size; ++i) {
        cout << i+1 << "." << participants[i] << " " << punts[i] << endl;
    }
}

void Torneig::finalitzar_torneig(Cjt_jugadors& jugadors, Cjt_categories& categories, vector<string>& participants_estadistiques, vector<int>& punts_estadistiques,vector<vector<int>>& estadistiques) {

    llegir_resultats(partits);

    punts = vector<int>(num_participants);
    calcular_guanyadors(partits, categories, 1, estadistiques);

    punts[((partits.value()).first) -1] = categories.consultar_punts(categoria, 0);
    imprimir_resultats(partits);
    cout << endl;

    imprimir_punts();

    participants_estadistiques = participants;
    jugadors.actualitzar_estadistiques(participants_estadistiques, estadistiques);

    punts_estadistiques = punts;
    jugadors.actualitzar_ranking(participants_estadistiques, punts_estadistiques, true);
}
