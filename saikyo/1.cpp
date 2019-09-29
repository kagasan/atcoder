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
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}
void solve(){
    ll N, M;
    cin >> N >> M;
    vector<ll>A(N), B(M);
    set<P>AS, BS;
    AS.insert(P(INF, INF));
    BS.insert(P(INF, INF));    
    rep(i, N){
        cin >> A[i];
        AS.insert(P(A[i], i));
    }
    rep(i, M){
        cin >> B[i];
        BS.insert(P(B[i], i));
    }
    ll w = 1;
    for(;;){
        P a(INF, INF), b(INF, INF);
        rep(i, N){
            P p = ijo_min(AS, P(A[i] + w, 0));
            if(p.first == INF)continue;
            chmin(a, P(p.first - A[i], i));
        }
        rep(i, M){
            P p = ijo_min(BS, P(B[i] + w, 0));
            if(p.first == INF)continue;
            chmin(b, P(p.first - B[i], i));
        }
        if(a.first == INF || b.first == INF){
            cout << -1 << endl;
            return;
        }
        if(a.first == b.first){
            ll a0 = a.second;
            ll a1 = ijo_min(AS, P(A[a0] + w, 0)).second;
            ll b0 = b.second;
            ll b1 = ijo_min(BS, P(B[b0] + w, 0)).second;
            cout << a0 << " " << b1 << " " << a1 << " " << b0 << endl;
            return;
        }
        w = max(a.first, b.first);
    }
}

int main(){

    solve();
    

    return 0;
}