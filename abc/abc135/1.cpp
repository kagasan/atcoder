#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll A, B;
    cin >> A >> B;
    if(A > B)swap(A, B);
    if((B - A) % 2)cout << "IMPOSSIBLE" << endl;
    else cout << A + (B - A) / 2 << endl;

    return 0;
}