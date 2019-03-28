#ifndef __TRANS_H__
#define __TRANS_H__

#include<stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief initializes underlying communication protocol.
 * @param[in] none
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t tansport_init(void);


/**
 * @brief writes data using underlying communication protocol.
 * @param[in] *data : pointer to buffer to be transmitted
 * @param[in] len : length of data
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t transport_write(uint8_t *data, uint32_t len);


/**
 * @brief Reads data using underlying communication protocol.
 * @param[in] *data : pointer to buffer to be transmitted
 * @param[in] len : length of data
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t transport_read(uint8_t *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
