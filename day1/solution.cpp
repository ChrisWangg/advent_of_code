#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // Read in input file
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error, Unable to open file";
        return 1;
    }

    string line;
    // Constants defined as we are guaranteed to have 5 digit ids for both
    // first and second location ids.
    constexpr size_t endOfFirst = 5;
    constexpr size_t startOfSecond = 8;

    // Left and Right arrays for locations in 2 lists
    vector<int> left;
    vector<int> right;

    // Hashmap used to store the count of an item in list 2.
    unordered_map<int, int> list2;


    while (getline(inputFile, line)) {
        // Split at a constant position
        string first_str = line.substr(0, endOfFirst);
        string second_str = line.substr(startOfSecond);

        // String to Integer
        int first = stoi(first_str);
        int second = stoi(second_str);

        // Insert into arrays and hashmap
        left.push_back(first);
        right.push_back(second);
        list2[second] += 1;
    }

    // Sort both arrays for part 1
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int totalResPt1 = 0;
    int totalResPt2 = 0;

    for (int i = 0; i < left.size(); i++) {
        totalResPt1 += abs(left[i] - right[i]);
        totalResPt2 += left[i] * list2[left[i]];
    }


    cout << "Part 1 Answer: " << totalResPt1 << endl;
    cout << "Part 2 Answer: " << totalResPt2 << endl;
}