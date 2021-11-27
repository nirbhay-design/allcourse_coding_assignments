#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> & a,pair<int,int> & b) {
    if ((float)(a.first / a.second) <= (float) (b.first/b.second)) {
        return false;
    }
    return true;
}

class Solution{
    public:
    int n,wt;
    pair<int,int> * arr;
    Solution() {
        cin >> n;
        arr = new pair<int,int>[n];
        for (int i =0;i<n;i++) {
            int price,weight;
            cin >> price >> weight;
            arr[i].first = price;
            arr[i].second = weight;
        }
        cin >> wt;
    }
    
    void solve() {
        sort(arr,arr+n,comparator);

        for (int i =0;i<n;i++) {
            cout << arr[i].first << " " << arr[i].second << endl;
        }
        int curwt=0;
        int profit=0;
        for (int i =0;i<n;i++) {
            if (curwt == wt) {
                continue;
            }
            if (curwt + arr[i].second <= wt) {
                curwt += arr[i].second;
                profit += arr[i].first;
            } else {
                int diff = wt - curwt;
                curwt += diff;
                profit += (arr[i].first / arr[i].second) * diff;

            }
        }

        cout << profit;

    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();
}

/*
4
120 24
120 20
280 40
100 10
60

*/