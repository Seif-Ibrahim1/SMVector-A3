#include <iostream>
using namespace std;

template <typename T>
class SMVector {
private:
    typedef T* iterator;
    int s;
    int c;
    T* data;
public:
    // Constructors and Big 4

    // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    SMVector (int _c) {

    }		

    // Initialize by n items from array
    SMVector (T*, int  n) {

    }

    // Initialize with a copy	
    SMVector (const SMVector&) {

    }	

    // seif
    // Delete allocated memory	
    ~SMVector() {

    }

    // seif
    // Copy assignment			
    SMVector &operator=(const SMVector&) {

    }

    // seif
    // Move assignment  
    SMVector &operator=(const SMVector&&) {

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
    void erase(iterator) {

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
