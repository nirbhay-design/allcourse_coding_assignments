#include <bits/stdc++.h>

using namespace std;

bool hasdup(string s) {
  for (int i =0;i<s.length();i++) {
    for (int j = i+1;j<s.length();j++) {
      if (s[i] == s[j]) {
        return true;
      }
    }
  }
  return false;
}


int main(){
  int n;
  cin >> n;
  vector<long long int> v;
  v.resize(n+1);
  v.clear();
  if (n > 9) {
    for (int i = 0;i<=9;i++) {
      v[i] = 0;
    }
  } else {
    cout << 0;
    return 0;
  }
  
  for (int i =10;i<=n;i++) {
      int val = (hasdup(to_string(i)))?1:0; 
      v[i] = (v[i-1] + val);
    
  }
  cout << v[n];

//   cout << hasdup(to_string(344))<<endl;
  return 0;
  
}