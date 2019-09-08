#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;

const ll INF = 1145141919;

ll solve(){
    ll N;
    scanf("%lld", &N);
    vector<ll>v(1 << N);
    for(ll i = 0; i < (1 << N); i++){
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    set<P>S;
    S.insert(P(1145141919, 0));
    for(ll i = 0; i < (1 << N); i++){
        if(i == 0){
            S.insert(P(v[i], N));
            continue;
        }
        set<P>::iterator it = S.upper_bound(P(v[i], INF));
        ll val = (*it).first;
        ll cnt = (*it).second;
        S.erase(it);
        if(val == 1145141919)return 0;
        if(cnt > 1)S.insert(P(val, cnt - 1));
        if(cnt > 1)S.insert(P(v[i], cnt - 1));
    }
    return 1;
}

int main(){

    Say(solve());


    return 0;
}