#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(const string &a, const string &b) {
    string x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return x == y;
}

int main() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<int> result;

    for(int i = 0; i <= n - m; i++){
        string sub = s.substr(i, m);
        if(isAnagram(sub, p))
            result.push_back(i);
    }

    // Print result
    cout << "[";
    for(size_t i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size()-1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
