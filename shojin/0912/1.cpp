#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

vector<ll>path[101010];
ll flg[101010][2];

int main(){

    ll N, M;
    cin >> N >> M;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    flg[1][0] = 1;
    queue<P>Q;
    Q.push(P(1, 0));
    while(!Q.empty()){
        ll idx = Q.front().first;
        ll v = Q.front().second;
        Q.pop();
        ll v2 = v ^ 1;
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(flg[to][v2])continue;
            flg[to][v2] = 1;
            Q.push(P(to, v2));
        }
    }
    
    ll ans = -M;
    ll x = 0, y = 0;
    for(ll i = 1; i <= N; i++)x += flg[i][0];
    for(ll i = 1; i <= N; i++)y += flg[i][1];
    if(x == N)ans += N * (N - 1) / 2;
    else ans += x * y;
    cout << ans << endl;

    return 0;
}