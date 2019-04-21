# コピペで使えるテク


# テンプレ
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

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

# vector
**宣言**  
vector<T>(要素数, 初期値)
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
vector<int>v;
v.push_back(2);
v.push_back(3);
v.push_back(1);
v.push_back(4);
sort(v.begin(), v.end());
for(int i = 0; i < v.size(); i++)cout << v[i];
// 1234
```
降順
```cpp
vector<int>v;
v.push_back(2);
v.push_back(3);
v.push_back(1);
v.push_back(4);
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
