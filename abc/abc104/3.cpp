#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll ans = 1145141919;

    ll D, G;
    cin >> D >> G;
    vector<ll>s(D), p(D), c(D);
    for(ll i = 0; i < D; i++){
        cin >> p[i] >> c[i];
        s[i] = (i + 1) * 100;
    }
    for(ll i = 0; i < (1LL << D); i++){
        ll sum = 0;
        ll cnt = 0;
        for(ll j = 0; j < D && sum < G; j++){
            if((i & (1 << j)) == 0)continue;
            for(ll k = 1; k <= p[j] && sum < G; k++){
                cnt++;
                sum += s[j];
                if(k == p[j])sum += c[j];
            }
        }
        for(ll j = D - 1; j >= 0 && sum < G; j--){
            if((i & (1 << j)))continue;
            for(ll k = 1; k <= p[j] && sum < G; k++){
                cnt++;
                sum += s[j];
                if(k == p[j])sum += c[j];
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}