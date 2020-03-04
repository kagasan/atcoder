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

ll N;
char A[500][500];
char B[500][500];
char C[500][500];
void rot(){
    rep(y, N)rep(x, N)C[y][x] = A[y][x];
    rep(y, N)rep(x, N)A[y][x] = C[x][N - y - 1];
}
void show(){
    rep(y, N){
        rep(x, N)cout << A[y][x];
        cout << endl;
    }
    cout << endl;
}
ll diff(){
    ll ret = 0;
    rep(y, N)rep(x, N)if(A[y][x] != B[y][x])ret++;
    return ret;
}
int main(){

    cin >> N;
    rep(y, N)rep(x, N)cin >> A[y][x];
    rep(y, N)rep(x, N)cin >> B[y][x];
    
    ll ans = diff();
    rot();
    chmin(ans, diff() + 1);
    rot();
    chmin(ans, diff() + 2);
    rot();
    chmin(ans, diff() + 1);
    cout << ans << endl;
    
    return 0;
}