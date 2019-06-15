#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

int main(){

    ll N, M;
    cin >> N >> M;
    set<ll>S;
    S.insert(1145141919);
    vector<P>v(M);
    for(ll i = 0; i < M; i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i = 0; i < M; i++){
        ll a = v[i].second;
        ll b = v[i].first;
        ll p = *S.lower_bound(a);
        if(p < b)continue;
        ans++;
        S.insert(b - 1);
    }
    cout << ans << endl;

    return 0;
}
