#include <iostream>
#include "utils.hh" 

using namespace std;

template<typename T> void vector_dump(vector<T>& v) {
    int i;
    for (i = 0; i < v.size() -1; i++)
        cout << v[i] << ",";
    cout << v[i] << endl;

}

vector<int> string2vector(string s) { // "[1,2,3,4]"
    vector<int> v;
    for (int i=0; i<s.length(); ) {
        while ((s[i] < '0' || s[i] > '9') && s[i] != '-' && i<s.length())
            i++;
        if (i == s.length())
            break;
        int j = i+1;
        while ((s[j] >= '0' && s[j] <= '9') && j<s.length())
            j++;
        int num = stoi(s.substr(i, j-i));
        v.push_back(num);
        i = j;
    }
    return v;
}

int main1() {
	//vector<int> v=string2vector("[1,2,3,4]");
	//vector<int> v={1,22,333};
	vector<string> v={"abc", "aaa", "bbb"};
	vector_dump(v);
    return 0;
}

