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

ll ad(ll a, ll b){return (a + b) % MOD;}
ll ad(ll a, ll b, ll c){return ad(a, ad(b, c));}
ll ml(ll a, ll b){return (a * b) % MOD;}

class hand{
    public:
    ll r, s, p;
    hand(ll _r = 0, ll _s = 0, ll _p = 0){
        r = _r;
        s = _s;
        p = _p;
    }
};

hand PLUS(hand a, hand b){
    hand ret;
    ret.r = ad(ml(a.r, b.r), ml(a.r, b.s), ml(a.s, b.r));
    ret.s = ad(ml(a.s, b.s), ml(a.s, b.p), ml(a.p, b.s));
    ret.p = ad(ml(a.r, b.p), ml(a.p, b.r), ml(a.p, b.p));
    return ret;
}
hand MINUS(hand a, hand b){
    hand ret;
    ret.r = ad(ml(a.r, b.r), ml(a.r, b.p), ml(a.p, b.r));
    ret.s = ad(ml(a.r, b.s), ml(a.s, b.r), ml(a.s, b.s));
    ret.p = ad(ml(a.s, b.p), ml(a.p, b.s), ml(a.p, b.p));
    return ret;
}
hand MLT(hand a, hand b){
    hand ret;
    ret.r = ad(ml(a.r, b.r), ml(a.s, b.p), ml(a.p, b.s));
    ret.s = ad(ml(a.r, b.p), ml(a.s, b.s), ml(a.p, b.r));
    ret.p = ad(ml(a.r, b.s), ml(a.s, b.r), ml(a.p, b.p));
    return ret;
}

ll N;
char s[202020];
char A;
hand expression(int &idx);
hand term(int &idx);
hand factor(int &idx);

hand expression(int &idx){
    hand ret = term(idx);
    for(;;){
        if(s[idx] == '+'){
            idx++;
            ret = PLUS(ret, term(idx));
        }
        else if(s[idx] == '-'){
            idx++;
            ret = MINUS(ret, term(idx));
        }
        else break;
    }
    return ret;
}

hand term(int &idx){
    hand ret = factor(idx);
    for(;;){
        if(s[idx] == '*'){
            idx++;
            ret = MLT(ret, factor(idx));
        }
        else break;
    }
    return ret;
}

hand factor(int &idx){
    hand ret(1, 1, 1);
    if(s[idx] == '('){
        idx++;
        ret = expression(idx);
        idx++;
    }
    else{
        if(s[idx] == 'R')ret = hand(1, 0, 0);
        if(s[idx] == 'S')ret = hand(0, 1, 0);
        if(s[idx] == 'P')ret = hand(0, 0, 1);
        idx++;
    }
    return ret;
}


int main(){

    cin >> N;
    rep(i, N)cin >> s[i];
    cin >> A;
    int idx = 0;
    hand ans = expression(idx);
    if(A == 'R')cout << ans.r << endl;
    if(A == 'S')cout << ans.s << endl;
    if(A == 'P')cout << ans.p << endl;

    return 0;
}