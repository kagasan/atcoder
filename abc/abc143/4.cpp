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


ll imos[2020][2020];

int main(){

    ll N;
    cin >> N;
    vector<ll>v(N + 1, 0);
    rep1(i, N){
        cin >> v[i];
        imos[i][v[i]]++;
    }

    for(ll i = 1; i <= 2005; i++){
        for(ll j = 1; j <= 2005; j++){
            imos[i][j] += imos[i][j - 1];
        }
    }
    for(ll j = 1; j <= 2005; j++){
        for(ll i = 1; i <= 2005; i++){
            imos[i][j] += imos[i - 1][j];
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j = i + 1; j <= N; j++){
            if(j == N)continue;
            ll a = v[i], b = v[j];
            ll mn = max(b - a, a - b);
            ll mx = a + b - 1;
            if(mn > mx)continue;
            ans += imos[N][mx] + imos[j][mn] - imos[j][mx] - imos[N][mn];
            // ll tmp1 = imos[N][mx] + imos[j][mn] - imos[j][mx] - imos[N][mn];
            // ll tmp2 = 0;
            // for(ll k = j + 1; k <= N; k++){
            //     ll c = v[k];
            //     if(mn < c && c <= mx)tmp2++;
            // }
            // if(i == 2 && j == 3){
            //     cout << "#" << mn << " " << mx << endl;
            // }
            // cout << a << " " << b << " " << tmp1 << " " << tmp2 << endl;
        }
    }
    cout << ans << endl;

    return 0;
}