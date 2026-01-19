#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Message {
    int id;
    int sender;
    int value;
};

int main() {
    int N, Q, K;
    cin >> N >> Q >> K;

    vector<set<int>> subscriptions(N+1);
    vector<Message> messages;
    int msg_id = 1;

    for(int i = 0; i < Q; i++) {
        string op;
        cin >> op;

        if(op == "B") {
            int u, m;
            cin >> u >> m;
            messages.push_back({msg_id++, u, m});
        } 
        else if(op == "S") {
            int u, v;
            cin >> u >> v;
            subscriptions[u].insert(v);
        } 
        else if(op == "U") {
            int u, v;
            cin >> u >> v;
            subscriptions[u].erase(v);
        } 
        else if(op == "F") {
            int u;
            cin >> u;
            vector<pair<int,bool>> visible;

            for(auto it = messages.rbegin(); it != messages.rend(); ++it) {
                if(it->sender == u || subscriptions[u].count(it->sender)) {
                    visible.push_back({it->id, it->value % 3 == 0});
                }
            }

            sort(visible.begin(), visible.end(), [](auto &a, auto &b) {
                if(a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });

            if(visible.empty()) cout << "EMPTY\n";
            else {
                for(size_t i = 0; i < min(visible.size(), size_t(10)); i++) {
                    if(i > 0) cout << " ";
                    cout << visible[i].first;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
