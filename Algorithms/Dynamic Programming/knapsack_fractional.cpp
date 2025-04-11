#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store an item's value and weight
struct Item {
    int value, weight;
};

// Comparator function to sort items by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Higher ratio first
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp); // Sort items by value/weight ratio

    double maxValue = 0.0; // Maximum value in the knapsack
    for (auto& item : items) {
        if (W >= item.weight) { // Take the full item
            W -= item.weight;
            maxValue += item.value;
        } else { // Take a fraction of the item
            maxValue += (double)item.value * ((double)W / item.weight);
            break;
        }
    }
    return maxValue;
}

// Driver function
int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50; // Knapsack capacity

    cout << "Maximum Value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
