#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> & a,pair<int,int> & b) {
    if ((float)(a.first / a.second) <= (float) (b.first/b.second)) {
        return false;
    }
    return true;
}

int main() {

    vector <pair<int,int>> v;
    v.push_back(make_pair(120,24));
    v.push_back(make_pair(120,20));
    v.push_back(make_pair(36,6));
    v.push_back(make_pair(100,20));

    for (int i =0;i<4;i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    sort(v.begin(),v.end(),comparator);
    cout << "after sorting" << endl;
    for (int i =0;i<4;i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}