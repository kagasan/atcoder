#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

priority_queue<ll>X;
priority_queue<ll, vector<ll>, greater<ll> >Y;

void push(ll x){
    X.push(x);
    while(Y.size() > X.size()){
        ll tmp = Y.top();
        Y.pop();
        X.push(tmp);
    }
    while(Y.size() + 2 <= X.size()){
        ll tmp = X.top();
        X.pop();
        Y.push(tmp);
    }
}

ll mid(){
    if(X.empty())return 0;
    return X.top();
}

vector<ll>A;
ll B = 0;
ll f(ll x){
    ll res = B;
    for(ll i = 0; i < A.size(); i++){
        res += abs(x - A[i]);
    }
    return res;
}

int main(){
    
    

    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll a, b;
            cin >> a >> b;
            A.push_back(a);
            push(a);
            B += b;
        }
        else{
            ll x = mid();
            cout << x << " " << f(x) << endl;
        }
    }

    return 0;
}