#include <bits/stdc++.h>

using namespace std;
int main(int argc ,char * argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i =0;i<n;i++) {
    cin >> v[i];
  }
  
  int ind = 0;
  int j = v[ind];
  int ans = 0;
  while (ind < n) {
    if (ind >= n-1) break;
    ind = ind + j;
    j = v[ind];
    ans++;
  }
  cout << ans;
  
  
  return 0;
}