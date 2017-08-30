#include "humidtyreader.h"
#include <linux/i2c-dev.h> // I2C bus definitions
#include <sys/ioctl.h>
#include <arpa/inet.h>

namespace adc1115 {

humidtyReader::humidtyReader()
{
    fd = 0;
}
humidtyReader::~humidtyReader()
{
    close(fd);
}

short humidtyReader::readHumidity()
{

    short readBuf[2]{};

    if (read(fd, readBuf, 2) != 2) {
      CDPMessage("Reading Conversion register: Failed\n");
      return 0;
    }

    readBuf[0] = ntohs(readBuf[0]);

    return (readBuf[0] < 0 ) ? 0 : readBuf[0];

}
int humidtyReader::configureHumidity(short *cnf, int asd_adr, std::string adapter)
{
    if(adapter.empty()) { CDPMessage("No adapter set"); return 0; }
    if(!(bool)asd_adr) { CDPMessage("No slave address set"); return 0; }

    short readBuf[2]{};
    uint8_t c = 1;
    uint8_t *a = &c;


    if ((fd = open(adapter.c_str(), O_RDWR)) < 0) {
        CDPMessage("Error: Couldn't open device! %d\n", fd);
        return 0;
    }

    if (ioctl(fd, I2C_SLAVE, asd_adr) < 0) {
        CDPMessage("Error: Couldn't find device on address!\n");
        return 0;
    }

    if (write(fd, (const void*)a, 1) != 1) {
        CDPMessage("Selecting configure register: Failed\n");
        return 0;
    }

    if (write(fd, (const void*)cnf, 2) != 2) {
        CDPMessage("Configuring configure register: Failed\n");
        return 0;
    }

    if (write(fd, readBuf, 1) != 1)
    {
        CDPMessage("Selecting Conversion register: Failed\n");
        return 0;
    }

    return 1;
}

int humidtyReader::closeHumidity()
{
    if(close(fd) < 0)
        return 1;

    return 0;
}

} // namespace adc1115

