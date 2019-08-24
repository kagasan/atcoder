#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll M, D;
    cin >> M >> D;
    ll ans = 0;
    for(ll m = 1; m <= M; m++){
        for(ll d = 1; d <= D; d++){
            ll d1 = d % 10;
            ll d10 = d / 10;
            if(d1 >= 2 && d10 >= 2 && d1 * d10 == m)ans++;
        }
    }
    cout << ans << endl;

    return 0;
}