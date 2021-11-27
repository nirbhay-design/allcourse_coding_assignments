#include <bits/stdc++.h>

using namespace std;

class myname{
    public:
    static int hashfunction;
    myname() {
        hashfunction++;
    }
};

int myname::hashfunction = 0;

class student{
    public:
    string name;
    int rollno;

    student(string naam,int rolno) {
        rollno = rolno;
        name =naam;
    }
};
int main(int argc ,char * argv[]) {
    // myname obj;
    // myname obt;
    // myname otr;


    // cout << obj.hashfunction << endl;
    // int *arr = (int *) malloc(sizeof(int) * 6);
    // for (int i =0;i<6;i++) {
    //     arr[i] = i+1;
    //     // cout << arr[i] << " ";
    // }
    
    // for (int i =0;i<6;i++) {
    //     // arr[i] = i+1;
    //     cout << arr[i] << " ";
    // }

    // arr = (int *)realloc((void *)arr,8*sizeof(int));

    // cout << endl;
    // for (int i =0;i<8;i++) {
    //     cout << arr[i] << " ";
    // }
    vector<student*> v;
    v.resize(5);
    cout << v.size() << endl;

    for (int i =0;i<v.size();i++) {
        v[i] = new student("nirbhay",i);
    }

    cout << "before resizing" << endl;
    for (int i =0;i<v.size();i++) {
        if (v[i] == NULL) {cout << "NULL" << endl ; continue;}
        cout << v[i]->rollno << endl;

    }

    v.resize(10);
    cout << "after resizing" << endl;
    for (int i =0;i<v.size();i++) {
        if (v[i] == NULL) {cout << "NULL" << endl ; continue;}
        cout << v[i]->rollno << endl;

    }

    for (int i = 0;i<v.size();i++) {
        if (v[i] == NULL) {v[i] = new student("ravi",7);}
    }
    v[6]->rollno=10;
    v[7]->rollno=11;
    v[8]->rollno=12;

    cout << "after resizing and pushing" << endl;
    for (int i =0;i<v.size();i++) {
        if (v[i] == NULL) {cout << "NULL" << endl ; continue;}
        cout << v[i]->rollno << endl;

    }

    // cout << v[0]->name << endl;
    return 0;
}