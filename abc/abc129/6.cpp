#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    ll N;
    cin >> N;
    vector<ll>v(N);
    for(ll i = 0; i < N; i++)cin >> v[i];
    ll ans = 0;
    for(ll d = 1; d < N; d++){
        ll score = 0;
        for(ll j = 0; j < N - d; j += d){
            score += v[j] + v[N - 1 - j];
            if((N - 1) % d == 0 && j >= N - 1 - j){
                break;
            }
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
    return 0;
}
