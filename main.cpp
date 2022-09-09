#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(1) space
vector<int> findThreeLargestNumbersSimplest(vector<int> &array) {
    int largest = INT16_MIN;
    int middle = INT16_MIN;
    int smallest = INT16_MIN;
    for(int element : array) {// O(n) time
        if(element >= largest) {
            smallest = middle;
            middle = largest;
            largest = element;
        } else if(element >= middle) {
            smallest = middle;
            middle = element;
        } else if(element >= smallest) {
            smallest = element;
        }
    }
    return *new vector<int> {smallest, middle, largest};// O(1) space
}

// O(n) time | O(1) space
void shiftAndUpdate(vector<int> &array, int num, int index) {
    for(int i = 0; i <= index; i++) {// O(n)
        if(i == index) {
            array[i] = num;
        } else {
            array[i] = array[i + 1];
        }
    }
}

// O(n) time | O(1) space
void updateLargest(vector<int> &array, int number) {
    if(number > array[2]) {
        shiftAndUpdate(array, number, 2);// O(n) time | O(1) space
    } else if(number > array[1]) {
        shiftAndUpdate(array, number, 1);// O(n) time | O(1) space
    } else if(number > array[0]) {
        shiftAndUpdate(array, number, 0);// O(n) time | O(1) space
    }
}

// O(n) time | O(1) space
vector<int> findThreeLargestNumbersMultipleMethods(vector<int> &array) {
    vector<int> threeLargest = {INT16_MIN, INT16_MIN, INT16_MIN};// O(1) space
    for(int element : array) {
        updateLargest(threeLargest, element);// O(n) time | O(1) space
    }
    return threeLargest;
}

int main() {
    vector<int> input = {-1, -2, -3, -7, -17, -27, -18, -541, -8, -7, 7};
    vector<int> simple = findThreeLargestNumbersSimplest(input);
    for(int element : simple) {
        cout << element << " ";
    }
    cout << endl;
    vector<int> multipleMethods = findThreeLargestNumbersMultipleMethods(input);
    for(int element : multipleMethods) {
        cout << element << " ";
    }
    return 0;
}
