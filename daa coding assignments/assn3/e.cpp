#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int n;
    vector<int> v;
    Solution() {
        cin >> n;
        for (int i =0;i<n;i++) {
            int val;cin >> val;
            v.push_back(val);
        }
    }
    int merge(int l,int mid,int r) {
        int ci = 0; 
        vector<int> t;
        int ls = mid-l+1,rs = r-mid;
        int left = l;
        int mid1 = mid+1;
        while (left <= mid && mid1 <= r) {
            if (v[left] > v[mid1]) {
                ci += ls-left+l;
                t.push_back(v[mid1++]);
            } else if (v[left] == v[mid1]) {
                t.push_back(v[left++]);
                t.push_back(v[mid1++]);
            } else {
                t.push_back(v[left++]);
            }
        }
        while (left <= mid) {
            t.push_back(v[left++]);
        }
        while (mid1 <= r) {
            t.push_back(v[mid1++]);
        }

        int l1 = l;
        for (int i =0;i<r-l+1;i++) {
            v[l1++] = t[i];
        }
        return ci;
    }

    int mergesort(int l,int r) {
        // cout << l << " "<< r << endl;
        int inv = 0;
        if (l < r) {
            int mid = (l + r) / 2;
            inv += mergesort(l,mid);
            inv += mergesort(mid+1,r);
            inv += merge(l ,mid,r);
        }

        return inv;
    }

    void solve() {
        cout << mergesort(0,n-1);
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();
}

/*

10
157 160 166 170 168 172 140 133 153 155

7
153 167 133 145 163 140 155
*/