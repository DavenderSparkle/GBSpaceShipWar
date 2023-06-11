//Special thanks to Moos on GBDK Discord for giving me the base idea on how to do this.

#include <gb/gb.h>

uint8_t enemX;
uint8_t enemY;

uint8_t receivedData;
uint8_t ByteSend = 0;

enum DataLinked
{
    Null,
    InputLeft,
    InputRight,
    InputUp
};

void sendByte(uint8_t b)
{
    _io_out = b;
    send_byte();
}

void UpdateMult()
{
    sendByte(ByteSend);

    receive_byte();
    receivedData = _io_in;

    switch (receivedData)
    {
    case InputLeft:
        ++enemX;
        break;
    
    case InputRight:
        --enemX;
        break;
    case InputUp:
        ++enemY;
        break;
    }

    ByteSend = Null;

    move_sprite(1, enemX, enemY);

}