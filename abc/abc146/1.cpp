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

    string s;
    cin >> s;
    if(s == "SUN")cout << 7 << endl;
    if(s == "MON")cout << 6 << endl;
    if(s == "TUE")cout << 5 << endl;
    if(s == "WED")cout << 4 << endl;
    if(s == "THU")cout << 3 << endl;
    if(s == "FRI")cout << 2 << endl;
    if(s == "SAT")cout << 1 << endl;
    

    return 0;
}