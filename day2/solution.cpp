#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

bool isSafe(vector<int> results);
bool isSafeWithRemoval(vector<int> results);

int main() {
    ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string line;
    int safeReports = 0;
    int safeReportsPt2 = 0;
    while (getline(inputFile, line)) {
        vector<string> results;
        vector<int> resultsAsInt;
        split(results, line, is_any_of(" "));
        for (string i: results) {
            resultsAsInt.push_back(stoi(i));
        }
        if (isSafe(resultsAsInt)) {
            safeReports++;
        }
        if (isSafeWithRemoval(resultsAsInt)) {
            safeReportsPt2++;
        }
        
    }
    cout << "Amount of safe reports: " << safeReports << endl;
    cout << "Amount of safe reports pt 2: " << safeReportsPt2 << endl;
}

bool isSafe(vector<int> results) {
    if (results[0] == results[1]) return false;
    bool increasing = (results[0] > results[1]) ? true: false;
    for (int i = 0; i < results.size() - 1; i++) {
        int left = results[i];
        int right = results[i + 1];
        if (increasing) {
            if (left >= right || (right - left) > 3) {
                return false;
            }
        } else {
            if (left <= right || (left - right > 3)) {
                return false;
            }
        }
    }
    return true;
}


bool isSafeWithRemoval(vector<int> results) {
    if (isSafe(results)) return true;

    for (int i = 0; i < results.size(); i++) {
        vector<int> modified;
        modified.reserve(results.size() - 1);
        for (int j = 0; j < results.size(); j++) {
            if (j != i) modified.push_back(results[j]);
        }

        if (isSafe(modified)) return true;
    }

    return false;
}