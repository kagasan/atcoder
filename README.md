# コピペで使えるテク
# memo
- 入力順序にあまり意味がない場合はsortを考える．
- 木は根を設定してみる。（↑に通じる）
- 難しい問題は簡単な制約で解けないか考える．簡単な制約が解けるなら拡張してみる．
（拡張の例：W*Hの問題についてW*1で考察して，Hに拡張してみる）

# template
[paiza](https://paiza.io/projects/HFQxqtclBAj06LsR8Fux9Q)
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

int main(){

    

    return 0;
}
```

# auto
```cpp
set<ll>S;
V v;
rrep(i, 5){
S.insert(i);
v.push_back(i);
}
// 01234
for(auto x : S)cout << x << endl;
// 43210
for(auto x : v)cout << x << endl;
```

# set(関数)
[詳細](lib/set.md)
```cpp
template<class T> T ika_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}
template<class T> T choka_min(set<T> &S, const T &x){
    return *S.upper_bound(x);
}
template<class T> T miman_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}

set<ll>S;
S.insert(5);
S.erase(5);
if(S.find(9) == S.end())cout << "not found" << endl;
```

# sort, priority_queue
```cpp
// vector/昇順
sort(v.begin(), v.end());

// vector/降順
sort(v.begin(), v.end(), greater<int>());

// priority_queue/昇順
priority_queue<int, vector<int>, greater<int> >Q;

// priority_queue/降順
priority_queue<int>Q;
```

# 累積和,BIT
- [詳細](lib/imos_bit.md)

# MOD
- [詳細](lib/mod.md)

# tree,LCA
- [詳細](lib/tree.md)

# GCD(最大公約数),LCM(最小公倍数)
```cpp
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
```

# struct
```cpp
struct hoge{
    ll a, b, c;
    hoge(ll _a, ll _b, ll _c):a(_a),b(_b),c(_c){}
};
```

# timer
```cpp
// ms timer
struct TIMER{
    std::chrono::system_clock::time_point tp;
    void start(){tp = std::chrono::system_clock::now();}
    TIMER(){start();}
    double now(){return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - tp).count();}
};
```


# string
**vectorみたいに宣言**
```cpp
string s(10, '0');
cout << s << endl;
// 0000000000
```
**一部だけ取り出す**
i番目からn文字
```cpp
string s1 = "0123456789";
string s2 = s1.substr(2, 5);
cout << s2 << endl;
// 23456
```
**反転**
```cpp
string s = "01234";
reverse(s.begin(), s.end());
cout << s << endl;
// 43210
```
**intをstringに**
```cpp
string s = to_string(-100);
cout << s << endl;
// -100
```
**検索置換**
```cpp
bool replace(string &s1, const string &s2, const string &s3){
    int pos = s1.find(s2);
    if(pos == string::npos)return false;
    s1.replace(pos, s2.size(), s3);
    return true;
}
```
```cpp
string replace(string s1, string s2, string s3){
    int pos = s1.find(s2);
    if(pos == string::npos){
        return s1;
    }
    s1.replace(pos, s2.size(), s3);
    return s1;
}
// cout << replace("abcabc", "bc", "d") << endl;
// adabc
```

# vector
**宣言**  
vector<T>変数名(要素数, 初期値);  
もしくは  
vector<T>変数名 = {a, b, c, ...};
```cpp
vector<int>vec(3, 0);
vec[1] = 1;
vec.push_back(-1);
for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}
// 0
// 1
// 0
// -1
```

**sort**  
昇順
```cpp
vector<int>v = {2, 3, 1, 4};
sort(v.begin(), v.end());
for(int i = 0; i < v.size(); i++)cout << v[i];
// 1234
```
降順
```cpp
vector<int>v = {2, 3, 1, 4};
sort(v.begin(), v.end(), greater<int>());
for(int i = 0; i < v.size(); i++)cout << v[i];
// 4321
```

**順列全列挙**  
sortしてから使う
```cpp
vector<int>v;
v.push_back(2);
v.push_back(0);
v.push_back(1);
sort(v.begin(), v.end());
do{
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}while(next_permutation(v.begin(), v.end()));
// 012
// 021
// 102
// 120
// 201
// 210
```
stringでも可
```cpp
string s = "bca";
sort(s.begin(), s.end());
do{
    cout << s << endl;
}while(next_permutation(s.begin(), s.end()));
// abc
// acb
// bac
// bca
// cab
// cba
```
# stack
これいる？
```cpp
stack<int>S;
for(int i = 0; i < 3; i++){
    S.push(i);
}
while(!S.empty()){
    int tmp = S.top();
    S.pop();
    cout << tmp << endl;
}
// 2
// 1
// 0
```
# set
重複した要素を許さないデータ構造  
内部ではソートされて保存される
**宣言,挿入,検索,削除**
```cpp
set<int>S;
S.insert(7);
S.insert(6);
S.insert(5);
S.insert(6);
set<int>::iterator it;
for(it = S.begin(); it != S.end(); it++){
    cout << *it << endl;
}
// 5
// 6
// 7

