// C++ program to find the longest repeated 
// non-overlapping substring 
#include"bits/stdc++.h"
using namespace std; 
  
// Returns the longest repeating non-overlapping 
// substring in str 
string longestRepeatedSubstring(string str) 
{ 
    int n = str.length(); 
    int LCSRe[n+1][n+1]; 
  
    // Setting all to 0 
    memset(LCSRe, 0, sizeof(LCSRe)); 
  
    string res; // To store result 
    int res_length  = 0; // To store length of result 
  
    // building table in bottom-up manner 
    int i, index = 0; 
    for (i=1; i<=n; i++) 
    { 
        for (int j=i+1; j<=n; j++) 
        { 
            // (j-i) > LCSRe[i-1][j-1] to remove 
            // overlapping 
            if (str[i-1] == str[j-1] && 
                LCSRe[i-1][j-1] < (j - i)) 
            { 
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1; 
  
                // updating maximum length of the 
                // substring and updating the finishing 
                // index of the suffix 
                if (LCSRe[i][j] > res_length) 
                { 
                    res_length = LCSRe[i][j]; 
                    index = max(i, index); 
                } 
            } 
            else
                LCSRe[i][j] = 0; 
        } 
    } 
  
    // If we have non-empty result, then insert all 
    // characters from first character to last 
    // character of string 
    if (res_length > 0) 
        for (i = index - res_length + 1; i <= index; i++) 
            res.push_back(str[i-1]); 
  
    return res; 
} 
  
// Driver program to test the above function 
int main() 
{ 
    int n;
    string str = "geeksforgeeks"; 
    cin >> n;
    cin >> str;
    cout << longestRepeatedSubstring(str).size() << endl;; 
    return 0; 
} 