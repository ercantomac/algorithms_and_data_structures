#include <iostream>

using namespace std;

int *insertionSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (array[i + 1] < array[j])
            {
                // SHIFTING ELEMENTS FORWARD BY 1 INDEX
                int temp = array[i + 1];
                for (int k = i + 1; k > j; k--)
                {
                    array[k] = array[k - 1];
                }

                // INSERTING THE VALUE INTO WHERE IT NEEDS TO BE
                array[j] = temp;
            }
        }
    }

    return array;
}

int main()
{
    int array[10] = {23, -80, 756, 2, 99, 1083, 564, 58, 326, 99};
    int *result = insertionSort(array, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << *(result + i) << endl;
    }

    return 0;
}