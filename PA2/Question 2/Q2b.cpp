#include <iostream>

using namespace std;

double series(double);

double n = 0;

int main() {
    cout << "Enter n: ";
    cin >> n;

    double ans = series(n);

    cout << "Series(" << n << ") is: " << ans << endl;

    return 0;
}

double series(double n) {
    double left_series = 0;

    if (n == 0)
        return 0;
    else {
        left_series = series(n - 1);
        return (2 * n / (3 * n + 2)) + left_series;
    }
}