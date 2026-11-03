#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;
void insertCharacters(deque<char>& dq, string str) {
    for (int i = 0; i < str.length(); i++) {
        dq.push_back(tolower(static_cast<unsigned char>(str[i])));
    }
}
bool checkPalindrome(deque<char>& dq) {
    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            return false;
        }
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}
void displayDeque(deque<char> dq) {
    cout << "Deque elements: ";
    if (dq.empty()) {
        cout << "Empty";
    } else {
        for (char ch : dq) {
            cout << ch << " ";
        }
    }
    cout << endl;
}
int main() {
    deque<char> dq;
    string str;
    cout << "  PALINDROME CHECKER USING DEQUE\n";
    cout << "Enter a string: ";
    getline(cin, str);
    if (str.empty()) {
        cout << "Empty string is considered a palindrome.\n";
        return 0;
    }
    insertCharacters(dq, str);
    cout << "\nOriginal Deque:\n";
    displayDeque(dq);
    if (checkPalindrome(dq)) {
        cout << "\nResult: " << str
             << " is a PALINDROME.\n";
    } else {
        cout << "\nResult: " << str
             << " is NOT a PALINDROME.\n";
    }
    cout << "\nDeque after comparison:\n";
    displayDeque(dq);
    return 0;
}
