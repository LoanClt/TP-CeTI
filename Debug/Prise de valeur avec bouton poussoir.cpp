#include "mbed.h"
AnalogIn analog_in(A0);
DigitalIn bouton(D7);

int main()
{
    int dim =  100; //Nombre de mesures réalisées
    int cpt = 0;
    double tension;
    double tableau[dim];

    while(1){
        if (bouton == 1){
            printf("bouton presse\n");
        }
        if (bouton == 1 && cpt < dim) { // Le bouton est pressé
            tableau[cpt] = analog_in.read();
            cpt += 1;
            printf("Mesure * %d * effectuee\n", cpt);
            wait_us(2000000);
        }
        if (cpt == dim){
            printf("Fin de la mesure, faire la moyenne ...\n");
        }
    }
}
