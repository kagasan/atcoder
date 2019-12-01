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

/*
クエリA_iは次のように言い換えられる
「値がA_iの要素を1つ選び，インクリメントする．」
初期状態は値が0の要素*3
選ぶ際の選択肢の数だけ組み合わせがかけられる．
*/

int main(){

    ll N;
    cin >> N;
    ll ans = 1;
    map<ll, ll>cnt;
    cnt[0] = 3;
    rep(i, N){
        ll A;
        cin >> A;
        ans = (ans * cnt[A]) % MOD;
        cnt[A]--;
        cnt[A + 1]++;
    }
    cout << ans << endl;

    return 0;
}