# 区間和
- 任意の区間要素の和を求めたい！
- 愚直な方法だと計算量はO(N)
- 高速に処理するために累積和やBITが用いられる．
- 区間更新区間取得は遅延セグメント木などを用いそう．しんどいのでパス．

# 検証に使えそうな問題(更新中)
- 1次元
- [最大の和(AtCoder)](https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_a)
- [最大の和(AOJ)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516)
- 2次元
- [Triangles(AtCoder)](https://atcoder.jp/contests/abc143/tasks/abc143_d)

# 累積和
- 端から要素を足して累積和を作る．
- 任意の区間和は，端からの累積和の差．
- 区間和を求めるのはO(1)と高速だが，累積和を準備するのにO(N)かかる．
- updateクエリがsumクエリより前にある場合に使いたい．
```cpp
// 1indexed1dimention[l,r]
class imos1d{
    public:
    vector<ll>t, v;
    ll num;
    ll flg;
    imos1d(ll NUM = 0){
        flg = 0;
        num = NUM + 10;
        v = vector<ll>(num, 0);
        t = vector<ll>(num, 0);
    }
    void add(ll idx, ll x){
        flg = 0;
        t[idx] += x;
    }
    void make(){
        flg = 1;
        for(ll i = 1; i < num; i++)v[i] = v[i - 1] + t[i];
    }
    ll sum(ll l, ll r){
        if(!flg)make();
        return v[r] - v[l - 1];
    }
};
```

# bit
- 特殊な木構造に沿って要素を足す．
- 区間和, 更新共にO(logN)と比較的高速．
- updateクエリがsumクエリより後の場合に使いたい．
```cpp
// 1indexed1dimention[l,r]
class bit1d{
    public:
    vector<ll>v;
    ll num;
    bit1d(ll NUM = 0){
        num = NUM + 10;
        v = vector<ll>(num, 0);
    }
    void add(ll idx, ll x){
        if(idx == 0)return;
        while(idx <= num){
            v[idx] += x;
            idx += idx & -idx;
        }
    }
    ll sum_of_1_to_idx(ll idx){
        if(idx <= 0)return 0;
        ll s = 0;
        while(idx > 0){
            s += v[idx];
            idx -= idx & -idx;
        }
        return s;
    }
    ll sum(ll l, ll r){
        return sum_of_1_to_idx(r) - sum_of_1_to_idx(l - 1);
    }
};
```

# 2次元
- 複雑だけどパワフル
# 累積和
```cpp
```

# bit
```cpp
```