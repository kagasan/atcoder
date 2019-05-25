#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    int A = 0, B = 0;
    for(int i = 0; i < 2; i++){
        char c;
        cin >> c;
        A = (A * 10) + c - '0';
    }
    for(int i = 0; i < 2; i++){
        char c;
        cin >> c;
        B = (B * 10) + c - '0';
    }
    int ym = 0, my = 0;
    if(1 <= B && B <= 12){
        ym = 1;
    }
    if(1 <= A && A <= 12){
        my = 1;
    }
    if(ym && my)cout << "AMBIGUOUS" << endl;
    else if(ym)cout << "YYMM" << endl;
    else if(my)cout << "MMYY" << endl;
    else cout << "NA" << endl;

    return 0;
}