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

ll N, Q, S, T;
ll A[202020];
ll B[202020];
ll calc(ll idx){
    if(B[idx] > 0)return -B[idx] * S;
    else return -B[idx] * T;
}

int main(){

    cin >> N >> Q >> S >> T;
    for(ll i = 0; i <= N; i++)cin >> A[i];
    for(ll i = 0; i < N; i++){
        B[i] = A[i + 1] - A[i];
    }
    ll sum = 0;
    rep(i, N)sum += calc(i);
    for(ll i = 0; i < Q; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        if(0 < l){
            sum -= calc(l - 1);
            B[l - 1] += x;
            sum += calc(l - 1);
        }
        if(r < N){
            sum -= calc(r);
            B[r] -= x;
            sum += calc(r);
        }
        cout << sum << endl;
    }

    return 0;
}