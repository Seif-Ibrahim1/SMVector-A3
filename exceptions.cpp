#include <exception>
using namespace std;

class InvalidSize : public exception {
    public:
    InvalidSize(){}
    virtual const char* what() const throw() {
        return "invalid size";
    }
};

class Invaliditerator : public exception {
    public:
    Invaliditerator(){}
    virtual const char* what() const throw() {
        return "invalid iterator";
    }
};

class OutOfRange : public exception {
    public:
    OutOfRange(){}
    virtual const char* what() const throw() {
        return "Out of range";
    }
};
