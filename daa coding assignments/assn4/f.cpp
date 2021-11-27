#include <bits/stdc++.h>

using namespace std;

class Solution{
  string s;
  public:
  Solution(string ser){
    s = ser;
  }

  void decode() {
    int ans = 0;
    vector<int> dp;
    dp.resize(s.length());
    if (s[0] == '0') {
      cout<< 0;
      return;
    }
    dp[0] = 1;
    for (int i = 1;i<s.length();i++) {
      if (s[i-1] == '0' && s[i] == '0') {
        dp[i] = 0;
      } else if (s[i-1] == '0' && s[i] != '0') {
        dp[i] = dp[i-1];
      } else if (s[i-1] != '0' && s[i] == '0') {
        dp[i] = (s[i-1] =='1' || s[i-1] =='2')?(i >=2)?dp[i-2]:1:0;
      } else {
        string st = "";
        st += s[i-1]; 
        st += s[i];
        dp[i] =0;
        if (stoi(st) > 10 && stoi(st) <= 26) {
          dp[i] += (i>=2)?dp[i-2]:1;
        }
        dp[i] += dp[i-1];
      }
    }
    cout << dp[s.length()-1];
  }
};

int main(int argc ,char * argv[]) {
  string s;
  cin >> s;
  Solution * sol = new Solution(s);
  sol->decode();

}