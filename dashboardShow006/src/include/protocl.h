#ifndef PROTOCL_H
#define PROTOCL_H
/*
 * socketpack
 */
typedef struct {
    uint8_t generatorPower;
    uint8_t speed;
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

/*
 * byte length for frame
 */
#define SPECIAL_INFO_LEN       (const int)(sizeof(SpecialInfo))
#define SPECIAL_FRAME_LEN      (const int)(sizeof(SpecialFrame))
#define SPECSETTINGS_INFO_LEN  (const int)(sizeof(SpecSettingsInfo))
#define SPECSETTINGS_FRAME_LEN (const int)(sizeof(SpecSettingsFrame))

#endif // PROTOCL_H

