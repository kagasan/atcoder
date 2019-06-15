#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    vector<ll>v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << v[2] - v[0] << endl;

    return 0;
}
