#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

int main(){

    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll E, F;
    cin >> E >> F;
    cout << A + B + C + D - min(min(A, B), min(C, D)) + max(E, F) << endl;

    return 0;
}