#include <iostream>

using namespace std;

void swap(int array[], int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int partition(int array[], int p, int r)
{
    int pivot = array[r];

    while (true)
    {
        int largerFromLeft = -1, smallerFromRight = -1;
        for (int i = p; i < r; i++)
        {
            if (array[i] > pivot)
            {
                largerFromLeft = i;
                break;
            }
        }
        if (largerFromLeft == -1)
        {
            return r;
        }

        for (int i = r - 1; i >= p; i--)
        {
            if (array[i] <= pivot)
            {
                smallerFromRight = i;
                break;
            }
        }
        if (smallerFromRight == -1)
        {
            swap(array, p, r);
            return p;
        }

        if (smallerFromRight < largerFromLeft)
        {
            swap(array, largerFromLeft, r);
            return largerFromLeft;
        }
        swap(array, largerFromLeft, smallerFromRight);
    }
}

int *quickSort(int array[], int p, int r)
{
    if ((r - p) >= 1)
    {
        int pivotIndex = partition(array, p, r);
        quickSort(array, p, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, r);
    }

    return array;
}

int main()
{
    int array[10] = {23, -80, 756, 2, 99, 1083, 564, 58, 326, 99};
    int *result = quickSort(array, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << *(result + i) << endl;
    }

    return 0;
}
