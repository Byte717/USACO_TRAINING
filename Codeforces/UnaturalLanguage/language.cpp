#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string word;
        cin >> word;

        string syllables;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && ((word[i] == 'a' || word[i] == 'e') && (word[i + 1] == 'b' || word[i + 1] == 'c' || word[i + 1] == 'd'))) {
                syllables += word[i];
                syllables += '.';
            } else {
                syllables += word[i];
            }
        }

        cout << syllables << endl;
    }

    return 0;
}
