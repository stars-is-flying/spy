#include"spy.h"
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;

// 获取指定索引位置的比特位
int getBit(void* ptr, int index) {

    unsigned char* bytePtr = static_cast<unsigned char*>(ptr);
    
    int byteIndex = index / 8;
    
    int bitIndex = index % 8;
    
    unsigned char byte = bytePtr[byteIndex];
    
    int bitValue = (byte >> bitIndex) & 1;
    
    return bitValue;
}

void setBit(void* ptr, int index, int value) {

    unsigned char* bytePtr = static_cast<unsigned char*>(ptr);
    
    int byteIndex = index / 8;
    
    int bitIndex = index % 8;
    
    unsigned char byte = bytePtr[byteIndex];
    
    byte &= ~(1 << bitIndex);
    
    byte |= (value & 1) << bitIndex;
    
    bytePtr[byteIndex] = byte;
}

void rightRotateBits(void* data) {
    unsigned char* bytePtr = static_cast<unsigned char*>(data);

    bool lastBit = bytePtr[31] & 1;

    for (int i = 31; i >= 0; --i) {

        bool currentLastBit = bytePtr[i] & 1;

        bytePtr[i] >>= 1;

        if (i > 0)
            bytePtr[i] |= (currentLastBit ? 0x80 : 0);
    }

    bytePtr[0] |= (lastBit ? 0x80 : 0);
}

void leftRotateBits(void* data) {

    unsigned char* bytePtr = static_cast<unsigned char*>(data);

    bool firstBit = (bytePtr[0] & 0x80) != 0;

    for (int i = 0; i < 32; ++i) {
        bool currentFirstBit = (bytePtr[i] & 0x80) != 0;

        bytePtr[i] <<= 1;

        if (i < 31)
            bytePtr[i] |= (currentFirstBit ? 1 : 0);
    }

    bytePtr[31] |= (firstBit ? 1 : 0);
}

data_ encrypt(data_ data, data_ key) {

    data_ res;
    memset(&res, 32, 0);

    for(int i=0;i<256;++i) {
        // rightRotateBits(&data);
        // leftRotateBits(&key);

        // res.data1 = data.data1 ^ key.data1;
        // res.data2 = data.data2 ^ key.data2;
        // res.data3 = data.data3 ^ key.data3;
        // res.data4 = data.data4 ^ key.data4;

        cout<<(int)(BOX[i])<<" ";

        setBit(&res, i, getBit(&res, (int)(BOX[i])));
    }

    return res;
}