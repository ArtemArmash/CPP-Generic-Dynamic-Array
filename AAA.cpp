#include <iostream>
#include <cstring> 
using namespace std;

template<class T>
class Queue {
private:
    T* datas;
    int size;
    int capacity;

public:
    Queue() : datas{ nullptr }, size{ 0 }, capacity{ 0 } {}
    explicit Queue(int capacity) : datas{ new T[capacity] }, size{ 0 }, capacity{ capacity } {}
    Queue(const Queue& q) : datas{ new T[q.capacity] }, size{ q.size }, capacity{ q.capacity } {
        for (int i = 0; i < size; i++) {
            datas[i] = q.datas[i];
        }
    }

    ~Queue() {
        delete[] datas;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            int newCapacity = capacity + 4;
            T* tmp = new T[newCapacity];

            for (int i = 0; i < size; i++) {
                tmp[i] = datas[i];
            }

            delete[] datas;
            datas = tmp;
            capacity = newCapacity;
        }
        datas[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            size--;

            if (size < capacity - 4) {
                T* tmp = new T[size + 4];
                for (int i = 0; i < size; i++) {
                    tmp[i] = datas[i];
                }
                delete[] datas;
                datas = tmp;
                capacity = size + 4;
            }
        }
    }

    T& front() {
        if (size > 0) {
            return datas[0];
        }
    }

    T& back() {
        if (size > 0) {
            return datas[size - 1];
        }
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void SWAP(Queue& ptr) {
        swap(datas, ptr.datas);
        swap(size, ptr.size);
        swap(capacity, ptr.capacity);
    }

    Queue& operator= (const Queue& q) {
        if (this != &q) {
            delete[]datas;
            datas = new T[q.capacity];
            for (size_t i = 0; i < q.size; i++)
            {
                datas[i] = q.datas[i];
            }
            size = q.size;
            capacity = q.capacity;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Queue& q) {
        for (int i = 0; i < q.size; i++) {
            out << q.datas[i] << ' ';
        }
        return out;
    }

};

int main() {
    Queue<char*> qa;
    char str1[] = "Hi, ";
    char str2[] = "World!!!";
    qa.push_back(str1);
    qa.push_back(str2);
    cout << qa << endl;
    qa.pop_back();
    cout << qa << endl;

    qa.front();
    cout << qa << endl;
}
