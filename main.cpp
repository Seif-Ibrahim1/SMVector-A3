#include <iostream>
#include "SMVector.cpp"
using namespace std;
int main() {
    try {
        // testing initialize with size
        SMVector<int> vec(5);

        // testing capacity
        cout << vec.capacity() << endl;

        // testing push back
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        // testing size
        cout << vec.size() << endl;

        // testing operator<<
        cout << vec << endl;

        // testing erase range and begin and end functions
        vec.erase(vec.begin(), vec.end());
        cout << vec << endl;

        // testing operator[]
        cout << vec[0] << endl;

        // testing pop back
        vec.pop_back();
        cout << vec.size() << endl;


        // testing insert
        vec.insert(vec.begin(), 2);
        vec.insert(vec.begin() , 1);
        cout << vec << endl;

        // testing copy constructor
        SMVector<int> vec2(vec);
        cout << vec2 << endl;

        // testing == operator
        cout << (vec == vec2) << endl;
        vec2.insert(vec2.begin(), 2);
        cout << (vec == vec2) << endl;

        // testing < operator
        cout << (vec < vec2) << endl;
        cout << (vec2 < vec) << endl;

        // testing initialize with array
        string arr[3] = {"Seif", "Mina"};
        SMVector<string> vec3(arr, 3);
        cout << vec3 << endl;

        // testing operator=
        SMVector<string> vec4 = vec3;
        cout << vec4 << endl;

        // testing erase
        vec4.erase(vec4.end());
        cout << vec4 << endl;

        // testing resize
        cout << vec4.capacity() << endl;
        cout << vec4.resize() << endl;

        // testing clear and empty
        cout << vec4.empty() << endl;
        vec4.clear();
        cout << vec4.empty() << endl;

        // testing exceptions

        // this will give error
//          SMVector<int> vec5(-5);

        // this will give error
//          vec.erase(vec.begin() + 1, vec.begin());

        // this will give error
//          vec.erase(vec.begin() + 10);

        // this will give error
//          cout << vec[20] << endl;

    } catch (Invaliditerator e) {
        cout << e.what() << endl;
    } catch (OutOfRange e) {
        cout << e.what() << endl;
    } catch (InvalidSize e) {
        cout << e.what() << endl;
    }

    return 0;
}
