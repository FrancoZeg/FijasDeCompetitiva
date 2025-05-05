#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int ALPHABET_SIZE = 26;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bitset<ALPHABET_SIZE>> sets(n);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            bitset<ALPHABET_SIZE> bs;
            for (char c : s) {
                bs.set(c - 'a');
            }
            sets[i] = bs;
        }

        int cuts = 0;
        bitset<ALPHABET_SIZE> common = sets[0];

        for (int i = 1; i < n; ++i) {
            if ((common & sets[i]).none()) {
                cuts++;
                common = sets[i];
            }
            else {
                common &= sets[i];
            }
        }

        cout << cuts << '\n';
    }

    return 0;
}
