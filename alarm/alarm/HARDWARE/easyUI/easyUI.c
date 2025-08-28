#include "easyUI.h"
#include <string.h>
#include "lcd.h"   // 你自己的LCD驱动
#include "touch.h" // 触摸屏驱动
#include "text.h"
#include "stdint.h"
#include "dht11.h"
#include "pcf8574.h"
#include "rtc.h"
//const unsigned char hanzi_wen[32] = {
//    0x00,0x10,0x00,0x10,0x3F,0xFC,0x20,0x08,
//    0x20,0x08,0x3F,0xF8,0x22,0x48,0x22,0x48,
//    0x3E,0x48,0x22,0x48,0x22,0x48,0x3E,0x48,
//    0x20,0x48,0x20,0x48,0x20,0x48,0x00,0x48
//};
void UI_Main_show(void){
		u8 T,dT,temperature, humidity;
        static u8 T_last=0;
		char buf[32]; 
        u8 tbuf[40];	
	    RTC_TimeTypeDef RTC_TimeStruct;
        RTC_DateTypeDef RTC_DateStruct;
		PCF8574_ReadBit(BEEP_IO);
		DHT11_Read_Data(&temperature, &humidity);
	    dT = abs(T - T_last);
	
			if(dT>10){
				sprintf(buf, "%d ℃", T_last); 
				Show_Str(360, 100, 300, 16, (uint8_t*)buf, 16, 0);
			}else{
				T=temperature;
				T_last=T;
				sprintf(buf, "%d ℃", T); 
				Show_Str(360, 100, 300, 16, (uint8_t*)buf, 16, 0);
			}
			
			
			HAL_RTC_GetTime(&RTC_Handler,&RTC_TimeStruct,RTC_FORMAT_BIN);
			sprintf((char*)tbuf,"%02d:%02d:%02d",RTC_TimeStruct.Hours,RTC_TimeStruct.Minutes,RTC_TimeStruct.Seconds); 
			LCD_ShowString(80,100,210,16,16,tbuf);	
            HAL_RTC_GetDate(&RTC_Handler,&RTC_DateStruct,RTC_FORMAT_BIN);
//			sprintf((char*)tbuf,"Date:20%02d-%02d-%02d",RTC_DateStruct.Year,RTC_DateStruct.Month,RTC_DateStruct.Date); 
//			LCD_ShowString(30,160,210,16,16,tbuf);


		}

void UI_Main(void) {
    LCD_Clear(WHITE);

	Show_Str_Mid(130,259,"三相电检测设置",32,220);
	Show_Str_Mid(130,334,"采集设备设置",32,220);
	Show_Str_Mid(130,409,"温度报警设置",32,220);
	Show_Str_Mid(130,484,"报警状态查询",32,220);
	Show_Str_Mid(130,559,"报警输入设置",32,220);
	Show_Str_Mid(130,634,"系统维护设置",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);   
    LCD_DrawRectangle(130,625,350,675);
	
	Show_Str(30,100,200,16,"时间：",16,0); 
    Show_Str(30,150,200,16,"生长日龄：",16,0);    
    Show_Str(280,100,200,16,"当前温度：",16,0);
	Show_Str(280,150,200,16,"目标温度：",16,0);
	
    current_screen = 0;
}
//三相电检测设置
void UI_100(void) {
    LCD_Clear(WHITE);
	
	Show_Str_Mid(130,259,"三相电状态查看",32,220);
	Show_Str_Mid(130,334,"三相电电压查看",32,220);
	Show_Str_Mid(130,409,"三相电阈值设置",32,220);

	
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

	
	Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 
	
    current_screen = 20;
}

// 子菜单：三相电状态查看
void UI_110(void) {
    LCD_Clear(WHITE);
	
	Show_Str_Mid(130,259,"是否断电：",32,220);
	Show_Str_Mid(130,334,"相序检测：",32,220);
	Show_Str_Mid(130,409,"缺相检测：",32,220);
	Show_Str_Mid(130,484,"最高电压：",32,220);
	Show_Str_Mid(130,559,"最低电压：",32,220);
	
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);
	
	Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 
	
    current_screen = 21;
}

