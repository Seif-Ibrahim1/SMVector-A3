#include <iostream>
#include "SMVector.cpp"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    SMVector <int>m(3);
    m.insert(m.begin(),5);
    cout<<m.size()<<endl;
    cout<<*(m.end());
    return 0;
}
