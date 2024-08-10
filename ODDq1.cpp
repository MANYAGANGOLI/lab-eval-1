#include <iostream>
#include <vector>

using namespace std;


vector<int> calculateDerivative(const vector<int>& coeffs) {
    vector<int> derivative;

    int degree = coeffs.size() - 1;
    for (int i = 1; i < coeffs.size(); ++i) {
        derivative.push_back(coeffs[i] * i);
    }

    return derivative;
}

void printPolynomial(const vector<int>& coeffs) {
    int degree = coeffs.size() - 1;
    for (int i = 0; i < coeffs.size(); ++i) {
        if (i == 0 && coeffs[i] != 0) {
            cout << coeffs[i];
        } else if (coeffs[i] != 0) {
            if (coeffs[i] > 0 && i != 0) {
                cout << " + " << coeffs[i];
            } else if (coeffs[i] < 0) {
                cout << " - " << -coeffs[i];
            }
            if (degree - i > 0) {
                cout << "x";
                if (degree - i > 1) {
                    cout << "^" << degree - i;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial (0 to 5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cout << "Invalid degree. Degree must be between 0 and 5." << endl;
        return 1;
    }

    vector<int> coefficients(degree + 1);

    cout << "Enter the coefficients (from constant term to the highest degree term):" << endl;
    for (int i = 0; i <= degree; ++i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "Polynomial: ";
    printPolynomial(coefficients);

    vector<int> derivative = calculateDerivative(coefficients);

    cout << "Derivative: ";
    printPolynomial(derivative);

    return 0;
}


