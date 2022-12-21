#include <iostream>
#include "SMVector.cpp"
using namespace std;
int main() {
    
    try {
        SMVector<int> vec(5);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.erase(vec.begin() + 8);
    } catch (Invaliditerator e) {
        cout << e.what() << endl;
    } catch (OutOfRange e) {
        cout << e.what() << endl;
    }

    return 0;
}
