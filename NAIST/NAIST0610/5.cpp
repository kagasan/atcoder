#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll>P;


int main(){
    
    for(ll N, M; cin >> N >> M, N;){
        vector<ll>mx(N, 0);
        vector<ll>mn(N, 0);
        for(ll i = 0; i < M; i++){
            ll s, k;
            cin >> s >> k;
            for(ll j = 0; j < k; j++){
                ll c;
                cin >> c;
                c--;
                if(k == 1)mn[c] += s;
                mx[c] += s;
            }
        }
        ll ans = 0;
        P x(-1, -1), y(-2, -2);
        for(ll i = 0; i < N; i++){
            if(mx[i] >= x.first){
                swap(x, y);
                x.first = mx[i];
                x.second = i;
            }
            else if(mx[i] >= y.first){
                y.first = mx[i];
                y.second = i;
            }
        }
        for(ll i = 0; i < N; i++){
            if(i == x.second)continue;
            ans = max(ans, mx[x.second] - mn[i]);
        }
        for(ll i = 0; i < N; i++){
            if(i == y.second)continue;
            ans = max(ans, mx[y.second] - mn[i]);
        }
        cout << ans + 1 << endl;
    }
    
    return 0;    
}