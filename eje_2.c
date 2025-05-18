#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define long_max 300

int main() {
	FILE *archivo = fopen("input.txt", "r" );
	if (archivo == NULL) {
		printf("Error: No se pudo abrir el archivo input.txt");
		return 1;
	}

	char palabra[long_max];
	char palabra_limpia[long_max];
	char *polindromo_larg = NULL;

	while (fscanf(archivo, "%259s", palabra) == 1) {
		int j = 0;
		for (int i = 0; palabra[i] != '\0'; i++) {
			if (isalnum((unsigned char)palabra[i])) {
				palabra_limpia[j] = tolower((unsigned char)palabra[i]);
				j++;
			}
		}
		palabra_limpia[j] = '\0';

		int polindromo = 1;
		int len = strlen(palabra_limpia);
		for (int i = 0; i < len / 2; i++){
			if (palabra_limpia[i] != palabra_limpia[len - 1 -i]) {
				polindromo = 0;
				break;
			}
		}

		if (polindromo && len > 0) {
			if (polindromo_larg == NULL || len > strlen(polindromo_larg)) {
				if (polindromo_larg != NULL) {
					free(polindromo_larg);
				}

				polindromo_larg = (char *) malloc((len + 1) * sizeof(char));
				strcpy(polindromo_larg, palabra_limpia);
			
			}
		}
	}
	fclose(archivo);

	if (polindromo_larg != NULL) {
		printf("Polindromo mas largo: %s\n", polindromo_larg);
		free(polindromo_larg);
	} else {
		printf("No se encuentran polindromos.\n");
	}
	return 0;
}

		    








