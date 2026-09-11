#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++)
        cin >> activities[i].first >> activities[i].second;

    sort(activities.begin(), activities.end(),
         [](pair<int,int> a, pair<int,int> b) {
             return a.second < b.second;
         });

    int lastFinish = -1;

    cout << "Selected Activities: ";

    for (int i = 0; i < n; i++) {
        if (activities[i].first >= lastFinish) {
            cout << "(" << activities[i].first << ", "
                 << activities[i].second << ") ";
            lastFinish = activities[i].second;
        }
    }

    return 0;
}