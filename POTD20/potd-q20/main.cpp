#include <iostream>
#include <vector>

using namespace std;

#include "isValid.cpp"


int main() {

    vector<string> tests =
    {
        // "()",
        // "()[]{}!",
        // "([cs225)]",
        // // add your own tests here!
        // "2323232",  // valid
        // "({[ew{{[ds]3}}23]34f})3(){s[[22]]}",  // valid
        // "({[][]{{()}})(){()}}", // invalid
        // "]", // invalid
        // "",  // valid
        // "{}", // valid
        // " (     ) ", // valid
        " )",   // invalid
    };


    cout << std::boolalpha << endl;
    for (string& t : tests) {
        cout << t << " : ";
        cout << isValid(t);
        cout << endl << endl;
    }
}
