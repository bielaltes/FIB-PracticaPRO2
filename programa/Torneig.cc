#include "Torneig.hh"

Torneig::Torneig(int cat) {
    categoria = cat;
    estadistiques = vector<vector<int>> (0,vector<int>(0));
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

void Torneig::crear_imprimir_emparellaments(BinTree<int>& a, int m) {
    if (m+1-a.value() <= num_participants) {
        BinTree<int> l(a.value());
        BinTree<int> r(m+1-a.value());
        crear_imprimir_emparellaments(l,2*m);
        crear_imprimir_emparellaments(r,2*m);
        a = BinTree<int>(a.value(),l,r);
    }
}

void Torneig::imprimir_torneig(BinTree<int>& a, bool left, bool pare,int prof) {
    if (not a.empty()) {
        BinTree<int> l = a.left();
        BinTree<int> r = a.right();
        if (not l.empty()) cout << "(";
        else {
            cout << a.value() << "." << participants[a.value()-1];
            if (left) cout << " ";
        }
        imprimir_torneig(l, true, left ,prof+1);
        imprimir_torneig(r, false, not left,prof+1);
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

void Torneig::restar_punts() {
    actualitzar_ranking(participants,punts,false);
}

void Torneig::iniciar_torneig(Cjt_jugadors& jugadors) {
    llegir_inscripcio(jugadors);

    BinTree<int> a(1);
    crear_imprimir_emparellaments(a,2);
    imprimir_torneig(a, true, true, 1);
    cout << endl;
}
