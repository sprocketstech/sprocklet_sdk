#pragma once
#include <stdint.h>
#include <string>
#define SPROCKET_UNADDRESSED 129
class Sprocklet
{
public:
    Sprocklet(const char *id) : _address(SPROCKET_UNADDRESSED)
    {
        _id = id;
    }
    void address(uint8_t address) { _address = address; }
    uint8_t address() { return _address; }
    const char *id() const { return _id.c_str(); }

    virtual uint16_t deviceId() = 0;

private:
    std::string _id;
    uint8_t _address;
};