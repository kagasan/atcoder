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

    string s;
    cin >> s;
    ll cnt[256] = {};
    rep(i, s.size())cnt[s[i] - 'a']++;
    ll odd = 0, even = 0;
    priority_queue<ll, vector<ll>, greater<ll> >Q;
    rep(i, 26){
        if(cnt[i] % 2)Q.push(1);
        even += cnt[i] / 2;
    }
    if(Q.empty()){
        cout << s.size() << endl;
        return 0;
    }
    rep(i, even){
        Q.push(Q.top() + 2);
        Q.pop();
    }
    cout << Q.top() << endl;
    
    return 0;
}