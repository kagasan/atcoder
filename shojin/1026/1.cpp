#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1234567;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

void m_plus(ll &a, ll b){a = (a + b) % MOD;}
void m_minus(ll &a, ll b){a = (a + MOD - b) % MOD;}

ll N, M;
ll h[505050];
ll dp[505050] = {1};

int main(){
    cin >> N >> M;
    rep1(i, N)cin >> h[i];
    rep1(i, N)h[i] += h[i - 1];
    ll l = 0, sum = 0;
    rep1(i, N){
        m_plus(sum, dp[i - 1]);
        for(;l < i; l++){
            if(h[l] >= h[i] - M)break;
            m_minus(sum, dp[l]);
        }
        dp[i] = sum;
    }
    cout << dp[N] << endl;

    return 0;
}