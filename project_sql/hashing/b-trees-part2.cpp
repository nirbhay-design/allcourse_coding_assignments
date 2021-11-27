#include <bits/stdc++.h>

using namespace std;



class record{
    public:
    int i;
    record(int j){
        i = j;
    }
};

class node{
    public:
    vector<record *> r;
    vector<node*> v;
    int c;
    bool l;
    node (int m) {
        l = true;
        c = 0;
        v.resize(m+1);
        r.resize(m);
    }
};

bool comparator(record * &a,record * &b) {
    if (a->i >= b->i) {
        return false;
    }
    return true;
}

class Bt{
    public:
    node * rt;
    int deg;
    Bt(int d){
        rt = new node(d);
        deg = d;
    }
    node * find(int e) {
        node * tp = rt;

        while (tp != NULL) {
            int c = tp->c;
            int j = 0;
            while (j < c) {
                if (e == tp->r[j]->i) {
                    return tp->v[j];
                } else if (e > tp->r[j]->i) {
                    j++;
                } else {
                    break;
                }
            }
            tp = tp->v[j];
            
        }
        return NULL;
    }

    void takecare(node * &t,record * &r) {
        t->r[t->c++] = r;
        sort(t->r.begin(),t->r.begin()+t->c,comparator);
    }
    pair<pair<node *,node *>,int> findip(record * &r) {
        node * p = NULL;
        node * tmp = rt;
        if (tmp->l) {
            takecare(tmp , r);
            return make_pair(make_pair(p,tmp),-1);//-1 means parent null;
        }
        while (tmp != NULL) {
            int c = tmp->c;
            int j = 0;
            while (j < c) {
                if (r->i > tmp->r[j]->i) {
                    j++;
                } else {
                    break;
                }
            }
            p = tmp;
            tmp = tmp->v[j];

            if (tmp->l) {
                takecare(tmp,r);
                return make_pair(make_pair(p,tmp),j);
            }
        }

        return make_pair(make_pair(p,tmp),-1);
    }

    pair<pair<node *,node *>,int> findpos(record * &r) {
        node * p = NULL;
        node * tmp = rt;
        if (tmp->l) {
            return make_pair(make_pair(p,tmp),-1);//-1 means parent null;
        }
        int globj = 0;
        while (tmp != NULL) {
            int c = tmp->c;
            int j = 0;
            while (j < c) {
                if (r->i > tmp->r[j]->i) {
                    j++;
                } else if(r->i < tmp->r[j]->i) {
                    p = tmp;
                    tmp = tmp->v[j];
                    globj = j;
                    break;
                } else {
                    return make_pair(make_pair(p,tmp),(tmp == rt)?-1:globj);
                }
            }
            if (j == c) {
                p = tmp;
                tmp = tmp->v[j];
                globj=j;
            }

            if (tmp->l) {
                return make_pair(make_pair(p,tmp),j);
            }
        }

        return make_pair(make_pair(p,p),-1);
    }
    pair<node*, int> getPar(node * &nd) {
        pair<pair<node *,node *>,int> p = findpos(nd->r[0]);
        pair<node * , int> ter;
        ter.first = p.first.first;
        ter.second =p.second;
        return ter;
    }

