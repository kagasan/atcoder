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

int main(){

    ll N, D, A;
    cin >> N >> D >> A;
    vector<P>v;
    rep(i, N){
        ll x, h;
        cin >> x >> h;
        v.push_back(P(x, h));
    }
    sort(v.begin(), v.end());
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(1145141919810LL, 0));
    ll ans = 0, sum = 0;
    rep(i, N){
        ll x = v[i].first;
        ll h = v[i].second;
        while(x > Q.top().first){
            sum -= Q.top().second;
            Q.pop();
        }
        if(sum >= h)continue;
        ll tmp = 1 + (h - sum) / A;
        if((h - sum) % A == 0)tmp--;
        sum += tmp * A;
        ans += tmp;
        Q.push(P(x + 2 * D, tmp * A));
    }
    cout << ans << endl;
    
    return 0;
}