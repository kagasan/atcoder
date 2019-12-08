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

vector<ll>path[101010];
ll path_flg[101010];
vector<ll>lang[101010];
ll lang_flg[101010];

int main(){

    ll N, M;
    cin >> N >> M;
    rep1(i, N){
        ll k;
        cin >> k;
        rep(j, k){
            ll l;
            cin >> l;
            path[i].push_back(l);
            lang[l].push_back(i);
        }
    }
    queue<ll>pq, lq;
    pq.push(1);
    path_flg[1] = 1;
    for(ll flg = 1; flg; ){
        flg = 0;
        while(!pq.empty()){
            flg = 1;
            ll idx = pq.front();
            pq.pop();
            rep(i, path[idx].size()){
                ll to = path[idx][i];
                if(lang_flg[to] == 0){
                    lang_flg[to] = 1;
                    lq.push(to);
                }
            }
        }
        while(!lq.empty()){
            flg = 1;
            ll idx = lq.front();
            lq.pop();
            rep(i, lang[idx].size()){
                ll to = lang[idx][i];
                if(path_flg[to] == 0){
                    path_flg[to] = 1;
                    pq.push(to);
                }
            }
        }
    }
    ll cnt = 0;
    rep1(i, N)cnt += path_flg[i];
    if(cnt == N)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}