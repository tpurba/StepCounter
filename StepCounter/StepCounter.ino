
void setup() {
  Serial.begin(115200);
  QMI8658_init();//uses the QMI8658.cpp given in test code from Waveshare
  Paint_Clear(WHITE);
  Paint_DrawRectangle(0, 00, 240, 47, 0XF410, DOT_PIXEL_2X2, DRAW_FILL_FULL);
      Paint_DrawRectangle(0, 47, 240, 120, 0X4F30, DOT_PIXEL_2X2, DRAW_FILL_FULL);
      Paint_DrawRectangle(0, 120, 240, 195, 0XAD55, DOT_PIXEL_2X2, DRAW_FILL_FULL);
      Paint_DrawRectangle(0, 195, 240, 240, 0X2595, DOT_PIXEL_2X2, DRAW_FILL_FULL);
      //todo get it to print out the values its equal to
      Paint_DrawString_EN(45, 30, "LongPress Quit", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 50, "ACC_X = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 75, "ACC_Y = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 100, "ACC_Z = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 125, "GYR_X = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 150, "GYR_Y = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 175, "GYR_Z = ", &Font16, WHITE, BLACK);
      Paint_DrawString_EN(45, 200, "BAT(V)=", &Font16, WHITE, BLACK);
      LCD_1IN28_Display(BlackImage);
}

void loop() {
  result = DEC_ADC_Read();
  QMI8658_read_xyz(acc, gyro, &tim_count);
  Serial.println("ACC: " );
  Serial.println(acc[0]);
  Serial.println("gyro: " );
  Serial.println(gyro[0]);
  
  Paint_Clear(WHITE);
  Paint_DrawRectangle(120, 47,  220, 120, 0X4F30, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  Paint_DrawRectangle(120, 120, 220, 195, 0XAD55, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  Paint_DrawRectangle(120, 195, 220, 240, 0X2595, DOT_PIXEL_2X2, DRAW_FILL_FULL);
  Paint_DrawNum(120, 50, acc[0], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(120, 75, acc[1], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(120, 100, acc[2], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(120, 125, gyro[0], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(120, 150, gyro[1], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(120, 175, gyro[2], &Font16, 2, BLACK, WHITE);
  Paint_DrawNum(130, 200, result * conversion_factor, &Font16, 2, BLACK, WHITE);
  LCD_1IN28_DisplayWindows(120, 50, 210, 200, BlackImage);
  LCD_1IN28_DisplayWindows(130, 200, 220, 220, BlackImage);
}
