#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

// Function to replace {name} with actual name
string personalizeExcuse(string excuse, string name) {
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name); // 6 = length of "{name}"
        pos = excuse.find("{name}");
    }
    return excuse;
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // List of excuse templates (at least 10)
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} was about to finish the homework when the power went out for hours.",
        "{name} lost the notebook somewhere on the way to school.",
        "{name}'s dog chewed up the homework just before submission.",
        "{name} had internet issues and couldn't access the assignment file.",
        "{name} accidentally deleted the completed assignment.",
        "{name} was not feeling well and couldn't concentrate on studies.",
        "{name} helped a friend in an emergency and ran out of time.",
        "{name} forgot the homework at home in a hurry.",
        "{name}'s system crashed while saving the final version.",
        "{name} misunderstood the deadline and thought it was due later.",
        "{name} spent time fixing a technical issue and couldn't finish the work."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % excuses.size();

    // Get selected excuse
    string selectedExcuse = excuses[randomIndex];

    // Replace placeholder with actual name
    string finalExcuse = personalizeExcuse(selectedExcuse, name);

    // Display result
    cout << "\nGenerated Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}