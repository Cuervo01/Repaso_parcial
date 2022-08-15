#include <Arduino.h>
#include "task3.h"


void task3(){
    enum class Task3States{
        INIT,
        WAIT_TO_TOGGLE_LED
    };
    static Task3States Task3State = Task3States::INIT;
    static uint32_t lasTime;
    static constexpr uint32_t INTERVAL = 50;
    static constexpr uint8_t ledRed = 5;
    static bool ledStatus = false;

    switch(Task3State){
        case Task3States::INIT:{
            pinMode(ledRed,OUTPUT);
            lasTime = millis();
            Task3State = Task3States::WAIT_TO_TOGGLE_LED;
            break;
        }

        case Task3States::WAIT_TO_TOGGLE_LED:{
            // evento 1:
            uint32_t currentTime = millis();
            if( (currentTime - lasTime) >= INTERVAL ){
                lasTime = currentTime;
                digitalWrite(ledRed,ledStatus);
                ledStatus = !ledStatus;
            }
            break;
        }

        default:{
            break;
        }
    }

}