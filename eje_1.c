#include <stdio.h>
#include <stdlib.h>

int *crearmatriz(int size) {
	return (int *)malloc(size * size * sizeof(int));
}
	

void llenar_matriz (int *matriz, int size) {
	for (int i = 0; i < size * size; i ++) {
		*(matriz + i) = rand() % 2;
	}
}

void imprimir_matriz(int *matriz, int size) {
	printf("Matriz generada: \n");
	for (int i = 0; i < size * size; i ++) {
		printf("%d", *(matriz + i));
		if ((i + 1) % size == 0) printf("\n");
	}
}


int secuenciaunosmax(int *matriz, int size) {
	int actual = 0; int max = 0;

	for (int i = 0; i < size *size; i ++) {
		if (*(matriz + i) == 1) {
			actual++;
		if (actual > max)
			max = actual;
		} else {
			actual = 0;
		}
	}
	return max;
}



int main() {
	int size;
	printf("Ingresar tamano de matriz:");
	scanf("%d", &size);

	int *matriz = crearmatriz(size);
	if (matriz == NULL) {
		printf("Error al reservar memoria.\n");
		return 1;
	}

	llenar_matriz(matriz, size);
	imprimir_matriz(matriz, size);

	int resultado = secuenciaunosmax(matriz, size);
	printf("La mayor secuencia de unos es: %d\n", resultado);

	free(matriz);
	return 0;
}

