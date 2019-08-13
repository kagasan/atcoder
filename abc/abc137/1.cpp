#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll a, b;
    cin >> a >> b;
    cout << max(a+b, max(a-b, a*b)) << endl;

    return 0;
}