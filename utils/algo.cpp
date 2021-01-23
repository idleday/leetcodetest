#include <iostream>
#include <vector>

#include "utils.hh"
#include "algo.hh"

using namespace std;

void insert_sort(vector<int> &a, int n) {
//    dump_vector(a);
    int s1 = 0, s2 = a.size() - 1;
    int s = a.size();
    while(s1 < s2) {
        int m = (s1+s2)/2;
        int v = a.at(m);
        if (v > n) {
            s2 = m-1;
        }
        else if(v < n) {
            s1 = m + 1;
        }
        else
        {
            s1 = m;
            s2 = m;
        }
    }
    vector<int>::iterator i = a.begin() + s1;
    if (*i > n)
        a.insert(i, n);
    else
        a.insert(++i, n);
}

void insert_sort(vector<int> &a, vector<int> &b) {
    vector<int>::iterator i;
    if (a.size() == 0)
        a = b;
    else {
        for (i=b.begin(); i!=b.end(); i++) {
            insert_sort(a, *i);
        }
    }
}
