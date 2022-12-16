#include <iostream>
using namespace std;

template <typename T>
class SMVector {
private:
    typedef T* iterator;
    int _size;
    int _capacity;
    T* _vec;
public:
    // Constructors and Big 4

    // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    SMVector (int) {

    }		

    // Initialize by n items from array
    SMVector (T*, int) {

    }

    // Initialize with a copy	
    SMVector (const SMVector&) {

    }	

    // seif
    // Delete allocated memory	
    ~SMVector() {
        delete[] _vec;
    }

    // seif
    // Copy assignment			
    SMVector &operator=(const SMVector& other) {
        if(*this != other) {
            delete[] _vec;
            _capacity = other._capacity;
            _size = other._size;
            _vec = new T[_capacity];
            for(int i = 0; i < _size; i++) {
                _vec[i] = other._vec[i];
            }
        }
        return *this;
    }

    // seif
    // Move assignment  
    SMVector &operator=(const SMVector&& other) {
        if (*this != other) {
            delete[] _vec;
            _capacity = other._capacity;
            _size = other._size;
            _vec = other._vec;    
            other._vec = nullptr;
            other._capacity = 0;
            other._size = 0;
        }
        return *this;
    }	 

    // Access operations
    // Access item by reference
    // Throw an exception if out of range
    T& operator[](int) {

    }	

    // Modifying operations
    // Add item to end of vec & return # of items
    // Increase capacity of needed
    int push_back(T) {
        return 1;
    }	

    // Remove and return last element in vec
    T pop_back()  {

    }

    // seif
    // Remove item at iterator
    // Throw exception if invalid iter
    void erase(iterator i) {
        
    }

    // seif
    // Remove items between
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range       
    void erase(iterator, iterator) {

    }	

    // Delete all vector content
    void clear() {

    }	 

    // Insert item at iterator
    // Throw exception if invalid 
    void insert(iterator, T) {

    }

    // seif
    // Return an iterator (T*)
    iterator begin() {

    }

    // seif
    // Return an iterator (T*)
    iterator end() {

    }		

    // Comparison operations
    // Return true if ==
    bool operator==(const SMVector<T>&) {
        return true;
    }

    // seif
    // Compares item by item
    // Return true if first different item in this is < in other
    bool operator< (const SMVector<T>&) {
        return true;
    }	

    // Capacity operations
    // Return current size of vec
    int size() const {
        return 1;
    }	 

    // Return size of current allocated array
    int capacity() const {
        return 1;
    }

    // seif
    // Relocate to bigger space
    int resize() {
        return 1;
    }	

    // Return true if size is 0
    bool empty() {
        return true;
    }

    // seif
    // Friends
    friend ostream& operator << (ostream& out, SMVector<T>){
        return out;
    }
};
