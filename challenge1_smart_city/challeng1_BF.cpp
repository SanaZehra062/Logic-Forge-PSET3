#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> temp(N);
    for (int i = 0; i < N; i++) cin >> temp[i];

    // Compute alert days (brute-force)
    vector<int> alerts(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (temp[j] >= temp[i] + K || temp[j] <= temp[i] - K) {
                alerts[i] = j;
                break;
            }
        }
    }

    // Build prefix sum for COUNT queries
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
