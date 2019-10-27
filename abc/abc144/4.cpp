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

int main(){

    ll a, b, x;
    cin >> a >> b >> x;
    if(x == a * a * b){
        cout << 0 << endl;
        return 0;
    }
    if(2 * x == a * a * b){
        cout << 45 << endl;
        return 0;
    }
    double r;
    if(2 * x < a * a * b){
        r = acos(-1) * 0.5 - atan2(2.0 * x / (a * b), b);
        r = 180 * r / acos(-1);
    }
    if(2 * x > a * a * b){
        r = 180 * atan2(2.0 * (a * a * b - x) / (a * a), a) / acos(-1);
    }
    printf("%.10f\n", r);

    return 0;
}