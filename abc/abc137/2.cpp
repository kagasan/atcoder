#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll k, x;
    cin >> k >> x;
    vector<ll>ans;
    for(ll i = -1000000; i <= 1000000; i++){
        if(abs(x - i) < k)ans.push_back(i);
    }
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i + 1 == ans.size())cout << endl;
        else cout << " ";
    }

    return 0;
}