#include "bits/stdc++.h"
#include <random>
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

ll N, K;
string s;

ll h[26][NUM];

class H{
    public:
    ll cnt[26];
    ll value;
    ll idx;
    H(){
        rep(i, 26)cnt[i] = 0;
        idx = 0;
        rep(i, K)cnt[s[i] - 'a']++;
        value = 0;
        rep(i, 26)value ^= h[i][cnt[i]];
    }
    ll step(){
        if(idx + K >= N)return 0;
        cnt[s[idx] - 'a']--;
        idx++;
        cnt[s[idx + K - 1] - 'a']++;
        value = 0;
        rep(i, 26)value ^= h[i][cnt[i]];
        return 1;
    }
};

int main(){

    random_device rd;
    mt19937_64 mt(rd());
    rep(i, 26)rep(j, NUM)h[i][j] = mt();

    cin >> N >> K >> s;
    V v(NUM, 0), flg(NUM, 0);
    H a;
    for(ll i = 0; ;i++){
        v[i] = a.value;
        flg[i] = 1;
        if(a.step() == 0)break;
    }
    set<ll>S;
    for(ll i = 0, j = K; j < N; i++, j++){
        if(flg[j] == 0)break;
        S.insert(v[i]);
        if(S.find(v[j]) != S.end()){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;


    return 0;
}