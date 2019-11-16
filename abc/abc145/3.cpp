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

ll N;
double x[8], y[8];
double len(ll a, ll b){
    return hypot(x[a] - x[b], y[a] - y[b]);
}    


int main(){

    cin >> N;
    rep(i, N)cin >> x[i] >> y[i];
    vector<ll>v(N);
    rep(i, N)v[i] = i;
    double sum = 0.0;
    ll cnt = 0;
    do{
        cnt++;
        for(ll i = 1; i < N; i++){
            sum += len(v[i-1], v[i]);
        }
    }while(next_permutation(v.begin(), v.end()));
    printf("%.10f\n", sum / cnt);

    return 0;
}