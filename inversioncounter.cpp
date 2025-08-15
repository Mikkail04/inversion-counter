*/*******************************************************************************
* Name : inversioncounter.cpp
* Author : Mikkai Allen
* Version : 1.0
* Date : 11/4/23
* Description : Counts the number of inversions in an array.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

// Function prototypes
static long mergesort(int array[], int scratch[], int low, int high);

// Count inversions in an array using a slow algorithm (Theta(n^2)).
long count_inversions_slow(int array[], int length) {
    long inversionCount = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

// Count inversions in an array using a fast algorithm
long count_inversions_fast(int array[], int length) {
    int* scratch = new int[length];
    long inversions = mergesort(array, scratch, 0, length - 1);
    delete[] scratch;
    return inversions;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        long left_inversions = mergesort(array, scratch, low, mid);
        long right_inversions = mergesort(array, scratch, mid + 1, high);
        long merge_inversions = 0;

        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (array[i] <= array[j]) {
                scratch[k++] = array[i++];
            } else {
                scratch[k++] = array[j++];
                merge_inversions += mid - i + 1; // Count inversions during the merge
            }
        }

        while (i <= mid) {
            scratch[k++] = array[i++];
        }

        while (j <= high) {
            scratch[k++] = array[j++];
        }

        for (k = low; k <= high; k++) {
            array[k] = scratch[k];
        }

        return left_inversions + right_inversions + merge_inversions;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Parse arguments
    bool useSlow = false;
    if (argc == 2) {
        if (string(argv[1]) == "slow") {
            useSlow = true;
        } else {
            cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
            return 1;
        }
    } else if (argc > 2) {
        cerr << "Usage: " << argv[0] << " [slow]" << endl;
        return 1;
    }

    cout << "Enter sequence of integers, each followed by a space: " << flush;
    istringstream iss;
    int value;
    vector<int> values;

    string input;
    getline(cin, input);

    if (input.empty()) {
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }

    iss.clear(); // Clear any previous error flags
    iss.str(input);

    bool integersReceived = false;

    while (iss >> value) {
        values.push_back(value);
        integersReceived = true;
    }

    if (!integersReceived) {
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }

    if (useSlow) {
        long inversions = count_inversions_slow(&values[0], values.size());
        cout << "Number of inversions (slow): " << inversions << endl;
    } else {
        long inversions = count_inversions_fast(&values[0], values.size());
        cout << "Number of inversions (fast): " << inversions << endl;
    }

    return 0;
}
