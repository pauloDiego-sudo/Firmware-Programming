#include <stdio.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <string.h>
#include <u8g2.h>

#include "sdkconfig.h"
#include "u8g2_esp32_hal.h"

// CLK - GPIO 18
#define PIN_CLK 18

// MOSI - GPIO 23
#define PIN_MOSI 23

// RESET - GPIO 22
#define PIN_RESET 22

// DC - GPIO -1
#define PIN_DC U8G2_ESP32_HAL_UNDEFINED

// CS - GPIO 05
#define PIN_CS 05
static char tag[] = "test_SST7920";
void app_main(void)
{
  u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
  u8g2_esp32_hal.bus.spi.clk = PIN_CLK;
  u8g2_esp32_hal.bus.spi.mosi = PIN_MOSI;
  u8g2_esp32_hal.bus.spi.cs = PIN_CS;
  u8g2_esp32_hal.dc = PIN_DC;
  u8g2_esp32_hal.reset = PIN_RESET;
  u8g2_esp32_hal_init(u8g2_esp32_hal);

  u8g2_t u8g2;  // a structure which will contain all the data for one display
  vTaskDelay(2000 / portTICK_PERIOD_MS);
    u8g2_Setup_st7920_128x64_f(
        &u8g2,
        U8G2_R0,
        u8g2_esp32_spi_byte_cb,
        u8g2_esp32_gpio_and_delay_cb);  // init u8g2 structure




    u8g2_esp32_hal_init(u8g2_esp32_hal);



    

  u8g2_InitDisplay(&u8g2);  // send init sequence to the display, display is in
                            // sleep mode after this,

  u8g2_SetPowerSave(&u8g2, 0);  // wake up display
  u8g2_ClearBuffer(&u8g2);
  u8g2_DrawBox(&u8g2, 10, 20, 20, 30);
  u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
  u8g2_DrawStr(&u8g2, 0, 15, "Hello World!");
  u8g2_SendBuffer(&u8g2);

  ESP_LOGI(tag, "All done!");
}


// #include <driver/gpio.h>
// #include <driver/spi_master.h>
// #include <esp_log.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <stdio.h>
// #include <string.h>
// #include <u8g2.h>

// #include "sdkconfig.h"
// #include "u8g2_esp32_hal.h"

// // CLK - GPIO14
// #define PIN_CLK 14

// // MOSI - GPIO 13
// #define PIN_MOSI 13

// // RESET - GPIO 26
// #define PIN_RESET 26

// // DC - GPIO 27
// #define PIN_DC 27

// // CS - GPIO 15
// #define PIN_CS 15

// static const char* TAG = "ssd1306_spi";

// u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
// u8g2_t u8g2;

// void init_display() {
//     // Configuração do Hardware para SPI
//     u8g2_esp32_hal.bus.spi.clk = PIN_CLK;
//     u8g2_esp32_hal.bus.spi.mosi = PIN_MOSI;
//     u8g2_esp32_hal.bus.spi.cs = PIN_CS;
//     u8g2_esp32_hal.dc = PIN_DC;
//     u8g2_esp32_hal.reset = PIN_RESET;
//     u8g2_esp32_hal_init(u8g2_esp32_hal);

//     u8g2_Setup_ssd1306_128x64_noname_f(
//         &u8g2, U8G2_R0,
//         u8g2_esp32_spi_byte_cb,
//         u8g2_esp32_gpio_and_delay_cb);

//     ESP_LOGI(TAG, "u8g2_InitDisplay");
//     u8g2_InitDisplay(&u8g2); // Envia sequência de inicialização para o display

//     ESP_LOGI(TAG, "u8g2_SetPowerSave");
//     u8g2_SetPowerSave(&u8g2, 0); // Acorda o display
//     ESP_LOGI(TAG, "u8g2_ClearBuffer");
//     u8g2_ClearBuffer(&u8g2);
// }

// void app_main(void)
// {
//     init_display();

//     ESP_LOGI(TAG, "u8g2_DrawBox");
//     u8g2_DrawBox(&u8g2, 0, 26, 80, 6);
//     u8g2_DrawFrame(&u8g2, 0, 26, 100, 6);

//     ESP_LOGI(TAG, "u8g2_SetFont");
//     u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
//     ESP_LOGI(TAG, "u8g2_DrawStr");
//     u8g2_DrawStr(&u8g2, 2, 17, "Hi nkolban!");
//     ESP_LOGI(TAG, "u8g2_SendBuffer");
//     u8g2_SendBuffer(&u8g2);

