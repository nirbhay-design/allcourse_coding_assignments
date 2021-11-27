#include <bits/stdc++.h>

using namespace std;

int fifo(int f,string rs) {
    queue<int> q;
    vector<vector<int>> v(f,vector<int> (rs.length(),-1));
    int miss =0;
    int cycle = 0;
    for (int i =0;i<rs.length();i++) {
        int page = rs.at(i)-'0';
        bool find=false;
        bool emp = false;
        if (i != 0) {
            for (int j =0;j<f;j++) {
                v[j][i] = v[j][i-1];
            }
        }
        for (int j =0;j<f;j++) {
            if (v[j][i] !=-1 && v[j][i] == page) {
                find =true;
                break;
            } else if (v[j][i] == -1){
                emp = true;
            }
        }
        if (!find) {
            q.push(page);
            cout << "0 ";
            miss++;
            if (emp) {
                v[cycle][i] = page;
                cycle = (cycle + 1)%f;
            } else {
                int fif = q.front();
                q.pop();
                for (int ii =0;ii<f;ii++) {
                    if (v[ii][i] == fif) {
                        v[ii][i] = page; 
                        break;
                    }
                }
            }
            //replace page
        }
        else {
            cout << "1 ";
        } 
    }
    return miss;

}

int lru(int f,string rs){
    vector<vector<int>> v(f,vector<int> (rs.length(),-1));
    int miss =0;
    int cycle = 0;
    for (int i =0;i<rs.length();i++) {
        int page = rs.at(i)-'0';
        bool find=false;
        bool emp = false;
        if (i != 0) {
            for (int j =0;j<f;j++) {
                v[j][i] = v[j][i-1];
            }
        }
        for (int j =0;j<f;j++) {
            if (v[j][i] !=-1 && v[j][i] == page) {
                find =true;
                break;
            } else if (v[j][i] == -1){
                emp = true;
            }
        }
        if (!find) {
            cout << "0 ";
            miss++;
            if (emp) {
                v[cycle][i] = page;
                cycle = (cycle + 1)%f;
            } else {
                int imd = -1;
                int maxdis = INT_MIN;
                for (int m = 0;m<f;m++) {
                    int dis = 0;
                    bool b = false;
                    for (int p = i-1;p>-1;p--) {
                        int val = rs[p]-'0';
                        dis++;
                        if (val == v[m][i]) {
                            b=true;
                            break;
                        }
                    }
                    if (!b) {
                        dis = INT_MAX;
                    }
                    if (dis > maxdis) {
                        maxdis = dis;
                        imd = m;
                    }
                }
                v[imd][i] = page;
            }
            //replace page
        }
        else {
            cout << "1 ";
        } 
    }
    return miss;
}

int opr(int f,string rs){
    vector<vector<int>> v(f,vector<int> (rs.length(),-1));
    int miss =0;
    int cycle = 0;
    for (int i =0;i<rs.length();i++) {
        int page = rs.at(i)-'0';
        bool find=false;
        bool emp = false;
        if (i != 0) {
            for (int j =0;j<f;j++) {
                v[j][i] = v[j][i-1];
            }
        }
        for (int j =0;j<f;j++) {
            if (v[j][i] !=-1 && v[j][i] == page) {
                find =true;
                break;
            } else if (v[j][i] == -1){
                emp = true;
            }
        }
        if (!find) {
            cout << "0 ";
            miss++;
            if (emp) {
                v[cycle][i] = page;
                cycle = (cycle + 1)%f;
            } else {
                int imd =-1;
                int maxdis = INT_MIN;
                for (int m = 0;m<f;m++) {
                    int dis = 0;
                    bool b = false;
                    for (int p = i+1;p<rs.length();p++) {
                        int val = rs[p]-'0';
                        dis++;
                        if (val == v[m][i]) {
                            b=true;
                            break;
                        }
                    }
                    if (!b) {
                        dis = INT_MAX;
                    }
                    if (dis > maxdis) {
                        maxdis = dis;
                        imd = m;
                    }
                }
                v[imd][i] = page;                
            }
            //replace page
        }
        else {
            cout << "1 ";
        } 
    }
    return miss;
}

int main(int argc ,char * argv[]) {
    int n;
    cout << "enter number of times to run the algoriths : ";
    cin >> n;
    cout << "the algorithms will run for : " << n <<" times let's begin " << endl;
    cout << "enter the reference string as signle string of numbers where each character represents page number that cpu wants" << endl; 
    while (n--) {
        int f;
        cout << "enter number of frames : ";
        cin >> f;
        string rs;
        cout << "enter reference string : ";
        cin >> rs;
        int a = fifo(f,rs);
        cout << "\n (fifo) miss are : " << a <<  endl;
        int b = opr(f,rs);
        cout << "\n (opr) miss are : " << b << endl;
        int c = lru(f,rs);
        cout << "\n (lru) miss are : " << c << endl;
    }
    return 0;
}