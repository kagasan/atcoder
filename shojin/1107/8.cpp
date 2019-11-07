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

    ll N;
    cin >> N;
    vector<ll>buka[25];
    vector<ll>C(25, 1);
    for(ll i = 2; i <= N; i++){
        ll b;
        cin >> b;
        buka[b].push_back(i);
    }
    rrep1(i, N){
        if(buka[i].size() == 0)continue;
        ll mn = C[buka[i][0]];
        ll mx = C[buka[i][0]];
        rep(j, buka[i].size()){
            chmin(mn, C[buka[i][j]]);
            chmax(mx, C[buka[i][j]]);
        }
        C[i] += mn + mx;
    }
    cout << C[1] << endl;

    return 0;
}