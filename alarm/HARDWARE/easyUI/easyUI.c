#include "easyUI.h"
#include <string.h>
#include "lcd.h"   // ���Լ���LCD����
#include "touch.h" // ����������
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
				sprintf(buf, "%d ��", T_last); 
				Show_Str(360, 100, 300, 16, (uint8_t*)buf, 16, 0);
			}else{
				T=temperature;
				T_last=T;
				sprintf(buf, "%d ��", T); 
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

	Show_Str_Mid(130,259,"�����������",32,220);
	Show_Str_Mid(130,334,"�ɼ��豸����",32,220);
	Show_Str_Mid(130,409,"�¶ȱ�������",32,220);
	Show_Str_Mid(130,484,"����״̬��ѯ",32,220);
	Show_Str_Mid(130,559,"������������",32,220);
	Show_Str_Mid(130,634,"ϵͳά������",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);   
    LCD_DrawRectangle(130,625,350,675);
	
	Show_Str(30,100,200,16,"ʱ�䣺",16,0); 
    Show_Str(30,150,200,16,"�������䣺",16,0);    
    Show_Str(280,100,200,16,"��ǰ�¶ȣ�",16,0);
	Show_Str(280,150,200,16,"Ŀ���¶ȣ�",16,0);
	
    current_screen = 0;
}
//�����������
void UI_100(void) {
    LCD_Clear(WHITE);
	
	Show_Str_Mid(130,259,"�����״̬�鿴",32,220);
	Show_Str_Mid(130,334,"������ѹ�鿴",32,220);
	Show_Str_Mid(130,409,"�������ֵ����",32,220);

	
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

	
	Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 
	
    current_screen = 20;
}

// �Ӳ˵��������״̬�鿴
void UI_110(void) {
    LCD_Clear(WHITE);
	
	Show_Str_Mid(130,259,"�Ƿ�ϵ磺",32,220);
	Show_Str_Mid(130,334,"�����⣺",32,220);
	Show_Str_Mid(130,409,"ȱ���⣺",32,220);
	Show_Str_Mid(130,484,"��ߵ�ѹ��",32,220);
	Show_Str_Mid(130,559,"��͵�ѹ��",32,220);
	
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);
	
	Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 
	
    current_screen = 21;
}

// �Ӳ˵�����ߵ�ѹ
void UI_111(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A��",32,220);
    Show_Str_Mid(130,334,"B��",32,220);
    Show_Str_Mid(130,409,"C��",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 22;
}

// �Ӳ˵�����͵�ѹ
void UI_112(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A��",32,220);
    Show_Str_Mid(130,334,"B��",32,220);
    Show_Str_Mid(130,409,"C��",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 23;
}

// �Ӳ˵���������ѹ�鿴
void UI_120(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"A��",32,220);
    Show_Str_Mid(130,334,"B��",32,220);
    Show_Str_Mid(130,409,"C��",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 24;
}

// �Ӳ˵����������ֵ����
void UI_130(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"��ߵ�ѹ",32,220);
    Show_Str_Mid(130,334,"��͵�ѹ",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 25;
}

// ���㣺�ɼ��豸����
void UI_200(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"������",32,220);
    Show_Str_Mid(130,334,"FutureX",32,220);
    Show_Str_Mid(130,409,"����",32,220);
    Show_Str_Mid(130,484,"�η�",32,220);
    Show_Str_Mid(130,559,"���ֻ�",32,220);
    Show_Str_Mid(130,634,"ˮ��",32,220);

    LCD_DrawRectangle(130,250,350,300);
    LCD_DrawRectangle(130,325,350,375);
    LCD_DrawRectangle(130,400,350,450);
    LCD_DrawRectangle(130,475,350,525);
    LCD_DrawRectangle(130,550,350,600);
    LCD_DrawRectangle(130,625,350,675);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 30;
}

// �Ӳ˵���������
void UI_210(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"״̬����",32,220);
    Show_Str_Mid(130,334,"��ַ����",32,220);

    LCD_DrawRectangle(130,250,350,300);
    LCD_DrawRectangle(130,325,350,375);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 31;
}

