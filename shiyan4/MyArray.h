#ifndef MYARRAY_H
#define MYARRAY_H

#include <string>

class MyArray {
private:
    int* p;  // 数组指针
    int N;   // 数组元素个数

public:
    // 1. 构造函数
    MyArray();                              // 默认构造函数
    MyArray(int size);                      // 指定数组长度的构造函数
    MyArray(const MyArray& other);          // 拷贝构造函数（深拷贝）
    
    // 2. 析构函数
    ~MyArray();
    
    // 3. 运算符重载
    MyArray operator+(const MyArray& other) const;  // 数组合并
    
    // 4. 四则运算成员函数
    MyArray add(const MyArray& other) const;        // 加法
    MyArray subtract(const MyArray& other) const;   // 减法  
    MyArray multiply(const MyArray& other) const;   // 乘法
    MyArray divide(const MyArray& other) const;     // 除法
    
    // 5. 辅助函数
    int size() const;                       // 获取数组大小
    int& operator[](int index);             // 下标运算符（可修改）
    const int& operator[](int index) const; // 下标运算符（只读）
    MyArray& operator=(const MyArray& other); // 赋值运算符
    
    // 6. 工具函数
    void display() const;                   // 显示数组内容
    void fill(int value);                   // 填充数组
    bool isValid() const;                   // 检查数组是否有效
    
private:
    // 私有辅助函数
    void deepCopy(const MyArray& other);    // 深拷贝实现
    void cleanup();                         // 清理资源
};

#endif // MYARRAY_H