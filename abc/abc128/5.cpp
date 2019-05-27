#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

typedef pair<ll, ll>P;
typedef pair<ll, P>PP;

int main(){


    ll N, Q;
    cin >> N >> Q;
    vector<PP>v;
    for(ll i = 0; i < N; i++){
        ll s, t, x;
        cin >> s >> t >> x;
        v.push_back(PP(x, P(s - x, t - x - 1)));
    }
    sort(v.begin(), v.end());
    set<P>S;
    S.insert(P(1111111111LL,-1));
    vector<ll>ans(Q, -1);
    for(ll i = 0; i < Q; i++){
        ll d;
        cin >> d;
        S.insert(P(d, i));
    }
    for(ll i = 0; i < N; i++){
        ll x = v[i].first;
        ll L = v[i].second.first;
        ll R = v[i].second.second;
        for(;;){
            set<P>::iterator it = S.lower_bound(P(L, 0));
            if((*it).first > R)break;
            ans[(*it).second] = x;
            S.erase(it);
        }        
    }
    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }

    return 0;
}