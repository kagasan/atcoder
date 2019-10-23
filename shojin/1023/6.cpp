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

// 1indexed2dimention[]
class imos2d{
    public:
    vector<vector<ll> >t, v;
    ll h, w, flg;
    imos2d(ll H = 0, ll W = 0){
        flg = 0;
        h = H + 10;
        w = W + 10;
        v = vector<vector<ll> >(h, vector<ll>(w, 0));
        t = vector<vector<ll> >(h, vector<ll>(w, 0));
    }
    void add(ll x, ll y, ll val){
        flg = 0;
        t[y][x] += val;
    }
    void make(){
        flg = 1;
        for(ll y = 1; y < h; y++){
            for(ll x = 1; x < w; x++){
                v[y][x] = t[y][x] + v[y][x - 1];
            }
        }
        for(ll x = 1; x < w; x++){
            for(ll y = 1; y < h; y++){
                v[y][x] += v[y - 1][x];
            }
        }
    }
    ll sum(ll x1, ll y1, ll x2, ll y2){
        if(!flg)make();
        return v[y2][x2] + v[y1 - 1][x1 - 1] - v[y2][x1 - 1] - v[y1 - 1][x2];
    }
};

int main(){

    ll H, W, K;
    cin >> H >> W >> K;
    imos2d J(H, W), O(H, W), I(H, W);
    rep1(y, H)rep1(x, W){
        char c;
        cin >> c;
        if(c == 'J')J.add(x, y, 1);
        if(c == 'O')O.add(x, y, 1);
        if(c == 'I')I.add(x, y, 1);
    }
    rep(i, K){
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << J.sum(x1, y1, x2, y2) << " ";
        cout << O.sum(x1, y1, x2, y2) << " ";
        cout << I.sum(x1, y1, x2, y2) << endl;
    }

    return 0;
}