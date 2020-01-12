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

int main(){

    ll cnt[256] = {};
    ll H, W;
    cin >> H >> W;
    rep(i, H * W){
        char c;
        cin >> c;
        cnt[c]++;
    }        
    priority_queue<ll>Q1, Q2;
    for(char c = 'a'; c <= 'z'; c++)Q1.push(cnt[c]);
    for(ll y = 1; y <= H; y++){
        ll y2 = H - y + 1;
        if(y2 < y)continue;
        for(ll x = 1; x <= W; x++){
            ll x2 = W - x + 1;
            if(x2 < x)continue;
            if(y == y2 && x == x2)Q2.push(1);
            else if(x == x2)Q2.push(2);
            else if(y == y2)Q2.push(2);
            else Q2.push(4);
        }
    }
    while(!Q2.empty()){
        ll n = Q2.top();
        Q2.pop();
        ll m = Q1.top();
        Q1.pop();
        if(n > m){
            cout << "No" << endl;
            return 0;
        }
        Q1.push(m - n);
    }
    cout << "Yes" << endl;
    return 0;
}