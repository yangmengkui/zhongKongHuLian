#ifndef PROTOCAL_H
#define PROTOCAL_H

#include <stdint.h> //uint16_t
#include <QtCore/QByteArray>

/*baud rate for serial*/
#define BAUD_RATE QSerialPort::Baud115200
#define ROAD_NAME_LEN 64
/*crc16 check*/
uint16_t crc16Check(uint8_t *ptr,uint8_t len);

enum infoType {
  WORD_PICINDEX,//图标索引，图片在本地加载
  WORD_DISTANCE,//距离
  WORD_INDICATOR,//提示文字，预留。
  DATA_MAP,//地图信息，大图片，通过网络传输，预留。
  DATA_SMALL_PIC,//小图标，通过网络传输，预留。
};

//ORDI:普通路,FREEWAY高速路
enum picType {
     PICTYPE_NULL,//0
    /*导航转弯信息*/
    TURN_NULL,//null
    TURN_ORDI_STRAIGHT,//普通路直行
    TURN_ORDI_RIGHT_FRONT,//普通路右前方向
    TURN_ORDI_RIGHT,//普通路右转
    TURN_ORDI_RIGHT_REAR,//普通路右后方向
    TURN_ORDI_TURNED_AROUND,//普通路折返方向
    TURN_ORDI_LEFT_REAR,//普通路左后方向
    TURN_ORDI_LEFT,//普通路左转
    TURN_ORDI_LEFT_FRONT,//普通路左前方向
    TURN_ORDI_TO_ISLAND,//10
    TURN_ISLAND_TO_ISLAND,
    TURN_ISLAND_TO_ORDI,
    TURN_RIGHT_TURN_LANE,
    TURN_DRIVE_FROM_MIDDLE,
    TURN_DRIVE_ON_THE_MOST_LEFT,
    TURN_DRIVE_ON_THE_MOST_RIGHT,
    TURN_DRIVE_ON_THE_LEFT,
    TURN_DRIVE_ON_THE_RIGHT,
    TURN_STRAIGHT_FREEWAY_ENTRANCE,
    TURN_MIDDLE_FREEWAY_ENTRANCE,//20
    TURN_MOSTLEFT_FREEWAY_ENTRANCE,
    TURN_MOSTRIGHT_FREEWAY_ENTRANCE,
    TURN_LEFT_FREEWAY_ENTRANCE,
    TURN_RIGHT_FREEWAY_ENTRANCE,
    TURN_STRAIGHT_FREEWAY_EXIT,
    TURN_MIDDLE_FREEWAY_EXIT,
    TURN_MOSTLEFT_FREEWAY_EXIT,
    TURN_MOSTRIGHT_FREEWAY_EXIT,
    TURN_LEFT_FREEWAY_EXIT,
    TURN_RIGHT_FREEWAY_EXIT,//30
    TURN_LEFT_INTO_MAINROAD,
    TURN_RIGHT_EXIT_MAINROAD,
    TURN_GO_STRAIGHT_ON_LEFT,
    TURN_GO_STRAIGHT_ON_RIGHT,
    TURN_TOLL_STATION,
    TURN_TUNNEL,
    TURN_ROAD_TO_FERRY,
    TURN_ENTER_SERVICEAREA,
    TURN_ENTER_SERVICEAREA_ONLEFT,
    TURN_ENTER_SERVICEAREA_ONRIGHT,//40
    TURN_TURNLEFT_DRIVE_ONLEFT,
    TURN_TURNLEFT_DRIVE_ONRIGHT,
    TURN_TURNRIGHT_DRIVE_ONLEFT,
    TURN_TURNRIGHT_DRIVE_ONRIGHT,
    TURN_PASSING_POINT1,
    TURN_PASSING_POINT2,
    TURN_PASSING_POINT3,
    TURN_PASSING_POINT4,
    TURN_DESTINATION,
    TURN_STRAIGHT_CITYFAST_ENTRANCE,//50
    TURN_MIDDLE_CITYFAST_ENTRANCE,
    TURN_MOSTLEFT_CITYFAST_ENTRANCE,
    TURN_MOSTRIGHT_CITYFAST_ENTRANCE,
    TURN_LEFT_CITYFAST_ENTRANCE,
    TURN_RIGHT_CITYFAST_ENTRANCE,
    TURN_STRAIGHT_CITYFAST_EXIT,
    TURN_MIDDLE_CITYFAST_EXIT,
    TURN_MOSTLEFT_CITYFAST_EXIT,
    TURN_MOSTRIGHT_CITYFAST_EXIT,
    TURN_LEFT_CITYFAST_EXIT,//60
    TURN_RIGHT_CITYFAST_EXIT,
    TURN_BRIDGE,
    TURN_VIADUCT,
    TURN_PARKING,
    TURN_ENTER_PARKING_ONLEFT,
    TURN_ENTER_PARKING_ONRIGHT,
    TURN_OTHERS,//67

