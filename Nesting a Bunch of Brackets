#include <iostream>
#include <string>
#include <vector>
using namespace std;

int checkBrackets(string s) {
    vector<pair <char, int>> posnomas;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && s[i] == '(' && s[i+1] == '*') {
            posnomas.push_back({ '*', i + 1 });
            i++;
        }
        else if (i + 1 < s.size() && s[i] == '*' && s[i+1] == ')') {
            if (posnomas.empty() || posnomas.back().first != '*') {
                return i + 1;
            }
            posnomas.pop_back();
            i++;
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
            posnomas.push_back({s[i], i+1});
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>') {
            if (posnomas.empty()) return i + 1;
            if ((s[i] == ')' && posnomas.back().first == '(') || (s[i] == ']' && posnomas.back().first == '[') || (s[i] == '}' && posnomas.back().first == '{') || (s[i] == '>' && posnomas.back().first == '<')) {
                posnomas.pop_back();
            }
            else {
                return posnomas.back().second;
            }
        }
    }
    if (!posnomas.empty()) {
        return posnomas.back().second;
    }
    return -1;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int errorPos = checkBrackets(line);
        if (errorPos == -1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO " << errorPos << endl;
        }
    }
    return 0;
}
