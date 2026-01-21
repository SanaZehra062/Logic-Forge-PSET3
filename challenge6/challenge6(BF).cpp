#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int len;
    cin >> len; // optional if array is on single line
    vector<int> nums(len);
    for(int i = 0; i < len; i++)
        cin >> nums[i];

    unordered_map<int, int> freq;
    int n = len / 2;

    for(int x : nums) {
        freq[x]++;
        if(freq[x] == n) {
            cout << x << endl;
            break;
        }
    }

    return 0;
}
