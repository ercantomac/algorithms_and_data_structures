#include <iostream>

using namespace std;

int *merge(int leftHalf[], int rightHalf[], int leftHalfLength, int rightHalfLength)
{
    int *sortedArray = new int(leftHalfLength + rightHalfLength);

    for (int i = 0, j = 0, k = 0; k < (leftHalfLength + rightHalfLength); k++)
    {
        if (j >= rightHalfLength || (i < leftHalfLength && leftHalf[i] < rightHalf[j]))
        {
            sortedArray[k] = leftHalf[i];
            i++;
        }
        else
        {
            sortedArray[k] = rightHalf[j];
            j++;
        }
    }

    return sortedArray;
}

int *divide(int list[], int length)
{
    if (length == 1)
    {
        return list;
    }
    else
    {
        // DIVIDE THE ARRAY INTO TWO SEPARATE ARRAYS
        int middleIndex = (length % 2 == 0) ? (length / 2) : ((length + 1) / 2);
        int *leftHalf = new int(middleIndex);
        int *rightHalf = new int(length - middleIndex);
        for (int i = 0, j = 0, k = 0; i < length; i++)
        {
            if (i < middleIndex)
            {
                leftHalf[j] = list[i];
                j++;
            }
            else
            {
                rightHalf[k] = list[i];
                k++;
            }
        }

        // CALL THE FUNCTION RECURSIVELY FOR BOTH OF THE ARRAYS TO SORT THEM INTERNALLY
        int *leftHalfSorted = divide(leftHalf, middleIndex);
        int *rightHalfSorted = divide(rightHalf, (length - middleIndex));

        // MERGE AND SORT TWO SORTED ARRAYS, AND RETURN IT
        return merge(leftHalfSorted, rightHalfSorted, middleIndex, (length - middleIndex));
    }
}

int main()
{
    int array[10] = {23, 80, 756, 2, 99, 1083, 564, 58, 326, 99};
    int *result = divide(array, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << *(result + i) << endl;
    }

    return 0;
}