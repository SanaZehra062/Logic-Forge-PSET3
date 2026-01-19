#include <iostream>
#include <string>
using namespace std;

// Helper to check if substring s[l..r] is palindrome
bool isPalindrome(const string &s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string longest = "";

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)){
                if(j - i + 1 > longest.size())
                    longest = s.substr(i, j-i+1);
            }
        }
    }

    cout << longest << "\n";
    return 0;
}
