#include <iostream>

using namespace std;

int *slice(int array[], int from, int to)
{
    int *newArray = new int[(to - from)];
    for (int j = 0; j < (to - from); j++)
    {
        newArray[j] = array[from + j];
    }
    return newArray;
}

/* Returns either the index of the location in the array,
  or -1 if the array did not contain the targetValue */
int doSearch(int array[], int arrayLength, int targetValue)
{
    int min = 0;
    int max = arrayLength - 1;

    if (max < min)
    {
        return -1;
    }

    int guess = (arrayLength % 2 == 0) ? (arrayLength / 2) : ((arrayLength - 1) / 2);

    if (targetValue > array[guess])
    {
        if (arrayLength == 2 && array[1] == targetValue)
        {
            return 1;
        }
        int temp = doSearch(slice(array, (guess + 1), arrayLength), (arrayLength - (guess + 1)), targetValue);
        return (temp == -1) ? -1 : guess + 1 + temp;
    }

    if (targetValue < array[guess])
    {
        if (arrayLength == 2 && array[0] == targetValue)
        {
            return 0;
        }
        int temp = doSearch(slice(array, 0, guess), guess, targetValue);
        return (temp == -1) ? -1 : temp;
    }

    return guess;
}

int main()
{
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
                      41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int result = doSearch(primes, 25, 73);
    cout << "Found prime 73 at index " << result << endl;
    cout << (result == 20 ? "True" : "False") << endl
         << endl;

    result = doSearch(primes, 25, 13);
    cout << "Found prime 13 at index " << result << endl;
    cout << (result == 5 ? "True" : "False") << endl
         << endl;

    result = doSearch(primes, 25, 89);
    cout << "Found prime 89 at index " << result << endl;
    cout << (result == 23 ? "True" : "False") << endl
         << endl;

    result = doSearch(primes, 25, 43);
    cout << "Found prime 43 at index " << result << endl;
    cout << (result == 13 ? "True" : "False") << endl
         << endl;

    result = doSearch(primes, 25, 10);
    cout << "Found prime 10 at index " << result << endl;
    cout << (result == -1 ? "True" : "False") << endl
         << endl;

    result = doSearch(primes, 25, 120);
    cout << "Found prime 120 at index " << result << endl;
    cout << (result == -1 ? "True" : "False") << endl
         << endl;
}
