#include <bits/stdc++.h>

using namespace std;
class process{
    public:
    int maxsz;
    int pid,pgflt;
    map<int,int> tlb;
    map<int,int> pt;
    queue<int> q;
    vector<int> v,p;
    process(int id,int s,int f){
        v.resize(f);
        for (int m = 0;m<f;m++) {
            v[m] = -1;
        }
        pid=id;        
        maxsz=s;
        tlb.clear();
        pt.clear();
        pgflt =0;
    }
    int search(int pg){
        p.push_back(pg);
        if(tlb.find(pg)!=tlb.end()){
            cout<<"TLB HIT"<<endl;
            return tlb[pg];        
        }
        else{
            cout<<"TLB MISS"<<endl;
            if(pt.find(pg)!=pt.end()){
                cout<<"PAGE HIT"<<endl;
                //update TLB as we
                tlb[pg] = pt[pg]; 
                q.push(pg);  
                if (q.size() > maxsz) {
                    tlb.erase(q.front());
                    q.pop();
                }
                return pt[pg];

            }
            else{
                cout<<"PAGE FAULT"<<endl;
                pgflt++;
                //add using LRU to Main memory
                int f = v.size();
                for (int i = 0;i<f;i++) {
                    if (v[i] == -1) {
                        v[i] = pg;
                        pt[pg] = i;
                        tlb[pg] = i; 
                        q.push(pg);  
                        if (q.size() > maxsz) {
                            tlb.erase(q.front());
                            q.pop();
                        }
                        return i;
                    } 
                }
                int imd = -1;
                int max_dis = INT_MIN;
                for (int i = 0;i<f;i++) {
                    int dis = 0;
                    bool b = false;
                    for (int m = p.size()-2;m>-1;m--) {
                        int val = p[m];
                        dis++;
                        if (val == v[i]) {
                            b = true;
                            break;
                        }
                    }
                    if (!b) {
                        dis = INT_MAX;
                    }
                    if (dis > max_dis) {
                        max_dis = dis;
                        imd = i;
                    }
                }
                v[imd] = pg;
                pt[pg] = imd;
                tlb[pg] = imd; 
                q.push(pg);  
                if (q.size() > maxsz) {
                    tlb.erase(q.front());
                    q.pop();
                }
                return imd;
                //page update
                //tlb update

            }
        }

    }
    
};



int main(int argc, char * argv[]) {
    int k;// total np. of process
    cin>>k;
    int m;//VAS
    cin>>m;
    int f;
    cin >> f;//PAS
    int s; //size of tlb
    cin >> s;
    srand(time(NULL));
    for (int i = 0;i<k;i++) {
        cout << "process: " << i+1 << endl;  
        int id=rand()%k +1;
        process * pro = new process(id,s,f);
        int prom = rand() % m + 1;
        int range = rand() % 8*prom + 2*prom;
        vector<int> rs;
        for (int j = 0;j<range;j++) {
            rs.push_back(rand()%prom);
        }
        for (int j = 0;j<rs.size();j++) {
            pro->search(rs[j]);
        }
        
    }
    // TLB * t = new TLB(s);


    return 0;
}