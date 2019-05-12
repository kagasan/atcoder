# コピペで使えるテク


# テンプレ
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

    return 0;
}
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

# RMQ
0-indexedなデータ構造。  
update(k, x)でk番目の要素を更新。  
query(a, b)で区間[a, b)の最小を取得。
```cpp
//0-indexed RMQ
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
```
# GCD(最大公約数),LCM(最小公倍数)
```cpp
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
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
そのうちclassにする。
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
# UnionFind
多分0-indexed
```cpp
struct UF{
    int N;
    vector<int>rank;
    vector<int>parent;
    vector<ll>sz;
    void init(int n){
        N = n;
        rank = std::vector<int>(N, 0);
        sz = std::vector<ll>(N, 1);
        parent = std::vector<int>(N);
        for(int i = 0; i < N; i++)parent[i] = i;
    }
    UF(int n = 0){
        if(n)init(n);
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    ll unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return 0;
        
        ll tmp = sz[x] * sz[y];
        ll tmp2 = sz[x] + sz[y];
        sz[x] = tmp2;
        sz[y] = tmp2;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
        return tmp;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};
```
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
    ll modpow(ll x, ll n){
        ll res = 1;
        while(n > 0){
            if(n & 1)res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
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