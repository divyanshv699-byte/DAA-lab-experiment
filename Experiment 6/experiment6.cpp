
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;

    return ratio1 > ratio2;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int capacity = 50;

    double maximumValue = fractionalKnapsack(items, capacity);

    cout << fixed << setprecision(2);
    cout << "Maximum Value: " << maximumValue << endl;

    return 0;
}