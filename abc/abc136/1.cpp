#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll A, B, C;
    cin >> A >> B >> C;
    ll D = A - B;
    C -= D;
    cout << max(C, 0LL) << endl;

    return 0;
}