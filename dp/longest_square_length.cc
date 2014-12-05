#include <iostream>
#include <map>
using namespace std;

int LongestSquareLength(int* arr_a, int* arr_b, size_t length) {
    if (length == 0) {
       return 0;
    }
    int* arr = new int[length];
    for (int i = 0; i < length; ++i) {
        arr[i] = arr_a[i] - arr_b[i];
    }
    for (int i = 1; i < length; ++i) {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // unordered_map should have higher performance
    std::map<int, int> cache;
    cache[0] = -1;
    size_t start = 0;
    size_t end = 0;
    size_t max = 0;
    for (int i = 0; i < length; ++i) {
       if (cache.count(arr[i]) == 0) {
           cache[arr[i]] = i;
       } else {
           size_t len = i + 1 - cache[arr[i]];
           if (len > max) {
               max = len;
               start = cache[arr[i]];
               end = i;
           }
       }
    }
    delete [] arr;
    if (max == 0) {
        cout << "no valid square" << endl;
        return max;
    }
    int* a[2];
    a[0] = arr_a;
    a[1] = arr_b;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < length; ++i) {
            if (start == i) {
                cout << " | " ;
            }
            cout << a[j][i] << " ";
            if (end == i) {
                cout << " | ";
            }
        }
        cout << endl;
    }
    return max;
}

int main(int argc, char** argv) {
    int a[] = {1, 1, 0, 0, 1, 0};
    int b[] = {0, 0, 1, 1, 1, 1};
    size_t length = sizeof(a) / sizeof(int);
    cout << LongestSquareLength(a, b, length) << endl;
    return 0;
}
