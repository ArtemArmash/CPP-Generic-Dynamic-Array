# Generic Dynamic Array (Vector-like) Class in C++

This project is a C++ implementation of a generic, dynamic array class. It is designed to be a flexible container that can store elements of any data type and automatically manages its own memory, growing and shrinking as needed.

**Note:** Although the class is named `Queue` in the source code, its behavior is that of a **dynamic array** or **vector**, not a traditional First-In-First-Out (FIFO) queue. It uses methods like `push_back` and `pop_back`, which operate on the end of the collection.

## About The Project

This implementation is a great educational tool for understanding several fundamental and advanced C++ concepts:

*   **Class Templates**: The use of `template<class T>` makes the class generic and capable of working with any data type (`int`, `double`, `char*`, custom objects, etc.).
*   **Dynamic Memory Management**: The class uses `new[]` and `delete[]` to manage a contiguous block of memory on the heap, demonstrating manual resource management.
*   **The Rule of Three**: The class correctly implements a user-defined destructor, copy constructor, and copy assignment operator (`operator=`), which is essential for any class that manages its own memory.
*   **Automatic Resizing**: The internal array automatically grows when it runs out of space and shrinks when a significant amount of space becomes unused, optimizing memory usage.
*   **Operator Overloading**: The stream insertion operator (`<<`) is overloaded for easy printing of the container's contents to the console.

## Features

*   **Generic Programming**: Can be instantiated with any data type.
*   **Dynamic Capacity**: Automatically allocates more memory when `push_back` is called on a full container.
*   **Memory Optimization**: Shrinks its capacity if the number of elements drops significantly, freeing up unused memory.
*   **Core Container Operations**:
    *   `push_back()`: Adds an element to the end of the array.
    *   `pop_back()`: Removes the last element from the array.
    *   `front()`: Accesses the first element.
    *   `back()`: Accesses the last element.
    *   `getSize()`: Returns the number of elements currently stored.
    *   `empty()`: Checks if the container is empty.
    *   `SWAP()`: Efficiently swaps the contents of two containers.
*   **Proper Resource Management**: Adheres to the Rule of Three to prevent memory leaks and shallow copy issues.

## How to Build and Run

You will need a C++ compiler (e.g., G++, Clang, or MSVC).

1.  Save the code as a `.cpp` file (e.g., `MyDynamicArray.cpp`).
2.  Open a terminal or command prompt in the directory where you saved the file.
3.  Compile the code:
    ```sh
    g++ MyDynamicArray.cpp -o my_array_app
    ```
4.  Run the executable:
    ```sh
    ./my_array_app
    ```
    On Windows:
    ```cmd
    my_array_app.exe
    ```

## Important Considerations

### Naming: `Queue` vs. Dynamic Array

A traditional **Queue** data structure follows a **First-In-First-Out (FIFO)** principle. This means you add elements to the back (`enqueue`) and remove them from the front (`dequeue`). [2, 3, 5]

This class, however, implements `push_back` and `pop_back`, which both operate on the **end** of the data structure. This is characteristic of a **stack** (LIFO) or, more accurately, a **dynamic array** (like `std::vector`). [8, 9] For a true queue implementation, `pop_back` should be `pop_front`, and it would remove `datas[0]`.

### Usage with Raw Pointers (`char*`)

The `main` function demonstrates usage with `char*`. While this works, it highlights a potential pitfall. The class performs a **shallow copy** of the pointers themselves, not a **deep copy** of the C-style strings they point to.

**Example Issue:**
```cpp
Queue<char*> myStrings;
char* myStr = new char;
strcpy(myStr, "Hello");
myStrings.push_back(myStr);

// If we delete myStr here, the pointer inside the Queue becomes a dangling pointer.
delete[] myStr;

// This would lead to undefined behavior.
// std::cout << myStrings.front() << std::endl;
```

For robust use with C-style strings, it would be better to use `std::string` as the template type, as it manages its own memory correctly.
```cpp
// Safer usage
Queue<std::string> qa;
qa.push_back("Hi, ");
qa.push_back("World!!!");
std::cout << qa << std::endl; // Works perfectly
```
```
