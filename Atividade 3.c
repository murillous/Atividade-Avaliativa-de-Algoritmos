#include <stdio.h>
#include <string.h>
#include <locale.h>

#define VETOR_MAX 10
#define TAM_MAX 50

void addCarros( char carros[VETOR_MAX][TAM_MAX],char carrosEncomendados[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX],
                char clientes[VETOR_MAX][TAM_MAX], char clientesEncomendas[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX],
                char carrosVendidos[VETOR_MAX][TAM_MAX],char carrosVendidosClientes[VETOR_MAX][TAM_MAX],int carrosVendidosPrecos[VETOR_MAX]){

    int qtdCarros,qtdCarrosAdd;
    qtdCarrosAdd = 0;
    printf("Quantidade de carros a serem adicionados: ");
    scanf("%d", &qtdCarros);


    for(int i = 0; i < VETOR_MAX; i++){
        if(strcmp(carros[i],"")!= 0){
           qtdCarrosAdd++;
        }
    }

    if(qtdCarros == 0 || qtdCarros > (VETOR_MAX-qtdCarrosAdd)){
        printf("Quantidade invalida!\n\n");
    }else{
        // preenchendo os vetores
        int carroIndex = 0;
        while (qtdCarros > 0 && carroIndex < VETOR_MAX) {
            if(strcmp(carros[carroIndex],"")!= 0) {
                carroIndex++;
                continue;
            }
            while (getchar() != '\n');//Limpa o buffer de entrada para evitar problemas com o código
            printf("=========================\n");
            printf("Carro %d\n", carroIndex + 1);
            printf("Nome do carro: ");
            fgets(carros[carroIndex], TAM_MAX, stdin);
            carros[carroIndex][strcspn(carros[carroIndex], "\n")] = '\0';
            printf("Preço do carro: ");
            scanf("%d", &precos[carroIndex]);

            // Limpa a reserva do carro, caso exista
            for (int i = 0; i < VETOR_MAX; i++) {
                if (strcmp(carrosEncomendados[i], carros[carroIndex]) == 0) {
                    printf("O carro '%s' estava reservado para o cliente '%s' e já foi vendido!\n\n", carros[carroIndex], clientesEncomendas[i]);
                    strcpy(carrosVendidos[i],carros[carroIndex]);
                    strcpy(carrosVendidosClientes[i],clientesEncomendas[i]);
                    carrosVendidosPrecos[i] = precos[carroIndex];
                    strcpy(carrosEncomendados[i], "");
                    strcpy(clientesEncomendas[i], "");
                    strcpy(carros[carroIndex], "");
                    precos[carroIndex] = -1;
                    break;
                }
            }

            carroIndex++;
            qtdCarros--;
        }
        printf("=========================\n");
        printf("Carros adicionados!\n");
    }
}
void buscarCarros(char carros[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX]){

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
        printf("Preço: %d\n",precos[posicaoEncontrada]);
        printf("=========================\n");
    }else{
        printf("O carro '%s' não está presente no estoque!\n\n", carroProcurado);
        return;
    }
}
void alterarCarro(char carros[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX]) {
    //Procurando a string no array de strings

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
    printf("Preço do carro: ");
    scanf("%d", &precos[posicaoEncontrada]);
    printf("=========================\n");
    printf("Carro alterado!\n");
}
void excluirCarro(char carros[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX]){

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
        return;
    }

    strcpy(carros[posicaoEncontrada], "");
    precos[posicaoEncontrada] = -1;
    //Já como se trata de um vetor somente com números positivos, estou usando -1
    //para identificar aquela posição como "vazia"

    printf("Carro excluido com sucesso!\n");
}
void exibirEstoque(char carros[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX]){

    int temCarro = 0;
    printf("No estoque temos:\n");
    printf("===========ESTOQUE===========\n\n");
    for(int i = 0; i < VETOR_MAX; i++){
        if(strcmp(carros[i],"")!= 0){
            temCarro++;
            printf("Carro: %s\nPreço: R$%d\n\n",carros[i],precos[i]);
        }
    }
    printf("=============================\n");
    if(temCarro == 0){
        printf("Não há carros no estoque!\n\n");
        return;
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
        return;
    }

    //Fazendo a alteração
    printf("=========================\n");
    printf("Cliente %d\n", posicaoEncontrada+1);
    printf("Nome do cliente: ");
    fgets(clientes[posicaoEncontrada], TAM_MAX, stdin);
    clientes[posicaoEncontrada][strcspn(clientes[posicaoEncontrada], "\n")] = '\0';
    printf("Contato do cliente: ");
    scanf("%ld",&contato[posicaoEncontrada]);
    printf("=========================\n");
    printf("Cliente Alterado!\n");
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
        return;
    }

    //Fazendo a alteração
    strcpy(clientes[posicaoEncontrada],"");
    contato[posicaoEncontrada] = -1;
    printf("Cliente excluido com sucesso!\n");
}
void exibirClientes(char clientes[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX]){
    int temCliente = 0;
    printf("Clientes cadastrados no sistema:\n");
    printf("===========AGENDA===========\n");

    for(int i = 0; i < VETOR_MAX; i++){
        if(contato[i] != -1){
            temCliente++;

            printf("Cliente: %s\nContato: %d\n\n",clientes[i],contato[i]);
        }
    }
    printf("============================\n");
    if(temCliente == 0){
        printf("Não há clientes cadastrados no sistema!\n\n");
        return;
    }
}
void realizarVendas(char carros[VETOR_MAX][TAM_MAX],char carrosEncomendados[VETOR_MAX][TAM_MAX],int precos[VETOR_MAX],
                    char clientes[VETOR_MAX][TAM_MAX], char clientesEncomendas[VETOR_MAX][TAM_MAX],long int contato[VETOR_MAX],
                    char carrosVendidos[VETOR_MAX][TAM_MAX],char carrosVendidosClientes[VETOR_MAX][TAM_MAX],int carrosVendidosPrecos[VETOR_MAX]){

    //Cliente que irá comprar o carro
    char clienteProcurado[TAM_MAX];
    int clienteEncontrado = -1;
    char carroProcurado[TAM_MAX];
    int posicaoVazia = -1;

    while (getchar() != '\n');

    printf("Que cliente deseja comprar um carro? ");
    fgets(clienteProcurado, TAM_MAX, stdin);
    clienteProcurado[strcspn(clienteProcurado, "\n")] = '\0';

    // Verifica se o cliente está cadastrado no sistema
    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(clientes[i], clienteProcurado) == 0) {
            clienteEncontrado = i;
            break;
        }
    }

    if(clienteEncontrado == -1){
        printf("O cliente '%s' não está cadastrado no sistema!\n\n", clienteProcurado);
        return;
    }
    printf("O cliente '%s' foi encontrado no sistema!\n", clienteProcurado);


    // Carro que o cliente deseja comprar
    printf("Que carro deseja comprar? ");
    fgets(carroProcurado, TAM_MAX, stdin);
    carroProcurado[strcspn(carroProcurado, "\n")] = '\0';

    for(int i = 0; i < VETOR_MAX; i++){
        if(strcmp(carros[i],carroProcurado) == 0){
            printf("Carro vendido com sucesso!\n\n");
            strcpy(carrosVendidos[i],carros[i]);
            strcpy(carros[i],"");
            strcpy(carrosVendidosClientes[i],clienteProcurado);
            carrosVendidosPrecos[i] = precos[i];
            precos[i] = -1;
            return;
        }
    }

    // Se o carro não estiver reservado para o cliente, adiciona à lista de reservas
    for (int i = 0; i < VETOR_MAX; i++) {
        if (strcmp(carrosEncomendados[i], "") == 0) {
            posicaoVazia = i;
            break;
        }
    }

    if (posicaoVazia != -1) {
        strcpy(carrosEncomendados[posicaoVazia], carroProcurado);
        strcpy(clientesEncomendas[posicaoVazia], clienteProcurado);
        printf("O carro '%s' não está presente no estoque!\n", carroProcurado);
        printf("Assim que ele estiver disponível, será imediatamente seu!\n\n");
    }
}
void consultarVendas(char carrosVendidos[VETOR_MAX][TAM_MAX],char carrosVendidosClientes[VETOR_MAX][TAM_MAX],int carrosVendidosPrecos[VETOR_MAX]){

    int temVendas = 0;
    printf("===================VENDAS===================\n\n");
    for(int i = 0; i < VETOR_MAX; i++){
        if(carrosVendidosPrecos[i] != -1){
        temVendas++;
        printf("Carro: %s\nPreço: %d\nCliente Comprador: %s\n\n",carrosVendidos[i],carrosVendidosPrecos[i],carrosVendidosClientes[i]);
        }
    }
    printf("============================================\n");

    if(temVendas == 0){
        printf("Não há vendas ainda!\n\n");
    }
}
void clear_screen(void) {
// Função para limpar a tela independente do sistema operacional
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
int main() {

    setlocale(LC_ALL, "Portuguese");
    char carros[VETOR_MAX][TAM_MAX], carrosEncomendados[VETOR_MAX][TAM_MAX];
    char clientes[VETOR_MAX][TAM_MAX], clientesEncomendas[VETOR_MAX][TAM_MAX];
    char carrosVendidos[VETOR_MAX][TAM_MAX], carrosVendidosClientes[VETOR_MAX][TAM_MAX];
    int carrosVendidosPrecos[VETOR_MAX],precos[VETOR_MAX];
    long int contato[VETOR_MAX];
    int i = 0;

    //atribuindo valores para os vetores não darem problema de endereço de memória
    for(int c = 0;c < VETOR_MAX; c++){
        precos[c] = -1;
        carrosVendidosPrecos[c] = -1;
        contato[c] = -1;
        strcpy(carros[c],"");
        strcpy(carrosEncomendados[c],"");
        strcpy(clientesEncomendas[c],"");
        strcpy(carrosVendidosClientes[c],"");
        strcpy(carrosVendidos[c],"");
        strcpy(clientes[c],"");
    }

    while(i != 12){
    printf("O que deseja fazer?\n\n");
    printf("=========================MENU==========================\n\n");
    printf("1 - Adicionar carros\t\t7 - Alterar Cliente\n");
    printf("2 - Buscar carros\t\t8 - Excluir Cliente\n");
    printf("3 - Alterar carros\t\t9 - Exibir Cliente\n");
    printf("4 - Excluir carros\t\t10 - Realizar Vendas\n");
    printf("5 - Exibir estoque\t\t11 - Consultar Vendas\n");
    printf("6 - Cadastrar Cliente\t\t12 - Sair\n\n");
    printf("=======================================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &i);
    printf("\n");

        //consultar vendas
        switch(i){
            case 1:
                clear_screen();
                addCarros(carros,carrosEncomendados,precos,clientes,clientesEncomendas,contato,carrosVendidos,carrosVendidosClientes,carrosVendidosPrecos);
                break;
            case 2:
                clear_screen();
                buscarCarros(carros,precos);
                break;
            case 3:
                clear_screen();
                alterarCarro(carros,precos);
                break;
            case 4:
                clear_screen();
                excluirCarro(carros,precos);
                break;
            case 5:
                clear_screen();
                exibirEstoque(carros,precos);
                break;
            case 6:
                clear_screen();
                cadastrarCliente(clientes,contato);
                break;
            case 7:
                clear_screen();
                alterarCliente(clientes,contato);
                break;
            case 8:
                clear_screen();
                excluirCliente(clientes,contato);
                break;
            case 9:
                clear_screen();
                exibirClientes(clientes,contato);
                break;
            case 10:
                clear_screen();
                realizarVendas(carros,carrosEncomendados,precos,clientes,clientesEncomendas,contato,carrosVendidos,carrosVendidosClientes,carrosVendidosPrecos);
                break;
            case 11:
                clear_screen();
                consultarVendas(carrosVendidos,carrosVendidosClientes,carrosVendidosPrecos);
                break;
            case 12:
                clear_screen();
                printf("Obrigado pela preferência!");
                break;
            default:
                clear_screen();
                printf("Escolha uma opção!\n");
                break;
        }
    }
    return 0;
}
