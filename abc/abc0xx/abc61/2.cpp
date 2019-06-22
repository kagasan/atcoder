#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, M;
    cin >> N >> M;
    ll ans[100] = {};
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    for(ll i = 1; i <= N; i++)cout << ans[i] << endl;
    
    return 0;
}