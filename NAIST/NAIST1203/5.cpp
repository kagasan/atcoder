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

typedef pair<ll, P>IP;

double ans[2222];

int main(){

    rep(i, 2222)ans[i] = 50505050;

    ll N, L;
    cin >> N >> L;
    vector<IP>v(1);
    v[0].first = 0;
    cin >> v[0].second.first >> v[0].second.second;
    rep(i, N){
        ll X, V, D;
        cin >> X >> V >> D;
        v.push_back(IP(X, P(V, D)));
    }
    v.push_back(IP(L, P(1, 0)));
    sort(v.begin(), v.end());

    ans[0] = 0;
    for(ll i = 0; i <= N + 1; i++){
        if(ans[i] >= 50000000){
            cout << "impossible" << endl;
            return 0;
        }
        if(i == N + 1)break;
        for(ll j = i + 1; j <= N + 1; j++){
            ll len = v[j].first - v[i].first;
            if(v[i].second.second < len)continue;
            chmin(ans[j], ans[i] + (double)len / v[i].second.first);
        }
    }
    // for(ll i = 0; i <= N + 1; i++)printf("%lld : %.10f\n", i, ans[i]);
    printf("%.10f\n", ans[N + 1]);

    return 0;
}