// 子菜单：最高电压
void UI_111(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A相",32,220);
    Show_Str_Mid(130,334,"B相",32,220);
    Show_Str_Mid(130,409,"C相",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 22;
}

// 子菜单：最低电压
void UI_112(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A相",32,220);
    Show_Str_Mid(130,334,"B相",32,220);
    Show_Str_Mid(130,409,"C相",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 23;
}

// 子菜单：三相电电压查看
void UI_120(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A相",32,220);
    Show_Str_Mid(130,334,"B相",32,220);
    Show_Str_Mid(130,409,"C相",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 24;
}

// 子菜单：三相电阈值设置
void UI_130(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"最高电压",32,220);
    Show_Str_Mid(130,334,"最低电压",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 25;
}

// 顶层：采集设备设置
void UI_200(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"环控器",32,220);
    Show_Str_Mid(130,334,"FutureX",32,220);
    Show_Str_Mid(130,409,"料线",32,220);
    Show_Str_Mid(130,484,"刮粪",32,220);
    Show_Str_Mid(130,559,"播种机",32,220);
    Show_Str_Mid(130,634,"水线",32,220);

    LCD_DrawRectangle(130,250,350,300);
    LCD_DrawRectangle(130,325,350,375);
    LCD_DrawRectangle(130,400,350,450);
    LCD_DrawRectangle(130,475,350,525);
    LCD_DrawRectangle(130,550,350,600);
    LCD_DrawRectangle(130,625,350,675);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 30;
}

// 子菜单：环控器
void UI_210(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"状态设置",32,220);
    Show_Str_Mid(130,334,"地址设置",32,220);

    LCD_DrawRectangle(130,250,350,300);
    LCD_DrawRectangle(130,325,350,375);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 31;
}

// 子菜单：FutureX
void UI_220(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"FutureX设置",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 32;
}

// 子菜单：料线
void UI_230(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"料线设置",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 33;
}

// 子菜单：刮粪
void UI_240(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"刮粪设置",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 34;
}

// 子菜单：播种机
void UI_250(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"播种机设置",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 35;
}

// 子菜单：水线
void UI_260(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"水线设置",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 36;
}

// 温度报警设置 - 第1页
void UI_300(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"当前温度",32,220);
    Show_Str_Mid(130,284,"目标温度",32,220);
    Show_Str_Mid(130,359,"温度曲线",32,220);
    Show_Str_Mid(130,434,"温度校准",32,220);
    Show_Str_Mid(130,509,"最高偏差",32,220);
    Show_Str_Mid(130,584,"最低偏差",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // 翻页按钮
//    Show_Str(60,710,100,16,"上一页",16,0);
//    LCD_DrawRectangle(50,700,150,750);

    Show_Str(340,710,100,16,"下一页",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // 返回按钮
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 40; // 第1页
}

// 温度报警设置 - 第2页
void UI_301(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"开启风机",32,220);
    LCD_DrawRectangle(130,200,350,250);

    // 翻页按钮
    Show_Str(60,710,100,16,"上一页",16,0);
    LCD_DrawRectangle(50,700,150,750);

//    Show_Str(340,710,100,16,"下一页",16,0);
//    LCD_DrawRectangle(330,700,430,750);

    // 返回按钮
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 41; // 第2页
}

// 报警状态查询 主菜单
void UI_400(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"消音延时",32,220);
    Show_Str_Mid(130,284,"本机报警状态",32,220);
    Show_Str_Mid(130,359,"环控器报警状态",32,220);
    Show_Str_Mid(130,434,"报警输入状态",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 50;
}

void UI_410(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"断电报警",32,220);
    Show_Str_Mid(130,284,"高压报警",32,220);
    Show_Str_Mid(130,359,"低压报警",32,220);
    Show_Str_Mid(130,434,"缺相报警",32,220);
    Show_Str_Mid(130,509,"相序报警",32,220);
    Show_Str_Mid(130,584,"温度故障",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // 翻页按钮
    Show_Str(340,710,100,16,"下一页",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 51;
}

void UI_411(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"高温报警",32,220);
    Show_Str_Mid(130,284,"低温报警",32,220);
    Show_Str_Mid(130,359,"系统故障",32,220);
    Show_Str_Mid(130,434,"系统开机",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    // 翻页按钮
    Show_Str(60,710,100,16,"上一页",16,0);
    LCD_DrawRectangle(50,700,150,750);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 52;
}

void UI_420(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"环控器",32,220);
    Show_Str_Mid(130,284,"FutureX",32,220);
    Show_Str_Mid(130,359,"料线",32,220);
    Show_Str_Mid(130,434,"刮粪",32,220);
    Show_Str_Mid(130,509,"播种机",32,220);
    Show_Str_Mid(130,584,"水线",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 53;
}

void UI_421(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"高温报警",32,220);
    Show_Str_Mid(130,284,"低温报警",32,220);
    Show_Str_Mid(130,359,"高湿报警",32,220);
    Show_Str_Mid(130,434,"低湿报警",32,220);
    Show_Str_Mid(130,509,"CO2浓度高",32,220);
    Show_Str_Mid(130,584,"CO2浓度低",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // 翻页按钮
    Show_Str(340,710,100,16,"下一页",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 54;
}

void UI_422(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"NH3浓度高",32,220);
    Show_Str_Mid(130,284,"NH3浓度低",32,220);
    Show_Str_Mid(130,359,"温度故障",32,220);
    Show_Str_Mid(130,434,"湿度故障",32,220);
    Show_Str_Mid(130,509,"CO2故障",32,220);
    Show_Str_Mid(130,584,"NH3故障",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // 翻页按钮
    Show_Str(60,710,100,16,"上一页",16,0);
    LCD_DrawRectangle(50,700,150,750);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 55;
}

void UI_430(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"外部输入1",32,220);
    Show_Str_Mid(130,284,"外部输入2",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);

    // 返回
    Show_Str(25,23,200,16,"返回上一级",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 56;
}

// 报警输入设置
void UI_500(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"外部输入1",32,220);
    Show_Str_Mid(130,334,"外部输入2",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   

    // 返回上一级
    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 60;  // 第五项界面
}

void UI_600(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"设备信息设置",32,220);
    Show_Str_Mid(130,284,"设备信息维护",32,220);
    Show_Str_Mid(130,359,"采集网络设置",32,220);
    Show_Str_Mid(130,434,"上行网络设置",32,220);
    Show_Str_Mid(130,509,"密码修改",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 70;
}
void UI_610(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"时钟设置",32,220);
    Show_Str_Mid(130,284,"设备编号",32,220);
    Show_Str_Mid(130,359,"房屋类型",32,220);
    Show_Str_Mid(130,434,"房间编号",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 71;
}
void UI_620(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"电池电压查询",32,220);
    Show_Str_Mid(130,284,"温度检测",32,220);
    Show_Str_Mid(130,359,"供电类型",32,220);
    Show_Str_Mid(130,434,"定时报警设置",32,220);
    Show_Str_Mid(130,509,"出厂测试模式",32,220);
    Show_Str_Mid(130,584,"恢复出厂设置",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    Show_Str(340,710,100,16,"下一页",16,0);
    LCD_DrawRectangle(330,700,430,750);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 72;
}
void UI_621(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"语言",32,220);
    Show_Str_Mid(130,284,"软件版本",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);

    Show_Str(60,710,100,16,"上一页",16,0);
    LCD_DrawRectangle(50,700,150,750);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 73;
}
void UI_630(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"报警测试",32,220);
    Show_Str_Mid(130,284,"报警输出",32,220);
    Show_Str_Mid(130,359,"报警时间设置",32,220);
    Show_Str_Mid(130,434,"报警延时",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 74;
}
void UI_640(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"波特率",32,220);

    LCD_DrawRectangle(130,200,350,250);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 75;
}
void UI_650(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"主动上报",32,220);
    Show_Str_Mid(130,284,"波特率",32,220);
    Show_Str_Mid(130,359,"上报周期",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 76;
}
void UI_660(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"用户01",32,220);
    Show_Str_Mid(130,284,"用户02",32,220);
    Show_Str_Mid(130,359,"用户03",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);

    Show_Str(25,23,200,16,"返回上一级",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 77;
}

void UI_TouchHandler(u16 x, u16 y){
LCD_GetCursor(&x, &y);
    switch (current_screen)
    {
/* -------------------------------- 三相电检测设置 --------------------------------*/
/* -------------------------------- 三相电检测设置 --------------------------------*/
    case 20: // 子菜单1
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            current_screen = 21;
            UI_110(); // 三相电状态查看
        }
		else if (x > 130 && x < 350 && y > 325 && y < 375) {
            current_screen = 22;
            UI_120(); // 三相电电压查看
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            current_screen = 23;
            UI_130(); // 三相电阈值设置
        }
        else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 0;
            UI_Main();
        } 
		
        break;
		
/* -------------------------------- 三相电状态查看 --------------------------------*/
    case 21: // 三相电状态查看 (UI_110)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // 是否断电
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // 相序检测
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // 缺相检测
        }
        else if (x > 130 && x < 350 && y > 475 && y < 525) {
            current_screen = 22;
            UI_111(); // 最高电压
        }
        else if (x > 130 && x < 350 && y > 550 && y < 600) {
            current_screen = 23;
            UI_112(); // 最低电压
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
        } 
        break;

    case 22: // 最高电压 (UI_111)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A相
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B相
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C相
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 21;
            UI_110();
		}
        break;

    case 23: // 最低电压 (UI_112)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A相
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B相
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C相
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 21;
            UI_110();
		}
        break;

