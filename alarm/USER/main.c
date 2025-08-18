#include "sys.h"
#include "delay.h"
#include "usart.h"



/*下面主函数是使用HAL库函数实现控制IO口输出*/
 
int main(void)
{
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
    delay_init(180);                //初始化延时函数

    while(1)
    {

    }
}
 





