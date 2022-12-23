#include <iostream>
#include "exceptions.cpp"
using namespace std;

template <typename T>
class SMVector {
private:
    typedef T* iterator;
    int _size;
    int _capacity;
    T* _vec;
    int getIndex(iterator iter) {
        for(int i = 0; i < _size; i++) {
            if(_vec[i] == *iter) {
                return i;
            }
        }
        return -1;
    }
    //function return number of elemts in _vec
    // int NumOfElements(){
    //     int NumExist = 0 ;
    //     while (_vec[NumExist]){
    //         NumExist++;
    //     }
    //     return NumExist;
    // }
public:
    // Constructors and Big 4

    // Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    SMVector (int sz) {
        if (sz<0){
            throw InvalidSize();
        }
        //intialize the size by 0
        _size = 0;
        //give the capacity the number
        _capacity = sz;
        //create array of pointers of the given number 
        _vec = new T[_capacity];
    }		

    // Initialize by n items from array
    SMVector (T* arr, int sz) {
        _size = sz;
        _vec = arr;
        _capacity = sz;
    }

    // Initialize with a copy	
    SMVector (const SMVector& other) {
        _size = other._size;
        _capacity = other._capacity;
        _vec = other._vec;
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
    T& operator[](int index) {
        //check if the index is valid or not
        if (index < 0 || index >= _size){
            throw OutOfRange();
        }
        //if it valid return the index
        return _vec[index];
    }	

    // Modifying operations
    // Add item to end of vec & return # of items
    // Increase capacity of needed
    int push_back(T item) {
        //push the item in the vec
        _vec[_size] = item;
        //increase the size 
        _size++;
        //extend the capacity
        if (_size > _capacity){
            _capacity += (_capacity/2); 
        }
        //return size after adding the new elemnt
        return _size;
    }	

    // Remove and return last element in vec
    T pop_back()  {
        T* newarr = new T[_size-1];
        //copy all elemets in new array except last one
        for (size_t i = 0; i < _size-1; i++){
            newarr = _vec[i];
        }
        //copy all elemets from new array to the vec
        for (size_t i = 0; i < _size-1; i++){
            _vec[i]  = newarr;
        }
        //reduce size by 1
        _size--;
        //delete the new array
        delete[] newarr;
        return _vec[_size];
    }

    // seif
    // Remove item at iterator
    // Throw exception if invalid iter
    void erase(iterator i) {
        if(getIndex(i) == -1) {
            throw Invaliditerator();
        }
        T* newVec = new T[_capacity];
        int index = 0;
        for(int j = 0; j < _size; j++) {
            if(_vec[j] != *i){
                newVec[index++] = _vec[j];
            }
        }
        _size = index;
        _vec = new T[_capacity];
        for(int j = 0; j < _size; j++) {
            _vec[j] = newVec[j];
        }
        delete[] newVec;

    }

    // seif
    // Remove items between
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range       
    void erase(iterator iterator1, iterator iterator2) {

        int i1 = getIndex(iterator1);
        int i2 = getIndex(iterator2);
        if(i1 == -1 || i2 == -1) {
            throw Invaliditerator();
        }

        if(i1 >= i2) {
            throw OutOfRange();
        }

        T* newVec = new T[_capacity];
        int index = 0;
        for(int j = 0; j < _size; j++) {
            if(_vec[j] == *iterator1) {
                while(_vec[j++] != *iterator2) {
                    continue;
                }
            }
            newVec[index++] = _vec[j];
        }
        _vec = new T[_capacity];
        for(int j = 0; j < _size; j++) {
            _vec[j] = newVec[j];
        }
        delete[] newVec;
        _size = index;
    }	

    // Delete all vector content
    void clear() {
        delete[] _vec;
    }	 

    // Insert item at iterator
    // Throw exception if invalid
    // 10 1 2 3 4 5
    void insert(iterator i, T ins) {
        //if the size is equal increase the capacity
        if (_size == _capacity){
            resize();
        }
        int po;
        if(_size != 0) {
            po = getIndex(i);
        } else {
            //this means that the array is empty so we insert in first position
            po = 0;
        }
        //if the po is -1 so this is means that the iterator is invalid
        if (po == -1) {
                throw Invaliditerator();
        }
        //create new arry
        T* newarr = new T[++_size];
        int x = 0; // used as a counter
        for (int j = 0; j < _size ; j++){
            //if the position exist add the elemnt and increase the counter j by 1
            if (po == j){
                newarr[j] = ins;
                j++;
            }
            //copy the elemnts
            newarr[j] = _vec[x];
            x++;//increase the other counter
        }
        //make new array of pointers 
        _vec = new T[_capacity];
        //copy all new elemets after insert the elemet to the private vec 
        for(int j = 0; j < _size; j++) {
            _vec[j] = newarr[j];
        }
        //delete the newarr
        delete[] newarr;
    }

    // seif
    // Return an iterator (T*)
    iterator begin() {
        return _vec;
    }

    // seif
    // Return an iterator (T*)
    iterator end() {
        return _vec + (_size -1);
    }		

    // Comparison operations
    // Return true if ==
    bool operator==(const SMVector<T>& other) {
        //check the size first
        if (_size == other._size){
            //looping for all elemets and then check if it's equal or not
            for (size_t i = 0; i < _size; i++){
                if (_vec[i] != other._vec[i]){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }

    // seif
    // Compares item by item
    // Return true if first different item in this is < in other
    bool operator< (const SMVector<T>& other) {
        int s = (_size <= other._size) ? _size : other._size;
        for(int i = 0; i < s; i++) {
            if(_vec[i] < other._vec[i]) {
                return true;
            } else if(_vec[i] > other._vec[i]) {
                return false;
            }
        }
        return (_size < other._size);

    }	

    // Capacity operations
    // Return current size of vec
    int size() const {
        return _size;
    }	 

    // Return size of current allocated array
    int capacity() const {
        return _capacity;
    }

    // seif
    // Relocate to bigger space
    int resize() {
        _capacity *= 2;
        T* newVec = new T[_capacity];
        for(int i = 0; i < _size; i++) {
            newVec[i] = _vec[i];
        }
        delete[] _vec;
        _vec = new T[_capacity];
        for(int i = 0; i < _size; i++) {
            _vec[i] = newVec[i];
        }
        delete[] newVec;

        return _capacity;
    }	

    // Return true if size is 0
    bool empty() {
        if (_size == 0){
            return true;
        }
        return false;
    }

    // seif
    // Friends
    friend ostream& operator<<(ostream& out, SMVector<T>& vec){
        for(int i = 0; i < vec._size; i++) {
            cout << vec[i] << " ";
        }
        return out;
    }
};
