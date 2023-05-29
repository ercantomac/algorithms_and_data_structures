#include <iostream>

using namespace std;

/// MAX. VALUE OF N IS 94, WHICH RESULTS IN 12200160415121876738.
unsigned long long int *fibonacci(int n, bool isRecursive)
{
    if (n == 0)
    {
        unsigned long long int *result = new unsigned long long int[1];
        result[0] = 0;
        return result;
    }
    if (n == 1)
    {
        if (isRecursive)
        {
            unsigned long long int *result = new unsigned long long int[2];
            result[0] = 0;
            result[1] = 1;
            return result;
        }
        else
        {
            unsigned long long int *result = new unsigned long long int[1];
            result[0] = 1;
            return result;
        }
    }
    unsigned long long int *resultArray = fibonacci((n - 1), true);
    unsigned long long int resultOfThis = (resultArray[0] + resultArray[1]);
    if (isRecursive)
    {
        unsigned long long int *result = new unsigned long long int[2];
        result[0] = resultArray[1];
        result[1] = resultOfThis;
        return result;
    }
    unsigned long long int *result = new unsigned long long int[1];
    result[0] = resultOfThis;
    return result;
}

int main()
{
    int n = 0;
    while (true)
    {
        while (n < 1)
        {
            cout << "Find the n. fibonacci number. n: ";
            cin >> n;
            if (n < 1)
            {
                cout << "Type a number greater than 0." << endl;
            }
        }

        cout << n << ". fibonacci number is: " << fibonacci((n - 1), false)[0] << endl
             << endl;
        n = 0;
    }
    return 0;
}