// �Ӳ˵���FutureX
void UI_220(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"FutureX����",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 32;
}

// �Ӳ˵�������
void UI_230(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"��������",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 33;
}

// �Ӳ˵����η�
void UI_240(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"�η�����",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 34;
}

// �Ӳ˵������ֻ�
void UI_250(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"���ֻ�����",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 35;
}

// �Ӳ˵���ˮ��
void UI_260(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"ˮ������",32,220);

    LCD_DrawRectangle(130,250,350,300);

    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 36;
}

// �¶ȱ������� - ��1ҳ
void UI_300(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"��ǰ�¶�",32,220);
    Show_Str_Mid(130,284,"Ŀ���¶�",32,220);
    Show_Str_Mid(130,359,"�¶�����",32,220);
    Show_Str_Mid(130,434,"�¶�У׼",32,220);
    Show_Str_Mid(130,509,"���ƫ��",32,220);
    Show_Str_Mid(130,584,"���ƫ��",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // ��ҳ��ť
//    Show_Str(60,710,100,16,"��һҳ",16,0);
//    LCD_DrawRectangle(50,700,150,750);

    Show_Str(340,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // ���ذ�ť
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 40; // ��1ҳ
}

// �¶ȱ������� - ��2ҳ
void UI_301(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�������",32,220);
    LCD_DrawRectangle(130,200,350,250);

    // ��ҳ��ť
    Show_Str(60,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(50,700,150,750);

//    Show_Str(340,710,100,16,"��һҳ",16,0);
//    LCD_DrawRectangle(330,700,430,750);

    // ���ذ�ť
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 41; // ��2ҳ
}

// ����״̬��ѯ ���˵�
void UI_400(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"������ʱ",32,220);
    Show_Str_Mid(130,284,"��������״̬",32,220);
    Show_Str_Mid(130,359,"����������״̬",32,220);
    Show_Str_Mid(130,434,"��������״̬",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 50;
}

void UI_410(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�ϵ籨��",32,220);
    Show_Str_Mid(130,284,"��ѹ����",32,220);
    Show_Str_Mid(130,359,"��ѹ����",32,220);
    Show_Str_Mid(130,434,"ȱ�౨��",32,220);
    Show_Str_Mid(130,509,"���򱨾�",32,220);
    Show_Str_Mid(130,584,"�¶ȹ���",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // ��ҳ��ť
    Show_Str(340,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 51;
}

void UI_411(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"���±���",32,220);
    Show_Str_Mid(130,284,"���±���",32,220);
    Show_Str_Mid(130,359,"ϵͳ����",32,220);
    Show_Str_Mid(130,434,"ϵͳ����",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    // ��ҳ��ť
    Show_Str(60,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(50,700,150,750);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 52;
}

void UI_420(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"������",32,220);
    Show_Str_Mid(130,284,"FutureX",32,220);
    Show_Str_Mid(130,359,"����",32,220);
    Show_Str_Mid(130,434,"�η�",32,220);
    Show_Str_Mid(130,509,"���ֻ�",32,220);
    Show_Str_Mid(130,584,"ˮ��",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 53;
}

void UI_421(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"���±���",32,220);
    Show_Str_Mid(130,284,"���±���",32,220);
    Show_Str_Mid(130,359,"��ʪ����",32,220);
    Show_Str_Mid(130,434,"��ʪ����",32,220);
    Show_Str_Mid(130,509,"CO2Ũ�ȸ�",32,220);
    Show_Str_Mid(130,584,"CO2Ũ�ȵ�",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // ��ҳ��ť
    Show_Str(340,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(330,700,430,750);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 54;
}

void UI_422(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"NH3Ũ�ȸ�",32,220);
    Show_Str_Mid(130,284,"NH3Ũ�ȵ�",32,220);
    Show_Str_Mid(130,359,"�¶ȹ���",32,220);
    Show_Str_Mid(130,434,"ʪ�ȹ���",32,220);
    Show_Str_Mid(130,509,"CO2����",32,220);
    Show_Str_Mid(130,584,"NH3����",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    // ��ҳ��ť
    Show_Str(60,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(50,700,150,750);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 55;
}

void UI_430(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�ⲿ����1",32,220);
    Show_Str_Mid(130,284,"�ⲿ����2",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);

    // ����
    Show_Str(25,23,200,16,"������һ��",16,0);
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 56;
}

// ������������
void UI_500(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,259,"�ⲿ����1",32,220);
    Show_Str_Mid(130,334,"�ⲿ����2",32,220);

    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   

    // ������һ��
    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40); 

    current_screen = 60;  // ���������
}

void UI_600(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�豸��Ϣ����",32,220);
    Show_Str_Mid(130,284,"�豸��Ϣά��",32,220);
    Show_Str_Mid(130,359,"�ɼ���������",32,220);
    Show_Str_Mid(130,434,"������������",32,220);
    Show_Str_Mid(130,509,"�����޸�",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 70;
}
void UI_610(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"ʱ������",32,220);
    Show_Str_Mid(130,284,"�豸���",32,220);
    Show_Str_Mid(130,359,"��������",32,220);
    Show_Str_Mid(130,434,"������",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 71;
}
void UI_620(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"��ص�ѹ��ѯ",32,220);
    Show_Str_Mid(130,284,"�¶ȼ��",32,220);
    Show_Str_Mid(130,359,"��������",32,220);
    Show_Str_Mid(130,434,"��ʱ��������",32,220);
    Show_Str_Mid(130,509,"��������ģʽ",32,220);
    Show_Str_Mid(130,584,"�ָ���������",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);
    LCD_DrawRectangle(130,500,350,550);
    LCD_DrawRectangle(130,575,350,625);

    Show_Str(340,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(330,700,430,750);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 72;
}
void UI_621(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"����",32,220);
    Show_Str_Mid(130,284,"����汾",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);

    Show_Str(60,710,100,16,"��һҳ",16,0);
    LCD_DrawRectangle(50,700,150,750);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 73;
}
void UI_630(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"��������",32,220);
    Show_Str_Mid(130,284,"�������",32,220);
    Show_Str_Mid(130,359,"����ʱ������",32,220);
    Show_Str_Mid(130,434,"������ʱ",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);
    LCD_DrawRectangle(130,425,350,475);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 74;
}
void UI_640(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"������",32,220);

    LCD_DrawRectangle(130,200,350,250);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 75;
}
void UI_650(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�����ϱ�",32,220);
    Show_Str_Mid(130,284,"������",32,220);
    Show_Str_Mid(130,359,"�ϱ�����",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 76;
}
void UI_660(void) {
    LCD_Clear(WHITE);

    Show_Str_Mid(130,209,"�û�01",32,220);
    Show_Str_Mid(130,284,"�û�02",32,220);
    Show_Str_Mid(130,359,"�û�03",32,220);

    LCD_DrawRectangle(130,200,350,250);
    LCD_DrawRectangle(130,275,350,325);
    LCD_DrawRectangle(130,350,350,400);

    Show_Str(25,23,200,16,"������һ��",16,0);	
    LCD_DrawRectangle(20,20,110,40);

    current_screen = 77;
}

void UI_TouchHandler(u16 x, u16 y){
LCD_GetCursor(&x, &y);
    switch (current_screen)
    {
/* -------------------------------- ����������� --------------------------------*/
/* -------------------------------- ����������� --------------------------------*/
    case 20: // �Ӳ˵�1
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            current_screen = 21;
            UI_110(); // �����״̬�鿴
        }
		else if (x > 130 && x < 350 && y > 325 && y < 375) {
            current_screen = 22;
            UI_120(); // ������ѹ�鿴
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            current_screen = 23;
            UI_130(); // �������ֵ����
        }
        else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 0;
            UI_Main();
        } 
		
        break;
		
/* -------------------------------- �����״̬�鿴 --------------------------------*/
    case 21: // �����״̬�鿴 (UI_110)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // �Ƿ�ϵ�
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // ������
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // ȱ����
        }
        else if (x > 130 && x < 350 && y > 475 && y < 525) {
            current_screen = 22;
            UI_111(); // ��ߵ�ѹ
        }
        else if (x > 130 && x < 350 && y > 550 && y < 600) {
            current_screen = 23;
            UI_112(); // ��͵�ѹ
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
        } 
        break;

    case 22: // ��ߵ�ѹ (UI_111)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A��
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B��
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C��
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 21;
            UI_110();
		}
        break;

    case 23: // ��͵�ѹ (UI_112)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A��
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B��
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C��
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 21;
            UI_110();
		}
        break;

/* -------------------------------- ������ѹ�鿴 --------------------------------*/
    case 24: // ������ѹ�鿴 (UI_120)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // A��
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // B��
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            // C��
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
		}
        break;

