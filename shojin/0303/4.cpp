#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll M, R;
ll dp[101010][10];

ll mv[10][10];

void init(){
    rep(i, 10)rep(j, 10)mv[i][j] = INF;
    ll dx[4] = {0, 1, 0, -1};
    ll dy[4] = {1, 0, -1, 0};
    char mp[6][6] = {
        "#####",
        "#789#",
        "#456#",
        "#123#",
        "#0###",
        "#####"
    };
    rep1(y, 4)rep1(x, 3)if(mp[y][x] != '#'){
        ll n = mp[y][x] - '0';
        queue<P>Q;
        Q.push(P(y, x));
        mv[n][n] = 0;
        while(!Q.empty()){
            ll ny = Q.front().first;
            ll nx = Q.front().second;
            ll f = mp[ny][nx] - '0';
            Q.pop();
            rep(i, 4){
                ll ty = ny + dy[i];
                ll tx = nx + dx[i];
                ll t = mp[ty][tx] - '0';
                if(mp[ty][tx] == '#')continue;
                if(mv[n][t] < INF)continue;
                Q.push(P(ty, tx));
                mv[n][t] = mv[n][f] + 1;
            }
        }
    }
}

int main(){
    init();
    rep(i, 101010)rep(j, 10)dp[i][j] = INF;
    cin >> M >> R;
    priority_queue<IP, vector<IP>, greater<IP> >Q;
    Q.push(IP(0, P(0, 0)));
    while(!Q.empty()){
        ll cost = Q.top().first;
        ll r = Q.top().second.first;
        ll p = Q.top().second.second;
        Q.pop();
        if(dp[r][p] < INF)continue;
        dp[r][p] = cost;
        if(r == R){
            cout << cost << endl;
            break;
        }
        rep(i, 10){
            ll rr = (r * 10 + i) % M;
            if(dp[rr][i] < INF)continue;
            Q.push(IP(cost + 1 + mv[p][i], P(rr, i)));
        }
    }

    return 0;
}