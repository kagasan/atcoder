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

ll solve(ll N){
    if(N < 100)return 0;
    if(100 <= N && N <= 5000)return N / 100;
    if(6000 <= N && N <= 30000)return 50 + N / 1000;
    if(35000 <= N && N <= 70000)return 80 + (N / 1000 - 30) / 5;
    if(70000 < N)return 89;
    return -1;
}

int main(){

    ll N;
    cin >> N;
    if(solve(N) < 10)cout << "0";
    cout << solve(N) << endl;

    return 0;
}