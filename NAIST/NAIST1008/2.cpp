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

int main(){

    ll A, B;
	cin >> A >> B;
	cout << A / B << ".";
	A = (A % B) * 10;
	rep(i, 50){
		if(A < B){
			cout << "0";
			A *= 10;
		}
		else{
			cout << A / B;
			A %= B;
			A *= 10;
		}
	}

	cout << endl;

    return 0;
}