#include "flash_eeprom.h"
#include "uart.h"
#include "tim1.h"


u16 value_eeprom;
/*******************************************************************************
 * 说明: 每种型号的EEPROM的大小不一样，调用此函数的时候要注意将要写进的字节数组
         的大小是否超过该型号的EEPROM的地址。
         大容量的EEPROM的型号是STM8S208, STM8S207, STM8S007, STM8AF52Ax, STM8AF62Ax 
         EEPROM的地址是从0x004000到0x0047ff，共2048Byte,每个Block是128Byte,一共16个Block.
         BlockNum @ 1~16
         中容量的EEPROM的型号是STM8S105, STM8S005, STM8AF626x
         EEPROM的地址是从0x004000到0x0043ff，共1024Byte,每个Block是128Byte,一共8个Block.
         BlockNum @ 1~8
         小容量的EEPROM的型号是STM8S103, STM8S003, STM8S903 
         EEPROM的地址是从0x004000到0x00427f，共1024Byte,每个Block是64Byte,一共10个Block.
         BlockNum @ 1~10

 ******************************************************************************/


void Init_EEPROM(void)
{
    FLASH_DeInit();
    //Define flash programming time.
    //编程时间为标准编程时间的一半(1/2 tprog)
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD); 
}
/*
void WriteEEPROM(u16* data,u16 number)
{
  u16 i;  
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // 解锁EEPROM
  //while (FLASH_GetFlagStatus(FLASH_FLAG_DUL) == RESET)
  for(i=0;i<(number*2);i++)   // 写 eeprom
  { 
    FLASH_EraseByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i);
    FLASH_ProgramByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i,*(char*)(data+i));
  }
  FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
}
*/

void ReadEEPROM(u16* data,u16 number)
{
  u16 i,j;
  u8 data_change_H;
  u8 data_change_L;
  //u8 ir_eeprom_buffer[560];
  
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  data_change_H = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS);
  data_change_L = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS +1);
  number = (data_change_H & 0X00FF)<<8 | (data_change_L & 0x00FF);
  value_eeprom = number;
  for(i=0;i<number;i++)
  {
    data_change_H = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS + (j+2));
    data_change_L = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS + (j+3));
    j+=2;
    data[i+1] = (data_change_H & 0X00FF)<<8 | (data_change_L & 0x00FF);    
  }
  FLASH_Lock(FLASH_MEMTYPE_DATA);
  
  WriteEEPROM(TIM_IR_BUFFER,IR_FLAG_REMOVE);
}
void WriteEEPROM(u16* data,u16 number)
{
  u16 i;
  u16 *p;
  u8  *f;
  
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // 解锁EEPROM 
  for(i=0;i<100;i++)
  {
     f = (u8*)(0X4000+i);
     if(*f!=0) 
     {
        *f=0;
        while(FLASH->IAPSR & 0x40 == 0);
     }
  } 
  p = (u16 *)(0X4000);
  *p = number;
  while(FLASH->IAPSR & 0x40 == 0);
  for(i=0;i<number;i++)
  {
    p = (u16 *)((0X4000+2)+(i*2));
    *p = data[i+1];
  }
  FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
} 

















