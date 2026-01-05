#include <iostream>
using namespace std;

void generateSubsets(string &s, string current, int index) {
    if (index == s.length()) {
        cout << current << "\n";
        return;
    }

    generateSubsets(s, current, index + 1);

    generateSubsets(s, current + s[index], index + 1);
}

int main() {
    string input;
    cout << "Enter a string (e.g. ABC): ";
    cin >> input;

    cout << "Subsets:\n";
    generateSubsets(input, "", 0);

    return 0;
}
