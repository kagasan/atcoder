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

ll A[5050];

int main(){

    ll N;
    cin >> N;
    rep1(i, N)cin >> A[i];
    ll ans = 0;
    rep1(i, N){
        ll a = 0, b = 0;
        for(ll j = 1; j < i; j++)if(A[j] < A[i])a++;
        for(ll j = N; j > i; j--)if(A[j] < A[i])b++;
        ans += a * b;
    }
    cout << a * b << endl;
    
    return 0;
}