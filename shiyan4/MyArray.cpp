#include "MyArray.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// 默认构造函数
MyArray::MyArray() : p(nullptr), N(0) {}

// 指定长度的构造函数
MyArray::MyArray(int size) {
    if (size < 0) {
        throw invalid_argument("Array size cannot be negative");
    }
    
    N = size;
    if (N > 0) {
        p = new int[N];
        // 初始化为0
        for (int i = 0; i < N; ++i) {
            p[i] = 0;
        }
    } else {
        p = nullptr;
    }
}

// 拷贝构造函数（深拷贝）
MyArray::MyArray(const MyArray& other) {
    deepCopy(other);
}

// 析构函数
MyArray::~MyArray() {
    cleanup();
}

// 数组合并（+运算符重载）
MyArray MyArray::operator+(const MyArray& other) const {
    int newSize = N + other.N;
    MyArray result(newSize);
    
    // 复制当前数组元素
    for (int i = 0; i < N; ++i) {
        result.p[i] = p[i];
    }
    
    // 复制另一个数组元素
    for (int i = 0; i < other.N; ++i) {
        result.p[N + i] = other.p[i];
    }
    
    return result;
}

// 加法运算
MyArray MyArray::add(const MyArray& other) const {
    if (N != other.N) {
        throw invalid_argument("Arrays must have same size for addition");
    }
    
    MyArray result(N);
    for (int i = 0; i < N; ++i) {
        result.p[i] = p[i] + other.p[i];
    }
    return result;
}

// 减法运算
MyArray MyArray::subtract(const MyArray& other) const {
    if (N != other.N) {
        throw invalid_argument("Arrays must have same size for subtraction");
    }
    
    MyArray result(N);
    for (int i = 0; i < N; ++i) {
        result.p[i] = p[i] - other.p[i];
    }
    return result;
}

// 乘法运算
MyArray MyArray::multiply(const MyArray& other) const {
    if (N != other.N) {
        throw invalid_argument("Arrays must have same size for multiplication");
    }
    
    MyArray result(N);
    for (int i = 0; i < N; ++i) {
        result.p[i] = p[i] * other.p[i];
    }
    return result;
}

// 除法运算
MyArray MyArray::divide(const MyArray& other) const {
    if (N != other.N) {
        throw invalid_argument("Arrays must have same size for division");
    }
    
    MyArray result(N);
    for (int i = 0; i < N; ++i) {
        if (other.p[i] == 0) {
            throw runtime_error("Division by zero at index " + to_string(i));
        }
        result.p[i] = p[i] / other.p[i];
    }
    return result;
}

// 获取数组大小
int MyArray::size() const {
    return N;
}

// 下标运算符（可修改）
int& MyArray::operator[](int index) {
    if (index < 0 || index >= N) {
        throw out_of_range("Index out of range");
    }
    return p[index];
}

// 下标运算符（只读）
const int& MyArray::operator[](int index) const {
    if (index < 0 || index >= N) {
        throw out_of_range("Index out of range");
    }
    return p[index];
}

// 赋值运算符
MyArray& MyArray::operator=(const MyArray& other) {
    if (this != &other) {
        cleanup();
        deepCopy(other);
    }
    return *this;
}

// 显示数组内容
void MyArray::display() const {
    cout << "[";
    for (int i = 0; i < N; ++i) {
        cout << p[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// 填充数组
void MyArray::fill(int value) {
    for (int i = 0; i < N; ++i) {
        p[i] = value;
    }
}

// 检查数组是否有效
bool MyArray::isValid() const {
    return (p != nullptr && N > 0);
}

// 私有方法：深拷贝实现
void MyArray::deepCopy(const MyArray& other) {
    N = other.N;
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i) {
            p[i] = other.p[i];
        }
    } else {
        p = nullptr;
    }
}

// 私有方法：清理资源
void MyArray::cleanup() {
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
    }
    N = 0;
}