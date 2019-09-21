#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This problem was asked by Airbnb.
// Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
//Numbers can be 0 or negative.
// For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
// Follow-up: Can you do this in O(N) time and constant space?

//Find the largest number in the array. Find the second largest number in the array that is not next to the first
//largest number of the array.
int largestSum(int *arr, int size, int start)
{
    int theSum = 0;
    for (int i = start; i < size; i += 2)
    {
        theSum = theSum + arr[i];
    }

    return theSum;
}

//test if two numbers are consecutive from each other
void consecutive(int arr[], int size, int a, int b)
{
    //ia, ib, respectively are the indexes of a and b in the arr
    //cia, cib, keeps track of the number of times that a and b occurred in the array.
    //the count should only be 1

    bool arethey = true;
    int ia1 = 0, ia2 = 0, ib1 = 0, ib2 = 0, cia = 0, cib = 0;
    int first = 0, second = 0, ctrlVar = 2; //one occurrence for a, one for b
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == a && ctrlVar != 0)
        {
            cia++;
            ia1 = i;
            //if cia==2, that means the second occurrence has occurred, we use the second variable
            if (cia == 2)
            {
                ia2 = i;
            }

            ctrlVar--;
        }

        if (arr[i] == b && ctrlVar != 0)
        {
            cib++;
            ib1 = i;
            if (cib == 2)
            {
                ib2 = i;
            }

            ctrlVar--;
        }
    }
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;

    if (abs(ia1 - ib1) > 1)
    {
        arethey = false;
        //cout << "not consecutive!" << endl;
    }
    else
    {
        //cout << "consecutive!" << endl;
    }

    //return arethey;
}

void first(int arr[], int size, int a, int b)
{
    int premier = 0;
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] == a) || (arr[i] == b))
        {
            if (arr[i] == a)
            {
                premier = a;
            }

            else
            {
                premier = b;
            }
        }
    }

    cout << "first = " << premier << endl;
}

void addToArr(vector<int> arr)
{
}

//number of occurrence of element e in the array arr
void numOfOcc(int arr[], int size, int e)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (e == arr[i])
        {
            counter = counter + 1;
            cout << "matched! " << counter << endl;
        }
    }

    cout << "number of occurrence of " << e << " = " << counter << endl;
}

int main()
{

    int odd[] = {2, 4, 6, 2, 5};
    int even[] = {3, 1, 5, 2, 1, 9};
    int arr[] = {1, 2, 4, 3, 4, 3, 2, 1};

    //consecutive(even, 6, 3, 2);
    //numOfOcc(arr, 8, 4);
    //first(arr, 8, 4, 3);
}