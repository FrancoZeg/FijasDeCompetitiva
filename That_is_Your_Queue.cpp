#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, C, caseNum = 1;

    while (cin >> P >> C, P || C) {
        cout << "Case " << caseNum++ << ":\n";
        list<int> l;

        for (int i = 1; i <= P && i <= 1000; ++i) {
            l.push_back(i);
        }

        for (int i = 0; i < C; ++i) {
            string cmd;
            cin >> cmd;

            if (cmd == "N") {
                int id = l.front();
                l.pop_front();
                cout << id << '\n';
                l.push_back(id);
            }
            else if (cmd == "E") {
                int x;
                cin >> x;
                // Busca y elimina x en O(N), pero con listas es más eficiente en la práctica
                for (auto it = l.begin(); it != l.end(); ++it) {
                    if (*it == x) {
                        l.erase(it);
                        break;
                    }
                }
                l.push_front(x);
            }
        }
    }

    return 0;
}
