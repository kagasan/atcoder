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

ll solve(){
    ll N;
    cin >> N;
    vector<ll>v(N), cnt(N, 0);
    rep(i, N){
        cin >> v[i];
        cnt[v[i]]++;
    }
    sort(v.begin(), v.end(), greater<ll>());
    if(v[0] == 1 && N > 2)return 0;
    for(ll i = v[0]; i >= (v[0] + 1) / 2; i--){
        N -= cnt[i];
        if(i + i == v[0]){
            if(cnt[i] != 1)return 0;
        }
        else if(i == (v[0] + 1) / 2){
            if(cnt[i] != 2)return 0;
        }
        else if(cnt[i] < 2)return 0;
    }
    if(N)return 0;
    return 1;
}

int main(){

    if(solve())cout << "Possible" << endl;
    else cout << "Impossible" << endl;


    return 0;
}