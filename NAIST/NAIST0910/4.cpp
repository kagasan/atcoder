#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

template<class T> T ika_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}

ll N, T, Q;
ll A[101010], D[101010];
ll mn, mx;

int main(){
    
    set<ll>S;
    cin >> N >> T >> Q;
    for(ll i = 1; i <= N; i++){
        cin >> A[i] >> D[i];
        if(D[i] == 2)D[i] = -1;
    }
    for(ll i = 1; i + 1 <= N; i++){
        if(D[i] == -1 || D[i + 1] == 1)continue;
        if(A[i + 1] - T < A[i] + T){
            ll p = A[i] + (A[i + 1] - A[i]) / 2;
            if(S.empty())mn = mx = p;
            chmin(mn, p);
            chmax(mx, p);
            S.insert(p);
        }
    }
    for(ll i = 1; i <= Q; i++){
        ll p;
        cin >> p;
        ll to = A[p] + T * D[p];
        if(D[p] == 1 && mx >= A[p]){
            chmin(to, ijo_min(S, A[p]));
        }
        else if(D[p] == -1 && mn <= A[p]){
            chmax(to, ika_max(S, A[p]));
        }
        cout << to << endl;
    }

    return 0;
}