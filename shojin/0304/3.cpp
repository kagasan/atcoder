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

string s;
ll A(ll &idx);
ll B(ll &idx);

ll A(ll &idx){
    ll ret = B(idx);
    for(;;){
        if(s[idx] == '+'){
            idx++;
            ret += B(idx);
        }
        else if(s[idx] == '-'){
            idx++;
            ret -= B(idx);
        }
        else break;
    }
    return ret;
}
ll B(ll &idx){
    ll ret = 0;
    if(s[idx] == '('){
        idx++;
        ret = A(idx);
        idx++;
    }
    else{
        for(;'0' <= s[idx] && s[idx] <= '9';idx++){
            ret = 10 * ret + s[idx] - '0';
        }
    }
    return ret;
}


int main(){

    cin >> s;
    ll idx = 0;
    cout << A(idx) << endl;
    
    return 0;
}