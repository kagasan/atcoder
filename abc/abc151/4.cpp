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
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};

char mp[30][30];
ll H, W;

ll flg[30][30];
ll solve(ll x, ll y){
    if(mp[y][x] == '#')return -1;
    rep(i, 30)rep(j, 30)flg[i][j] = INF;
    queue<P>Q;
    Q.push(P(x, y));
    flg[y][x] = 0;
    ll ret = 0;
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        chmax(ret, flg[y][x]);
        rep(i, 4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(mp[ny][nx] == '#')continue;
            if(flg[ny][nx] < INF)continue;
            flg[ny][nx] = flg[y][x] + 1;
            Q.push(P(nx, ny));
        }
    }
    return ret;
}


int main(){
    
    rep(y, 30)rep(x, 30)mp[y][x] = '#';
    cin >> H >> W;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
    }
    ll ans = 0;
    rep1(y, H)rep1(x, W){
        chmax(ans, solve(x, y));
    }
    cout << ans << endl;
        
    return 0;
}