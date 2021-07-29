#include <iostream>
using namespace std;

void print_array(int arr[]) {
    cout << "In Function " << sizeof(arr) << endl; // In Function 8
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << "In Main " << sizeof(arr) << endl; // In Main 24

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    print_array(arr); // pass by reference가 발생, 따라서 주소값이 넘어감으로 8 bytes의 사이즈(64bit 시스템에서)를 가지게 됨

    return 0;
}