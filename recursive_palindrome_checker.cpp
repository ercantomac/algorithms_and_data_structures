#include <iostream>

using namespace std;

// Returns the string that results from removing the first
//  and last characters from str
char *middleCharacters(char str[], int stringLength)
{
    char *middleArray = new char[(stringLength - 2)];
    for (int i = 0; i < (stringLength - 2); i++)
    {
        middleArray[i] = str[i + 1];
    }

    return middleArray;
}

bool isPalindrome(char str[], int stringLength)
{
    // base case #1
    if (stringLength <= 1)
    {
        return true;
    }
    // recursive case
    if (str[0] == str[stringLength - 1])
    {
        return stringLength > 2 ? isPalindrome(middleCharacters(str, stringLength), (stringLength - 2)) : true;
    }
    return false;
}

void checkPalindrome(char str[], int stringLength)
{
    cout << "Is this word a palindrome? " << str << endl;
    cout << (isPalindrome(str, stringLength) ? "TRUE" : "FALSE") << endl
         << endl;
}

int main()
{
    checkPalindrome("a", 1);
    checkPalindrome("motor", 5);
    checkPalindrome("rotor", 5);
    checkPalindrome("ercan", 5);
    checkPalindrome("15951", 5);
    return 0;
}
