#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        string P;
        cin >> P;
        for(int i = 0; i < P.size(); i++){
            if(P[i] == 'S')P[i] = 'E';
            else P[i] = 'S';
        }
        cout << P << endl;
    }

    return 0;
}