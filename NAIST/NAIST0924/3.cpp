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

class WF{
	public:
	ll N;
	ll makeFlg;
	vector<vector<ll> >cost;
	WF(ll _N, ll INF = 1145141919){
		N = _N + 1;
		cost = vector<vector<ll> >(N, vector<ll>(N, INF));
		makeFlg = 0;
	}
	void add(ll a, ll b, ll c){
		cost[a][b] = min(cost[a][b], c);
		makeFlg = 0;
	}
	void make(){
		if(makeFlg)return;
		makeFlg = 1;
		for(ll i = 0; i < N; i++){
			for(ll j = 0; j < N; j++){
				for(ll k = 0; k < N; k++){
					cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
				}
			}
		}
	}
	ll get(ll a, ll b){
		if(makeFlg == 0)make();
		return cost[a][b];
	}
};

int main(){

    ll N, M;
    cin >> N >> M;
    WF wf(N);
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        wf.add(a, b, 0);
    }
    rep1(i, N){
        vector<ll>ans;
        rep1(j, N){
            if(i == j)ans.push_back(j);
            else if(wf.get(i, j) == 0 && wf.get(j, i) == 0)ans.push_back(j);
        }
        rep(j, ans.size()){
            cout << ans[j];
            if(j + 1 == ans.size())cout << endl;
            else cout << " ";
        }
    }

    return 0;
}