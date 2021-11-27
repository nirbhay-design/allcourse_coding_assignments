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
        v.resize(m);
        r.resize(m-1);
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

    pair<pair<node *,node *>,int> findip(record * &r) {
        node * p = NULL;
        node * tmp = rt;
        if (tmp->l) {
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
                return make_pair(make_pair(p,tmp),j);
            }
        }

        return make_pair(make_pair(p,tmp),-1);
    }

    pair<node*, int> getPar(node * &nd) {
        pair<pair<node *,node *>,int> p = findip(nd->r[0]);
        pair<node * , int> ter;
        ter.first = p.first.first;
        ter.second =p.second;
        return ter;
    }

    void hp_(node * &par,record * &r,int ind,node * &a,node * &b) {
        int val = r->i;
        int j =0;
        while (j<par->c) {
            if (val > par->r[j]->i) {
                j++;
            } else {
                break;
            }
        }
        // j+1 se pointer shift karne hai
        vector<node*> ver(par->v.begin(),par->v.end());
        par->r[par->c++] = r;
        sort(par->r.begin(),par->r.end(),comparator);
        par->v[ind] = a;
        par->v[ind+1] =b;
        int tval = ind+2;
        int pval = j+1;
        while (pval < ver.size()) {
            par->v[tval++] = ver[pval++];
        }
    }
    void split(node * &ch,node * &pr,int ind,record * r) {
        if (pr == NULL) {
            // 3 nodes; overflow at root
            node * nrt = new node(deg);
            node * a = new node(deg);
            node * b = new node(deg);
            int j = 0;
            vector<record *> ver;
            while (j < ch->c) {
                ver.push_back(ch->r[j]);
            }
            ver.push_back(r);
            sort(ver.begin(),ver.end(),comparator);
            int sz2 = ver.size()/2;
            record * elem = ver[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ver[a->c++];
            }

            while (b->c <= (ver.size()-sz2-1)) {
                b->r[b->c] = ver[sz2+1+b->c++];
            }
            int t = 0;
            while (ch->r[t]->i != elem->i) {
                t++;
            }
            for (int tt=0;tt<=t;tt++) {
                a->v[tt] = ch->v[tt];
            }
            for (int tt =0;tt<(ch->v.size()-t-1);tt++) {
                b->v[tt] = ch->v[tt+t+1];
            }
            nrt->v[0] = a;
            nrt->v[1] = b;
            rt = nrt;

            
        } else {
            // 2 nodes;
            node * a = new node(deg);
            node * b = new node(deg);
            pr->v[ind] = NULL;
            int j = 0;
            vector<record *> ver;
            while (j < ch->c) {
                ver.push_back(ch->r[j]);
            }
            ver.push_back(r);
            sort(ver.begin(),ver.end(),comparator);
            int sz2 = ver.size()/2;
            record * elem = ver[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ver[a->c++];
            }

            while (b->c <= (ver.size()-sz2-1)) {
                b->r[b->c] = ver[sz2+1+b->c++];
            }
            // if overflow -> split 
            if (pr->c == deg-1) {
                pair<node *,int> prr = getPar(pr);
                split(pr,prr.first,prr.second,r);
            }
            // else do this
            else {
                if (pr->l) {
                    hp(pr,r);
                    pr->v[ind] = a;
                    pr->v[ind+1] = b;
                }
                else {
                    hp_(pr,r,ind,a,b);
                }
                
            }
            
        }
    }

    void hp(node * &t,record * &r) {// insertion into leaf in a sorted order 
        int c = t->c++;
        int j = 0;
        vector<record*> vr;

        while (j < c) {
            if (r->i > t->r[j]->i) {
                vr.push_back(t->r[j]);
                j++;
            } else {
                break;
            }
        }
        vr.push_back(r);
        while (j < t->c) {
            vr.push_back(t->r[j++]);
        } 
        j = 0;
        while (j < t->c) {
            t->r[j] = vr[j];
            j++;
        }
    }
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
            if (c == deg-1) {
                // cout << "overflow occures\n" ;
                split (ch,p,tmp.second,r);
            } else {
                hp(ch,r);
            }
        }
    }
};


int main(int argc, char * argv[]) {
    Bt * t = new Bt(3);

    t->put(6);
    t->put(3);
    // t->put(9);


    int i =0;
    int c = t->rt->c;
    while (i < c) {
        cout << t->rt->r[i++]->i << " ";
    }
    cout << endl;
    return 0;
}