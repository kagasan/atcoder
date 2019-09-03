#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll>v;
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back(max(0LL, b - N));
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i = 0; i + 1 < M; i++){
        ans += v[i];
    }
    cout << ans << endl;
    
    return 0;    
}