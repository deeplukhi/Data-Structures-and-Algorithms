#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an activity with start and finish time
struct Activity {
    int start, finish;
};

// Comparator function to sort activities based on finish time
bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to perform Activity Selection (Greedy Approach)
void activitySelection(vector<Activity>& activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), activityCompare);
    
    cout << "Selected activities: " << endl;
    
    int n = activities.size();
    int lastFinishTime = 0;
    
    for (const auto& activity : activities) {
        if (activity.start >= lastFinishTime) {
            cout << "(" << activity.start << ", " << activity.finish << ") " << endl;
            lastFinishTime = activity.finish;
        }
    }
}

// Driver function
int main() {
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    
    activitySelection(activities);
    
    return 0;
}
