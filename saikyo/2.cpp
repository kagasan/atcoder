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

ll XY[300][300];
ll YZ[300][300];

int main(){

    ll N;
    cin >> N;
    rep(i, N)rep(j, N){
        XY[i][j] = INF;
        YZ[i][j] = 0;
    }
    rep(i, N){
        rep(j, N){
            char c;
            cin >> c;
            if(c == '1')XY[i][j] = 0;
        }
    }
    vector<string>v(N);
    rep(i, N){
        cin >> v[i];
        rep(j, N){
            if(v[i][j] == '0'){
                rep(k, N)if(XY[i][k] == 0){
                    YZ[k][j] = INF;                
                }
            }
        }
    }

    rep(i, N){
        rep(j, N){
            if(v[i][j] == '0'){
                continue;
            }
            ll flg = 1;
            rep(k, N){
                if(XY[i][k] == 0 && YZ[k][j] == 0)flg = 0;
            }
            if(flg){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    rep(i, N){
        rep(j, N){
            if(YZ[i][j] == 0)cout << 1;
            else cout << 0;
        }
        cout << endl;
    }

    return 0;
}