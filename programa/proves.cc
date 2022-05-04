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
