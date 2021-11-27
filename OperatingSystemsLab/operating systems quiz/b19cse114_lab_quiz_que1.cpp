#include <bits/stdc++.h>

using namespace std;

void fifo_algo(int f,vector<int> rs) {
    queue<int> q;
    vector<int> victimpage;
    vector<vector<int>> v(f,vector<int> (rs.size(),-1));
    int miss =0;
    int cycle_ind = 0;
    for (int i =0;i<rs.size();i++) {
        int page = rs[i];
        bool find=false;
        bool empty = false;
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
                empty = true;
            }
        }
        if (!find) {
            q.push(page);
            miss++;
            if (empty) {
                v[cycle_ind][i] = page;
                cycle_ind = (cycle_ind + 1)%f;
            } else {
                int victim_page = q.front();
                q.pop();
                victimpage.push_back(victim_page);
                for (int ii =0;ii<f;ii++) {
                    if (v[ii][i] == victim_page) {
                        v[ii][i] = page; 
                        break;
                    }
                }
            }
        }
    }
    printf("Total pages are %ld\n",rs.size());
    printf("Total page faults are %d\n",miss);
    printf("The victim pages are as follows \n");
    for (int i =0;i<victimpage.size();i++) {
        cout << victimpage[i] << " ";
    }
    cout << endl;

}

void opr_algo(int f,vector<int> rs){
    vector<vector<int>> v(f,vector<int> (rs.size(),-1));
    int miss =0;
    int cycle_ind = 0;
    vector<int> victimpage;
    for (int i =0;i<rs.size();i++) {
        int page = rs.at(i);
        bool find=false;
        bool empty = false;
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
                empty = true;
            }
        }
        if (!find) {
            miss++;
            if (empty) {
                v[cycle_ind][i] = page;
                cycle_ind = (cycle_ind + 1)%f;
            } else {
                int imd =-1;
                int maxdis = INT_MIN;
                for (int m = 0;m<f;m++) {
                    int dis = 0;
                    bool b = false;
                    for (int p = i+1;p<rs.size();p++) {
                        int val = rs[p];
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
                // victim page is at index imd;
                victimpage.push_back(v[imd][i]);
                v[imd][i] = page;                
            }
        }
    }
    printf("Total pages are %ld\n",rs.size());
    printf("Total page faults are %d\n",miss);
    printf("The victim pages are as follows \n");
    for (int i =0;i<victimpage.size();i++) {
        cout << victimpage[i] << " ";
    }
    cout << endl;
    
}

vector<int> parseinput(string rs) {
    vector<int> v;
    int i = 0;
    while (i < rs.length()) {
        int ascii = rs[i] - '0';
        if (rs[i] == ' ') {
            i++;
        } else if (ascii >= 0 && ascii <= 9) {
            string mystring="";
            while (rs[i] != ' ' && i < rs.length()) {
                mystring += rs[i];
                i++;
            }
            v.push_back(stoi(mystring));
        }
    }
    return v;
}
int main(int argc ,char * argv[]) {
    
    int f;
    cout << "enter the number of frames : ";
    cin >> f;
    string rs;//reference string
    cout << "enter the space separated reference string : ";
    cin.ignore();
    getline(cin,rs);
    vector<int> v = parseinput(rs);
    cout << "For FIFO:\n";
    fifo_algo(f,v);
    cout << "For Optimal Page Replacement:\n";
    opr_algo(f,v);
    
    
    return 0;
}