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
    vector<ll>v(N);
    ll sum = 0;
    rep(i, N){
        cin >> v[i];
        sum += v[i];
    }
    ll step_num = sum / (N * (N + 1) / 2);
    if(sum % (N * (N + 1) / 2))return 0;
    stack<ll>S;
    rep(a, N){
        ll b = (a + 1) % N;
        ll tmp = v[b] - v[a] - step_num;
        if(tmp < 0)S.push(-tmp);
    }
    while(!S.empty()){
        ll val = S.top();
        S.pop();
        if(val % N)return 0;
        step_num -= val / N;
    }
    if(step_num)return 0;
    return 1;
}

int main(){

    if(solve())cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}