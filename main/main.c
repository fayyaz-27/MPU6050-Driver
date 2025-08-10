// File: MPU6050 Main Code
// Author: Fayyaz Shaikh
// Email ID: fayyaz.shaikh24@spit.ac.in
// LinkedIn: https://www.linkedin.com/in/fayyaz-shaikh-7646312a3/


#include<stdio.h>
#include "esp_system.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#include "my_6050_driver.h"

#define TAG "MPU6050"

void app_main(){

    esp_err_t status;
    
    status = my_mpu6050_init();
    if (status != ESP_OK){
        ESP_LOGE(TAG, "MPU6050 initialization failed with error code: %d", status);
    }
    else {
        ESP_LOGI(TAG, "MPU6050 initialization successful with code: %d", status);
    }

    uint8_t who_am_i = my_mpu6050_who_am_i();
    ESP_LOGI(TAG, "WHO AM I Register Value: 0x%02X", who_am_i);

    while(1){
        float acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z, temp;

        mpu6050_read_acceleration(&acc_x, &acc_y, &acc_z);
        mpu6050_read_gyroscope(&gyro_x, &gyro_y, &gyro_z);
        mpu6050_read_temperature(&temp);

        ESP_LOGI(TAG, "Acceleration:-  X-Axis: %.2f, Y-Axis: %.2f, Z-Axis: %.2f", acc_x, acc_y, acc_z);
        ESP_LOGI(TAG, "Gyroscope:- X-Axis: %.2f, Y-Axis: %.2f, Z-Axis: %.2f", gyro_x, gyro_y, gyro_z);
        ESP_LOGI(TAG, "Temperature:- %.2f", temp);

        vTaskDelay(pdMS_TO_TICKS(100));
    }

}