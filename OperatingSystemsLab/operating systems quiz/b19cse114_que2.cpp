#include <bits/stdc++.h>

using namespace std;

void roundrobin_algo(int tq,vector<int> at,vector<int> bt) {
    queue<int> q;
    q.push(0);
    vector<int> ganttchart;
    vector<int> visited(at.size(),0);
    visited[0] = 1;
    int time = at[0];
    for (int i =1;i<at.size();i++) {
        if (at[i] == at[0]) {
            q.push(i);
            cout << "same arrival time\n";
            visited[i] = 1;
        }
    }
    while (!q.empty()) {
        int pro = q.front();
        q.pop();
        cout << "scheduling process " << pro << endl;
        ganttchart.push_back(pro);
        if (bt[pro] >= tq) {
            bt[pro] -= tq;
            time += tq;
        } else {
            time += bt[pro];
            bt[pro] = 0;
        }
        for (int i =0;i<at.size();i++) {
            if (!visited[i] && at[i] <= time) {
                cout << "till then " << i << " th process arrives\n";
                q.push(i);
                visited[i] = 1;
            }
        }
        if (bt[pro] != 0) {
            cout << "again inserting " << pro << endl;
            q.push(pro);
        }
    }
    for (int i =0;i<ganttchart.size();i++) {
        cout << ganttchart[i] << " ";
    }
    cout << endl;


}

int main(int argc, char * argv[]) {
    int n;
    cout << "enter number of process: ";
    cin >> n;
    int tq;
    cout << "enter time quantum: ";
    cin >> tq;
    vector<int> at(n);
    vector<int> bt(n);
    for (int i =0;i<n;i++) {
        cin >> at[i];
    }
    for (int i =0;i<n;i++) {
        cin >> bt[i];
    }

    roundrobin_algo(tq,at,bt);
    return 0;
}