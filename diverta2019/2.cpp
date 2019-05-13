#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ans = 0;
    for(ll r = 0; r <= N; r++){
        for(int g = 0; g <= N; g++){
            ll tmp = R * r + g * G;
            if(tmp > N)continue;
            if((N - tmp) % B == 0)ans++;
        }
    }
    cout << ans << endl;

    return 0;
}