    // void hp_(node * &par,record * &r,int ind,node * &a,node * &b) {
    //     int val = r->i;
    //     int j =0;
    //     while (j<par->c) {
    //         if (val > par->r[j]->i) {
    //             j++;
    //         } else {
    //             break;
    //         }
    //     }
    //     // j+1 se pointer shift karne hai
    //     vector<node*> ver(par->v.begin(),par->v.end());
    //     par->r[par->c++] = r;
    //     sort(par->r.begin(),par->r.end(),comparator);
    //     par->v[ind] = a;
    //     par->v[ind+1] =b;
    //     int tval = ind+2;
    //     int pval = j+1;
    //     while (pval < ver.size()) {
    //         par->v[tval++] = ver[pval++];
    //     }
    // }
    void printNode(node * a) {
        for (int i = 0;i<a->c;i++) {
            if (a->r[i] != NULL) {
                cout << a->r[i]->i << " ";

            } else {
                cout << "NULL" << endl;
            }
        }
        cout << endl;
    }
    void split(node * &ch,node * &pr,int ind) {
        if (pr == NULL) {
            // 3 nodes; overflow at root
            node * nrt = new node(deg);
            node * a = new node(deg);
            node * b = new node(deg);
            nrt->l = false;
            if (!ch->l) {
                a->l = false;
                b->l = false;
            }
            int sz2 = deg/2;
            record * elem = ch->r[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ch->r[a->c];
                a->c++;
            }
            
            while (b->c < (deg-sz2-1)) {
                b->r[b->c] = ch->r[sz2+1+b->c];
                b->c++;
            }
            // int t = 0;
            for (int d = 0;d<= sz2;d++) {
                a->v[d] = ch->v[d];
            }

            for (int d = sz2+1;d<=deg ;d++) {
                b->v[d-sz2-1] = ch->v[d];
            }
            // for (int man = 0;man <=deg;man++) {
            //     ch->v[man] = NULL;
            // }


            // while (ch->r[t]->i != elem->i) {
            //     t++;
            // }
            // for (int tt=0;tt<=t;tt++) {
            //     a->v[tt] = ch->v[tt];
            // }
            // for (int tt =0;tt<(ch->v.size()-t-1);tt++) {
            //     b->v[tt] = ch->v[tt+t+1];
            // }
            rt = nrt;
            rt->r[rt->c++] = elem;
            rt->v[0] = a;
            rt->v[1] = b;
            // printNode(a);
            // printNode(b);
            // cout << "printing new root: " << rt->c << endl;
            
        } else {
            // 2 nodes;
            node * a = new node(deg);
            node * b = new node(deg);
            if (!ch->l) {
                a->l = false;
                b->l = false;
            }
            
            // pr->v[ind] = NULL;

            int sz2 = deg/2;
            record * elem = ch->r[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ch->r[a->c];
                a->c++;
            }

            while (b->c < (deg-sz2-1)) {
                b->r[b->c] = ch->r[sz2+1+b->c];
                b->c++;
            }
            
            for (int d = 0;d<= sz2;d++) {
                a->v[d] = ch->v[d];
            }

            for (int d = sz2+1;d<=deg ;d++) {
                b->v[d-sz2-1] = ch->v[d];
            }
            // shift the pr->v from ind + 1
            if (ind < deg - 1) {
                node * mynd = pr->v[ind + 1];
                for (int d = ind+1;d<deg;d++) {
                    if (pr->v[d] == NULL) {
                        pr->v[d] = mynd;
                        break;
                    }
                    node * pnd = pr->v[d+1];
                    pr->v[d+1] = mynd; 
                    mynd = pnd;
                }
            }

            takecare(pr,elem);
            pr->v[ind] = a;
            pr->v[ind + 1] = b;


            // if overflow -> split 
            if (pr-> c == deg) {
                // cout << "\n\nanother start" << endl;
                // lvlorder();

                // cout << "end start \n\n";
                pair<node *,int> pp = getPar(pr);
                // if (pp.first != NULL) 
                    // cout << "printing some values :  "<<pp.first->r[0]->i << " " << pp.second<< endl;
                // if (pp.first == NULL) {
                //     cout << "NULL found\n";
                // } else {
                //     cout << "no found null\n";
                //     cout << "parent of :" << pr->v[0]->r[0]->i << endl;
                //     cout << pp.first->r[0]->i << endl;
                // }
                split(pr,pp.first,pp.second);
            }
        }
    }

    // void hp(node * &t,record * &r) {// insertion into leaf in a sorted order 
    //     int c = t->c++;
    //     int j = 0;
    //     vector<record*> vr;

    //     while (j < c) {
    //         if (r->i > t->r[j]->i) {
    //             vr.push_back(t->r[j]);
    //             j++;
    //         } else {
    //             break;
    //         }
    //     }
    //     vr.push_back(r);
    //     while (j < t->c) {
    //         vr.push_back(t->r[j++]);
    //     } 
    //     j = 0;
    //     while (j < t->c) {
    //         t->r[j] = vr[j];
    //         j++;
    //     }
    // }
    void put(int n) {
        record * r = new record(n);
        pair<pair<node *,node *>,int> tmp;
        tmp = findip(r);
        node * p,* ch;
        p = tmp.first.first;
        ch = tmp.first.second;

        if (ch->l) {
            // cout << "leaf confirmed " << endl;
            int c=  ch->c;
            if (c == deg) {
                // cout << "overflow occures\n" ;
                split (ch,p,tmp.second);
            }
        }
    }

    void lvlorder() {
        node * myrt = rt;
        queue <node *> q;
        q.push(myrt);
        while (!q.empty()) {
            node * nd = q.front();q.pop();
            cout << "popping : " << nd->r[0]->i << endl;
            for (int i =0;i<nd->c;i++) {
                if (nd->r[i] != NULL) {
                    cout << nd->r[i]->i << " ";

                }
            }
            cout << endl;

            for (int j = 0;j<=deg;j++) {
                if (nd->v[j] != NULL) {
                    cout << "pushing node :" << j << endl;
                    q.push(nd->v[j]);
                }
            }
        }

        cout << endl;
    }
};


int main(int argc, char * argv[]) {
    int m;cout << "enter degree: ";cin >> m;
    Bt * t = new Bt(m);

    int n;
    cout << "enter n: " ;
    cin >> n;
    while(n--) {
        int val;
        cout << "enter val: ";
        cin >> val;
        t->put(val);

        cout << "final B-Tree is: \n";
        t->lvlorder();
        // cout << "\n";
    }
    // t->put(6);
    // t->put(3);
    // t->put(9);
    // t->put(10);
    // t->put(4);
    // t->put(5);
    // t->put(11);
    // t->put(12);
    // t->put(13);
    // t->put(14);

    // t->lvlorder();
    return 0;
}