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

char mp[222][222];

ll b_flg[222][2];

ll cal(ll N, ll x){
    vector<ll>dep(N + 1, -1);
    dep[x] = 1;
    ll t = x;
    queue<ll>Q;
    Q.push(x);
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        if(dep[idx] > dep[t])t = idx;
        rep1(to, N){
            if(mp[idx][to] == '0')continue;
            if(dep[to] < 0){
                dep[to] = dep[idx] + 1;
                Q.push(to);
            }
        }
    }
    return dep[t];
}

int main(){

    ll N;
    cin >> N;
    rep1(i, N)rep1(j, N)cin >> mp[i][j];
    queue<P>Q;
    Q.push(P(1, 0));
    b_flg[1][0] = 1;
    while(!Q.empty()){
        ll idx = Q.front().first;
        ll b = Q.front().second;
        ll nxt_b = 1 ^ b;
        Q.pop();
        rep1(to, N){
            if(mp[idx][to] == '0')continue;
            if(b_flg[to][nxt_b] == 0){
                b_flg[to][nxt_b] = 1;
                Q.push(P(to, nxt_b));
            }
        }
    }
    rep1(i, N)if(b_flg[i][0] && b_flg[i][1]){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    rep1(i, N)chmax(ans, cal(N, i));
    cout << ans << endl;

    return 0;
}