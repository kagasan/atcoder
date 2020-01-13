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
double X[50], Y[50];

double check(double x, double y){
    double ret = 0;
    rep(i, N)chmax(ret, hypot(x - X[i], y - Y[i]));
    return ret;
}

double solve(ll a, ll b, ll c){
    double x = 0, y = 0;
    return check(x, y);
}

int main(){
    
    cin >> N;
    rep(i, N)cin >> X[i] >> Y[i];
    double ans = INF;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            for(ll k = j + 1; k < N; k++){
                chmin(ans, solve(i, j, k));
            }
        }
    }
    printf("%.10f\n", ans);    
        
    return 0;
}