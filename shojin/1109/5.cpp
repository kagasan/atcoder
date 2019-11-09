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

ll N, K;
stack<ll>X, Y, Z;
void solve(){
    cin >> N >> K;
    if(N < K){
        cout << -1 << endl;
        return;
    }
    set<ll>A, C;
    rep(i, N){
        A.insert(i);
        C.insert(N - K + i);
    }
    rrep(i, N){
        
    }
    while(!X.empty()){
        cout << X.top() << " " << Y.top() << " " << Z.top() << endl;
        X.pop();
        Y.pop();
        Z.pop();
    }
}

int main(){

    
    solve();
    
    return 0;
}