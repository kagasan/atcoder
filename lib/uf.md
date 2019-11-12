```cpp
class UF{
    public:
    ll N;
    vector<ll>rank;
    vector<ll>parent;
    vector<ll>sz;
    void init(ll n){
        N = n + 3;
        rank = std::vector<ll>(N, 0);
        sz = std::vector<ll>(N, 1);
        parent = std::vector<ll>(N);
        for(ll i = 0; i < N; i++)parent[i] = i;
    }
    UF(ll n = 0){
        if(n)init(n);
    }
    ll find(ll x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    ll unite(ll x, ll y){
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
    bool same(ll x, ll y){
        return find(x) == find(y);
    }
    ll get_size(ll x){
        return sz[find(x)];
    }
};
```
