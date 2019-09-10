#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N, M;
ll A[111];

int main(){
    
    cin >> N >> M;
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(ll k = 1; k <= M; k++){
        for(ll i = 1;; i++){
            if(i == N)break;
            if((A[i] % k) > (A[i + 1] % k)){
                swap(A[i], A[i + 1]);
            }
        }

    }
    for(ll i = 1; i <= N; i++)cout << A[i] << endl;

    return 0;
}