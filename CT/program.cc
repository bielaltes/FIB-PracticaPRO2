
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >>N;

    int num_cat = ceil(log2(N));
    bool first = true;
    cout << "1 " << num_cat << endl << "Cat1" << endl;
    for (int i = num_cat; i>0; --i){
        if (not first) cout << " " <<i;
        else cout << i;
        first = false;
    }
    cout << endl;

    cout << "1" << endl << "Barcelona 1" << endl;

    cout << N << endl;

    int i = 0;
    if (N < pow(27,6)) {
        for(char c1 = 'A'; c1 <= 'Z' and i<N; c1++){
            for(char c2 = 'a'; c2 <= 'z' and i<N; c2++){
                for(char c3 = 'a'; c3 <= 'z' and i<N; c3++){
                    for(char c4 = 'a'; c4 <= 'z' and i<N; c4++){
                        for(char c5 = 'a'; c5 <= 'z' and i<N; c5++){
                            for(char c6 = 'a'; c6 <= 'z' and i<N; c6++){
                                cout << "" << c1 << c2 << c3 << c4 << c5 << c6 << endl;;
                                ++i;
                            }
                        }
                    }
                }
            }
        }
    }
    else cout << "error" << endl;

    cout << "iniciar_torneo Barcelona" << endl;
    cout << N << endl;
    for (int i = 1; i <= N; ++i) {
        cout << i << " ";
    }
    cout << endl;

}
