#include <stdio.h>
#include <stdlib.h>

// Esta função gera um número aleatório entre 1 e 10.
int gerarNumerosAleatorios()
{
    return rand() % 10 + 1;
}
// Esta função realiza o algoritmo de insertion sort.
void insertionSort(int vetor[], int tamanho)
{
    int posicao, elemento, aux; // Variáveis para controle.

    // Loop principal que começa do segundo elemento até o último.
    for (posicao = 1; posicao < tamanho; posicao++)
    {
        aux = vetor[posicao];   // Armazena o valor atual.
        elemento = posicao - 1; // Inicia a comparação com o elemento anterior.

        // Move os elementos maiores que 'aux' uma posição à frente.
        while (elemento >= 0 && vetor[elemento] > aux)
        {
            vetor[elemento + 1] = vetor[elemento]; // Desloca o elemento.
            elemento = elemento - 1;               // Move para o próximo elemento para comparação.
        }

        // Insere o valor 'aux' na posição correta.
        vetor[elemento + 1] = aux;
    }
}

// Função principal que executa o programa.
int main()
{
    int tamanho;

    // Solicita ao usuário o tamanho do vetor.
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Aloca memória para o vetor de acordo com o tamanho informado.
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Preenche o vetor com números aleatórios.
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = gerarNumerosAleatorios();
    }

    // Exibe o vetor original.
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d ", vetor[i]);
    }

    // Chama a função de ordenação.
    insertionSort(vetor, tamanho);

    // Exibe o vetor ordenado.
    printf("\nVetor Ordenado: \n");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d ", vetor[i]);
    }

    // Libera a memória alocada para o vetor.
    free(vetor);

    return 0;
}
