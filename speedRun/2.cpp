#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    cout << N * (N + 1) / 2 << endl;
    return 0;
}