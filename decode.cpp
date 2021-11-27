#include <bits/stdc++.h>


using namespace std;

vector<string> arr;

void decode(string s,int i,string s0) {
    if (i == s.length()) {
        cout << s0 << endl;
        return;
    }

    int val = s[i] - '0';
    if (val == 0 || val == 1) {
        cout << "invalid\n";
        return;
    }

    for (int o = 0;o<arr[val].length();o++) {
        string to = s0;
        to += arr[val][o];
        decode (s,i+1,to);
    }

    return;

}


int main(){
    arr.resize(10);
    arr[2] = "abc";
    arr[3] = "def";
    arr[4] = "ghi";
    arr[5] = "jkl";
    arr[6] = "mno";
    arr[7] = "pqrs";
    arr[8] = "tuv";
    arr[9] = "wxyz";
    string s;
    cin >> s;

    decode (s,0,"");
    return 0;
}