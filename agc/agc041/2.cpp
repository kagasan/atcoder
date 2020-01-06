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

ll N, M, v, p;
V A;
ll tmp[NUM];
ll check(ll idx){
    rep1(i, N)tmp[i] = A[i];
    ll sum = M * v;
    for(ll i = idx; i <= N; i++, sum -= M){
        if(sum <= 0)break;
        tmp[i] += M;
    }
    for(ll i = 1; i < p; i++, sum -= M){
        if(sum <= 0)break;
        tmp[i] += M;
    }
    for(ll i = p; i < idx; i++){
        if(sum <= 0)break;
        ll hoge = tmp[idx] - tmp[i];
        if(hoge < 0)return 0;
        tmp[i] += hoge;
        sum -= hoge;
    }

    if(sum > 0)return 0;
    if(tmp[idx] < tmp[p])return 0;
    return 1;
}

int main(){
    cin >> N >> M >> v >> p;
    A = V(N);
    rep(i, N)cin >> A[i];
    A.push_back(INF);
    sort(A.begin(), A.end(), greater<ll>());
    ll ok = 1, ng = N + 1;
    while(ok + 1 < ng){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;        
    }
    cout << ok << endl;

    return 0;
}

