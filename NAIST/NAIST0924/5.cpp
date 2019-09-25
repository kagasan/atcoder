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

class node{
    public:
    ll R, A, W, T;
    bool operator < (const node &n)const{
        return (-(R + T) < -(n.R + n.T));
    }
};

ll dp[5000][2];

void update(){
    rrep1(i, 4500){
        chmax(dp[i][0], dp[i][1]);
        chmax(dp[i][0], dp[i + 1][0]);
        dp[i][1] = -INF;
    }
}

int main(){

    ll N;
    cin >> N;
    vector<node>v(N);
    rep(i, N){
        cin >> v[i].R >> v[i].A >> v[i].W >> v[i].T;
    }
    sort(v.begin(), v.end());
    update();
    rep(i, N){
        ll R = v[i].R, A = v[i].A, W = v[i].W, T = v[i].T;
        for(ll from = R + T; from > 1; from--){
            ll to = from - R;
            if(to < 1)break;
            chmax(dp[to][1], dp[from][0] + A);
            chmax(dp[to][1], dp[from][1] + W);
        }
        update();
    }
    cout << dp[1][0] << endl;

    return 0;
}