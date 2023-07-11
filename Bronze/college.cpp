#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long tuitions[n];
    for (int i = 0; i < n; i++) {
        cin >> tuitions[i];
    }
    sort(tuitions, tuitions+n);

    long long max_revenue = 0;
    long long optimal_tuition = 0;

    for (int i = 0; i < n; i++) {
        long long revenue = (n - i) * tuitions[i];
        if (revenue > max_revenue) {
            max_revenue = revenue;
            optimal_tuition = tuitions[i];
        }
    }
    cout << max_revenue << " " << optimal_tuition << endl;
    return 0;
}