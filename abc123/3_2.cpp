#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    vector<ll>vec(5);
    for(int i = 0; i < 5; i++)cin >> vec[i];
    ll mn = *min_element(vec.begin(), vec.end());
    cout << (N + mn - 1) / mn + 4 << endl;

    return 0;
}