S.insert(9);

// 要素の検索
if(S.find(9) != S.end())cout << "found" << endl;
else cout << "not found" << endl;
// found

// 要素の削除
S.erase(9);

if(S.find(9) != S.end())cout << "found" << endl;
else cout << "not found" << endl;
// not found
```
**以上の最小**
```cpp
cout << *S.lower_bound(6) << endl;
// 6
```
**以下の最大**
```cpp
it = S.lower_bound(6);
if(*it > 6)it--;
cout << *it << endl;
// 6
```
**超過の最小**
```cpp
cout << *S.upper_bound(6) << endl;
// 7
```
**未満の最大**
```cpp
it = S.lower_bound(6);
it--;
cout << *it << endl;
// 5
```
# priority_queue
降順
```cpp
priority_queue<int>Q;
Q.push(3);
Q.push(1);
Q.push(4);
while(!Q.empty()){
    int p = Q.top();
    Q.pop();
    cout << p << endl;
}
// 4
// 3
// 1
```
昇順
```cpp
priority_queue<int, vector<int>, greater<int> >Q;
Q.push(3);
Q.push(1);
Q.push(4);
while(!Q.empty()){
    int p = Q.top();
    Q.pop();
    cout << p << endl;
}
// 1
// 3
// 4
```
# deque
両端から操作できる
```cpp
deque<int> dq = {3, 1, 4};
// dq = deque<int>(3, 0);
// のようにもかける
for(int i = 0; i < dq.size(); i++){
    cout << dq[i] << endl;
}
// 3
// 1
// 4

