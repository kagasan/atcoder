#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    double N;
    cin >> N;
    printf("%.9f\n", 100 * (10000 - N) / (10000 - N + N * 99));

    return 0;
}