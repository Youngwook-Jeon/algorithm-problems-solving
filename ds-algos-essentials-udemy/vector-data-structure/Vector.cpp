// vector 자료구조 직접 구현하기
#include <iostream>
using namespace std;

class Vector {
    int *arr;
    int cs;
    int ms;

public:
    Vector(int max_size = 1) {
        cs = 0;
        ms = max_size;
        arr = new int[ms];
    }

    void push_back(const int d) {
        if (cs == ms) {
            int *oldArr = arr;
            ms = 2 * ms;
            arr = new int[ms];
            for (int i = 0; i < cs; i++) {
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
        }
        arr[cs] = d;
        cs++;
    }

    void pop_back() {
        if (cs >= 1) {
            cs--;
        }
    }

    bool is_empty() const {
        return cs == 0;
    }

    int front() const {
        return arr[0];
    }

    int back() const {
        return arr[cs - 1];
    }

    int at(int i) const {
        return arr[i];
    }

    int size() const {
        return cs;
    }

    int capacity() const {
        return ms;
    }

    int operator[](const int i) const {
        return arr[i];
    }
};

int main() {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << v.size() << endl;
    cout << v.capacity();
    return 0;
}