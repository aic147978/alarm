#include "easyUI.h"
#include <string.h>
#include "lcd.h"   // ���Լ���LCD����
#include "touch.h" // ����������


//const unsigned char hanzi_wen[32] = {
//    0x00,0x10,0x00,0x10,0x3F,0xFC,0x20,0x08,
//    0x20,0x08,0x3F,0xF8,0x22,0x48,0x22,0x48,
//    0x3E,0x48,0x22,0x48,0x22,0x48,0x3E,0x48,
//    0x20,0x48,0x20,0x48,0x20,0x48,0x00,0x48
//};




void UI_Main(void) {
    LCD_Clear(WHITE);
    LCD_ShowString(240,275,200,16,32,"�����������"); 
    LCD_ShowString(240,350,200,16,32,"�ɼ��豸����");    
    LCD_ShowString(240,425,200,16,32,"�¶ȱ�������");
	LCD_ShowString(240,500,200,16,32,"����״̬��ѯ"); 
    LCD_ShowString(240,575,200,16,32,"������������");    
    LCD_ShowString(240,650,200,16,32,"ϵͳά������");
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);   
    LCD_DrawRectangle(130,625,350,675);
	
	LCD_ShowString(120,100,200,16,16,"ʱ�䣺"); 
    LCD_ShowString(120,100,200,16,16,"�������䣺");    
    LCD_ShowString(360,150,200,16,16,"��ǰ�¶ȣ�");
	LCD_ShowString(360,150,200,16,16,"Ŀ���¶ȣ�");
	
    current_screen = 0;
}

void UI_100(void) {
    LCD_Clear(WHITE);
	LCD_ShowString(240,275,200,16,16,"�Ƿ�ϵ磺"); 
    LCD_ShowString(240,350,200,16,16,"�����⣺");    
    LCD_ShowString(240,425,200,16,16,"ȱ���⣺");
	LCD_ShowString(240,500,200,16,16,"��ߵ�ѹ��"); 
    LCD_ShowString(240,575,200,16,16,"��͵�ѹ��");  
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);
	
	LCD_ShowString(25,25,200,16,16,"������һ��");  
    LCD_DrawRectangle(20,20,80,40); 
	
    current_screen = 20;
}

void UI_200(void) {
    LCD_Clear(WHITE);
    LCD_ShowString(240,275,200,16,16,"��������"); 
    LCD_ShowString(240,350,200,16,16,"Future��");    
    LCD_ShowString(240,425,200,16,16,"���ߣ�");
	LCD_ShowString(240,500,200,16,16,"�η�"); 
    LCD_ShowString(240,575,200,16,16,"���ֻ�");    
    LCD_ShowString(240,650,200,16,16,"ˮ��");
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);   
    LCD_DrawRectangle(130,625,350,675);
	
    current_screen = 40;
}

void UI_300(void) {
    LCD_Clear(WHITE);

    LCD_ShowString(240,275,200,16,16,"��ǰ�¶ȣ�"); 
    LCD_ShowString(240,350,200,16,16,"Ŀ���¶ȣ�");    
    LCD_ShowString(240,425,200,16,16,"�¶����ߣ�");
	LCD_ShowString(240,500,200,16,16,"�¶�У׼��"); 
    LCD_ShowString(240,575,200,16,16,"���ƫ��");    
    LCD_ShowString(240,650,200,16,16,"���ƫ��");
    LCD_DrawRectangle(130,250,350,300);   
    LCD_DrawRectangle(130,325,350,375);   
    LCD_DrawRectangle(130,400,350,450);
	LCD_DrawRectangle(130,475,350,525);   
    LCD_DrawRectangle(130,550,350,600);   
    LCD_DrawRectangle(130,625,350,675);
	
    current_screen = 60;
}

void UI_TouchHandler(u16 x, u16 y){
	
LCD_GetCursor(&x, &y);

    if (current_screen == 0) {  
      
        if (x > 130 && x < 350 && y > 250 && y < 300) {
            current_screen = 20;
            UI_100();
        } 
        else if (x > 130 && x < 350 && y > 325 && y < 375) {
            current_screen = 40;
            UI_200();
        } 
        else if (x > 130 && x < 350 && y > 400 && y < 450) {
            current_screen = 60;
            UI_300();
        }
    } 
    else {
     
        if (x < 80 && y < 80) {
            UI_Main(); 
        }
    }





}

void UI_Init(void) {
    current_screen = 0;
    LCD_Clear(WHITE);
	UI_Main();
}