#include <stdio.h>

struct Jugador {
    int monedas;
    int vidas;
};

int calcularCosto(int cantidadVidas) {
    return cantidadVidas * 20;
}

int pagarCompra(int *saldo, int costo) {
    if (*saldo > costo) {
        *saldo = *saldo - costo;
        return 1;
    }

    return 0;
}

int main(void) {
    struct Jugador jugador = {20, 2};
    int costo = calcularCosto(1);

    printf("Saldo inicial: %d monedas\n", jugador.monedas);
    printf("Costo de una vida: %d monedas\n", costo);

    int pagoAceptado = pagarCompra(&jugador.monedas, costo);

    if (pagoAceptado == 1) {
        jugador.vidas = jugador.vidas + 1;
        printf("Compra aceptada. Recibiste una vida extra.\n");
    } else {
        printf("Monedas insuficientes.\n");
    }

    printf("Saldo final: %d monedas\n", jugador.monedas);
    printf("Vidas: %d\n", jugador.vidas);

    return 0;
}
// Función para calcular costo.