#include <iostream>

#include "mathvector/vector/MathVector.h"

using namespace std;
using namespace mathvector;

int main() {
    MathVector<int> vec = { 0, 1, 2 };

    cout << "vec1" <<endl;
    for (auto el: vec) {
        cout << el << " ";
    }
    cout<< endl;

    cout << "length " << vec.length() << endl;

    return 0;
}