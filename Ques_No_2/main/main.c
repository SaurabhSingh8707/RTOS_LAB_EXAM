#include<stdio.h>
#include<driver/gpio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>
TimerHandle_t motor_timer_handle;
void TurnMotoroff(TimerHandle_t xTimer)
{
    printf("Turning off motor\n");
}
void sensor_task(void *pv)
 {
   while(1){
   printf("sensor_task\n");
   vTaskDelay(1000 /portTICK_PERIOD_MS);
 }
 }
 void pressure_task(void *pv)
 {
   while(1){
   printf("pressure_task\n");
   vTaskDelay(2000 /portTICK_PERIOD_MS);
 }
 }
 void processing_task(void *pv)
 {
     motor_timer_handle=xTimerCreate("motoroff",pdMS_TO_TICKS(5000),pdTRUE,NULL,TurnMotoroff);
     xTimerStart(motor_timer_handle,0);
 }
 }
 void app_main()
 {
    xTaskCreate(sensor_task,"sensor_task",2048,NULL,5,NULL);
    xTaskCreate(pressure_task,"pressure_task",2048,NULL,6,NULL);
    xTaskCreate(processing_task,"processing_task",2048,NULL,7,NULL);
    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(10000));
    }