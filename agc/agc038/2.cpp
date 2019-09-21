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
// 1-indexed BIT
class BIT{
    public:
    vector<ll>bit;
    int N;
    void init(int n){
        N = n;
        bit = vector<ll>(N, 0);
    }
    // [1, n] = {}
    BIT(int n = 0){
        init(n);
    }
    // sum [1, i]
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    ll sum(ll l, ll r){
        if(l > r)return 0;
        if(l == 1)return sum(r);
        return sum(r) - sum(l - 1);
    }
    void add(int i, ll x){
        if(i == 0)return;
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
};

ll A[202020];

ll poped[202020];
priority_queue<ll>MAX_Q;
priority_queue<ll, vector<ll>, greater<ll> >MIN_Q;
void get_mn_mx(ll &mn, ll &mx){
    while(!MAX_Q.empty()){
        if(poped[MAX_Q.top()])MAX_Q.pop();
        else break;
    }
    while(!MIN_Q.empty()){
        if(poped[MIN_Q.top()])MIN_Q.pop();
        else break;
    }
    if(MAX_Q.empty()){
        mn = -INF;
        mx = INF;
        return;
    }
    mn = MIN_Q.top();
    mx = MAX_Q.top();
}
void push(ll x){
    MAX_Q.push(x);
    MIN_Q.push(x);
}

int main(){

    ll N, K;
    cin >> N >> K;
    BIT down(202020);
    rep1(i, N){
        cin >> A[i];
        A[i]++;
        if(A[i] < A[i - 1]){
            down.add(i, 1);
        }
    }
    A[0] = 200020;
    for(ll i = 0; i < K; i++)push(A[i]);
    ll ans = 0;
    ll def = 0;
    for(ll i = 1; i + K - 1 <= N; i++){
        ll l = i, r = l + K - 1;
        ll mn, mx;
        get_mn_mx(mn, mx);
        poped[A[l - 1]] = 1;
        push(A[r]);
        if(down.sum(l + 1, r) == 0){
            def = 1;
            continue;
        }
        if(mn == A[l - 1] && mx < A[r]){
            continue;
        }
        else{
            ans++;
        }
    }

    cout << ans + def << endl;

    return 0;
}