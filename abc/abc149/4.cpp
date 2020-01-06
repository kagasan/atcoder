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

ll N, K;
ll p, r, s;

int main(){

    cin >> N >> K;    
    cin >> r >> s >> p;
    string S;
    cin >> S;
    ll ans = 0;

    for(ll i = 0; i < N && i < K; i++){
        for(ll j = i; j < N; j += K){
            if(j - K >= 0 && S[j] == S[j - K]){
                S[j] = '*';
                continue;
            }
            if(S[j] == 'r')ans += p;
            if(S[j] == 's')ans += r;
            if(S[j] == 'p')ans += s;
        }
    }

    cout << ans << endl;

    return 0;
}