/* -------------------------------- 三相电电压查看 --------------------------------*/
    case 24: // 三相电电压查看 (UI_120)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A相
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B相
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C相
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
		}
        break;

/* -------------------------------- 三相电阈值查看 --------------------------------*/
    case 25: // 三相电阈值设置 (UI_130)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // 最高电压设置
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // 最低电压设置
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
		}
        break;
		
/* -------------------------------- 采集设备设置 --------------------------------*/
/* -------------------------------- 采集设备设置 --------------------------------*/
	case 30: // 顶层菜单 UI_200
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            current_screen = 31;
            UI_210(); // 环控器
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            current_screen = 32;
            UI_220(); // FutureX
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            current_screen = 33;
            UI_230(); // 料线
        }
        else if (x > 130 && x < 350 && y > 475 && y < 525) {
            current_screen = 34;
            UI_240(); // 刮粪
        }
        else if (x > 130 && x < 350 && y > 550 && y < 600) {
            current_screen = 35;
            UI_250(); // 播种机
        }
        else if (x > 130 && x < 350 && y > 625 && y < 675) {
            current_screen = 36;
            UI_260(); // 水线
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 0;
            UI_Main(); // 返回主界面
        }
        break;

/* -------------------------------- 环控器 --------------------------------*/
    case 31: // UI_210
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // 状态设置
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // 地址设置
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200(); // 返回采集设备设置
        }
        break;

