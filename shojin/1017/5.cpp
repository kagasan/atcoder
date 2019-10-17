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

vector<ll>path[10101];
ll flg[10101];

int main(){

    ll N, M;
    cin >> N >> M;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    ll ans = -1;
    rep1(i, N){
        if(flg[i])continue;
        ans++;
        queue<ll>Q;
        Q.push(i);
        flg[i] = 1;
        while(!Q.empty()){
            ll idx = Q.front();
            Q.pop();
            rep(j, path[idx].size()){
                ll to = path[idx][j];
                if(flg[to])continue;
                flg[to] = 1;
                Q.push(to);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
