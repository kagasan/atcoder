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

char S[1010][40];
char B[1010][1010];
char hoge[1010];


int main(){

    for(ll N, M, Q; cin >> N >> M >> Q, N;){
		rep(i, Q){
			rep(j, N)cin >> S[i][j];
			rep(j, M)cin >> B[i][j];
		}
		rep(i, M){
			rep(j, Q){
				if(j == 0)hoge[j] = B[j][i];
				else if(B[j][i] != B[j - 1][i])hoge[j] = '1';
				else hoge[j] = '0';
			}
			ll cnt = 0;
			ll tmp = 0;
			rep(j, N){
				ll f = 1;
				rep(k, Q)if(S[k][j] != hoge[k])f = 0;
				if(f){
					cnt++;
					tmp = j;
				}
			}
			if(cnt == 1){
				if(tmp < 10)cout << tmp;
				else cout << (char)('A' + tmp - 10);
			}
			else cout << "?";
		}
		cout << endl;
	}

    return 0;
}