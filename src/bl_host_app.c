#include<stdio.h>
#include<stdlib.h>
#include<proto.h>

static config_t boot_conf;
static int32_t choice;

int main(void){

    printf("\n***Starting Bootloader host Application***\n");
    proto_init();
    proto_get_cfg(&boot_conf);
    proto_set_cfg(&boot_conf);
    proto_erase_mem(1,2);
    proto_read_mem(NULL, 1, 2);
    proto_go(0x123456);

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
            printf("\n*** END of Boot_config information***\n");
          }break;

          case 2:{
            printf("\n*** UPDATING...***\n");
            printf("No updates require..\n");
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


