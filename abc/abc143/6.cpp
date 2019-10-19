#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N;
vector<ll>v;
ll ans[303030];

ll f(ll idx){
    priority_queue<ll, vector<ll>, greater<ll> >Q;
    rep(i, idx)Q.push(0);
    for(ll i = 0; i < v.size(); i++){
        ll t = Q.top();
        Q.pop();
        Q.push(t + v[i]);
    }
    return Q.top();
}

int main(){

    cin >> N;
    map<ll, ll>mp;
    rep(i, N){
        ll x;
        cin >> x;
        mp[x]++;
    }
    for(map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++){
        v.push_back((*it).second);
    }
    sort(v.begin(), v.end(), greater<ll>());
    for(ll i = 1; i <= N; i++){
        ans[i] = f(i);
        if(ans[i] == 0)break;
        ll ok = i, ng = N + 1;
        while(ok + 1 < ng){
            ll p = (ok + ng) / 2;
            if(f(p) == ans[i])ok = p;
            else ng = p;
        }
        for(ll j = i; j <= ok; j++)ans[j] = ans[i];
        i = ok;
    }
    rep1(i, N)cout << ans[i] << endl;

    return 0;
}