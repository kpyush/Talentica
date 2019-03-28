#include<stdio.h>
#include<stdlib.h>
#include<proto.h>

static config_t boot_conf;
static int32_t choice;

//new firmware image data
const char new_image[IMAGE_SIZE];
const uint32_t new_fw_version = 0x1234;


/**
 * @brief writes the image data into image slot.
 * @param[in] slot no 0 or 1
 * @retval  0  succuess.
 * @retval  -1  error.
 */
int32_t flash_new_image(int32_t slot){

    int32_t retval=-1;

    if(slot == 0){
      proto_write_mem(new_image,SLOT_0, IMAGE_SIZE);
      retval = 0;
    }
    else if(slot == 1){
      proto_write_mem(new_image,SLOT_1, IMAGE_SIZE);
      retval = 0;
    }
    else {
      printf("\n invalid slot \n");
    }
}


int main(void){

    printf("\n***Starting Bootloader host Application***\n");
    proto_init();
    printf("\n*** BOOT HOST MENU***\n");
    printf("1 : Print Boot Configuration \n");
    printf("2 : Update Target\n");
    printf("3 : help\n");
    printf("4 : exit\n");

    while(1){

        scanf("%d",&choice);

        switch(choice){
          case 1:{
            printf(" Printing Boot Configuration \n");
            printf("image[0] version:%0X\n",boot_conf.image[0].version);
            printf("image[0] checksum:%0X\n",boot_conf.image[0].checksum);
            printf("image[1] version:%0X\n",boot_conf.image[1].version);
            printf("image[1] checksum:%0X\n",boot_conf.image[1].checksum);
            printf("timestamp:%X\n",boot_conf.timestamp);
            printf("update_count:%0X\n",boot_conf.update_count);
            printf("bootloader_ver:%X\n",boot_conf.bootloader_ver);
            printf("protocol_ver:%X\n",boot_conf.protocol_ver);
            printf("active_image:%X\n",boot_conf.active_image);
            printf("\n*** END of Boot_config information***\n");
          }break;

          case 2:{
            //get the current config
            proto_get_cfg(&boot_conf);
            //check if image at slot_0 needs an update
            if(new_fw_version == boot_conf.image[0].version){
                //reset the target
                proto_reset_traget();
                //flash the image at slot 0
                flash_new_image(0);
                // make it active image
                boot_conf.active_image = 0;
                //save boot_conf
                proto_set_cfg(&boot_conf);
                // reset target
                proto_reset_traget();
                // delay more than 2 seconds 
            }
            else if (new_fw_version == boot_conf.image[1].version){
                //reset the target
                proto_reset_traget();
                //flash the image at slot 0
                flash_new_image(1);
                // make it active image
                boot_conf.active_image = 1;
                //save boot_conf
                proto_set_cfg(&boot_conf);
                // reset target
                proto_reset_traget();
                // delay more than 2 seconds 

            } 
            else {
                printf("No updates require..\n");
                // boot from the last active image
                if(boot_conf.active_image == 0){
                  proto_go(SLOT_0);
                } 
                else if (boot_conf.active_image == 1){
                  proto_go(SLOT_1);
                }
            }
          }break;

          case 3:{
            printf("\n*** BOOT HOST MENU***\n");
            printf("1 : Print Boot Configuration \n");
            printf("2 : Update Target\n");
            printf("3 : help\n");
            printf("4 : exit\n");
          }break;

          case 4:{
            printf("\n*** EXITING ***\n");
            exit(0);
          }break;

          default:{
            printf("\n*** please enter correct no. ***\n");
          }break;

       }
    }
        
    return 0;
}


