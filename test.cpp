#include<iostream>
using namespace std;
#include<cstring>
#include"spy.h"

// int main() {
//     cout<<sizeof(data_)<<endl;
//     return 0;
// }

// #include <iostream>

// // 获取指定索引位置的比特位
// int getBit(void* ptr, int index) {
//     // 将void指针转换为unsigned char指针
//     unsigned char* bytePtr = static_cast<unsigned char*>(ptr);
    
//     // 计算对应字节的索引
//     int byteIndex = index / 8;
    
//     // 计算对应比特位的索引
//     int bitIndex = index % 8;
    
//     // 获取对应字节
//     unsigned char byte = bytePtr[byteIndex];
    
//     // 获取比特位的值
//     int bitValue = (byte >> bitIndex) & 1;
    
//     return bitValue;
// }

int main() {
    data_ data;
    data_ key;

    memcpy(&data, "2234", 32);
    memcpy(&key, "5678", 32);

    for(int i=0;i<32;++i) {
        cout<<(int)((char*)&data)[i]<<" ";
    }
    cout<<endl;

    data_ en = encrypt(data, key);

    for(int i=0;i<32;++i) {
        cout<<(int)((char*)&en)[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
