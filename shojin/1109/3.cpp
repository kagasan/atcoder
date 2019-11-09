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

ll N;
vector<P>v;
string solve(){
    vector<P>st(N);
    rep(i, N)st[i] = P(v[i].second, i);
    sort(st.begin(), st.end());
    rep(i, N)if(st[i].first > v[i].first)return "No";
    rep(i, N)if(st[i].second == i)return "Yes";
    vector<ll>to(N);
    rep(i, N)to[st[i].second] = i;
    vector<ll>flg(N, 0);
    ll cnt = 0;
    rep(i, N){
        if(flg[i])continue;
        ll idx = i;
        ll tmp = -1;
        while(flg[idx] == 0){
            flg[idx] = 1;
            idx = to[idx];
            tmp++;
        }
        cnt += tmp;
    }
    if(cnt <= N - 2)return "Yes";
    for(ll i = 1; i < N; i++){
        ll a0 = st[i - 1].first;
        ll a1 = st[i].first;
        ll b0 = v[i - 1].first;
        ll b1 = v[i].first;
        if(a0 <= b1 && a1 <= b0)return "Yes";
    }
    return "No";
}

int main(){

    cin >> N;
    v = vector<P>(N);
    rep(i, N)cin >> v[i].second;
    rep(i, N)cin >> v[i].first;
    sort(v.begin(), v.end());
    cout << solve() << endl;

    return 0;
}