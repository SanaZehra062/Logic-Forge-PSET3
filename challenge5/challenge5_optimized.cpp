#include <iostream>
#include <string>
using namespace std;

// Expand around center and return palindrome length
pair<int,int> expandAroundCenter(const string &s, int left, int right) {
    int n = s.size();
    while(left >= 0 && right < n && s[left] == s[right]) {
        left--; right++;
    }
    // substring from left+1 to right-1
    return {left+1, right-1};
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int start = 0, end = 0;

    for(int i = 0; i < n; i++){
        // Odd length palindrome
        auto odd = expandAroundCenter(s, i, i);
        if(odd.second - odd.first > end - start){
            start = odd.first;
            end = odd.second;
        }
        // Even length palindrome
        auto even = expandAroundCenter(s, i, i+1);
        if(even.second - even.first > end - start){
            start = even.first;
            end = even.second;
        }
    }

    cout << s.substr(start, end-start+1) << "\n";
    return 0;
}
