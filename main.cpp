#include <iostream>

using namespace std;

template <typename T> class vectorClass{
    // Vector adresini tutan Pointer
    T* arr;
    // Vector kapasitesi
    int capacity;
    // o anki numarası
    int current;

public:
    // Default Constructor
    vectorClass(){
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(T data){
        if (current == capacity){
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++){
                temp[i] = arr[i];
            }
            delete [] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void push(int data, int index){
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    T get (int index) {
        if (index < current)
            return arr[index];
    }

    void pop(){
        current--;
    }

    int size() {
        return current;
    }

    void print(){
        for (int i = 0; i < current; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



int main() {
    vectorClass<int> v;

    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);

    cout << "Vector elements : ";
    v.print();

    cout << "Vector size : " << v.size();

    v.push(10, 2);

    cout << "\nAfter updating 2. index" << endl;
    v.print();

    cout << "Element at 1st index: " << v.get(1);

    v.pop();

    cout << "\nAfter delete last element" << endl;

    cout << "new Vector size: " << v.size() << endl;


    return 0;
}
