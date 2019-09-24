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

class MIN_MAX_QUEUE{
    private:
    unordered_map<ll, ll>cnt;
    ll sz;
    priority_queue<ll>mx_que;
    priority_queue<ll, vector<ll>, greater<ll> >mn_que;

    public:
    MIN_MAX_QUEUE(){
        sz = 0;
    }
    void push(ll x){
        cnt[x]++;
        sz++;
        mx_que.push(x);
        mn_que.push(x);
    }
    void pop(ll x){
        if(cnt[x] <= 0)return;
        sz--;
        cnt[x]--;
    }
    ll size(){
        return sz;
    }
    ll min(){
        if(sz <= 0)return 0;
        while(cnt[mn_que.top()] <= 0)mn_que.pop();
        return mn_que.top();
    }
    ll max(){
        if(sz <= 0)return 0;
        while(cnt[mx_que.top()] <= 0)mx_que.pop();
        return mx_que.top();
    }

};

ll A[202020];

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
    MIN_MAX_QUEUE mmq;
    for(ll i = 0; i < K; i++)mmq.push(A[i]);
    ll ans = 0;
    ll def = 0;
    for(ll i = 1; i + K - 1 <= N; i++){
        ll l = i, r = l + K - 1;
        ll mn = mmq.min();
        ll mx = mmq.max();
        mmq.pop(A[l - 1]);
        mmq.push(A[r]);
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