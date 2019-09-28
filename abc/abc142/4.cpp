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

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){

    ll A, B;
    cin >> A >> B;
    ll X = gcd(A, B);
    set<ll>S;
    for(ll i = 2; i * i <= X; i++){
        while(X % i == 0){
            S.insert(i);
            X /= i;
        }
    }
    if(X != 1)S.insert(X);
    cout << S.size() + 1 << endl;

    return 0;
}
