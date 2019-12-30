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

ll N, M;
V v;

ll check(ll x){
    ll sum = 0;
    rep(i, N){
        if(v[i] + v[0] < x)continue;
        ll ok = 0, ng = N;
        while(ok + 1 < ng){
            ll mid = (ok + ng) / 2;
            if(v[i] + v[mid] >= x)ok = mid;
            else ng = mid;
        }
        sum += ng;
    }
    return sum;
}

ll solve(ll x){
    V t(N);
    rep(i, N){
        if(i == 0)t[i] = v[i];
        else t[i] = t[i - 1] + v[i];
    }
    ll sum = 0;
    rep(i, N){
        if(v[i] + v[0] < x)continue;
        ll ok = 0, ng = N;
        while(ok + 1 < ng){
            ll mid = (ok + ng) / 2;
            if(v[i] + v[mid] >= x)ok = mid;
            else ng = mid;
        }
        sum += v[i] * ng + t[ok];
    }
    return sum;
}

int main(){

    cin >> N >> M;
    v = V(N);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    ll ng = 0, ok = INF;
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid) <= M)ok = mid;
        else ng = mid;
    }
    // cout << ok << ", " << check(ok)<< endl;

    cout << solve(ok) + (M - check(ok)) * (ok - 1)<< endl;
    return 0;
}