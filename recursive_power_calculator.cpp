#include <iostream>

using namespace std;

bool isEven(int n)
{
    return n % 2 == 0;
}

bool isOdd(int n)
{
    return !isEven(n);
}

double power(int x, int n)
{
    // println("Computing " + x + " raised to power " + n + ".");
    //  base case
    if (n == 0)
    {
        return 1;
    }
    // recursive case: n is negative
    if (n < 0)
    {
        return 1 / (power(x, (-n)));
    }
    // recursive case: n is odd
    if (isOdd(n))
    {
        return x * power(x, n - 1);
    }
    // recursive case: n is even
    int squareRoot = power(x, n / 2);
    return squareRoot * squareRoot;
}

void displayPower(int x, int n, double expectedResult)
{
    double result = power(x, n);
    cout << x << " to the " << n << " is " << result << " (" << (result == expectedResult ? "TRUE" : "FALSE") << ")" << endl;
}

int main()
{
    displayPower(3, 0, 1);
    displayPower(3, 1, 3);
    displayPower(3, 2, 9);
    displayPower(3, -1, (1.0 / 3.0));
    displayPower(5, 3, 125);
    displayPower(4, -4, (1.0 / 256.0));
    return 0;
}
