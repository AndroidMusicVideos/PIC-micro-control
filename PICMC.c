#include <xc.h>
#define _XTAL_FREQ 20000000

// Set up the configuration bits
#pragma config FOSC = HS // High-speed oscillator
#pragma config WDTE = OFF // Watchdog timer disabled
#pragma config PWRTE = ON // Power-up timer enabled
#pragma config MCLRE = OFF // MCLR pin function is digital input
#pragma config CP = OFF // No code protection
#pragma config CPD = OFF // Data memory code protection off
#pragma config BOREN = OFF // Brown-out reset disabled
#pragma config CLKOUTEN = OFF // CLKOUT function is disabled
#pragma config IESO = OFF // Internal/External Switchover mode is disabled
#pragma config FCMEN = OFF // Fail-Safe Clock Monitor is disabled

// Define the servo control pin
#define SERVO RB0

void delay_ms(unsigned int t) {
    for (unsigned int i = 0; i < t; i++) {
        __delay_ms(1);
    }
}

void set_servo_position(unsigned int position) {
    // Calculate the number of milliseconds to wait for the servo to reach the desired position
    unsigned int wait_time = (position * 10) + 600;

    SERVO = 1; // Set the servo control pin high
    delay_ms(wait_time); // Wait for the desired amount of time
    SERVO = 0; // Set the servo control pin low
}

void main(void) {
    TRISB = 0x00; // Set all PORTB pins as outputs
    while (1) {
        // Move the servo to 0 degrees
        set_servo_position(0);
        delay_ms(1000); // Wait 1 second

        // Move the servo to 180 degrees
        set_servo_position(180);
        delay_ms(1000); // Wait 1 second
    }
}
