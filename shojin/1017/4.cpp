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

int main(){

    ll N;
    cin >> N;
    stack<P>S;
    rep1(i, N){
        ll x;
        cin >> x;
        if(i == 1)S.push(P(1, x));
        else if(i % 2 == 1){
            P p = S.top();
            S.pop();
            if(p.second == x)S.push(P(p.first + 1, x));
            else{
                S.push(p);
                S.push(P(1, x));
            }
        }
        else{
            P p = S.top();
            S.pop();
            p.first++;
            p.second = x;
            if(!S.empty() && S.top().second == x){
                p.first += S.top().first;
                S.pop();
            }
            S.push(p);
        }
    }
    ll ans = 0;
    while(!S.empty()){
        P p = S.top();
        S.pop();
        if(p.second == 0)ans += p.first;
    }
    cout << ans << endl;

    return 0;
}
