#include <iostream>
#include <string>

using namespace std;
//when declaring a pointer as an array, always use a pointer
//if you want a function to return an array, that function should return a pointer

//One
//Given a list of numbers and a number n, return whether any two numbers from the list add up to n.
//For example, given[10, 15, 3, 7] and n of 17, return true since 10 + 7 is 17.
//One thing about C++, the codes are read and compiled from top to bottom.

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// This problem was asked by Stripe.
// Given an array of integers, find the first missing positive integer in linear time and constant space.
//In other words, find the lowest positive integer that does not exist in the array.
//The array can contain duplicates and negative numbers as well.
// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

//The number is either greater than the lowest number and it's positive and it's not in the array yet
//Or, it can be greater than the largest number and it's positive.
//I will keep incrementing from the lowest number until I reach a number that is not in the array
//or until I reached the largest number in the array and it's positive.
//If all the numbers are negative, the answer is 0.
//If the lowest number is negative and 0, we start at 1, then we start checking if it's in the array

//arr* here can be any array
int findLowest(int *arr, int size)
{
    int lowest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }

    return lowest;
}

int findLargest(int *arr, int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

bool thereIsANegativeElement(int *arr, int size)
{
    bool yes = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= 0)
        {
            yes = true;
            break;
        }
    }

    return yes;
}

//checks if each element is nonpositive
bool allIsNegative(int *arr, int size)
{
    bool yes = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            yes = false;
            break;
        }
    }

    return yes;
}

//check how many positives are there
int positives(int *arr, int size)
{
    int count = 0; //counts how many positive integers are in the array

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            count++;
        }
    }

    cout << "positives = " << count << endl;
    return count;
}

//function to get rid of the negative values of the array
//So you can modify an array using a function
int *dropNegatives(int *arr, int size)
{
    int count = 0; //counts how many nonpositive integers are in the array

    int j = 0; //indexes for the new array
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] <= 0)
    //     {
    //         count++;
    //     }
    // }

    count = positives(arr, size); //returns how many positive elements the new array will contain.

    //cout << "number of negatives = " << count << endl;
    int *newArr = new int[count];

    for (int k = 0; k < size; k++)
    {
        if (arr[k] > 0)
        {
            newArr[j] = arr[k];
            //cout << newArr[j] << " ";
            j++;
        }
    }
    return newArr;
}

int *fillUpArray(int start, int last, int size)
{
    int *newArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = start;
        start++;
    }

    return newArr;
}

int four(int *arr, int size)
{
    int num = 0;

    //Create a new array consisting of all numbers with unit increment.
    bool negativeElement = thereIsANegativeElement(arr, size);
    bool allNegative = allIsNegative(arr, size);
    //If all elements are negative, then the lowest positive integer is 1
    if ((int)allIsNegative == 1)
    {
        //cout << "fuck!" << endl;
        num = 1;
    }

    //When the array is a mixed of numbers,
    else
    {
        //drop all the negative integers from the array and store the remaining elements in a new array
        int *newArr = dropNegatives(arr, size);
        //cout << newArr[0] << endl;
        //returns how many positive elements are in the new array
        int count = positives(arr, size);
        //Now that the new array contains only positive elements, we can now determine the lowest and largest numbers.
        int lowest = findLowest(newArr, count);
        //first element in the possible answers array is lowest + 1;
        int start = lowest;
        //cout << "lowest = " << lowest << endl;
        int largest = findLargest(newArr, count);
        //last element in the possible answers array is largest + 1;
        int last = largest + 1;
        // cout << "largest = " << largest << endl;
        // cout << "last = " << last << endl;

        //difference is the range of values that will be contained in the array containing possible answers.
        int difference = last - start + 1; //the number of elements in the answers array
        int *answers = fillUpArray(start, last, (last - start + 1));
        cout << "count = " << count << endl;
        //cout << "difference = " << difference << endl;
        displayArray(newArr, count);
        int range = count * (difference);
        //cout << "range = " << range << endl;

        //This is it. We are now comparing the
        int reset = 0;
        int r = 0;       //this will keep track of the index of the elements containing the possible numbers
        int counter = 0; //counts how many times we encountered comparison
        for (int i = 1; i <= range; i++)
        {
            //cout << i << " ";
            if (answers[r] == newArr[(i - 1) % count])
            {
                counter++;
            }

            if ((i % count) == 0)
            {
                //If counter is not 0, we reset
                if (counter > 0)
                {
                    r++;
                    counter = 0;
                }

                else
                {
                    //cout << "found! " << answers[r];
                    num = answers[r];
                    break;
                }
            }

            // if (answers[r] == newArr[i % count])
            // {
            //     cout << answers[r] << " " << newArr[i % count];
            //     counter++;
            // }
            // //If it has been count (number of elements in the array) times and we found a match
            // //we reset to 0, we continue.
            // if (((i + 1) % count == 0) && (counter > 0))
            // {
            //     cout << "in!" << endl;
            //     reset = 0;
            //     r++;
            //     counter = 0; //resets counter to 0 for another round of comparisons.
            // }

            // if (((i + 1) % count == 0) && (counter == 0))
            // {
            //     cout << "found! " << answers[r] << endl;
            //     //break;
            // }
        }
    }

    //If there is, we start at 1.

    //Check if
    //for (int i = 0)

    return num;
}

// Summary:
// FirsT, I stored the positive elements from the array into another array newArr,
// Created another array containing all possible answers to the question which is contained in the
// new array answers. From that, I compared each of the positive elements of the answers array to each
// element in newArr. I did the comparisons in linear time.

int main()
{
    int arr1[] = {3, 2, 4, 1, 5};
    int arr2[] = {3, 5, -1, 4};
    int arr3[] = {-3, -2, -4, -1, -5};

    //fucking works! A pointer can hold an array, which holds the address of the first element of the array!
    //displayArray(newArray, 5); //so wtf! The pointer argument holds the first element of the array one
    //cout << "daily coding" << endl;
    // one(arr1, 5, 9);
    // cout << "lowest = " << findLowest(arr1, 5) << endl;
    // cout << "largest = " << findLargest(arr1, 5) << endl;
    // cout << "negative? " << thereIsANegativeElement(arr2, 5) << endl;
    // cout << "All is negative? " << allIsNegative(arr3, 5) << endl;

    //dropNegatives(arr2, 5);
    cout << four(arr2, 4) << endl;

    // int *newArr = fillUpArray(2, 6, 5);
    // displayArray(newArr, 5);
}