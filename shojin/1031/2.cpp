#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)

int main(){
    
    ll N, D, K;
    cin >> N >> D >> K;
    vector<ll>L(D + 1, 0), R(D + 1, 0);
    rep1(d, D)cin >> L[d] >> R[d];
    rep(i, K){
        ll l, r, t;
        cin >> l >> t;
        r = l;
        rep1(j, D){
            if(R[j] < l || r < L[j])continue;
            l = min(l, L[j]);
            r = max(r, R[j]);
            if(l <= t && t <= r){
                cout << j << endl;
                break;
            }
        }
    }
    
    return 0;
}
