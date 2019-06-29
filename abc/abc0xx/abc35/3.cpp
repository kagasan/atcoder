#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll imos[202020];

int main(){
    
    ll N, Q;
    cin >> N >> Q;
    for(ll i = 0; i < Q; i++){
        ll l, r;
        cin >> l >> r;
        imos[l] ^= 1;
        imos[r + 1] ^= 1;
    }
    for(ll i = 1; i <= N; i++){
        imos[i] ^= imos[i-1];
        cout << imos[i];
    }
    cout << endl;
    
    return 0;
}
