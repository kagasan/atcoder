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
const ll MOD = 998244353;
const ll NUM = 101010;

P mlt(P a, P b){
    if(a.second < 0 && b.second < 0)return P((a.first * b.first) % MOD, -1);
    if(a.second < 0)return P((a.first * b.first) % MOD, (a.first * b.second) % MOD);
    if(b.second < 0)return P((a.first * b.first) % MOD, (a.second * b.first) % MOD);
    return P((((a.first * b.first) % MOD) + ((a.second * b.second) % MOD)) % MOD, -1);
}

void show(P p){
    if(p.second < 0)cout << p.first << endl;
    else cout << "(" << p.first << ", " << p.second << ")" << endl;
}

char s[NUM];
P expr(ll &idx);
P term(ll &idx);
P factor(ll &idx);

P expr(ll &idx){
    P ret = term(idx);
    return ret;
}
P term(ll &idx){
    P ret = factor(idx);
    for(;;){
        if(s[idx] == '*'){
            idx++;
            ret = mlt(ret, factor(idx));
        }
        else if(s[idx] == ','){
            idx++;
            ret = P(ret.first, factor(idx).first);
        }
        else break;
    }
    return ret;
}
P factor(ll &idx){
    P ret(0, -1);
    if(s[idx] == '('){
        idx++;
        ret = expr(idx);
        idx++;
    }
    else{
        for(;'0' <= s[idx] && s[idx] <= '9'; idx++){
            ret.first = (ret.first * 10 + s[idx] - '0') % MOD;
        }
    }
    return ret;
}

int main(){

    string t;
    cin >> t;
    rep(i, t.size())s[i] = t[i];
    ll idx = 0;
    cout << expr(idx).first << endl;
    
    return 0;
}