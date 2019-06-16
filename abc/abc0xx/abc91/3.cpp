#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

// 0-indexed 2部マッチング
class BM{
public:
	vector<vector<int> >G;
	vector<int>match;
	vector<int>used;
	BM(int n){
		G.resize(n);
	}
	void addEdge(int from, int to){
		G[from].push_back(to);
		G[to].push_back(from);
	}
	bool dfs(int v){
		used[v] = 1;
		for (int i = 0; i < G[v].size(); i++){
			int u = G[v][i];
			int w = match[u];
			if (w < 0 || (!used[w] && dfs(w))){
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
	int flow(){
		int res = 0;
		match.clear();
		match.resize(G.size(), -1);
		for (int v = 0; v < G.size(); v++){
			if (match[v] < 0){
				used.clear();
				used.resize(G.size(), 0);
				if (dfs(v)){
					res++;
				}
			}
		}
		return res;
	}
};

int main(){

    ll N;
    cin >> N;
    BM bm(N + N);
    vector<ll>X(N), Y(N);
    for(ll i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    for(ll i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        for(ll j = 0; j < N; j++){
            if(X[j] < x && Y[j] < y){
                bm.addEdge(j, N + i);
            }
        }
    }
    cout << bm.flow() << endl;
    return 0;
}