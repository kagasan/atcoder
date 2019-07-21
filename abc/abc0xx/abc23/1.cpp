#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll x;
    cin >> x;
    cout << (x/10) + (x%10) << endl;

    return 0;
}
