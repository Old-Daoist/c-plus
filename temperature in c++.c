#include <iostream>
using namespace std;

int main() {
    float temp;
    char unit;

    cout << "Enter the temperature and unit (C/F):" << endl;
    cin >> temp >> unit;

    if (unit == 'C' || unit == 'c') {
        float f = 1.8 * temp + 32;
        cout << "Temperature in Fahrenheit = " << f << endl;
    }
    else if (unit == 'F' || unit == 'f') {
        float c = (temp - 32) / 1.8;
        cout << "Temperature in Celsius = " << c << endl;
    }
    else {
        cout << "Invalid unit! Please enter C or F." << endl;
    }

    return 0;
}