/* -------------------------------- FutureX --------------------------------*/
    case 32: // UI_220
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- 料线 --------------------------------*/
    case 33: // UI_230
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- 刮粪 --------------------------------*/
    case 34: // UI_240
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- 播种机 --------------------------------*/
    case 35: // UI_250
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- 水线 --------------------------------*/
    case 36: // UI_260
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;
		
/* -------------------------------- 温度报警设置 --------------------------------*/
/* ----------------------------- 温度报警设置第一页------------------------------*/
    case 40: // UI_300
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // 当前温度
        }
        else if (x > 130 && x < 350 && y > 275 && y < 325) {
            // 目标温度
        }
        else if (x > 130 && x < 350 && y > 350 && y < 400) {
            // 温度曲线
        }
        else if (x > 130 && x < 350 && y > 425 && y < 475) {
            // 温度校准
        }
        else if (x > 130 && x < 350 && y > 500 && y < 550) {
            // 最高偏差
        }
        else if (x > 130 && x < 350 && y > 575 && y < 625) {
            // 最低偏差
        }
        // 翻页
        else if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 41;
            UI_301(); // 下一页
        }
        // 返回
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 20;
            UI_Main(); // 返回上一级
        }
        break;

/* ----------------------------- 温度报警设置第二页------------------------------*/
    case 41: // UI_301
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // 开启风机
        }
        // 翻页
        else if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 40;
            UI_300(); // 上一页
        }

        // 返回
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 20;
            UI_Main(); // 返回上一级
        }
        break;
		
