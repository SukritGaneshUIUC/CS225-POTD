// your code here!

#include <cmath>
#include <iostream>

namespace potd {
  int *raise(int *arr) {
    // int size = 0;
    // for (int x : arr) {
    //   size++;
    // }
    // std::cout << "size:" << size << std::endl;

    // int * powerArray;
    // for (int i = 0; i < (int) size - 2; i++) {
    //   std::cout << i << std::endl;
    //   *(powerArray + i) = pow(*(powerArray + i), *(powerArray + i + 1));
    //    // powerArray[i] = pow(powerArray[i], powerArray[i+1]);
    // }

    int size = 0;
    while(arr[size] > 0) {
      size++;
    }
    size++;

    std::cout << size << std::endl;

    int * powerArray = new int[size];
    // int count = 0;
    // while(true) {
    //   if (*(arr + 1) > 0) {
    //     powerArray[count] = pow(*arr, *(arr + 1));
    //     count++;
    //   } else {
    //     break;
    //   }
    // }
    for (int i = 0; i < size - 2; i++) {
      std::cout << i << std::endl;
      powerArray[i] = pow(arr[i], arr[i+1]);
    }
    powerArray[size - 2] = arr[size - 2];
    powerArray[size - 1] = arr[size - 1];

    return powerArray;
  }
}
