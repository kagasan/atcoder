#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll m_pow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1)(ret *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ret;
}

set<P>S;
ll pc = 0;
ll sz = 0;
void push(ll x){sz++;S.insert(P(x, pc++));}
ll get_min(){return (*S.begin()).first;}
ll get_max(){set<P>::iterator it = S.end();it--;return (*it).first;}
ll pop(){ll tmp = get_min();sz--;S.erase(S.begin());return tmp;}

int main(){

    ll N, A, B;
    cin >> N >> A >> B;
    rep(i, N){
        ll a;
        cin >> a;
        push(a);
    }
    if(A == 1){
        while(sz)cout << pop() << endl;
        return 0;
    }
    for(; B; B--){
        if(get_min() * A > get_max())break;
        ll tmp = pop() * A;
        push(tmp);
    }
    if(B == 0){
        while(sz)cout << pop() << endl;
        return 0;
    }
    ll a = B / N, b = B % N;
    queue<ll>x, y;
    rep(i, N){
        if(i >= b)x.push((pop() * m_pow(A, a)) % MOD);
        else y.push((pop() * m_pow(A, a + 1)) % MOD);
    }
    for(;!x.empty(); x.pop())cout << x.front() << endl;
    for(;!y.empty(); y.pop())cout << y.front() << endl;

    return 0;
}