dq.pop_front();
dq.pop_back();
dq.push_front(0);
dq.push_back(2);
for(int i = 0; i < dq.size(); i++){
    cout << dq[i] << endl;
}
// 0
// 1
// 2
```

# BIT
1-indexedなデータ構造。  
sum(i)で区間[1, i]の和を計算。  
add(i, x)で足し引きもできる。
```cpp
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
    void add(int i, ll x){
        if(i == 0)return;
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
};
```

# 2d-BIT
1-indexedな2次元BIT.  
1点に足すのと，区間和をlogで行う．
```cpp
// 1-indexed 2d BIT
class BIT2{
    public:
    ll H, W;
    vector<vector<ll> >bit;
    BIT2(ll _H, ll _W){
        H = _H + 5;
        W = _W + 5;
        bit.resize(_H + 10, vector<ll>(_W + 10, 0));
    }
    void add_point(ll x, ll y, ll v){
        for(ll Y = y; Y <= H; Y += Y & -Y){
            for(ll X = x; X <= W; X += X & -X){        
                bit[Y][X] += v;
            }
        }
    }
    ll get_sum(ll x, ll y){
        if(x <= 0 || y <= 0)return 0;
        if(x > W || y > H)return 0;
        ll sum = 0;
        for(ll Y = y; Y > 0; Y -= Y & -Y){
            for(ll X = x; X > 0; X -= X & -X){
                sum += bit[Y][X];
            }
        }
        return sum;
    }
    ll get_sum(ll x1, ll y1, ll x2, ll y2){
        ll tmp = 0;
        tmp += get_sum(x2, y2);
        tmp -= get_sum(x2, y1 - 1);
        tmp -= get_sum(x1 - 1, y2);
        tmp += get_sum(x1 - 1, y1 - 1);
        return tmp;
    }
};
```

# RMQ
0-indexedなデータ構造。  
```cpp
// 0indexed-RMQ[l, r]
class RMQ{
    public:
    ll N;
    vector<ll>mn, mx, L, R;
    RMQ(ll n, ll x = 0){
        for(N = 1; N < n + 5;)N *= 2;
        mn.resize(2 * N, x);
        mx.resize(2 * N, x);
        L.resize(2 * N, -1);
        R.resize(2 * N, -1);
        for(ll i = 0; i < N; i++)L[i + N] = R[i + N] = i;
        for(ll i = N - 1; i > 0; i--){
            L[i] = L[i * 2];
            R[i] = R[i * 2 + 1];
        }
    }
    void add(ll idx, ll x){
        idx += N;
        mn[idx] += x;
        mx[idx] += x;
        for(idx /= 2; idx > 0; idx /= 2){
            mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
            mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
        }
    }
    void update(ll idx, ll x){
        add(idx, x - mn[idx + N]);
    }
    ll get_min(ll l, ll r, ll idx = 1){
        if(l <= L[idx] && R[idx] <= r)return mn[idx];
        if(R[idx * 2] < l)return get_min(l, r, idx * 2 + 1);
        if(r < L[idx * 2 + 1])return get_min(l, r, idx * 2);
        return min(get_min(l, r, idx * 2), get_min(l, r, idx * 2 + 1));
    }
    ll get_max(ll l, ll r, ll idx = 1){
        if(l <= L[idx] && R[idx] <= r)return mx[idx];
        if(R[idx * 2] < l)return get_max(l, r, idx * 2 + 1);
        if(r < L[idx * 2 + 1])return get_max(l, r, idx * 2);
        return max(get_max(l, r, idx * 2), get_max(l, r, idx * 2 + 1));
    }
};
```

# 逆元
```cpp
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b){
        d = extgcd(b,a%b,y,x);
        y -= (a/b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}
ll mod_inverse(ll a, ll m){
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
```
# ワーシャルフロイド
```cpp
class WF{
	public:
	ll N;
	ll makeFlg;
	vector<vector<ll> >cost;
	WF(ll _N, ll INF = 1145141919){
		N = _N + 1;
		cost = vector<vector<ll> >(N, vector<ll>(N, INF));
		makeFlg = 0;
	}
	void add(ll a, ll b, ll c){
		cost[a][b] = min(cost[a][b], c);
		makeFlg = 0;
	}
	void make(){
		if(makeFlg)return;
		makeFlg = 1;
		for(ll i = 0; i < N; i++){
			for(ll j = 0; j < N; j++){
				for(ll k = 0; k < N; k++){
					cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
				}
			}
		}
	}
	ll get(ll a, ll b){
		if(makeFlg == 0)make();
		return cost[a][b];
	}
};
```
```cpp
int cost[100][100];

for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
        cost[i][j] = 200000;
    }
}

for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        for(int k = 0; k < N; k++){
            cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
        }
    }
}
```

# ベルマンフォード
ループを検出できるため，負辺があっても大丈夫．ただし計算量はO(EV).  
ループしない経路に含まれるノードはたかだかV個までなので，V回以上更新されるならループ．
```cpp
class BF{
    public:
    ll N;
    ll INF;
    vector<vector<P> >path;
    vector<vector<ll> >rev;
    vector<ll>dist;
    vector<ll>flg;
    BF(ll n, ll inf){
        N = n + 1;
        INF = inf;
        path = vector<vector<P> >(N);
        rev = vector<vector<ll> >(N);
        dist = vector<ll>(N, INF);
        flg = vector<ll>(N, 1);
    }
    void add(ll a, ll b, ll c){
        path[a].push_back(P(b, c));
        rev[b].push_back(a);
    }
    // loopがあったらtrue(目標ノードに到達できないところでloopする可能性あり)
    // 無関係なノードはadjust()で消しておくと良い
    bool make(ll s){
        dist[s] = 0;
        for(ll i = 0; i < N; i++){
            for(ll v = 0; v < N; v++){
                if(dist[v] == INF)continue;
                for(ll k = 0; k < path[v].size(); k++){
                    ll to = path[v][k].first;
                    ll w = path[v][k].second;
                    if(dist[to] > dist[v] + w){
                        dist[to] = dist[v] + w;
                        if(i == N - 1 && flg[to])return true;
                    }
                }
            }
        }
        return false;
    }
    // 目標ノードに到達できないノードのフラグを0にする
    void adjust(ll t){
        flg = vector<ll>(N, 0);
        queue<ll>Q;
        flg[t] = 1;
        Q.push(t);
        while(!Q.empty()){
            ll q = Q.front();
            Q.pop();
            for(ll i = 0; i < rev[q].size(); i++){
                ll j = rev[q][i];
                if(flg[j])continue;
                flg[j] = 1;
                Q.push(j);
            }
        }
    }
    ll get(ll t){
        return dist[t];
    }
};
```

# UnionFind
0-indexed
[詳細](lib/uf.md)

# 累積和
a番目からb番目までの和が求まる
```cpp
// 1-indexed imos
void imosAct(vector<ll> &VEC){
    for(int i = 1; i < VEC.size(); i++){
        VEC[i] += VEC[i - 1];
    }
}

