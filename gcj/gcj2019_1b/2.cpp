#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll I[6][6] = {
    {100, -100, -50, 0, 0, 25},
    {-1200, 1200, 100, 0, 0, -50},
    {-400, -600, 1200, 0, 0, -100},
    {1600, -1600, -800, 1000, 0, -100},
    {-1600, 1600, 800, -1000, 1000, -400},
    {2400, -400, -1200, 0, -1000, 600}
};
ll F[6];
ll M[6];

void calc(){
    for(int i = 0; i < 6; i++){
        M[i] = 0;
        for(int j = 0; j < 6; j++){
            M[i] += I[i][j] * F[j];
        }
        M[i] /= 1000;
    }
}

int main(){

    int T, W;
    cin >> T >> W;
    for(int t = 1; t <= T; t++){
        // int W;
        // cin >> W;
        for(int i = 1; i <= 6; i++){
            cout << i << endl << flush;
            cin >> F[i - 1];
        }
        calc();
        for(int i = 0; i < 6; i++){
            cout << M[i];
            if(i == 5)cout << endl << flush;
            else cout << " ";
        }
        int hoge;
        cin >> hoge;
    }

    return 0;
}