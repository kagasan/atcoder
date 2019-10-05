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

ll cal(string &s){
    ll cnt = 0;
    for(ll i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]){
            s[i] = '*';
            cnt++;
        }
    }
    return cnt;
}

int main(){

    string s;
    cin >> s;
    ll K;
    cin >> K;
    if(s.size() == 1){
        cout << K / 2 << endl;
        return 0;
    }

    string t1 = s, t2 = s, t3 = s;
    ll a1 = 0, a2 = 0, a3 = 0;
    a1 += cal(t1);
    if(t1[t1.size() - 1] == t2[0]){
        t2[0] = '*';
        a2++;
    }
    a2 += cal(t2);
    if(t2[t2.size() - 1] == t3[0]){
        t3[0] = '*';
        a3++;
    }
    a3 += cal(t3);
    // cout << t1 << " : " << a1 << endl;
    // cout << t2 << " : " << a2 << endl;
    // cout << t3 << " : " << a3 << endl;
    
    if(K == 2){
        cout << a1 + a2 << endl;
        return 0;
    }
    if(K == 3){
        cout << a1 + a2 + a3 << endl;
        return 0;
    }
    if(t1 == t2 && t2 == t3){
        cout << a1 * K << endl;
        return 0;
    }
    if(t1 != t2 && t2 == t3){
        cout << a1 + a2 * (K - 1)<< endl;
        return 0;
    }
    if(t1 != t2 && t2 != t3){
        ll A = (K + 1) / 2;
        ll B = K / 2;
        cout << a1 * A + a2 * B << endl;
        return 0;
    }


    return 1;
}