//     ESP_LOGI(TAG, "All done!");
// }


// #include <driver/gpio.h>
// #include <driver/spi_master.h>
// #include <esp_log.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <stdio.h>
// #include <string.h>
// #include <u8g2.h>

// #include "sdkconfig.h"
// #include "u8g2_esp32_hal.h"

// // CLK - GPIO14
// #define PIN_CLK 14

// // MOSI - GPIO 13
// #define PIN_MOSI 13

// // RESET - GPIO 26
// #define PIN_RESET 26

// // DC - GPIO 27
// #define PIN_DC 27

// // CS - GPIO 15
// #define PIN_CS 15
// static char tag[] = "test_SSD1306";

// void task_test_SSD1306(void* ignore) {
//   u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
//   u8g2_esp32_hal.bus.spi.clk = PIN_CLK;
//   u8g2_esp32_hal.bus.spi.mosi = PIN_MOSI;
//   u8g2_esp32_hal.bus.spi.cs = PIN_CS;
//   u8g2_esp32_hal.dc = PIN_DC;
//   u8g2_esp32_hal.reset = PIN_RESET;
//   u8g2_esp32_hal_init(u8g2_esp32_hal);

//   u8g2_t u8g2;  // a structure which will contain all the data for one display
//   u8g2_Setup_ssd1306_128x64_noname_f(
//       &u8g2, U8G2_R0, u8g2_esp32_spi_byte_cb,
//       u8g2_esp32_gpio_and_delay_cb);  // init u8g2 structure

//   u8g2_InitDisplay(&u8g2);  // send init sequence to the display, display is in
//                             // sleep mode after this,

//   u8g2_SetPowerSave(&u8g2, 0);  // wake up display
//   u8g2_ClearBuffer(&u8g2);
//   u8g2_DrawBox(&u8g2, 10, 20, 20, 30);
//   u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
//   u8g2_DrawStr(&u8g2, 0, 15, "Hello World!");
//   u8g2_SendBuffer(&u8g2);

//   ESP_LOGD(tag, "All done!");

//   vTaskDelete(NULL);
// }

// void app_main() {
//     xTaskCreate(&task_test_SSD1306, "test_SSD1306", 2048, NULL, 5, NULL);
// }

// #include <driver/gpio.h>
// #include <driver/spi_master.h>
// #include <esp_log.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <stdio.h>
// #include <string.h>
// #include <u8g2.h>

// #include "sdkconfig.h"
// #include "u8g2_esp32_hal.h"

// // SDA - GPIO21
// #define PIN_SDA 21

// // SCL - GPIO22
// #define PIN_SCL 22

// static const char* TAG = "ssd1306";

// u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
// u8g2_t u8g2;

// void init_display() {
//   u8g2_esp32_hal.bus.i2c.sda = PIN_SDA;
//   u8g2_esp32_hal.bus.i2c.scl = PIN_SCL;
//   u8g2_esp32_hal_init(&u8g2_esp32_hal);

//     u8g2_Setup_ssd1306_128x64_noname_f(
//         &u8g2, U8G2_R0,
//         u8g2_esp32_spi_byte_cb,
//         u8g2_esp32_gpio_and_delay_cb);
        
//   u8x8_SetI2CAddress(&u8g2.u8x8, 0x78);

//   ESP_LOGI(TAG, "u8g2_InitDisplay");
//   u8g2_InitDisplay(&u8g2);  // send init sequence to the display, display is in
//                             // sleep mode after this,

//   ESP_LOGI(TAG, "u8g2_SetPowerSave");
//   u8g2_SetPowerSave(&u8g2, 0);  // wake up display
//   ESP_LOGI(TAG, "u8g2_ClearBuffer");
//   u8g2_ClearBuffer(&u8g2);
// }


// void app_main(void)
// {
//   init_display();

//   ESP_LOGI(TAG, "u8g2_DrawBox");
//   u8g2_DrawBox(&u8g2, 0, 26, 80, 6);
//   u8g2_DrawFrame(&u8g2, 0, 26, 100, 6);

//   ESP_LOGI(TAG, "u8g2_SetFont");
//   u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
//   ESP_LOGI(TAG, "u8g2_DrawStr");
//   u8g2_DrawStr(&u8g2, 2, 17, "Hi nkolban!");
//   ESP_LOGI(TAG, "u8g2_SendBuffer");
//   u8g2_SendBuffer(&u8g2);

//   ESP_LOGI(TAG, "All done!");
// }