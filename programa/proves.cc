#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include "BinTree.hh"
#endif
using namespace std;

int main() {
    BinTree<pair<int,string>> a = BinTree<pair<int,string>> (pair<int,string>(1,"hola"));
    cout << (a.value()).first << endl;
}

(1.Tsitsipas vs 3.Berrettini 7-6,3-6,6-4(1.Tsitsipas vs 5.Bautista 6-2,6-4(1.Tsitsipas vs 9.Monfils 6-4,6-4(8.Cilic vs 9.Monfils 6-4,4-6,4-6))(4.Schwartzman vs 5.Bautista 1-6,6-2,3-6(4.Schwartzman vs 13.Dimitrov 6-1,6-3)(5.Bautista vs 12.Ramos 7-5,7-6)))(7.Alcaraz vs 3.Berrettini 7-6,4-6,6-7(2.Nadal vs 7.Alcaraz 5-7,5-7(7.Alcaraz vs 10.Khachanov 6-3,6-7,7-5))(3.Berrettini vs 6.Carreno 5-7,6-3,6-0(3.Berrettini vs 14.Delbonis 6-4,7-6)(6.Carreno vs 11.Garin 1-0))))
