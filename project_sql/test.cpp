#include <bits/stdc++.h>
using namespace std;

class node{
    public :
    int a;
    node * next;
    node (int b) { 
        a =b;
        next = NULL;
    }

};

int main() {
    node value(2);
    node val(3);
    value.next = &val;
    // value.a = 12;

    cout << value.a << " " << value.next->a;    
}