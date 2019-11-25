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

ll A, B, X;
ll d(ll N){
    ll ret = 0;
    for(;N; N/=10)ret++;
    return ret;
}
ll f(ll N){
    return A * N + B * d(N);
}

int main(){
    cin >> A >> B >> X;
    ll ok = 0, ng = 1000000001;
    while(ok + 1 < ng){
        ll p = (ok + ng) / 2;
        if(f(p) <= X)ok = p;
        else ng = p;
    }
    cout << ok << endl;

    return 0;
}