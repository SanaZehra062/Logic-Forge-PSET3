#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int weight;
    int priority;
};

int main() {
    int N, Q, limit;
    cin >> N >> Q >> limit;

    vector<Person> people(N);
    for(int i = 0; i < N; i++) cin >> people[i].weight;
    for(int i = 0; i < N; i++) cin >> people[i].priority;

    // Sort people by weight
    vector<int> idx(N);
    for(int i = 0; i < N; i++) idx[i]=i;
    sort(idx.begin(), idx.end(), [&](int a,int b){
        return people[a].weight < people[b].weight;
    });

    // Compute minimum boats using two-pointer greedy
    int l=0, r=N-1, boats=0;
    vector<bool> used(N,false);
    while(l<=r){
        if(used[idx[l]]) { l++; continue; }
        if(used[idx[r]]) { r--; continue; }

        if(l!=r && people[idx[l]].weight + people[idx[r]].weight <= limit
           && !(people[idx[l]].priority==1 && people[idx[r]].priority==1)) {
            used[idx[l]] = used[idx[r]] = true;
            l++; r--;
        } else {
            used[idx[r]] = true;
            r--;
        }
        boats++;
    }

    cout << "Minimum boats = " << boats << "\n";

    // Answer queries
    while(Q--){
        string type;
        cin >> type;
        if(type=="CANPAIR"){
            int X,Y; cin >> X >> Y;
            if(people[X].weight + people[Y].weight <= limit
               && !(people[X].priority==1 && people[Y].priority==1))
                cout << "Yes\n";
            else
                cout << "No\n";
        } else if(type=="REMAINING"){
            int B; cin >> B;
            // Max people evacuated in B boats = min(2*B, N)
            // But must respect priority/weight
            // Simulate similar to minimum boats but stop after B boats
            vector<int> tempIdx = idx;
            vector<bool> used2(N,false);
            int l2=0,r2=N-1, boatsUsed=0, evac=0;
            while(l2<=r2 && boatsUsed<B){
                if(used2[tempIdx[l2]]) { l2++; continue; }
                if(used2[tempIdx[r2]]) { r2--; continue; }

                if(l2!=r2 && people[tempIdx[l2]].weight + people[tempIdx[r2]].weight <= limit
                   && !(people[tempIdx[l2]].priority==1 && people[tempIdx[r2]].priority==1)) {
                    used2[tempIdx[l2]] = used2[tempIdx[r2]] = true;
                    evac += 2;
                    l2++; r2--;
                } else {
                    used2[tempIdx[r2]] = true;
                    evac += 1;
                    r2--;
                }
                boatsUsed++;
            }
            cout << N-evac << "\n";
        }
    }

    return 0;
}
