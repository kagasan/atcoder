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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	int cnt = 0;
	for(int i = 0; i < (1 << 24); i++){
		int j = (1 << 1) + 1;
		int mp[7][7] = {};
		for(int y = 1, b = 1; y <= 5; y++){
			for(int x = 1; x <= 5; x++, b <<= 1){
				if(j & b)mp[y][x] = 1;
				else mp[y][x] = 2;
			}
		}
		int hoge[3] = {};
		int flg[7][7] = {};
		for(int y = 1; y <= 5; y++){
			for(int x = 1; x <= 5; x++){
				if(flg[y][x])continue;
				hoge[mp[y][x]]++;
				queue<P>Q;
				Q.push(P(x, y));
				flg[y][x] = 1;
				while(!Q.empty()){
					ll tx = Q.front().first;
					ll ty = Q.front().second;
					Q.pop();
					rep(k, 4){
						if(flg[ty + dy[k]][tx + dx[k]])continue;
						if(mp[ty][tx] != mp[ty + dy[k]][tx + dx[k]])continue;
						flg[ty + dy[k]][tx + dx[k]] = 1;
						Q.push(P(tx + dx[k], ty + dy[k]));
					}
				}
				if(hoge[1] == 1 && hoge[2] == 1)cnt++;
			}
		}
		
	}
	cout << cnt << endl;
	// 16777216

    return 0;
}