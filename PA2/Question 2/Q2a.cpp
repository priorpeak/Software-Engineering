#include <iostream>

using namespace std;

int gcd(int, int);

int ans = 0;

int main() {
    int m, n = 0;

    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    ans = gcd(m, n);
    cout << "GCD is: " << ans << endl;
    
    return 0;
}

int gcd(int m, int n) {
    if (m % n == 0)
        return n;
    else
        ans = gcd(n, m % n);
        return ans;
}