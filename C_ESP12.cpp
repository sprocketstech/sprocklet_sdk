#if defined(ESP8266)

#include <sprocklets/C_ESP12.h>
#include <sprocklets/SprockletESP12_defs.h>
#include <Arduino.h>
#include <Wire.h>

SprockletESP12Board::SprockletESP12Board()
    : _scl(SPROCKLET_DEFAULT_SCL),
      _sda(SPROCKLET_DEFAULT_SDA),
      _pgm(SPROCKLET_DEFAULT_I2C_PGM)
{
}

SprockletESP12Board::SprockletESP12Board(const uint8_t sda,
                                         const uint8_t scl,
                                         const uint8_t pgm)
    : _scl(scl),
      _sda(sda),
      _pgm(pgm)
{
}

#define MAX_LOG_BUFFER_SIZE 64
static char logBuffer[MAX_LOG_BUFFER_SIZE];

void SprockletESP12Board::programAddresses(programAddressesLogCallback cb, std::vector<Sprocklet *> &sprocklets)
{
    cb("Starting address programming");
    // reset the chain
    pinMode(_pgm, OUTPUT);
    // write I2C_PGM low
    digitalWrite(_pgm, LOW);
    delay(100);
    digitalWrite(_pgm, HIGH);
    Wire.begin(_sda, _scl);
    delay(500);
    // program the addresses of the sprocklets
    for (uint8_t i = 0; i < sprocklets.size(); ++i)
    {
        uint8_t addr = programUnit(cb, i);
        if (addr > 0)
        {
            sprocklets[i]->address(addr);
            waitForReady(cb, addr);
            uint16_t deviceId = 0;
            // query the device id
            Wire.beginTransmission(addr);
            Wire.write(0);
            Wire.endTransmission(false);
            Wire.requestFrom(addr, (uint8_t)1, true);
            deviceId = Wire.read() << 8;
            Wire.requestFrom(addr, (uint8_t)1, true);
            deviceId |= Wire.read();
            Wire.endTransmission();
            if (sprocklets[i]->deviceId() != deviceId)
            {
                ::snprintf(logBuffer, MAX_LOG_BUFFER_SIZE, "Sprocklet at address %d is expected to be 0x%04x, but is 0x%04x",
                           addr,
                           sprocklets[i]->deviceId(),
                           deviceId);
                cb(logBuffer);
            }
            else
            {

                ::snprintf(logBuffer, MAX_LOG_BUFFER_SIZE, "Sprocklet %s is at address %d",
                           sprocklets[i]->id(),
                           addr);
                cb(logBuffer);
            }
        }
        yield();
    }
}

bool SprockletESP12Board::waitForReady(programAddressesLogCallback cb, uint8_t addr)
{
    bool done = false;
    while (!done)
    {
        // query the address which is in register SPROCKLET_PROGRAM_COMMAND
        Wire.beginTransmission(addr);
        Wire.write(SPROCKLET_PROGRAM_COMMAND);
        Wire.endTransmission(false);
        Wire.requestFrom(addr, (uint8_t)1, true);
        uint8_t reportedAddr = addr;
        Wire.endTransmission();

        ::snprintf(logBuffer, MAX_LOG_BUFFER_SIZE, "Sprocklet at address %d reports address %d",
                   addr,
                   reportedAddr);
        cb(logBuffer);

        if (reportedAddr != addr)
        {
            delay(5);
        }
        else
        {
            done = true;
        }
    }
}

uint8_t SprockletESP12Board::programUnit(programAddressesLogCallback cb, uint8_t unit)
{
    bool done = false;
    int loopCount = 0;
    int error;
    byte newAddr = unit + SPROCKLET_ADDRESS_OFFSET;
    while (!done)
    {
        // program unit n
        Wire.beginTransmission(SPROCKLET_PROGRAM_ADDRESS);
        // write program command
        Wire.write(SPROCKLET_PROGRAM_COMMAND);
        // write the new address (0x10 + current unit)
        Wire.write((byte)newAddr);
        error = Wire.endTransmission();
        if (error == 2)
        {
            // 2 means address not accepted;
            // could be one of two conditions:
            // Next unit is booting
            // Next unit does not exist.
            if (loopCount > 10)
            {
                // next unit not found
                ::snprintf(logBuffer, MAX_LOG_BUFFER_SIZE, "No sprocklet found attached at index %d", unit);
                cb(logBuffer);
                done = true;
                newAddr = 0;
                break;
            }
            else
            {
                // could be booting, sleep and retry
                ++loopCount;
                delay(50);
            }
        }
        else if (error == 0)
        {
            // programmed successfully
            // do the next one
            ::snprintf(logBuffer, MAX_LOG_BUFFER_SIZE, "Sprocklet %d addressed as %d", unit, newAddr);
            cb(logBuffer);
            done = true;
        }
    }
    return newAddr;
}
#endif