/* -------------------------------- �������ֵ�鿴 --------------------------------*/
    case 25: // �������ֵ���� (UI_130)
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // ��ߵ�ѹ����
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // ��͵�ѹ����
        }
		else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 20;
            UI_100();
		}
        break;
		
/* -------------------------------- �ɼ��豸���� --------------------------------*/
/* -------------------------------- �ɼ��豸���� --------------------------------*/
	case 30: // ����˵� UI_200
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            current_screen = 31;
            UI_210(); // ������
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            current_screen = 32;
            UI_220(); // FutureX
        }
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            current_screen = 33;
            UI_230(); // ����
        }
        else if (x > 130 && x < 350 && y > 475 && y < 525) {
            current_screen = 34;
            UI_240(); // �η�
        }
        else if (x > 130 && x < 350 && y > 550 && y < 600) {
            current_screen = 35;
            UI_250(); // ���ֻ�
        }
        else if (x > 130 && x < 350 && y > 625 && y < 675) {
            current_screen = 36;
            UI_260(); // ˮ��
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 0;
            UI_Main(); // ����������
        }
        break;

/* -------------------------------- ������ --------------------------------*/
    case 31: // UI_210
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // ״̬����
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // ��ַ����
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200(); // ���زɼ��豸����
        }
        break;

