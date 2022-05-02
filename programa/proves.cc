#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#endif
using namespace std;

int main() {
    int num_partits = 0;
    for (int i = 0; i < log2(14); ++i) num_partits += pow(2,i);
    cout << num_partits << endl;
}
