#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    double E[30];
    ll K;
    cin >> K;
    for(ll x = K - 1; x >= 0; x--){
        E[x] += E[x + 1];
        E[x] += E[x + 2];
        E[x] += E[x + 3];
        E[x] += E[x + 4];
        E[x] += E[x + 5];
        E[x] += E[x + 6];
        E[x] /= 6;
        E[x] += 1;
    }
    printf("%.10f\n", E[0]);

    return 0;
}