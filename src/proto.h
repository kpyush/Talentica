#ifndef __BL_HOST_PROTO_H__
#define __BL_HOST_PROTO_H__

#include<stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*Image partition information*/
#define PART       0x02

/* Protocol command set*/
#define GET_CFG    0x00
#define SET_CFG    0x01
#define ERASE      0x02
#define WRITE_MEM  0x04
#define READ_MEM   0x08
#define GO         0x10

/* structure to hold the image information*/
typedef struct{
  uint32_t version;    /*version of the image*/
  uint32_t checksum;   /*checksum of image*/
}image_t;


typedef struct {
  image_t  image[PART];     /* image information placeholder*/
  uint32_t timestamp;       /* epoch timestamp of last update*/
  uint32_t update_count;    /* image update counter */
  uint32_t bootloader_ver;  /* bootloader version of target*/
  uint32_t protocol_ver;    /* protocol version of host*/
  uint32_t active_image;    /* active image*/
}config_t;

/**
 * @brief initializes protocol buffers and underlying hardware.
 * @param[in] none
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_init(void);


/**
 * @brief generates reset signal in order to reset the target
 * @param[in] none
 *
 * @retval  none
 */
void proto_reset_traget(void);

/**
 * @brief reads configuration data from the boot_conf .
 * @param[in] config_t * : pointer to config_t structure
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_get_cfg(config_t *cfg);

/**
 * @brief writes configuration data from the boot_conf .
 * @param[in] config_t * : pointer to config_t structure
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_set_cfg(config_t *cfg);

/**
 * @brief erases memory from the given address .
 * @param[in] add : address of the memory to be erased.
 * @param[in] len : lenght to be erased from the address
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_erase_mem(uint32_t add, uint32_t len);

/**
 * @brief reads memory from the given address .
 * @param[in] add : address of the memory to be read.
 * @param[in] len : lenght to be read 
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_read_mem(char *buff, uint32_t add, uint32_t len);

/**
 * @brief Writes memory from the given address .
 * @param[in] add : address of the memory to be write.
 * @param[in] len : lenght to be written 
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_write_mem(const char *buff, uint32_t add, uint32_t len);

/**
 * @brief loads the image from the specific address and executes
 * @param[in] add : address of the memory from which the image will be loaded.
 *
 * @retval none
 */
void proto_go(uint32_t add);

#ifdef __cplusplus
}
#endif

#endif
