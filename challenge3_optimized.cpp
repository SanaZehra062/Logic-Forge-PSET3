#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct Message {
    int id;
    int value;
};

// For the priority queue
struct PQItem {
    int id;
    int isCritical; // 1 if critical, 0 if not
    bool operator<(const PQItem &other) const {
        // Max-heap: higher id first, critical first
        if(id != other.id)
            return id < other.id;          // bigger id = newer
        return isCritical < other.isCritical; // critical first
    }
};

int main() {
    int N, Q, K;
    cin >> N >> Q >> K;

    vector<set<int>> subscriptions(N+1);
    vector<vector<Message>> user_messages(N+1);
    int msg_id = 1;

    for(int i = 0; i < Q; i++) {
        string op;
        cin >> op;

        if(op == "B") {
            int u, m;
            cin >> u >> m;
            user_messages[u].push_back({msg_id++, m});
            if((int)user_messages[u].size() > K)
                user_messages[u].erase(user_messages[u].begin());
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

            priority_queue<PQItem> pq;

            // own messages
            for(auto &m: user_messages[u]) {
                int isCritical = (m.value % 3 == 0) ? 1 : 0;
                pq.push({m.id, isCritical});
            }

            // subscribed messages
            for(int v : subscriptions[u]) {
                for(auto &m : user_messages[v]) {
                    int isCritical = (m.value % 3 == 0) ? 1 : 0;
                    pq.push({m.id, isCritical});
                }
            }

            set<int> seen;
            vector<int> result;
            while(!pq.empty() && (int)result.size() < 10) {
                int mid = pq.top().id;
                pq.pop();
                if(seen.count(mid)) continue;
                result.push_back(mid);
                seen.insert(mid);
            }

            if(result.empty())
                cout << "EMPTY\n";
            else {
                for(size_t i = 0; i < result.size(); i++) {
                    if(i > 0) cout << " ";
                    cout << result[i];
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
