#include <stdio.h>
#include <stdlib.h>

void retiraItem( int *vetor, int indice, int tam) {
	
	int i;

	// Inicia o laço no indice do número a ser removido
	// E vai até o fim do vetor ( já decrementado em 1 )
	for( i = indice; i < tam; i++ )
    	*( vetor + i) = *( vetor + i + 1); // Move os números 1 posição atras
	
	vetor = (int *) realloc(vetor, tam * sizeof(int)); // Realoca a memoria com o novo tamanho.

}

int main() {

	int tam, i, j;
	int *vetor;


	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &tam);

	vetor = (int *) malloc( tam * sizeof( int ) ); // Aloca a memoria para receber os números no vetor

	for( i = 0; i < tam ; i++ ) { // Recebe os números
		scanf("%d", vetor+i);
	} 

	/** Percorre todo o vetor **/
	for( i = 0; i < tam; i++ ) { 

		j = i+1;
		while( j < tam ) {
			if( *(vetor + j) == *(vetor + i) ) { // Verifica se os valores são iguais
                tam--; // Se for diminui o tamanho em 1.
                retiraItem(vetor, j, tam); // Chama a função para remover o item repitido e diminuir o vetor
                // E segue para a próxima verificação sem incrementar o J, pois a função retiraItem,
                // Move os outros valores para a posição do número removido, logo a a mesma posição
                // tem que ser verificada novamente.
            } else {
                j++; // Se não for igual incrementa o J e vai para o próximo número
            }
		}
    }

    /* Imprime o vetor sem os numero repetidos */
	printf("Vetor sem repetidos\n");
	for( int i = 0; i < tam ; i++ ) {
		printf("%d ", *(vetor+i));
	} 

	/* desaloca memoria */
	free(vetor);
	return 0;
}
