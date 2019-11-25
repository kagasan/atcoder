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

ll N, M;
string s;

ll check(){
    ll ok = 0;
    for(ll i = 0; i <= N; i++){
        if(s[i] == '1')continue;
        if(ok < i)return 1;
        chmax(ok, i + M);
    }
    return 0;
}


ll step[101010];
ll calc_step(){
    rep(i, 101010)step[i] = INF;
    step[0] = 0;
    ll done = 0;
    for(ll i = 0; i <= N; i++){
        if(s[i] == '1')continue;
        for(;done + 1 <= N && done + 1 <= i + M; done++)chmin(step[done + 1], step[i] + 1);
    }
    return step[N];
}

ll rv[101010];
void solve(){
    rep(i, 101010)rv[i] = INF;
    rv[N] = 0;
    ll done = N;
    for(ll i = N; i >= 0; i--){
        if(s[i] == '1')continue;
        for(;done - 1 >= 0 && done - 1 >= i - M; done--)chmin(rv[done - 1], rv[i] + 1);
    }
    ll lst = 0;
    queue<ll>ans;
    for(ll i = 0; i <= N; i++){
        if(s[i] == '1')continue;
        if(rv[i] != rv[lst]){
            ans.push(i - lst);
            lst = i;
        }
    }
    while(!ans.empty()){
        ll x = ans.front();
        ans.pop();
        cout << x;
        if(!ans.empty())cout << " ";
        else cout << endl;
    }
}

int main(){

    cin >> N >> M;
    cin >> s;
    if(check()){
        cout << -1 << endl;
        return 0;
    }
    calc_step();
    solve();

    return 0;
}