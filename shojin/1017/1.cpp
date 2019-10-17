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
    ll x, y;
    cin >> s;
    cin >> x >> y;
    set<ll>X, Y;
    X.insert(0);
    Y.insert(0);
    
    vector<ll>v;
    s += "T";
    for(ll i = 0, j = 0; i < s.size(); i++){
        if(s[i] == 'F')j++;
        else{
            v.push_back(j);
            j = 0;
        }
    }
    for(ll i = 0; i < v.size(); i++){
        set<ll>S;
        set<ll>::iterator it;
        if(i % 2 == 0){
            for(it = X.begin(); it != X.end(); it++){
                if(i)S.insert(*it - v[i]);
                S.insert(*it + v[i]);
            }
            X = S;
        }
        else{
            for(it = Y.begin(); it != Y.end(); it++){
                S.insert(*it - v[i]);
                S.insert(*it + v[i]);
            }
            Y = S;
        }
    }
    if(X.find(x) != X.end() && Y.find(y) != Y.end()){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}