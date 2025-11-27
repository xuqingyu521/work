#include <iostream>
#include "MyArray.h"

using namespace std;

void testConstructors() {
    cout << "=== Testing Constructors ===" << endl;
    
    // 测试默认构造函数
    MyArray arr1;
    cout << "Default constructor - Size: " << arr1.size() << endl;
    
    // 测试指定长度构造函数
    MyArray arr2(5);
    cout << "Size constructor - Size: " << arr2.size() << ", Contents: ";
    arr2.display();
    
    // 测试拷贝构造函数
    MyArray arr3(arr2);
    cout << "Copy constructor - Size: " << arr3.size() << ", Contents: ";
    arr3.display();
    
    cout << endl;
}

void testAssignment() {
    cout << "=== Testing Assignment ===" << endl;
    
    MyArray arr1(3);
    arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;
    
    MyArray arr2;
    arr2 = arr1;  // 赋值操作
    
    cout << "Original array: ";
    arr1.display();
    cout << "Assigned array: ";
    arr2.display();
    
    // 修改原数组，验证深拷贝
    arr1[0] = 100;
    cout << "After modifying original - Original: ";
    arr1.display();
    cout << "After modifying original - Assigned: ";
    arr2.display();
    
    cout << endl;
}

void testConcatenation() {
    cout << "=== Testing Concatenation ===" << endl;
    
    MyArray arr1(3);
    arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;
    
    MyArray arr2(2);
    arr2[0] = 4; arr2[1] = 5;
    
    MyArray arr3 = arr1 + arr2;
    
    cout << "Array 1: "; arr1.display();
    cout << "Array 2: "; arr2.display();
    cout << "Concatenated: "; arr3.display();
    
    cout << endl;
}

void testArithmeticOperations() {
    cout << "=== Testing Arithmetic Operations ===" << endl;
    
    MyArray arr1(4);
    arr1[0] = 10; arr1[1] = 20; arr1[2] = 30; arr1[3] = 40;
    
    MyArray arr2(4);
    arr2[0] = 1; arr2[1] = 2; arr2[2] = 3; arr2[3] = 4;
    
    cout << "Array 1: "; arr1.display();
    cout << "Array 2: "; arr2.display();
    
    try {
        MyArray addResult = arr1.add(arr2);
        cout << "Addition: "; addResult.display();
        
        MyArray subResult = arr1.subtract(arr2);
        cout << "Subtraction: "; subResult.display();
        
        MyArray mulResult = arr1.multiply(arr2);
        cout << "Multiplication: "; mulResult.display();
        
        MyArray divResult = arr1.divide(arr2);
        cout << "Division: "; divResult.display();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << endl;
}

void testErrorHandling() {
    cout << "=== Testing Error Handling ===" << endl;
    
    MyArray arr1(3);
    MyArray arr2(2);
    
    cout << "Array 1 size: " << arr1.size() << endl;
    cout << "Array 2 size: " << arr2.size() << endl;
    
    try {
        MyArray result = arr1.add(arr2);
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    try {
        MyArray arr3(-1);  // 无效大小
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    cout << endl;
}

void testFillAndAccess() {
    cout << "=== Testing Fill and Access ===" << endl;
    
    MyArray arr(5);
    arr.fill(7);
    cout << "After filling with 7: ";
    arr.display();
    
    // 测试下标访问
    cout << "Element at index 2: " << arr[2] << endl;
    
    // 测试修改元素
    arr[2] = 99;
    cout << "After modifying index 2: ";
    arr.display();
    
    cout << endl;
}

int main() {
    cout << "MyArray Class Test Program" << endl;
    cout << "===========================" << endl << endl;
    
    testConstructors();
    testAssignment();
    testConcatenation();
    testArithmeticOperations();
    testErrorHandling();
    testFillAndAccess();
    
    cout << "All tests completed!" << endl;
    
    return 0;
}