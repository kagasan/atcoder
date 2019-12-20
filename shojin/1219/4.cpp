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

ll N, K;
vector<ll>a, b;

ll ika_count(ll x){
    ll ret = 0;
    rep(i, N){
        if(a[i] * b[0] > x)continue;
        ll ok = 0, ng = N;
        while(ok + 1 < ng){
            ll p = (ok + ng) / 2;
            if(a[i] * b[p] > x)ng = p;
            else ok = p;
        }
        ret += ok + 1;
    }
    return ret;
}

int main(){

    cin >> N >> K;
    a.resize(N);
    b.resize(N);  
    rep(i, N)cin >> a[i];
    rep(i, N)cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // rep1(i, 20)cout << i << " : " << ika_count(i) << endl;
    // return 0;
    
    ll ng = 0, ok = a[N - 1] * b[N - 1];
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        if(ika_count(p) < K)ng = p;
        else ok = p;
    }
    cout << ok << endl;

    return 0;
}