// sum of [a, b]
ll imosGet(const vector<ll> &VEC, int a, int b){
    return VEC[b] - VEC[a - 1];
}
```
```cpp
// 2d 1-indexed imos
void imosAct2d(vector<vector<ll> > &VEC){
    for(int y = 1; y < VEC.size(); y++){
        for(int x = 1; x < VEC[y].size(); x++){
            VEC[y][x] += VEC[y][x - 1];
        }
    }
    for(int x = 1; x < VEC[0].size(); x++){
        for(int y = 1; y < VEC.size(); y++){
            VEC[y][x] += VEC[y - 1][x];
        }
    }
}

// sum of [[ax, ay], [bx, by]]
ll imosGet2d(const vector<vector<ll> > &VEC, int ax, int ay, int bx, int by){
    return VEC[by][bx] - VEC[by][ax - 1] - VEC[ay - 1][bx] + VEC[ay - 1][ax - 1];
}
```
# 組み合わせの数
[詳細](combination/combination.md)
! 壊れている可能性大

- 並び替え
  - N種の要素を並び替えてできる通りの数
  - 階乗, factorial
  - N! = N * (N - 1) * ... * 2 * 1
- 順列
  - N種の要素からk個取り出して並べる通りの数
  - nPk = n! / (n - k)!
- 組合せ
  - N種の要素からk個を選ぶ通りの数
  - nCk = nPk / k! = n! / (n - k)! / k!
- 重複組合せ  
  - N種の要素からk個を選ぶ通りの数(重複して良い)  
  - nHk = n+k-1Ck = (n + k - 1)! / k! / (n - 1)!

拡張ユークリッドの互除法による逆元(modが素数でなくてもいい)と，modを指定した累乗関数もセット．
```cpp
class Combination{
    private:
    vector<ll>fact, inv;
    ll mod;
    
