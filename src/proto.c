#include<stdio.h>
#include<stdint.h>
#include<proto.h>
#include<transport.h>
#include<bl_host_conf.h>

#define TIMESTAMP 1553738394U
#define PRTOCOL_VER 0x12345678U
#define BOOTLOADER_VER 0x98765432U

/**
 * @brief initializes protocol buffers and underlying hardware.
 * @param[in] none
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_init(void){
    LOG("%s\n",__FUNCTION__);
    tansport_init();
}

/**
 * @brief resets the tar protocol buffers and underlying hardware.
 * @param[in] none
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */

void proto_reset_traget(void){
    LOG("%s\n",__FUNCTION__);
}

/**
 * @brief reads configuration data from the boot_conf .
 * @param[in] config_t * : pointer to config_t structure
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */

uint32_t proto_get_cfg(config_t *cfg){
    LOG("%s\n",__FUNCTION__);
    transport_write(NULL,0x1234);
    transport_read(NULL,0x1234);
    cfg->image[0].version = 0xDAAD;
    cfg->image[0].checksum = 0xDEAD;
    cfg->image[1].version = 0xBEEF;
    cfg->image[1].checksum = 0xBEAD;
    cfg->timestamp = TIMESTAMP;
    cfg->update_count = 0x02;
    cfg->bootloader_ver = BOOTLOADER_VER;
    cfg->protocol_ver = PRTOCOL_VER;
    cfg->active_image = 1;
    return 0;
}

/**
 * @brief writes configuration data from the boot_conf .
 * @param[in] config_t * : pointer to config_t structure
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */

uint32_t proto_set_cfg(config_t *cfg){
    LOG("%s\n",__FUNCTION__);
    transport_write(NULL,0x1234);
    transport_read(NULL,0x1234);
    return 0;
}

/**
 * @brief erases memory from the given address .
 * @param[in] add : address of the memory to be erased.
 * @param[in] len : lenght to be erased from the address
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */

uint32_t proto_erase_mem(uint32_t add, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    transport_write(NULL,0x1234);
    return 0;
}

/**
 * @brief reads memory from the given address .
 * @param[in] add : address of the memory to be read.
 * @param[in] len : lenght to be read 
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_read_mem(char *buff, uint32_t add, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    transport_write(NULL,0x1234);
    transport_read(NULL,0x1234);
    return 0;
}

/**
 * @brief Writes memory from the given address .
 * @param[in] add : address of the memory to be write.
 * @param[in] len : lenght to be written 
 *
 * @retval  0  succuess.
 * @retval  1  error.
 */
uint32_t proto_write_mem(const char *buff, uint32_t add, uint32_t len){
    LOG("%s\n",__FUNCTION__);
    transport_write(NULL,0x1234);
    transport_read(NULL,0x1234);
    return 0;
}

/*
 * @brief loads the image from the specific address and executes
 * @param[in] add : address of the memory from which the image will be loaded.
 *
 * @retval none
 */
void proto_go(uint32_t add){
    LOG("%s\n",__FUNCTION__);
    LOG("booting from address:%0x\n",add);
    transport_write(NULL,0x1234);
}
