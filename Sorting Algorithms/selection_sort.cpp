#include <iostream>

using namespace std;

int *selectionSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i)
        {
            int temp = array[i];
            array[i] = array[smallestIndex];
            array[smallestIndex] = temp;
        }
    }
    return array;
}

int main()
{
    int array[10] = {23, 80, 756, 2, 99, 1083, 564, 58, 326, 99};
    int *result = selectionSort(array, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << *(result + i) << endl;
    }

    return 0;
}