/* -------------------------------- 报警状态查询---------------------------------*/
/* -------------------------------- 报警状态查询---------------------------------*/
    case 50: // UI_400
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // 消音延时
        }
        else if (x > 130 && x < 350 && y > 275 && y < 325) {
            current_screen = 51; UI_410(); // 本机报警状态
        }
        else if (x > 130 && x < 350 && y > 350 && y < 400) {
            current_screen = 53; UI_420(); // 环控器报警状态
        }
        else if (x > 130 && x < 350 && y > 425 && y < 475) {
            current_screen = 56; UI_430(); // 报警输入状态
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 0; UI_Main(); // 返回
        }
        break;

/* -------------------------------- 本机报警状态1---------------------------------*/
    case 51: // UI_410
        if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 52; UI_411(); // 下一页
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // 返回
        }
        break;
/* -------------------------------- 本机报警状态2---------------------------------*/
    case 52: // UI_411
        if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 51; UI_410(); // 上一页
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // 返回
        }
        break;

/* -------------------------------- 环控器报警状态---------------------------------*/
    case 53: // UI_420
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            current_screen = 54; UI_421(); // 环控器子菜单
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // 返回
        }
        break;
/* -------------------------------- 环控器1---------------------------------*/
    case 54: // UI_421
        if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 55; UI_422(); // 下一页
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 53; UI_420(); // 返回
        }
        break;
/* -------------------------------- 环控器2---------------------------------*/
    case 55: // UI_422
        if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 54; UI_421(); // 上一页
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 53; UI_420(); // 返回
        }
        break;
/* -------------------------------- 报警输入状态---------------------------------*/
    case 56: // UI_430
        if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 50; UI_400(); // 返回
        }
        break;
/* -------------------------------- 报警输入设置---------------------------------*/
    case 60: // UI_500
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // 外部输入1 设置
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // 外部输入2 设置
        }
        else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 0; // 返回主菜单
            UI_Main();
        }
        break;
/* -------------------------------- 系统维护设置---------------------------------*/
/* -------------------------------- 系统维护设置---------------------------------*/
    case 70: // UI_600
        if (x > 130 && x < 350 && y > 200 && y < 250) { current_screen = 71; UI_610(); }
        else if (x > 130 && x < 350 && y > 275 && y < 325) { current_screen = 72; UI_620(); }
        else if (x > 130 && x < 350 && y > 350 && y < 400) { current_screen = 75; UI_640(); }
        else if (x > 130 && x < 350 && y > 425 && y < 475) { current_screen = 76; UI_650(); }
        else if (x > 130 && x < 350 && y > 500 && y < 550) { current_screen = 77; UI_660(); }
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 0; UI_Main(); }
        break;

    // -------- 设备信息设置 --------
    case 71: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- 设备信息维护 --------
    case 72: // UI_620
        if (x > 330 && x < 430 && y > 700 && y < 750) { current_screen = 73; UI_621(); }
        else if (x > 130 && x < 350 && y > 425 && y < 475) { current_screen = 74; UI_630(); } // 定时报警设置
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); }
        break;

    case 73: // UI_621
        if (x > 50 && x < 150 && y > 700 && y < 750) { current_screen = 72; UI_620(); }
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); }
        break;

    // -------- 定时报警设置 --------
    case 74: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 72; UI_620(); } break;

    // -------- 采集网络设置 --------
    case 75: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- 上行网络设置 --------
    case 76: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- 密码修改 --------
    case 77: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

	case 0: // 主菜单


        if (x > 130 && x < 350 && y > 250 && y < 300) {

            UI_100(); 
        } 
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            
            UI_200();
        } 
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            
            UI_300();
        }
		else if (x > 130 && x < 350 && y > 475 && y < 525) {
            
            UI_400();
        } 
        else if (x > 130 && x < 350 && y > 550 && y < 600) {
            
            UI_500();
        }
		else if (x > 130 && x < 350 && y > 600 && y < 675) {
            
            UI_600();
        } 

        break;
		
		
    default:
        if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 0;
            UI_Main(); // 返回主菜单
        }
        break;
    }
}

void UI_DATA_Show(u16 x, u16 y){
//LCD_GetCursor(&x, &y);
	    switch (current_screen)
    {
	case 0:
		{
		UI_Main_show();
		}

	}


}

void UI_Init(void) {
    current_screen = 0;
    LCD_Clear(WHITE);
	UI_Main();
	UI_Main_show();
	
}







