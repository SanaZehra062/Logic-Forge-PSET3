#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> temp(N);
    for (int i = 0; i < N; i++) cin >> temp[i];

    // Arrays to store next warmer and next colder days
    vector<int> nextWarmer(N, 0), nextColder(N, 0);

    stack<int> s;

    // Next warmer day (temp[j] >= temp[i] + K)
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && temp[s.top()] < temp[i] + K)
            s.pop();
        nextWarmer[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    // Clear stack for next calculation
    while (!s.empty()) s.pop();

    // Next colder day (temp[j] <= temp[i] - K)
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && temp[s.top()] > temp[i] - K)
            s.pop();
        nextColder[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    // Compute final alert day (earliest non-zero)
    vector<int> alerts(N, 0);
    for (int i = 0; i < N; i++) {
        if (nextWarmer[i] && nextColder[i])
            alerts[i] = min(nextWarmer[i], nextColder[i]);
        else if (nextWarmer[i])
            alerts[i] = nextWarmer[i];
        else if (nextColder[i])
            alerts[i] = nextColder[i];
        // else alerts[i] remains 0
    }

    // Prefix sum for COUNT queries
    vector<int> pref(N, 0);
    pref[0] = (alerts[0] != 0 ? 1 : 0);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + (alerts[i] != 0 ? 1 : 0);
    }

    // Answer queries
    while (Q--) {
        string type;
        cin >> type;
        if (type == "NEXT") {
            int X;
            cin >> X;
            if (alerts[X] != 0) cout << alerts[X] << "\n";
            else cout << "No Alert\n";
        } else if (type == "COUNT") {
            int L, R;
            cin >> L >> R;
            int count = pref[R] - (L > 0 ? pref[L - 1] : 0);
            cout << count << "\n";
        }
    }

    return 0;
}