/* -------------------------------- FutureX --------------------------------*/
    case 32: // UI_220
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- ���� --------------------------------*/
    case 33: // UI_230
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- �η� --------------------------------*/
    case 34: // UI_240
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- ���ֻ� --------------------------------*/
    case 35: // UI_250
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;

/* -------------------------------- ˮ�� --------------------------------*/
    case 36: // UI_260
        if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 30;
            UI_200();
        }
        break;
		
/* -------------------------------- �¶ȱ������� --------------------------------*/
/* ----------------------------- �¶ȱ������õ�һҳ------------------------------*/
    case 40: // UI_300
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // ��ǰ�¶�
        }
        else if (x > 130 && x < 350 && y > 275 && y < 325) {
            // Ŀ���¶�
        }
        else if (x > 130 && x < 350 && y > 350 && y < 400) {
            // �¶�����
        }
        else if (x > 130 && x < 350 && y > 425 && y < 475) {
            // �¶�У׼
        }
        else if (x > 130 && x < 350 && y > 500 && y < 550) {
            // ���ƫ��
        }
        else if (x > 130 && x < 350 && y > 575 && y < 625) {
            // ���ƫ��
        }
        // ��ҳ
        else if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 41;
            UI_301(); // ��һҳ
        }
        // ����
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 20;
            UI_Main(); // ������һ��
        }
        break;

/* ----------------------------- �¶ȱ������õڶ�ҳ------------------------------*/
    case 41: // UI_301
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // �������
        }
        // ��ҳ
        else if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 40;
            UI_300(); // ��һҳ
        }

        // ����
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 20;
            UI_Main(); // ������һ��
        }
        break;
		
