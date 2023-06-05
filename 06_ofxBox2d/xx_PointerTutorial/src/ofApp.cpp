#include "ofApp.h"

void ofApp::setup() {
    int num = 12345;
    int* ptr;
    ptr = &num;
    cout << "num: " << num << endl;
    cout << "&num: " << &num << endl;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    cout << "----------------" << endl;

    int* numPtr;
    numPtr = new int(10);
    cout << "numPtr: " << numPtr << endl;
    cout << "*numPtr: " << *numPtr << endl;

    cout << "----------------" << endl;

    int* ptr2 = new int(12345);
    cout << "ptr2: " << ptr2 << endl;
    cout << "*ptr2: " << *ptr2 << endl;

    cout << "----------------" << endl;

    ofPtr<int> optr(new int(34567));
    cout << "optr: " << optr << endl;
    cout << "*optr: " << *optr << endl;
}