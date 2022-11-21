#include "mbed.h"
AnalogIn analog_in(A0);
DigitalIn bouton(D7);

int main()
{
    int dim =  100; //Nombre de mesures réalisées
    int cpt = 0;
    double tension;
    double tableau[dim];
    bool fin = true;
    double somme = 0;
    double moyenne;
    double n = dim;
    bool faireLaMesure = false;

    while(!faireLaMesure){
        printf("En attente de lancer la mesure ... Appuyer sur le bouton\n");
        if (bouton == 1) { faireLaMesure = true; printf("Mesure commencee\n");}
        wait_us(2000000);
    }
    while (faireLaMesure){
        if (cpt < dim) { // Le bouton est pressé
            tableau[cpt] = analog_in.read();
            cpt += 1;
            printf("Mesure * %d * effectuee: * %lf *\n", cpt, tableau[cpt]);
            wait_us(50000);
        }
        if (cpt == dim && fin){
            printf("Fin de la mesure, faire la moyenne ...\n");
            fin = false;
            for (int i = 0; i < dim; i++){
                somme += tableau[i];
            }
            moyenne = somme/n;
            printf("");
            printf("Voici la moyenne des %d valeurs mesures : %lf", dim, moyenne);
        }   
    }
}

//pb: Mesure * 95 * effectuee: * -9223372036854775808.000000 *