    public:
    // xのn乗
    ll modpow(ll x, ll n){
        ll res = 1;
        while(n > 0){
            if(n & 1)res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    // /x
    ll modinv(ll x){
        ll y = mod, u = 1, v = 0;
        while(y){
            ll t = x / y;
            x -= t * y; swap(x, y);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if(u < 0)u += mod;
        return u;
    }
    Combination(ll num, ll _mod = 1000000007){
        fact = vector<ll>(2 * num + 10);
        inv = vector<ll>(2 * num + 10);
        mod = _mod;
        fact[0] = 1;
        inv[0] = modinv(fact[0]);
        for(ll i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = modinv(fact[i]);
        }
    }
    // n!(事前に設定した範囲)
    ll factrial(ll n){
        return fact[n];
    }
    ll nPk(ll n, ll k){
        return fact[n] * inv[n - k] % mod;
    }
    ll nCk(ll n, ll k){
        return nPk(n, k) * inv[k] % mod;
    }
    ll nHk(ll n, ll k){
        return nCk(n+k-1, k);
    }
};
```

# 木の直径
```cpp
class Tree{
    public:
    vector<vector<int> >edge;
    vector<int>depth;
    Tree(int num){
        edge = vector<vector<int> >(num);
        depth = vector<int>(num, 0);
    }
    void add(int a, int b){
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    void dfs(int x = 0, int from = -1, int dep = 1){
        depth[x] = dep;
        for(int i = 0; i < edge[x].size(); i++){
            int nxt = edge[x][i];
            if(from == nxt)continue;
            dfs(nxt, x, dep + 1);
        }
    }
    int diameter(){
        dfs();
        int mxIdx = 0;
        for(int i = 0; i < depth.size(); i++){
            if(depth[mxIdx] < depth[i]){
                mxIdx = i;
            }
        }
        dfs(mxIdx);
        int mxDepth = 0;
        for(int i = 0; i < depth.size(); i++){
            mxDepth = max(mxDepth, depth[i]);
        }
        return mxDepth;
    }
};
```

# エラトステネスの篩
```cpp
class Era{
    public:
    vector<int>prime;
    vector<int>imos;
    Era(int num = 0){
        if(num < 2)return;
        prime = vector<int>(num + 1, 1);
        prime[0] = 0;
        prime[1] = 0;
        for(int i = 2; i * i <= num; i++){
            if(prime[i] == 0)continue;
            for(int j = i + i; j <= num; j += i){
                prime[j] = 0;
            }
        }
        imos = vector<int>(num + 1, 0);
        for(int i = 1; i <= num; i++){
            imos[i] = imos[i - 1] + prime[i];
        }
    }
};
```

# 素因数分解
```cpp
map<ll, ll> prime_factorization(ll N){
    map<ll, ll>cnt;
    for(ll i = 2; i * i <= N; i++){
        while(N % i == 0){
            cnt[i]++;
            N /= i;
        }
    }
    if(N > 1)cnt[N]++;
    return cnt;
}
```

# 約数列挙
```cpp
vector<ll> divisor(ll N){
    vector<ll>v;
    for(ll i = 1; i * i <= N; i++){
        if(N % i == 0){
            v.push_back(i);
            if(i * i != N)v.push_back(N / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}
```

# 落下
ぷよぷよ的な
```cpp
string mp[5] = {
    ".A.B.",
    "C..DE",
    "..FG.",
    "H.IJK",
    "...LM"
};
for(int x = 0; x < 5; x++){
    queue<char>Q;
    for(int y = 4; y >= 0; y--){
        if(mp[y][x] != '.')Q.push(mp[y][x]);
        mp[y][x] = '.';
    }
    for(int y = 4; !Q.empty(); y--){
        mp[y][x] = Q.front();
        Q.pop();
    }
}
for(int y = 0; y < 5; y++){
    for(int x = 0; x < 5; x++){
        cout << mp[y][x];
    }
    cout << endl;
}
// ...B.
// ...D.
// ...GE
// C.FJK
// HAILM
```

# classのsort
https://atcoder.jp/contests/abc128/tasks/abc128_b
```cpp
class hoge{
    public:
    string s;
    int p;
    int idx;
    bool operator < (const hoge &h)const{
        if(s != h.s)return s < h.s;
        return -p < -h.p;
    }
};
// 昇順sort
vector<hoge>v(N);
sort(v.begin(), v.end());
// 降順priority_queue
priority_queue<hoge>Q;
```
greater
```cpp
class hoge{
    public:
    string s;
    int p;
    int idx;
    bool operator > (const hoge &h)const{
        if(s != h.s)return s > h.s;
        return p < h.p;
    }
};
// 降順sort
vector<hoge>v(N);
sort(v.begin(), v.end(), greater<hoge>());
// 昇順priority_queue
priority_queue<hoge, vector<hoge>, greater<hoge> >Q;
```

# bitの扱い
```cpp
int N = 4;
for(int i = 0; i < (1 << N); i++){
    //4bit分の全列挙
}
```

# 中央値
```cpp
// Left.top() == Right.top()の場合は中央値は1つ
// Left.top() < Right.top()の場合はその区間(もしくは2つのどちらか)
priority_queue<ll>Left;
priority_queue<ll, vector<ll>, greater<ll> >Right;
void push(ll x){
    Left.push(x);
    Right.push(x);
    ll l = Left.top();
    ll r = Right.top();
    if(l > r){
        Left.pop();
        Left.push(r);
        Right.pop();
        Right.push(l);
    }
}
```
# 中央値の候補が多すぎるとき  
「k以下の要素が過半数あるか？」で2分探索を行い,  
「k以下の要素が過半数ある」かつ「k-1以下の要素は過半数ない」で、中央値がkだとわかる。



# random
https://atcoder.jp/contests/abc110/submissions/5900173
```cpp
#include <random>
random_device rd;
mt19937_64 mt(rd());
vector<ll>hash(202020, 0);
for(ll i = 0; i < 202020; i++){
    hash[i] = mt();
}
```

# LIS(最長増加部分列)
```cpp
ll LIS_test(const V &v){
    V dp(v.size() + 1, INF);
    for(auto x : dp)cout << ((x == INF) ? "+" : to_string(x)) << " ";
    cout << endl << endl;
    for(auto x : v){
        *lower_bound(dp.begin(), dp.end(), x) = x;
        cout << x << endl;
        for(auto x : dp)cout << ((x == INF) ? "+" : to_string(x)) << " ";
        cout << endl << endl;
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();    
}

ll LIS(const V &v){
    V dp(v.size() + 1, INF);
    for(auto x : v){
        *lower_bound(dp.begin(), dp.end(), x) = x;
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
```

# rot
```cpp
// 回転は  
xx = cos(rad) * x - sin(rad) * y;
yy = sin(rad) * x + cos(rad) * y;
// 特に
rad = deg * pi / 180

deg = 0
xx = x
yy = y

deg = 90
xx = -y
yy = x

deg = 180
xx = -x
yy = -y

deg = 270
xx = y
yy = -x
```

# 二部マッチング
```cpp

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
```

# A以上B以下を数える
```cpp

//A以上B以下を数える
class ABCount{
    public:
    vector<ll>v;
    set<pair<ll, ll> >S;
    ll makeFlg;
    ll Inf;
    ABCount(ll inf = 1145141919){
        Inf = inf;
        makeFlg = 0;
    }
    void push(ll a){
        v.push_back(a);
    }
    void make(){
        makeFlg = 1;
        S.clear();
        sort(v.begin(), v.end());
        for(ll i = 0; i < v.size(); i++){
            S.insert(pair<ll, ll>(v[i], i));
        }
        S.insert(pair<ll,ll>(Inf, v.size()));
    }
    ll count(ll a, ll b){
        if(a > b)return 0;
        if(makeFlg == 0)make();
        return (*S.upper_bound(pair<ll,ll>(b, Inf))).second - (*S.lower_bound(pair<ll,ll>(a, 0))).second;
    }
};
```

# min_max_queue
```cpp
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
```

# ダブリング
ノードがN個あって、それぞれから有向辺が1本ずつ生えている。  
このとき、以下のようなクエリをたくさん処理したい。
- ノードaからノードbまでのコストは？
- ノードaからコストcでいける限界ノードは？
  
クエリが1つだけならゴリゴリ回せばいいが、多いと間に合わない。そこで、高速に求める方法を考える。
- 事前に1コストで移動できるノードがわかっているとする。各ノードについて、1コストで移動できるノードから1コストでいけるノードを調べると、2コストで移動できるノードがわかる。O(N)
- 同様に各ノードについて、xコストで移動できるノードからxコストでいけるノードを調べると、2xコストで移動できるノードがわかる。O(N)
- コストを求める場合は、開始ノードから可能な範囲でジャンプしていれば良い。
- 限界ノードを調べる時も、開始ノードから可能な範囲でジャンプしていれば良い。

# K進数の全列挙
```cpp
class ZEN{
    public:
    vector<ll>v;
    ll N, K;
    ZEN(ll n, ll k){
        v = vector<ll>(n + 1, 0);
        N = n;
        K = k;
    }
    void next(){
        v[0]++;
        for(ll i = 0; i < N; i++){
            if(v[i] == K){
                v[i] = 0;
                v[i + 1]++;
            }
        }
    }
    bool end(){
        return v[N] != 0;
    }
};
```
