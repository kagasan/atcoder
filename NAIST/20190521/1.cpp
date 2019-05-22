#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

    for(int n, m; cin >> n >> m, n;){
        vll A(n);
        ll ans = -1;
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(A[i] + A[j] <= m)ans = max(ans, A[i]+A[j]);
            }
        }
        if(ans < 0)cout <<"NONE"<<endl;
        else cout << ans << endl;
    }    

    return 0;
}