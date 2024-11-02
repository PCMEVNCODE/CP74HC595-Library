#ifndef CP74HC595_H
#define CP74HC595_H

#include <Arduino.h>

class CP74HC595 {
    private:
        int8_t dataPin;          // DS
        int8_t clockPin;         // SH_CP
        int8_t latchPin;         // ST_CP
        uint8_t pinCount;        // Số lượng chân đang điều khiển
        uint8_t pinStates[100];  // Mảng tĩnh lưu trạng thái của các chân, tối đa 100 chân

    public:
        // Constructor để khởi tạo các chân và số lượng chân
        CP74HC595(int8_t DS, int8_t SH_CP, int8_t ST_CP, uint8_t numPins)
            : dataPin(DS), clockPin(SH_CP), latchPin(ST_CP), pinCount(numPins) {
            pinMode(dataPin, OUTPUT);
            pinMode(clockPin, OUTPUT);
            pinMode(latchPin, OUTPUT);
            // Đặt tất cả trạng thái của các chân thành LOW ban đầu
            for (uint8_t i = 0; i < pinCount && i < 100; i++) {
                pinStates[i] = LOW;
            }
        }
        
        // Hàm để điều khiển các chân, pin là chỉ số chân và state là trạng thái (HIGH/LOW)
        void setPin(uint8_t pin, bool state) {
            if (pin < pinCount) { // Kiểm tra nếu chỉ số chân hợp lệ
                pinStates[pin] = state;  // Cập nhật trạng thái chân
                updateShiftRegister();
            }
        }

    private:
        // Hàm để gửi dữ liệu đến các IC 74HC595
        void updateShiftRegister() {
            digitalWrite(latchPin, LOW); // Bắt đầu ghi dữ liệu

            // Gửi dữ liệu từng byte đến 74HC595, từ byte cuối đến byte đầu
            for (int i = (pinCount - 1) / 8; i >= 0; i--) {
                uint8_t byteToSend = 0;
                for (int bit = 0; bit < 8; bit++) {
                    int pinIndex = i * 8 + bit;
                    if (pinIndex < pinCount && pinStates[pinIndex]) {
                        byteToSend |= (1 << bit);
                    }
                }
                shiftOut(dataPin, clockPin, MSBFIRST, byteToSend);
            }

            digitalWrite(latchPin, HIGH); // Kết thúc ghi dữ liệu
        }
};

#endif
