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

class RMQ{
    public:
    int N;
    ll MAX;
    vector<ll>dat;
    RMQ(int n, ll x){
        N = 1;
        while(N < n)N *= 2;
        dat = vector<ll>(2 * N);
        for(int i = 0; i < 2 * N - 1; i++)dat[i] = x;
        MAX = (1ll) << 62;
    }
    void update(int k, ll x){
        k += N - 1;
        dat[k] = x;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    // [a, b)
    ll query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l)return MAX;
        if(a <= l && r <= b)return dat[k];
        else{
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    ll query(int a, int b){
        return query(a, b, 0, 0, N);
    }
};

int main(){

    ll N;
	cin >> N;
	vector<ll>A(N + 1), B(N + 1);
	rep1(i, N)cin >> A[i] >> B[i];
	ll ans = 0;
	rep1(i, N)ans += A[i];
	for(ll i = 2; i <= N; i++)ans += B[i];

	RMQ rmq(N + 10, 0);
	rep1(i, N)rmq.update(i, A[i]);
	ans += rmq.query(1, N + 1);
    queue<P>Q;
    Q.push(P(1, N));
    while(!Q.empty()){
        ll l = Q.front().first;
        ll r = Q.front().second;
        Q.pop();
        if(l == r)continue;
        ll tmp = 0;
        ll l_r;
        for(ll i = l; i + 1 <= r; i++){
            ll hoge = rmq.query(l, i + 1) + rmq.query(i + 1, r + 1) - rmq.query(l, r + 1) - B[i + 1];
            if(hoge < tmp){
                tmp = hoge;
                l_r = i;
            }
        }

        if(tmp == 0)continue;
        ans += tmp;
        Q.push(P(l, l_r));
        Q.push(P(l_r + 1, r));
    }
    cout << ans << endl;

    return 0;
}