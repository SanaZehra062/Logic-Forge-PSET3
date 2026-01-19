#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q, limit;
    cin >> N >> Q >> limit;

    vector<int> w(N), priority(N);
    for(int i = 0; i < N; i++) cin >> w[i];
    for(int i = 0; i < N; i++) cin >> priority[i];

    // Minimum boats calculation (brute-force greedy)
    vector<bool> used(N, false);
    int boats = 0;

    while(true) {
        int first = -1, second = -1;
        // Find first unused person
        for(int i = 0; i < N; i++) {
            if(!used[i]) { first = i; break; }
        }
        if(first == -1) break; // all evacuated

        used[first] = true;
        // Try to pair with someone else
        for(int j = N-1; j >= 0; j--) {
            if(!used[j] && w[first]+w[j] <= limit && !(priority[first]==1 && priority[j]==1)) {
                second = j;
                break;
            }
        }
        if(second != -1) used[second] = true;
        boats++;
    }

    cout << "Minimum boats = " << boats << "\n";

    // Answer queries
    while(Q--) {
        string type;
        cin >> type;
        if(type == "CANPAIR") {
            int X,Y;
            cin >> X >> Y;
            if(w[X]+w[Y] <= limit && !(priority[X]==1 && priority[Y]==1))
                cout << "Yes\n";
            else
                cout << "No\n";
        } else if(type == "REMAINING") {
            int B;
            cin >> B;
            // Brute-force simulate first B boats
            vector<bool> used2(N,false);
            vector<int> people = w;
            int evac = 0;

            while(B--) {
                int first = -1, second = -1;
                for(int i = 0; i < N; i++) if(!used2[i]) { first = i; break; }
                if(first == -1) break;

                used2[first] = true;
                for(int j = N-1; j >= 0; j--) {
                    if(!used2[j] && w[first]+w[j] <= limit && !(priority[first]==1 && priority[j]==1)) {
                        second = j;
                        break;
                    }
                }
                if(second != -1) used2[second] = true;
                evac += (second!=-1 ? 2 : 1);
            }

            int remaining = 0;
            for(int i = 0; i < N; i++) if(!used2[i]) remaining++;
            cout << remaining << "\n";
        }
    }

    return 0;
}
