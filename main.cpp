#include <iostream>
#include "SMVector.cpp"
using namespace std;
int main() {
    
    try {
        SMVector<int> vec(-5);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.insert(vec.begin(), 1);
        

        cout << vec[9] << endl;
    } catch (Invaliditerator e) {
        cout << e.what() << endl;
    } catch (OutOfRange e) {
        cout << e.what() << endl;
    } catch (InvalidSize e) {
        cout << e.what() << endl;
    }

    return 0;
}
