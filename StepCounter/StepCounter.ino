#include <Arduino.h>
#include "LCD_Test.h"
UWORD Imagesize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;// set the screen size 
UWORD *BlackImage;//declares a pointer
CST816S touch(6, 7, 13, 5);	// sda, scl, rst, irq <- these are the corresponding pins

// const float conversion_factor = 3.3f / (1 << 12) * 3;

void setup() {
  Serial.begin(115200);
  
  touch.begin();//initializes touch input 
  
  // PSRAM Initialize-> pseudo static random access Memory 
  if(psramInit()){
    Serial.println("\nPSRAM is correctly initialized");
  }else{
    Serial.println("PSRAM not available");
  }
  
  if ((BlackImage = (UWORD *)ps_malloc(Imagesize)) == NULL){//Memory Allocation for black image 
      Serial.println("Failed to apply for black memory...");
      exit(0);
  }
  // put your setup code here, to run once:
  if (DEV_Module_Init() != 0)//initializes GPIO pins 
    Serial.println("GPIO Init Fail!");
  else
    Serial.println("GPIO Init successful!");
    // LCD_1IN28_Init(HORIZONTAL);//initializes lcd 
    // LCD_1IN28_Clear(WHITE);  //clears the lcd screen and fills it with white color 
    // // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    // Paint_NewImage((UBYTE *)BlackImage, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);//create a buffer and fill it with white color 
    // Paint_SetScale(65);//set the drawing scale factor to 65% of the original 
    // Paint_SetRotate(ROTATE_0);//sets the rotation angle of the drawing 0 degrees 
    // // Paint_Clear(WHITE);//clear the drawing context sets it to white
    // /* GUI */
    // Serial.println("drawing...\r\n");
    // delay(2000);//delay 2 seconds 
    // LCD_1IN28_Clear(RED);
    // delay(2000);
    // LCD_1IN28_Clear(GREEN);
    // delay(2000);
    // LCD_1IN28_Clear(BLUE);
    // delay(2000);
#if 1
  float acc[3], gyro[3];
  unsigned int tim_count = 0;
  uint16_t result;

  QMI8658_init();

  // Paint_Clear(WHITE);
  // Paint_DrawRectangle(0, 00, 240, 47, 0XF410, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  // Paint_DrawRectangle(0, 47, 240, 120, 0X4F30, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  // Paint_DrawRectangle(0, 120, 240, 195, 0XAD55, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  // Paint_DrawRectangle(0, 195, 240, 240, 0X2595, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  // //todo get it to print out the values its equal to
  // Paint_DrawString_EN(45, 30, "LongPress Quit", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 50, "ACC_X = ", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 75, "ACC_Y = ", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 100, "ACC_Z = ", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 125, "GYR_X = ", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 150, "GYR_Y = ", &Font16, WHITE, BLACK);
  // Paint_DrawString_EN(45, 175, "GYR_Z = ", &Font16, WHITE, BLACK);
  // // Paint_DrawString_EN(45, 200, "BAT(V)=", &Font16, WHITE, BLACK);
  // LCD_1IN28_Display(BlackImage);

  while (true)
  {
    result = DEC_ADC_Read();
    QMI8658_read_xyz(acc, gyro, &tim_count);
    Serial.println("ACC_X = " );
    Serial.println(acc[0]);
    Serial.println("ACC_Y = " );
    Serial.println(acc[1]);
    Serial.println("ACC_Z = " );
    Serial.println(acc[2]);
    Serial.println("GYR_X = " );
    Serial.println(gyro[0]);
    Serial.println("GYR_Y = " );
    Serial.println(gyro[1]);
    Serial.println("GYR_Z = " );
    Serial.println(gyro[2]);
    
    // Paint_Clear(WHITE);
    // Paint_DrawRectangle(120, 47,  220, 120, 0X4F30, DOT_PIXEL_2X2, DRAW_FILL_FULL);
    // Paint_DrawRectangle(120, 120, 220, 195, 0XAD55, DOT_PIXEL_2X2, DRAW_FILL_FULL);
    // Paint_DrawRectangle(120, 195, 220, 240, 0X2595, DOT_PIXEL_2X2, DRAW_FILL_FULL);
    // Paint_DrawNum(120, 50, acc[0], &Font16, 2, BLACK, WHITE);
    // Paint_DrawNum(120, 75, acc[1], &Font16, 2, BLACK, WHITE);
    // Paint_DrawNum(120, 100, acc[2], &Font16, 2, BLACK, WHITE);
    // Paint_DrawNum(120, 125, gyro[0], &Font16, 2, BLACK, WHITE);
    // Paint_DrawNum(120, 150, gyro[1], &Font16, 2, BLACK, WHITE);
    // Paint_DrawNum(120, 175, gyro[2], &Font16, 2, BLACK, WHITE);
    // // Paint_DrawNum(130, 200, result * conversion_factor, &Font16, 2, BLACK, WHITE);
    // LCD_1IN28_DisplayWindows(120, 50, 210, 200, BlackImage);
    // LCD_1IN28_DisplayWindows(130, 200, 220, 220, BlackImage);
    // if (touch.available()){
    //   if(touch.data.y<45){
    //     break;
    //   }
    // }
  }
#endif
}

void loop() {
}
