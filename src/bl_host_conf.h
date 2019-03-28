#ifndef __BL_HOST_CONF_H__
#define __BL_HOST_CONF_H__

#ifdef __cplusplus
extern "C"
{
#endif

//image definitions
#define IMAGE_SIZE 0x1D000
#define SLOT_0 0x50000000
#define SLOT_1 0x22000000

//transport protocol selection
#define  TRANSPORT_I2C  0
#define  TRANSPORT_SPI  0
#define  TRANSPORT_UART 1

//debug adapter
#define  DEBUG 0
#if DEBUG
  #define LOG(fmt, ...)    printf(fmt, ##__VA_ARGS__)
#else
  #define LOG(fmt, ...)    (void)0
#endif


#ifdef __cplusplus
}
#endif

#endif
