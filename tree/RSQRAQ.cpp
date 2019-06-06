#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class segTree{
    public:
    vector<ll>val;
    vector<ll>sub;
    vector<ll>left;
    vector<ll>right;
    ll offset;
    segTree(ll n, ll initVal = 0){
        offset = 2;
        while(offset < n + 1)offset <<= 1;
        val = vector<ll>(offset * 2, initVal);
        sub = vector<ll>(offset * 2, 0);
        left = vector<ll>(offset * 2, 0);
        right = vector<ll>(offset * 2, 0);
        for(ll i = 0; i < offset; i++){
            left[i + offset] = i;
            right[i + offset] = i;
        }
        for(ll i = offset - 1; i; i--){
            left[i] = left[i * 2];
            right[i] = right[i * 2 + 1];
        }
    }
    void update(ll l, ll r, ll x, ll p = 1){
        if(r < left[p] || right[p] < l)return;
        val[p] += x * (r - l + 1);
        if(left[p] == l && right[p] == r){
            sub[p] += x;
            return;
        }
        update(l, min(r, right[p * 2]), x, p * 2);
        update(max(l, left[p * 2 + 1]), r, x, p * 2 + 1);
    }

    ll get(ll l, ll r, ll p = 1){
        if(r < left[p])return 0;
        if(right[p] < l)return 0;
        // cout << p << ", " << l << " - " << r << endl;
        if(left[p] == l && right[p] == r){
            return val[p];
        }
        if(sub[p]){
            update(left[p*2], right[p*2], sub[p], p * 2);
            update(left[p*2+1], right[p*2+1], sub[p], p * 2 + 1);
            sub[p] = 0;
        }
        ll sum = 0;
        sum += get(l, min(r, right[p * 2]), p * 2);
        sum += get(max(l, left[p * 2 + 1]), r, p * 2 + 1);
        return sum;
    }

    void show(){
        cout << "-----" << endl;
        for(ll i = 1; i < offset * 2; i++){
            if(i < offset)cout << "(" << i << ")[" << val[i] << ", " << sub[i] << "] ";
            else cout << "<" << i - offset << ">[" << val[i] << ", " << sub[i] << "] ";
            ll flg = 1;
            for(ll tmp = i + 1; tmp; tmp /= 2){
                if((tmp & 1) && (tmp > 1))flg = 0;
            }
            if(flg)cout << endl;
        }
        cout << "+++++" << endl;
    }
};

int main(){

    ll N, Q;
    cin >> N >> Q;
    segTree tree(N);
    for(ll i = 0; i < Q; i++){
        ll q;
        cin >> q;
        if(q == 0){
            ll s, t, x;
            cin >> s >> t >> x;
            tree.update(s, t, x);
        }
        else{
            ll s, t;
            cin >> s >> t;
            cout << tree.get(s, t) << endl;
        }
        // tree.show();
    }

    return 0;
}