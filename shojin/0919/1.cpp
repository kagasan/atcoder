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

    string a, b;
    cin >> a >> b;
    while(a.size() < b.size())a = "0" + a;
    while(a.size() > b.size())b = "0" + b;
    if(a == b)cout << "EQUAL" << endl;
    if(a < b)cout << "LESS" << endl;
    if(a > b)cout << "GREATER" << endl;

    return 0;
}