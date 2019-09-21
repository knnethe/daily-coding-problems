#include <iostream>
#include <vector>

using namespace std;
// This problem was asked by Google.

// Given an array of integers and a number k, where 1 <= k <= length of the array,
//compute the maximum values of each subarray of length k.

// For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

// 10 = max(10, 5, 2)
// 7 = max(5, 2, 7)
// 8 = max(2, 7, 8)
// 8 = max(7, 8, 7)
// Do this in O(n) time and O(k) space.
//You can modify the input array in-place and you do not need to store the results.
//You can simply print them out as you compute them.

//takes as a parameter, an array of size k
int max(int arrk[], int k)
{
    int newMax = arrk[0];
    for (int i = 1; i < k; i++)
    {
        if (arrk[i] > newMax)
        {
            newMax = arrk[i];
        }
    }

    return newMax;
}

int main()
{
    int k = 3;
    int arr[] = {10, 5, 2, 7, 8, 7};

    cout << "htlleo" << endl;

    //cout << max(arr, 6);
    int newMax = 0, counter = 0, j = 0, size = 6;
    for (int i = 0; i < size - 2; i++)
    {
        counter = 0;
        newMax = arr[i];
        j = i + 1;
        while (counter != 2)
        {
            //cout << arr[j] << " ";
            if (arr[j] > newMax)
            {
                newMax = arr[j];
            }
            counter++;
            j++;
        }
        //cout << endl;
        cout << newMax << " ";
        j = 0;
    }
}