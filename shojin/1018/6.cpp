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

vector<P>path[110];
ll solve(ll a, ll b){
    vector<ll>flg(110, -1);
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(0, a));
    while(!Q.empty()){
        P p = Q.top();
        Q.pop();
        ll cst = p.first;
        ll idx = p.second;
        if(flg[idx] != -1)continue;
        flg[idx] = cst;
        if(idx == b)break;
        rep(i, path[idx].size()){
            ll to = path[idx][i].first;
            ll c = cst + path[idx][i].second;
            if(flg[to] == -1)Q.push(P(c, to));
        }
    }
    return flg[b];
}

int main(){

    ll N, K;
    cin >> N >> K;
    rep(i, K){
        ll q, a, b, c;
        cin >> q;
        if(q == 0){
            cin >> a >> b;
            cout << solve(a, b) << endl;
        }
        else{
            cin >> a >> b >> c;
            path[a].push_back(P(b, c));
            path[b].push_back(P(a, c));
        }
    }

    return 0;
}