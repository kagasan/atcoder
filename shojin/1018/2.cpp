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

map<ll, ll> prime_factorization(ll N){
    map<ll, ll>cnt;
    for(ll i = 2; i * i <= N; i++){
        while(N % i == 0){
            cnt[i]++;
            N /= i;
        }
    }
    if(N > 1)cnt[N]++;
    return cnt;
}

ll hoge(ll x, ll n){
    ll sum = 0;
    for(ll i = x; ; i += x){
        for(ll j = i; j % x == 0; j /= x)sum++;
        if(sum >= n)return i;
    }
}

ll solve(ll N){
    ll ans = 0;
    map<ll, ll>mp = prime_factorization(N);
    for(map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++){
        ll x = (*it).first;
        ll n = (*it).second;
        chmax(ans, hoge(x, n));
    }
    return ans;
}

int main(){

    ll N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}