#include <stdio.h>
#include <string.h>
#include <locale.h>

#define VETOR_MAX 10
#define TAM_MAX 50

void addCarros(char carros[VETOR_MAX][TAM_MAX],int anos[VETOR_MAX],int precos[VETOR_MAX]){

    int qtdCarros,qtdCarrosAdd;
    qtdCarrosAdd = 0;
    printf("Quantidade de carros a serem adicionados: ");
    scanf("%d", &qtdCarros);

    for(int i = 0; i < VETOR_MAX; i++){
        if(anos[i] != -1){
           qtdCarrosAdd++;
        }
    }

    if(qtdCarros == 0 || qtdCarros > (VETOR_MAX-qtdCarrosAdd)){
        printf("Quantidade invalida!\n\n");
    }else{
        // preenchendo os vetores
        int carroIndex = 0;
        while (qtdCarros > 0 && carroIndex < VETOR_MAX) {
            if (anos[carroIndex] != -1) {
                carroIndex++;
                continue;
            }
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            printf("=========================\n");
            printf("Carro %d\n", carroIndex + 1);
            printf("Nome do carro: ");
            fgets(carros[carroIndex], TAM_MAX, stdin);
            carros[carroIndex][strcspn(carros[carroIndex], "\n")] = '\0';
            printf("Ano do carro: ");
            scanf("%d", &anos[carroIndex]);
            printf("Preço do carro: ");
            scanf("%d", &precos[carroIndex]);

            carroIndex++;
            qtdCarros--;
        }
        printf("=========================\n");
        printf("Carros adicionados!\n");
    }
}
void buscarCarros(char carros[VETOR_MAX][TAM_MAX],int anos[VETOR_MAX],int precos[VETOR_MAX]){

    // Procurando a string no array de strings
    char carroProcurado[TAM_MAX];
    int posicaoEncontrada = -1;
    while (getchar() != '\n');

    printf("Qual carro que deseja procurar? ");
    fgets(carroProcurado, TAM_MAX, stdin);
    carroProcurado[strcspn(carroProcurado, "\n")] = '\0';
    for (int i = 0; i < VETOR_MAX; i++){
        if (strcmp(carros[i], carroProcurado) == 0) {
            posicaoEncontrada = i;
            break;
        }
    }

    // Exibindo o resultado da busca
    if (posicaoEncontrada != -1) {
        printf("Informações encontradas!\n");
        printf("=========================\n");
        printf("Carro: %s\n",carros[posicaoEncontrada]);
        printf("Ano: %d\n",anos[posicaoEncontrada]);
        printf("Preço: %d\n",precos[posicaoEncontrada]);
        printf("=========================\n");
    }else{
        printf("O carro '%s' não está presente no estoque!\n\n", carroProcurado);
        return;
    }
}
void alterarCarro(char carros[VETOR_MAX][TAM_MAX], int anos[VETOR_MAX], int precos[VETOR_MAX]) {
    // Procurando a string no array de strings

    char carroProcurado[TAM_MAX];
    int posicaoEncontrada = -1;
    while (getchar() != '\n');

    printf("Qual carro que deseja alterar? ");
    fgets(carroProcurado, TAM_MAX, stdin);
    carroProcurado[strcspn(carroProcurado, "\n")] = '\0'; // Remove o caractere de nova linha (\n)

    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(carros[i], carroProcurado) == 0) {
            posicaoEncontrada = i;
            break;
        }
    }

    if (posicaoEncontrada == -1) {
        printf("O carro '%s' não está presente no estoque!\n\n", carroProcurado);
        return;
    }

    // Fazendo a alteração
    printf("=========================\n");
    printf("Carro %d\n", posicaoEncontrada + 1);
    printf("Nome do carro: ");
    fgets(carros[posicaoEncontrada], TAM_MAX, stdin);
    carros[posicaoEncontrada][strcspn(carros[posicaoEncontrada], "\n")] = '\0';
    printf("Ano do carro: ");
    scanf("%d", &anos[posicaoEncontrada]);
    printf("Preço do carro: ");
    scanf("%d", &precos[posicaoEncontrada]);
    printf("=========================\n");
    printf("Carro alterado!\n");
}
void excluirCarro(char carros[VETOR_MAX][TAM_MAX],int anos[VETOR_MAX],int precos[VETOR_MAX]){

    char carroProcurado[TAM_MAX];
    int posicaoEncontrada = -1;
    while (getchar() != '\n');

    printf("Qual o nome do carro que deseja excluir? ");
    fgets(carroProcurado, TAM_MAX, stdin);
    carroProcurado[strcspn(carroProcurado, "\n")] = '\0';

    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(carros[i], carroProcurado) == 0) {
            posicaoEncontrada = i;
            break;
        }
    }

    if(posicaoEncontrada == -1){
        printf("O carro '%s' não está presente no estoque!\n\n", carroProcurado);
        return 1;
    }

    strcpy(carros[posicaoEncontrada], "");
    anos[posicaoEncontrada] = -1;
    precos[posicaoEncontrada] = -1;
    //Já como se trata de um vetor somente com números positivos, estou usando -1
    //para identificar aquela posição como "vazia"

    printf("Carro excluido com sucesso!\n");
}
void exibirEstoque(char carros[VETOR_MAX][TAM_MAX],int anos[VETOR_MAX],int precos[VETOR_MAX]){

    int temCarro = 0;
    printf("No estoque temos:\n");
    printf("===========ESTOQUE===========\n");
    for(int i = 0; i < VETOR_MAX; i++){
        if(anos[i] != -1){
            temCarro++;
            printf("Carro: %s\nAno: %d\nPreço: R$%d\n\n",carros[i],anos[i],precos[i]);
        }
    }
    printf("=============================\n");
    if(temCarro == 0){
        printf("Não há carros no estoque!\n\n");
        return 1;
    }
}
void cadastrarCliente(char clientes[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX]){

    int qtdClientes,qtdClientesAdd;
    qtdClientesAdd = 0;
    printf("Quantidade de clientes a serem Cadastrados: ");
    scanf("%d", &qtdClientes);


    for(int i = 0; i < VETOR_MAX; i++){
        if(contato[i] != -1){
           qtdClientesAdd++;
        }
    }

    if(qtdClientes == 0 || qtdClientes > (VETOR_MAX-qtdClientesAdd)){
        printf("Quantidade invalida!\n\n");
    }else{
        // preenchendo os vetores
        int clienteIndex = 0; // Índice do próximo cliente a ser adicionado
        while (qtdClientes > 0 && clienteIndex < VETOR_MAX) {
            if (contato[clienteIndex] != -1) {
                clienteIndex++;
                continue;
            }
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            printf("=========================\n");
            printf("Cliente %d\n", clienteIndex + 1);
            printf("Nome do Cliente: ");
            fgets(clientes[clienteIndex], TAM_MAX, stdin);
            clientes[clienteIndex][strcspn(clientes[clienteIndex], "\n")] = '\0';
            printf("Contato do cliente: ");
            scanf("%ld", &contato[clienteIndex]);

            clienteIndex++;
            qtdClientes--;
        }
        printf("=========================\n");
        printf("Clientes adicionados!\n");
    }
}
void alterarCliente(char clientes[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX]){
    //Procurando a string no array de strings
    char clienteProcurado[TAM_MAX];
    int posicaoEncontrada = -1;
    while (getchar() != '\n');

    printf("Que cliente que deseja alterar? ");
    fgets(clienteProcurado, TAM_MAX, stdin);
    clienteProcurado[strcspn(clienteProcurado, "\n")] = '\0';

    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(clientes[i], clienteProcurado) == 0) {
            posicaoEncontrada = i;
            break;
        }
    }

    if(posicaoEncontrada == -1){
        printf("O cliente '%s' não está cadastrado no sistema!\n\n", clienteProcurado);
        return 1;
    }

    //Fazendo a alteração
    printf("=========================\n");
    printf("Cliente %d\n", posicaoEncontrada+1);
    printf("Nome do cliente: ");
    fgets(clienteProcurado, TAM_MAX, stdin);
    clienteProcurado[strcspn(clienteProcurado, "\n")] = '\0';
    printf("Contato do cliente: ");
    scanf("%ld", &contato[posicaoEncontrada]);
    printf("=========================\n");
    printf("Carro alterado!\n");
}
void excluirCliente(char clientes[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX]){
    //Procurando a string no array de strings
    char clienteProcurado[TAM_MAX];
    int posicaoEncontrada = -1;
    while (getchar() != '\n');

    printf("Qual o nome do cliente que deseja excluir do sistema? ");
    fgets(clienteProcurado, TAM_MAX, stdin);
    clienteProcurado[strcspn(clienteProcurado, "\n")] = '\0';

    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(clientes[i], clienteProcurado) == 0) {
            posicaoEncontrada = i;
            break;
        }
    }

    if(posicaoEncontrada == -1){
        printf("O cliente '%s' não está cadastrado no sistema!\n\n", clienteProcurado);
        return 1;
    }

    //Fazendo a alteração
    strcpy(clientes[posicaoEncontrada],"");
    contato[posicaoEncontrada] = -1;
    printf("Cliente excluido com sucesso!\n");
}
void exibirClientes(char clientes[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX]){
    int temCliente = 0;
    printf("Clientes cadastrados no sistema:\n");
    printf("===========AGENDA=========\n");
    for(int i = 0; i < VETOR_MAX; i++){
        if(contato[i] != -1){
            temCliente++;

            printf("Cliente: %s\nContato: %d\n\n",clientes[i],contato[i]);
        }
    }
    printf("==========================\n");
    if(temCliente == 0){
        printf("Não há clientes cadastrados no sistema!\n\n");
        return 1;
    }
}
int main() {

    setlocale(LC_ALL, "Portuguese");
    char carros[VETOR_MAX][TAM_MAX];
    int anos[VETOR_MAX],precos[VETOR_MAX];
    char clientes[VETOR_MAX][TAM_MAX];
    long int contato[VETOR_MAX];
    int i = 0;

    //atribuindo valores para os vetores não darem problema de alocação de endereço
    for(int c = 0;c < VETOR_MAX; c++){
        precos[c] = -1;
        anos[c] = -1;
        contato[c] = -1;
    }

    while(i != 999){
    printf("O que deseja fazer?\n\n");
    printf("1 - Adicionar carros\t\t7 - Alterar Cliente\n");
    printf("2 - Buscar carros\t\t8 - Excluir Cliente\n");
    printf("3 - Alterar carros\t\t9 - Exibir Cliente\n");
    printf("4 - Excluir carros\n");
    printf("5 - Exibir estoque\n");
    printf("6 - Cadastrar Cliente\t\t999 - Sair\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &i);
    printf("\n");

        //realizar vendas
        //consultar vendas
        switch(i){
            case 1:
                addCarros(carros,anos,precos);
                break;
            case 2:
                buscarCarros(carros,anos,precos);
                break;
            case 3:
                alterarCarro(carros,anos,precos);
                break;
            case 4:
                excluirCarro(carros,anos,precos);
                break;
            case 5:
                exibirEstoque(carros,anos,precos);
                break;
            case 6:
                cadastrarCliente(clientes,contato);
                break;
            case 7:
                alterarCliente(clientes,contato);
                break;
            case 8:
                excluirCliente(clientes,contato);
                break;
            case 9:
                exibirClientes(clientes,contato);
                break;
            case 999:
                break;
            default:
                printf("Escolha uma opção!\n");
                break;
        }
    }

    return 0;
}
