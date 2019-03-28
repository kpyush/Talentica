#include<stdio.h>
#include<transport.h>
#include<bl_host_conf.h>

#if TRANSPORT_I2C

uint32_t tansport_init(void){
    LOG("%s\n",__FUNCTION__);
    LOG("using I2C transport\n");

}

uint32_t transport_write(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using I2C transport\n");
}

uint32_t transport_read(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using I2C transport\n");
}
#endif

#if TRANSPORT_SPI
uint32_t tansport_init(void){
    LOG("%s\n",__FUNCTION__);
    LOG("using SPI transport\n");

}
uint32_t transport_write(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using SPI transport\n");
}
uint32_t transport_read(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using SPI transport\n");
}
#endif

#if TRANSPORT_UART
uint32_t tansport_init(void){
    LOG("%s\n",__FUNCTION__);
    LOG("using UART transport\n");

}
uint32_t transport_write(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using UART transport\n");
}
uint32_t transport_read(uint8_t *data, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    LOG("using UART transport\n");
}
#endif



