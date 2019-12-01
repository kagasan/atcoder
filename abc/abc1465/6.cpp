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

ll t1, t2, a1, a2, b1, b2;
ll sum_a, sum_b;

int main(){

    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    sum_a = t1 * a1 + t2 * a2;
    sum_b = t1 * b1 + t2 * b2;

    if(a1 == b1 || sum_a == sum_b){
        cout << "infinity" << endl;
        return 0;
    }
    if(sum_a < sum_b){
        swap(sum_a, sum_b);
        swap(a1, b1);
        swap(a2, b2);
    }

    if(a1 > b1){
        cout << 0 << endl;
        return 0;
    }

    ll D = sum_a - sum_b;
    ll d = b1 * t1 - a1 * t1;

    ll ans = 1;

    ans += d / D * 2;
    if(d % D == 0)ans--;
    cout << ans << endl;


    return 0;
}