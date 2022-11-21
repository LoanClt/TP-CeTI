#include "mbed.h"
AnalogIn analog_in(A0);
DigitalIn bouton(D7);
DigitalOut test_ticker(D1);
Ticker T;
void toggle_ticker(void);    // Déclaration de la fonction d'interruption du ticker
int meas_int;
double tension;


int main() {
    printf("Hello World !\n");
    T.attach(&toggle_ticker, 1);
    while (1) {
    // Boucle Infinie
    }
}

void toggle_ticker() { 
    test_ticker=1;
    meas_int = analog_in.read_u16();  // sur 12 bits MSB
    tension = meas_int / 65536.0 * 3.3;     // en V
    printf("Tension = %lf V \r\n", tension);
    printf("Hello World !\n");
}
