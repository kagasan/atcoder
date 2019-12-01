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
    string s;
    cin >> s;    
    ll ans = 0;
    rep(i, N){
        if(s[i] == '3')ans++;
        if(s[i] == '5')ans++;
        if(s[i] == '7')ans++;
    }
    queue<ll>one;
    rep(i, N){
        if(s[i] == '1')one.push(i);
        if(s[i] == '9'){
            if(!one.empty()){
                s[i] = '0';
                s[one.front()] = '0';
                one.pop();
                ans++;
            }
        }
    }
    ll n = 0, o = 0;
    rep(i, N){
        if(s[i] == '9')n++;
        if(s[i] == '1'){
            if(n >= 2){
                n -= 2;
                ans++;
            }
            else o++;
        }
    }
    cout << ans + o / 2 << endl;
    
    return 0;
}