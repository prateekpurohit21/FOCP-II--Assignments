#include <iostream>
#include <vector>
#include <string>
#include <random>   // modern random library

using namespace std;

// Function to replace {name} with actual name
string personalizeRoast(string roast, string name) {
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}", pos + name.length()); // move forward
    }
    return roast;
}

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Roast templates
    vector<string> roasts = {
        "{name}, you bring everyone so much joy when you leave the room.",
        "{name}, you're not stupid, you just have bad luck thinking.",
        "{name}, if laziness were a sport, you'd come second because you're too lazy to come first.",
        "{name}, your secrets are always safe with me. I never even listen when you tell them.",
        "{name}, you have something on your chin no, the third one down.",
        "{name}, I'd explain it to you, but I left my crayons at home.",
        "{name}, you're like a cloud. When you disappear, it's a beautiful day.",
        "{name}, you have the personality of a damp towel.",
        "{name}, if brains were dynamite, you wouldn't have enough to blow your nose.",
        "{name}, you're proof that even evolution takes a break sometimes."
    };

    // Modern random generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, roasts.size() - 1);

    int randomIndex = dist(gen);

    string finalRoast = personalizeRoast(roasts[randomIndex], name);

    cout << "\n Your Roast \n";
    cout << finalRoast << endl;

    return 0;
}