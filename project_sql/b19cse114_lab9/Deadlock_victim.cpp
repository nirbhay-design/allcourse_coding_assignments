#include <bits/stdc++.h>

using namespace std;

typedef struct Instance{
    int priority;
    int nofrem;
    int timestamp;
    int index;
}instance;

bool comparator(instance &a, instance &b){
    if(a.priority > b.priority) {
        return false;
    } else if(a.timestamp > b.timestamp && a.priority==b.priority){
        return false;
    } else if(a.timestamp == b.timestamp && a.priority==b.priority && a.nofrem >= b.nofrem){
        return false;
    }
    return true;
}

int select_victim_instance(instance * myinstances,int n){
    sort(myinstances,myinstances + n,comparator);
    cout << "victim instance is: " << myinstances[0].index << "\n";
    // for (int i = 0;i<n;i++){
    //     cout << myinstances[i].priority << " " << myinstances[i].timestamp << " " << myinstances[i].nofrem << "\n";
    // }
    return 0;
}


int main(int argc, char * argv[]){
    int n;
    cin>>n; 
    instance * inst = new instance[n];
    for (int i = 0;i<n;i++){
        inst[i].index = i;
        cin>>inst[i].priority >> inst[i].timestamp >> inst[i].nofrem;
    }
    select_victim_instance(inst,n);

    return 0;
}

/*
5
7 2 4 
6 3 1
1 4 3
2 10 1
10 10 20
*/