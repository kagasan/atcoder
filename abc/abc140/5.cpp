#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll X[101010];
ll Idx[101010];

int main(){

    set<ll>S;
    ll N;
    cin >> N;
    S.insert(-1);
    S.insert(N + 1);
    S.insert(0);
    S.insert(N + 2);
    for(ll i = 1; i <= N; i++){
        cin >> X[i];
        Idx[X[i]] = i;
    }
    ll ans = 0;
    for(ll i = N; i >= 1; i--){
        ll idx = Idx[i];
        set<ll>::iterator it = (S.lower_bound(idx));
        ll mx = *it;
        it++;
        ll mxx = *it;
        it--;
        it--;
        ll mn = *it;
        it--;
        ll mnn = *it;
        if(mn != 0){
            ans += i * (mx - idx) * (mn - mnn);
        }
        if(mx != N + 1){
            ans += i * (idx - mn) * (mxx - mx);
        }
        S.insert(idx);
    }
    cout << ans << endl;

    return 0;
}