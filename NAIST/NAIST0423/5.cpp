#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int NUM = 3000;
class tree{
    public:
    int value[NUM];
    int left[NUM];
    int right[NUM];
    queue<int>iQ;
    queue<int>lQ;
    queue<int>rQ;
    void push(int idx, int l, int r){
        iQ.push(idx);
        lQ.push(l);
        rQ.push(r);
    }
    tree(string s){
        for(int i = 0; i < NUM; i++){
            value[i] = -1;
            left[i] = -1;
            right[i] = -1;
        }
        int cnt = 0;
        push(0, 0, s.size() - 1); cnt++;
        while(!iQ.empty()){
            int idx = iQ.front(); iQ.pop();
            int l = lQ.front(); lQ.pop();
            int r = rQ.front(); rQ.pop();
            if(l + 1 >= r)continue;
            
            int sum;
            sum = 0;
            int LR = l;
            for(;LR==l || sum; LR++){
                if(s[LR] == '(')sum++;
                if(s[LR] == ')')sum--;
            }
            sum = 0;
            int RL = r;
            for(;RL == r || sum; RL--){
                if(s[RL] == ')')sum++;
                if(s[RL] == '(')sum--;
            }
            stringstream ss;
            for(int i = LR + 1; i < RL; i++)ss << s[i];
            // cout << ss.str() << endl;
            ss >> value[idx];

            left[idx] = cnt;
            push(cnt, l + 1, LR - 2); cnt++;

            right[idx] = cnt;
            push(cnt, RL + 2, r - 1); cnt++;

        }
    }
    tree(tree t1, tree t2){
        for(int i = 0; i < NUM; i++){
            value[i] = -1;
            left[i] = -1;
            right[i] = -1;
        }
        int cnt = 0;
        queue<int>s, s1, s2;
        s.push(cnt); cnt++;
        s1.push(0);
        s2.push(0);
        while(!s1.empty()){
            int idx = s.front(); s.pop();
            int idx1 = s1.front(); s1.pop();
            int idx2 = s2.front(); s2.pop();
            value[idx] = t1.value[idx1] + t2.value[idx2];
            // cout << value[idx] << endl;
            if(t1.value[t1.left[idx1]] >= 0 && t2.value[t2.left[idx2]] >= 0){
                left[idx] = cnt;
                s.push(cnt); cnt++;
                s1.push(t1.left[idx1]);
                s2.push(t2.left[idx2]);
            }
            if(t1.value[t1.right[idx1]] >= 0 && t2.value[t2.right[idx2]] >= 0){
                right[idx] = cnt;
                s.push(cnt); cnt++;
                s1.push(t1.right[idx1]);
                s2.push(t2.right[idx2]);
            }
        }
    }
    string func(int idx){
        if(value[idx] < 0)return "";
        string res = "";
        res += "(";
        if(left[idx] >= 0)res += func(left[idx]);
        res += ")";
        res += "[";
        if(value[idx] >= 0){
            stringstream ss;
            ss << value[idx];
            res += ss.str();
            // res += to_string(value[idx]);
        }
        res += "]";
        res += "(";
        if(right[idx] >= 0)res += func(right[idx]);
        res += ")";
        return res;
    }
};

int main(){

    for(string s1, s2;cin >> s1 >> s2;){
        tree t1(s1);
        tree t2(s2);
        tree t3(t1, t2);
        // cout << t1.func(0) << endl;
        // cout << t2.func(0) << endl;
        cout << t3.func(0) << endl;
        // break;
    }

    return 0;
}