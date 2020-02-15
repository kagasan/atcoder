//ABC007D
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

ll solve(string a){
    
    while(a.size() < 21)a = "0" + a;
    ll eq[25][10] = {};
    ll miman[25][10] = {};
    eq[0][0] = 1;
    rep(i, 20)rep(j, 10)rep(k, 10)if(k != 4 && k != 9){
        if(a[i + 1] == k + '0')eq[i + 1][k] += eq[i][j];
        if(a[i + 1] > k + '0')miman[i + 1][k] += eq[i][j];
        miman[i + 1][k] += miman[i][j];
    }
    
    ll ret = 0;
    rep(i, 10)ret += eq[20][i];
    rep(i, 10)ret += miman[20][i];
    return ret;
}

ll ika_count(ll x){
    if(x <= 0)return 0;
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    return x + 1 - solve(s);
}

int main(){

    for(ll a, b; cin >> a >> b;){
        cout << ika_count(b) - ika_count(a - 1) << endl;
    }
    
    return 0;
}