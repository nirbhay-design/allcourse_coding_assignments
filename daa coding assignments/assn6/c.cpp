#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node * next;
    node(int data){
        val = data;
        next = NULL;
    }
};

class linkedlist{
    public:
    node * head;
    node * tail;
    linkedlist(){
        head = NULL;
        tail = NULL;
    }
    void insert(int data){
        node * mynode = new node(data);
        if (head == NULL){
            head = mynode;
            tail = head;
        } else {
            tail->next = mynode;
            tail = tail->next;
        }
    }
    void removefront(){
        if (head == tail){
            head = NULL;
            tail = NULL;
        }else{
            head = head->next;
        }
    }
    void print(){
        node * hd = head;
        while (hd != tail->next){
            cout << hd->val << " ";
            hd = hd->next;
        }
        // cout << hd->val << " ";
        cout << endl;
    }
};
struct comparator{

    bool operator()(linkedlist * a,linkedlist * b){
        if (a->head->val > b->head->val){
            return true;
        }
        return false;
    } 
};

class solution{
    public:
    int k;
    vector<linkedlist *> arr;
    solution(){
        cin >> k;
        arr.resize(k);
        for (int i =0;i<k;i++){
            arr[i] = new linkedlist();
            int a;
            cin >> a;
            for (int j = 0;j<a;j++){
                int b;
                cin >> b;
                arr[i]->insert(b);                
            }
        }
    }
    int solve(){
        if (k ==0) return 0;
        priority_queue<linkedlist*,vector<linkedlist*>,comparator> pq;
        for (int i = 0;i<k;i++){
            pq.push(arr[i]);
        }
        while (!pq.empty()){
            linkedlist * ptr = pq.top();
            pq.pop();
            cout << ptr->head->val << " ";
            ptr->removefront();
            if (ptr->head == NULL){
                continue;
            }
            pq.push(ptr);

        }
        cout << endl;
        // if (k == 0) {cout << 0;return 0;}
        // while(!pq.empty()){
        //     cout << -pq.top()<<" ";
        //     pq.pop();
        // }  
        return 0;  
    }
};


int main(int argc, char * argv[]){
    solution * sol = new solution();
    int ans = sol->solve();
    // cout << ans;
    return 0;
}