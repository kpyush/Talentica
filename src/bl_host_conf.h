#ifndef __BL_HOST_CONF_H__
#define __BL_HOST_CONF_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define  TRANSPORT_I2C  0
#define  TRANSPORT_SPI  0
#define  TRANSPORT_UART 1


#define  DEBUG 1
#if DEBUG
  #define LOG(fmt, ...)    printf(fmt, ##__VA_ARGS__)
#else
  #define LOG(fmt, ...)    (void)0
#endif


#ifdef __cplusplus
}
#endif

#endif
