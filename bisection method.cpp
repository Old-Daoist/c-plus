#include <iostream>
#include <cmath>
using namespace std;

// Define the function f(x)
float f(float x) {
    return (x*x*x - x - 2);
}

int main() {
    float a, b, c, e;

    cout << "Enter initial guesses a and b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid initial guesses. f(a) and f(b) must have opposite signs.";
        return 0;
    }

    cout << "Enter allowed error: ";
    cin >> e;

    do {
        c = (a + b) / 2;

        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(b - a) >= e);

    cout << "Root is approximately: " << c;

    return 0;
}
