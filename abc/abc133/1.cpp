#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N, A, B;
    cin >> N >> A >> B;
    cout << min(N * A, B) << endl;

    return 0;
}