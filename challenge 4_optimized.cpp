#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<int> result;

    if(n < m){
        cout << "[]\n";
        return 0;
    }

    vector<int> pFreq(26, 0), windowFreq(26, 0);

    // Frequency of p
    for(char c : p) pFreq[c - 'a']++;

    // Initial window
    for(int i = 0; i < m; i++) windowFreq[s[i] - 'a']++;

    if(windowFreq == pFreq) result.push_back(0);

    // Sliding window
    for(int i = m; i < n; i++){
        windowFreq[s[i] - 'a']++;            // add new char
        windowFreq[s[i - m] - 'a']--;        // remove old char
        if(windowFreq == pFreq)
            result.push_back(i - m + 1);
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
