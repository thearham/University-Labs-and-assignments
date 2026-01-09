#include <iostream>
using namespace std;

template <typename T>
class MyArray {
private:
    T* arr;
    int size;
    int count;

public:
    MyArray(int size = 100) : size(size), count(0) {
        arr = new T[size];
    }

    ~MyArray() {
        delete[] arr;
    }

    void add(const T& item) {
        if (count < size) {
            arr[count++] = item;
        }
    }

    int length() const {
        return count;
    }

    void clear() {
        for (int i = 0; i < count; i++) {
            arr[i] = '\0';
        }
        count = 0;
    }

    T& operator[](int index) {
        return arr[index];
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    MyArray<T>& operator++() {
        for (int i = 0; i < count; i++) {
            arr[i]++;
        }
        return *this;
    }

    MyArray<T> operator++(int) {
        MyArray<T> temp(*this);
        operator++();
        return temp;
    }

    MyArray<T>& operator--() {
        for (int i = 0; i < count; i++) {
            arr[i]--;
        }
        return *this;
    }

    MyArray<T> operator--(int) {
        MyArray<T> temp(*this);
        operator--();
        return temp;
    }

    template <typename U>
    friend MyArray<U> operator+(const MyArray<U>& arr1, const MyArray<U>& arr2);

    template <typename U>
    friend void print(const MyArray<U>& arr);
};

template <typename U>
MyArray<U> operator+(const MyArray<U>& arr1, const MyArray<U>& arr2) {
    MyArray<U> result(arr1.size + arr2.size);
    for (int i = 0; i < arr1.count; i++) {
        result.add(arr1.arr[i]);
    }
    for (int i = 0; i < arr2.count; i++) {
        result.add(arr2.arr[i]);
    }
    return result;
}

template <typename U>
void print(const MyArray<U>& arr) {
    for (int i = 0; i < arr.length(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    MyArray<char> arr1; // make a default array of 100 size
    arr1.add('[');
    arr1.add('A');
    arr1.add('B');
    arr1.add('C');
    arr1.add('D');
    arr1.add(']');
    cout << "arr1\n";
    print(arr1);
    cout << "Length of arr1 is = " << arr1.length() << endl;

    arr1.clear();
    cout << "After clearing arr1\n";
    print(arr1);
    arr1.add('$');
    cout << "After adding $ to arr1\n";
    print(arr1);

    cout << "arr2\n";
    MyArray<int> arr2;
    arr2.add(1);
    arr2.add(2);
    arr2.add(3);
    arr2.add(4);
    arr2.add(5);
    print(arr2);
    cout << "Length of arr2 is =" << arr2.length() << endl;

    MyArray<char> arr3;
    arr3.add('*');
    arr3 = arr1 + arr3;
    cout << "arr3\n";
    print(arr3);

    MyArray<double> arr4(5);
    arr4.add(2.5);
    arr4.add(3.5);
    arr4.add(6.5);
    arr4.add(7.5);
    cout << "arr4\n";
    print(arr4);
    arr4[0] = arr4[1] + 2.0;
    print(arr4);
    print(arr4++);
    print(++arr4);
    print(--arr4);
    print(arr4--);

    return 0;
}
