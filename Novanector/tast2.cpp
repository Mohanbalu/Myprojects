#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string checkPasswordStrength(const string& pass) {
    int length = pass.length();
    int cap = 0, low = 0, num = 0, special = 0;
    bool hasCommonPattern = false;

    for (char c : pass) {
        if (islower(c)) low++;
        else if (isupper(c)) cap++;
        else if (isdigit(c)) num++;
        else special++;

        if (pass.find("123") != string::npos || pass.find("password") != string::npos ||
            pass.find("qwerty") != string::npos || pass.find("abc") != string::npos) {
            hasCommonPattern = true;
        }
    }

    int score = 0;
    if (length >= 8) score++;
    if (cap > 0) score++;
    if (low > 0) score++;
    if (num > 0) score++;
    if (special > 0) score++;
    if (!hasCommonPattern) score++;

    if (score >= 5) return "Strong";
    else if (score >= 3) return "Moderate";
    else return "Weak";
}

int main() {
    string pass;

    do {
        cout << "Enter password (at least 8 characters long): ";
        cin >> pass;

        if (pass.length() < 8) {
            cout << "Password must be at least 8 characters long." << endl;
        }
    } while (pass.length() < 8);

    string strength = checkPasswordStrength(pass);

    cout << "Password strength: " << strength << endl;

    if (strength == "Weak") {
        cout << "Recommendations: Consider adding more characters (uppercase, lowercase, digits, special characters)." << endl;
    } else if (strength == "Moderate") {
        cout << "Recommendations: Consider adding special characters or avoiding common patterns." << endl;
    } else {
        cout << "Password is strong." << endl;
    }

    return 0;
}