    /*引导道路类型*/
    GUIDE_FREEWAY_ENTRANCE,//68
    GUIDE_FREEWAY_EXIT,
    GUIDE_CITYFAST_ENTRANCE,
    GUIDE_CITYFAST_EXIT,
    GUIDE_ENTER_VIADUCT,
    GUIDE_EXIT_VIADUCT,
    GUIDE_ENTER_BRIDGE,
    GUIDE_EXIT_BRIDGE,
    GUIDE_OTHERS,//76

    /*时钟方向*/
    TOWARDS_DEFAULT,//77
    TOWARDS_DIRECTION_1,
    TOWARDS_DIRECTION_2,
    TOWARDS_DIRECTION_3,
    TOWARDS_DIRECTION_4,
    TOWARDS_DIRECTION_5,
//    TOWARDS_DIRECTION_RESERVED,
    TOWARDS_DIRECTION_7,
    TOWARDS_DIRECTION_8,
    TOWARDS_DIRECTION_9,
    TOWARDS_DIRECTION_A,
    TOWARDS_DIRECTION_B,
    TOWARDS_DIRECTION_C,//88

    /*时钟背景*/
    CLOCK_DEFAULT,//89
    CLOCK_DIRECTION_1,
    CLOCK_DIRECTION_2,
    CLOCK_DIRECTION_3,
    CLOCK_DIRECTION_4,
    CLOCK_DIRECTION_5,
//    CLOCK_DIRECTION_6,//
    CLOCK_DIRECTION_7,
    CLOCK_DIRECTION_8,
    CLOCK_DIRECTION_9,
    CLOCK_DIRECTION_10,
    CLOCK_DIRECTION_11,
    CLOCK_DIRECTION_12,//100
};
//    int TURN_MAX = TURN_OTHERS;
//    int GUIDE_MAX = GUIDE_OTHERS;
//    int TOWARDS_MAX = TOWARDS_DIRECTION_C;
//    int CLOCK_MAX = CLOCK_DIRECTION_12;

    typedef struct {
//        uint8_t speed;   //导航和仪表之间的协议,没有这两项
//        uint8_t stalls;

        infoType type;
        picType type_first;
        picType type_second;
        uint32_t turn_distance;
        uint32_t dest_distance;

        char curRoad[ROAD_NAME_LEN];
        char turnRoad[ROAD_NAME_LEN];
    }__attribute__((packed)) Data;

    typedef struct {
        uint8_t head;
        uint8_t length;
        infoType info_type; //flag1,消息的类型,大类
        picType pic_type_first;//flag2,第一个参数的类型
        picType pic_type_second;//flag3,第二个参数的类型
        Data data;//有效数据,暂定32位，3Bytes + 3Bytes,可以发送枚举类型和距离，没考虑直接发送图片的情况。
        uint16_t crc;
        uint8_t tail;
    }__attribute__((packed)) Frame;

#define FRAME_BYTELEN	(const int)(sizeof(Frame))

/*
 * socketpack
 */
typedef struct {
    uint8_t speed; //仪表和HUD之间的协议  有这两项
    uint8_t stalls;

    uint8_t id_turn;
    uint8_t id_guide;
    uint8_t id_towards;
    uint8_t id_clock;

    int turnDistance;
    int destDistance;

    char curRoad[ROAD_NAME_LEN];
    char turnRoad[ROAD_NAME_LEN];

}__attribute__((packed)) SocketPack;

typedef struct {
    uint8_t head;
    uint8_t length;
    SocketPack socketPack;
    uint16_t crc;
    uint8_t tail;
}__attribute__((packed)) AckSocket;


#define CONNECT_SERVERS_ADDR "127.0.0.1"
#define CONNECT_SERVERS_PORT 6666



uint8_t crc8(uint8_t *p, uint16_t nBytes);

#endif // PROTOCAL_H
