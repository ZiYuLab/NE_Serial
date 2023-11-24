//
// Created by ziyu on 11/16/23.
//

#ifndef NESERIAL_NEINIT_H
#define NESERIAL_NEINIT_H


#include <bits/types.h>
#include <mutex>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//#define DEBUG // <---------------------------
#ifdef DEBUG
#include <assert.h>
#define ASSERT(f) assert(f)
#else
#define ASSERT(f) ((void)0)
#endif
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// 多线程互斥设置
// std::mutex mutSerialWriteBuffers;

// 比赛基本设置


// Type re def
typedef __uint8_t NE_8U;
typedef __uint16_t NE_16U;
typedef __uint32_t NE_32U;
typedef float NE_32F;
typedef double NE_64F;

// Change types to 1 byte
union NE32F2NE8U
{
    NE_32F ne32FIN;
    NE_8U ne8uOUT[4];
};

union NE16U2NE8U
{
    NE_16U ne16UIN;
    NE_8U ne8uOUT[2];
};

namespace ne{
    void neInit();
}

#endif //NESERIAL_NEINIT_H
