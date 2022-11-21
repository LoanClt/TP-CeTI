#include "mbed.h"
AnalogIn analog_in(A0);
DigitalOut led(LED1);
DigitalIn bouton(D7);

int main()
{
    double meas, tension;
    while(1) {
        if (bouton == 1){
            printf("Ca marche bien");
            wait_us(200000);
        }
        meas = analog_in.read(); // Convertit et lit la tension d'entée analogique (valeur entre 0.0 et 1.0)
        tension = meas * 3.3; // Change la valeur pour être entre 0.0 et 3.3 (qui correspond à 3.3V)
        if (tension > 0.5) { // Si la valeur est supérieure à 0.5V, alors on allume la LED
            led = 1;
        } else {          // Sinon on l'éteint
            led = 0;
        }
        double meas_int = analog_in.read_u16();  // sur 12 bits MSB
        //printf("Tension = %d \r\n", meas_int);
        tension = meas_int / 65536.0 * 3.3;     // en V
        printf("Tension = %lf V \r\n", tension);
        wait_us(2000000);
    }
}
