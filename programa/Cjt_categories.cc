#include "Cjt_categories.hh"

Cjt_categories::Cjt_categories(int c, int k) {
    C = c;
    K = k;
    noms = vector<string> (C);
    puntuacio = vector<vector<int>> (C, vector<int> (K));
}

Cjt_categories::~Cjt_categories() {

}

void Cjt_categories::llegir_categories() {
    for (int i = 0; i < C; ++i) {
        cin >> noms[i];
    }
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> puntuacio[i][j];
        }
    }
}

void Cjt_categories::imprimir_categories() {
    cout << endl;
    cout << C << " " << K << endl;
    for (int i = 0; i < C; ++i) {
        cout << noms[i];
        for (int j = 0; j < K; ++j) {
            cout << " " <<puntuacio[i][j];
        }
        cout << endl;
    }
}

int Cjt_categories::num_categories() {
    return C;
}

string Cjt_categories::nom_categoria(int num) {
    return noms[num-1];
}

int Cjt_categories::consultar_punts(int categoria, int nivell) {
    return puntuacio[categoria-1][ nivell];
}
