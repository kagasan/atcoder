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
template<class T> T miman_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}

ll X[101010];
ll L, Q;
ll step[101010][20];

int main(){

    ll N;
    cin >> N;
    set<P>S;
    rep1(i, N){
        cin >> X[i];
        S.insert(P(X[i], i));
    }
    cin >> L;
    step[N][0] = -1;
    for(ll i = 1; i < N; i++){
        step[i][0] = miman_max(S, P(X[i] + L + 1, 0)).second;
    }
    rep(i, 19){
        rep1(j, N){
            ll idx = step[j][i];
            if(idx < 0){
                step[j][i + 1] = -1;
                continue;
            }
            step[j][i + 1] = step[idx][i];
        }
    }

    cin >> Q;
    rep(i, Q){
        ll a, b;
        cin >> a >> b;
        if(a > b)swap(a, b);
        ll ans = 0;
        while(a < b){
            ll nxt = 0;
            for(; ; nxt++){
                if(step[a][nxt + 1] < 0)break;
                if(step[a][nxt + 1] > b)break;
            }
            ans += (1 << nxt);
            a = step[a][nxt];
        }
        cout << ans << endl;
    }

    return 0;
}