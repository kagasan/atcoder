#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll x, y;
    cin >> x >> y;
    Say(x < y, "Better", "Worse");

    return 0;
}
