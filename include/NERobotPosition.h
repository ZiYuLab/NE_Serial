/*
    机器人位置设定，并自动生成数据串口函数
    20231124 by ZiYu
    裁判串口协议版本：v1.5
*/
#ifndef NESERIAL_NEROBOTPOSITION_H
#define NESERIAL_NEROBOTPOSITION_H

#include <vector>
#include "include/NEInit.h"

namespace ne
{

#define ROBOT_RED_HERO 1
#define ROBOT_RED_ENGINEER 2
#define ROBOT_RED_INFANTRY_3 3
#define ROBOT_RED_INFANTRY_4 4
#define ROBOT_RED_INFANTRY_5 5
#define ROBOT_RED_SENTRY 7

#define ROBOT_BLUE_HERO 101
#define ROBOT_BLUE_ENGINEER 102
#define ROBOT_BLUE_INFANTRY_3 103
#define ROBOT_BLUE_INFANTRY_4 104
#define ROBOT_BLUE_INFANTRY_5 105
#define ROBOT_BLUE_SENTRY 107

#define ROBOT_GROUND_NUM_REGION 10 // 5 * 2
#define ROBOT_GROUND_NUM_NATIONWIDE 12 // 6 * 2

#define BUFFERS_MAX_LIMIT 20

    class NERobotPosition {
    private:
        NE32F2NE8U ne32F2Ne8U;
        NE16U2NE8U ne16U2Ne8U;
        std::vector<std::vector<NE_8U>> buffers_;
        int robotGroundNum_;
    public:
        const NE_16U cmdID = 0x0305;
        const int sizeEach = 10;

        NERobotPosition(int size);
        ~NERobotPosition();
        void setPosition(int robotID, NE_32F x, NE_32F y);
        std::vector<std::vector<NE_8U>> exportBuffers() const;

        // 每次更新数据结束务必调用清楚缓冲区，不然会导致内存溢出
        void clearBuffers();
    };
}


#endif //NESERIAL_NEROBOTPOSITION_H
