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
vector<ll>A, B;

ll calc_cost(ll NUM){
    ll sum = 0;
    rep(i, N){
        if(A[i] * B[i] <= NUM)continue;
        ll tmp = NUM / B[i];
        sum += A[i] - tmp;
    }
    return sum;
}

int main(){

    cin >> N >> K;
    A = vector<ll>(N);
    B = vector<ll>(N);
    rep(i, N)cin >> A[i];
    rep(i, N)cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<ll>());


    ll ng = -1, ok = A[N - 1] * B[0];
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        if(calc_cost(p) <= K)ok = p;
        else ng = p;
    }
    cout << ok << endl;
    
    return 0;
}