/* -------------------------------- ����״̬��ѯ---------------------------------*/
/* -------------------------------- ����״̬��ѯ---------------------------------*/
    case 50: // UI_400
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            // ������ʱ
        }
        else if (x > 130 && x < 350 && y > 275 && y < 325) {
            current_screen = 51; UI_410(); // ��������״̬
        }
        else if (x > 130 && x < 350 && y > 350 && y < 400) {
            current_screen = 53; UI_420(); // ����������״̬
        }
        else if (x > 130 && x < 350 && y > 425 && y < 475) {
            current_screen = 56; UI_430(); // ��������״̬
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 0; UI_Main(); // ����
        }
        break;

/* -------------------------------- ��������״̬1---------------------------------*/
    case 51: // UI_410
        if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 52; UI_411(); // ��һҳ
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // ����
        }
        break;
/* -------------------------------- ��������״̬2---------------------------------*/
    case 52: // UI_411
        if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 51; UI_410(); // ��һҳ
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // ����
        }
        break;

/* -------------------------------- ����������״̬---------------------------------*/
    case 53: // UI_420
        if (x > 130 && x < 350 && y > 200 && y < 250) {
            current_screen = 54; UI_421(); // �������Ӳ˵�
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 50; UI_400(); // ����
        }
        break;
/* -------------------------------- ������1---------------------------------*/
    case 54: // UI_421
        if (x > 330 && x < 430 && y > 700 && y < 750) {
            current_screen = 55; UI_422(); // ��һҳ
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 53; UI_420(); // ����
        }
        break;
/* -------------------------------- ������2---------------------------------*/
    case 55: // UI_422
        if (x > 50 && x < 150 && y > 700 && y < 750) {
            current_screen = 54; UI_421(); // ��һҳ
        }
        else if (x > 0 && x < 80 && y > 0 && y < 80) {
            current_screen = 53; UI_420(); // ����
        }
        break;
/* -------------------------------- ��������״̬---------------------------------*/
    case 56: // UI_430
        if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 50; UI_400(); // ����
        }
        break;
/* -------------------------------- ������������---------------------------------*/
    case 60: // UI_500
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            // �ⲿ����1 ����
        }
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            // �ⲿ����2 ����
        }
        else if (x < 80 && x>0 && y < 80 && y > 0) {
            current_screen = 0; // �������˵�
            UI_Main();
        }
        break;
/* -------------------------------- ϵͳά������---------------------------------*/
/* -------------------------------- ϵͳά������---------------------------------*/
    case 70: // UI_600
        if (x > 130 && x < 350 && y > 200 && y < 250) { current_screen = 71; UI_610(); }
        else if (x > 130 && x < 350 && y > 275 && y < 325) { current_screen = 72; UI_620(); }
        else if (x > 130 && x < 350 && y > 350 && y < 400) { current_screen = 75; UI_640(); }
        else if (x > 130 && x < 350 && y > 425 && y < 475) { current_screen = 76; UI_650(); }
        else if (x > 130 && x < 350 && y > 500 && y < 550) { current_screen = 77; UI_660(); }
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 0; UI_Main(); }
        break;

    // -------- �豸��Ϣ���� --------
    case 71: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- �豸��Ϣά�� --------
    case 72: // UI_620
        if (x > 330 && x < 430 && y > 700 && y < 750) { current_screen = 73; UI_621(); }
        else if (x > 130 && x < 350 && y > 425 && y < 475) { current_screen = 74; UI_630(); } // ��ʱ��������
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); }
        break;

    case 73: // UI_621
        if (x > 50 && x < 150 && y > 700 && y < 750) { current_screen = 72; UI_620(); }
        else if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); }
        break;

    // -------- ��ʱ�������� --------
    case 74: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 72; UI_620(); } break;

    // -------- �ɼ��������� --------
    case 75: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- ������������ --------
    case 76: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

    // -------- �����޸� --------
    case 77: if (x < 80 && x>0 && y < 80 && y > 0) { current_screen = 70; UI_600(); } break;

	case 0: // ���˵�


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
            UI_Main(); // �������˵�
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







