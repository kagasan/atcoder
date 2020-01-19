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
const ll INF = 1000000000;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll N, M;
ll D[101010];

V path[101010];
map<ll, ll>w[101010];

ll ans[101010];
ll d[101010];

ll I1[202020], I2[202020];

int main(){

    cin >> N >> M;
    vector<P>v;
    rep1(i, N){
        cin >> D[i];
        v.push_back(P(D[i], i));
    }
    sort(v.begin(), v.end());
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
        I1[i] = a;
        I2[i] = b;
    }

    rep(i, N){
        ll idx = v[i].second;
        ll f = 0;
        ll c1 = 0, c2 = 0;
        rep(j, path[idx].size()){
            ll to = path[idx][j];
            if(ans[to] == 1){
                f = 1;
                c1++;
            }
            if(ans[to] == 2){
                f = 1;
                c2++;
            }
        }
        if(f == 0){
            d[idx] = D[idx];
            ans[idx] = 1;
        }
        else{
            ans[idx] = 1;
            if(c2 == 0)ans[idx] = 2;
            rep(j, path[idx].size()){
                ll to = path[idx][j];
                if(ans[to] == 0)continue;
                if(d[to] == D[idx])d[to] = 0;
                w[idx][to] = D[idx];
                w[to][idx] = D[idx];
            }
        }
    }
    rep1(i, N){
        if(d[i] > 0){
            cout << -1 << endl;
            return 0;
        }
    }

    rep1(i, N)cout << (ans[i] == 1 ? "B" : "W");
    cout << endl;
    rep(i, M){
        cout << w[I1[i]][I2[i]] << endl;
    }

    return 0;
}