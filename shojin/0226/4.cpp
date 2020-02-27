//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll counter = 0;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}
ll solve(ll a, ll b){
    counter = 0;
    gcd(a, b);
    return counter;
}

ll A[45], B[45];

int main(){

    A[0] = 1;
    B[0] = 1;
    rep1(i, 40){
        B[i] = A[i - 1];
        A[i] = A[i - 1] + B[i - 1];
    }

    // rep(i, 41)cout << i << " : " << A[i] << ", " << B[i] << endl;
    // rep(i, 41)cout << i << " : " << solve(A[i], B[i]) << endl;
    ll K;
    cin >> K;
    cout << A[K] << " " << B[K] << endl;

    return 0;
}