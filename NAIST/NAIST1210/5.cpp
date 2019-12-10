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

string s;

string answer(){
    string t = "";
    rep(j, s.size()){
        if(s[j] == '.')t += s[s.size() - 1 - j];
        else t += s[j];
    }
    return t;
}

ll check(ll idx){
    ll to = s.size() - 1 - idx;
    if(s[idx] == '.' || s[to] == '.' || s[idx] == s[to])return 1;
    return 0;
}

string solve(){
    s = "." + s;
    ll goal = (s.size() + 1) / 2;
    ll cnt = 0;
    rep(i, s.size())if(s.size() - 1 - i >= i)cnt += check(i);

    rep(i, s.size()){
        // cout << s << " : " << cnt << " / " << goal << endl;
        if(cnt == goal)return answer();
        if(i + 1 == s.size())break;
        cnt -= check(i);
        cnt -= check(i + 1);
        swap(s[i], s[i + 1]);
        cnt += check(i);
        cnt += check(i + 1);        
    }

    return "NA";
}

int main(){

    cin >> s;
    if(s.size() == 1){
        cout << s << s << endl;
        return 0;
    }
    if(s.size() == 2){
        cout << s << s[0] << endl;
        return 0;
    }
    cout << solve() << endl;

    return 0;
}