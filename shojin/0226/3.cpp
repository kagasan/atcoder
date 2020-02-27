//
#include <iostream>
#include <string>
#include <vector>
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

ll x1, y1, r, x2, y2, x3, y3;
ll contain_box(ll x, ll y){
    if(x < x2)return 0;
    if(x > x3)return 0;
    if(y < y2)return 0;
    if(y > y3)return 0;
    return 1;
}
string solve1(){
    if(contain_box(x1, y1 + r) == 0)return "YES";
    if(contain_box(x1, y1 - r) == 0)return "YES";
    if(contain_box(x1 + r, y1) == 0)return "YES";
    if(contain_box(x1 - r, y1) == 0)return "YES";
    return "NO";
}
ll contain_circle(ll x, ll y){
    if((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r)return 1;
    return 0;
}
string solve2(){
    if(contain_circle(x2, y2) == 0)return "YES";
    if(contain_circle(x2, y3) == 0)return "YES";
    if(contain_circle(x3, y2) == 0)return "YES";
    if(contain_circle(x3, y3) == 0)return "YES";
    return "NO";
}

int main(){

    
    cin >> x1 >> y1 >> r;
    cin >> x2 >> y2 >> x3 >> y3;
    cout << solve1() << endl;
    cout << solve2() << endl;

    return 0;
}