#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int x;
    while(cin >> x)
        nums.push_back(x);

    int repeated;

    // Check first three elements
    if(nums[0] == nums[1] || nums[0] == nums[2])
        repeated = nums[0];
    else
        repeated = nums[1];

    cout << repeated << endl;
    return 0;
}
