#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, X;
    cin >> N >> X;
    ll ans = 1;
    ll d = 0;
    for(ll i = 0; i < N; i++){
        ll l;
        cin >> l;
        d += l;
        if(d <= X)ans++;
    }


    cout << ans << endl;

    return 0;
}