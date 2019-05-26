#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

priority_queue<ll>Q1;
priority_queue<ll, vector<ll>, greater<ll> >Q2;

ll push(ll x){
    Q1.push(x);
    Q2.push(x);
    ll q1 = Q1.top();
    Q1.pop();
    ll q2 = Q2.top();
    Q2.pop();
    Q1.push(min(q1, q2));
    Q2.push(max(q1, q2));
    return abs(q1 - q2);
}

int main(){
    
    ll Q;
    cin >> Q;
    ll x = 0;
    ll fx = 0;
    for(ll i = 0; i < Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll a, b;
            cin >> a >> b;
            fx += b + push(a);
        }
        else{
            cout << Q1.top() << " " << fx << endl;
        }
    }

    return 0;
}
