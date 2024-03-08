#include <stdio.h>

// Definir las tasas de conversión
#define GTQ_TO_USD 0.13
#define GTQ_TO_EUR 0.11
#define USD_TO_GTQ 7.71
#define EUR_TO_GTQ 9.16

int main() {
    // Variables para almacenar la cantidad y la opción de moneda
    float amount, converted_amount;
    int choice_from, choice_to;

    // Mostrar las opciones de moneda al usuario
    printf("Seleccione la moneda de origen:\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares estadounidenses (USD)\n");
    printf("3. Euros (EUR)\n");
    scanf("%d", &choice_from);

    printf("Seleccione la moneda de destino:\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares estadounidenses (USD)\n");
    printf("3. Euros (EUR)\n");
    scanf("%d", &choice_to);

    // Solicitar al usuario el monto a convertir
    printf("Ingrese el monto a convertir: ");
    scanf("%f", &amount);

    // Realizar la conversión según las opciones seleccionadas
    switch (choice_from) {
        case 1: // Convertir desde quetzales
            if (choice_to == 2)
                converted_amount = amount * GTQ_TO_USD;
            else if (choice_to == 3)
                converted_amount = amount * GTQ_TO_EUR;
            else
                converted_amount = amount; // La conversión es de GTQ a GTQ
            break;
        case 2: // Convertir desde dólares estadounidenses
            if (choice_to == 1)
                converted_amount = amount * USD_TO_GTQ;
            else if (choice_to == 3)
                converted_amount = amount / (1 / GTQ_TO_EUR);
            else
                converted_amount = amount; // La conversión es de USD a USD
            break;
        case 3: // Convertir desde euros
            if (choice_to == 1)
                converted_amount = amount * EUR_TO_GTQ;
            else if (choice_to == 2)
                converted_amount = amount / GTQ_TO_EUR;
            else
                converted_amount = amount; // La conversión es de EUR a EUR
            break;
        default:
            printf("Opción no válida.\n");
            return 1;
    }

    // Mostrar el resultado de la conversión
    printf("El monto convertido es: %.2f\n", converted_amount);

    return 0;
}