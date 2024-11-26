/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 25/11/2024
Objetivo do trecho: Consultar as contas cadastradas de modo geral, por ordem de código e ordem alfabética
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"

void consultar_contas(Lista_ContaBancaria *lista_contaBancaria)
{
    int opcao;
    tela_listagem();

    do
    {
        system("cls");
        tela_listagem();
        gotoxy(7, 23);
        printf("Digite uma opcao (4 para voltar): ");
        gotoxy(42, 23);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exibir_contas_geral(lista_contaBancaria);
            break;

        case 2:
            consultar_ordem_alfabetica(lista_contaBancaria);
            break;

        case 3:
            consultar_conta_ordem_cd(lista_contaBancaria);
            break;

        case 4:
            gotoxy(07, 23);
            printf("                                    ");
            gotoxy(7, 23);
            printf("Voltando ao menu principal...");
            getch();
            break;

        default:
            gotoxy(07, 23);
            printf("                                    ");
            gotoxy(7, 23);
            printf("Opcao invalida!!!");
            getch();
            break;
        }
    } while (opcao != 4);
}

// Exibir as contas de forma geral
void exibir_contas_geral(Lista_ContaBancaria *lista_contaBancaria)
{

    TipoApontadorConta aux = lista_contaBancaria->Primeiro;

    system("cls");
    tela_listagem();
    gotoxy(07, 23);
    printf("                                                                     ");

    if (aux == NULL)
    {
        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Nenhuma conta cadastrada.");
        getch();
        return;
    }

    system("cls");
    tela();

    gotoxy(10, 6);
    printf("=== Contas Cadastradas ===");

    while (aux != NULL)
    {
        gotoxy(10, 6);
        printf("[1] Codigo....................: %d", aux->conteudo.cd_conta);
        gotoxy(10, 8);
        printf("[2] Banco.....................: %s", aux->conteudo.banco);
        gotoxy(10, 10);
        printf("[3] Agencia...................: %s", aux->conteudo.agencia);
        gotoxy(10, 12);
        printf("[4] Numero da conta...........: %s", aux->conteudo.numero_conta);
        gotoxy(10, 14);
        printf("[5] Tipo da conta.............: %s", aux->conteudo.tipo_conta);
        gotoxy(10, 16);
        printf("[6] Saldo disponivel..........: %.2lf", aux->conteudo.vl_saldo);
        gotoxy(10, 18);
        printf("[7] Limite disponivel.........: %.2lf", aux->conteudo.vl_limite);
        gotoxy(10, 20);
        printf("[8] Status da conta...........: %s", aux->conteudo.status);
        getch();
        aux = aux->proximo;
    }
}
void consultar_ordem_alfabetica(Lista_ContaBancaria *lista_contaBancaria)
{
    int total = contador(lista_contaBancaria);

    if (total == 0)
    {
        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Nenhuma conta cadastrada.");
        getch();
        return;
    }

    ContaBancaria *contas = (ContaBancaria *)malloc(total * sizeof(TipoConta));

    if (contas == NULL)
    {
        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Erro na alocacao de memoria.");
        getch();
        return;
    }

    TipoApontadorConta aux = lista_contaBancaria->Primeiro;
    for (int i = 0; i < total; i++)
    {
        contas[i] = aux->conteudo;
        aux = aux->proximo;
    }

    for (int i = 0; i < total - 1; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (strcmp(contas[i].banco, contas[j].banco) > 0)
            {
                ContaBancaria temp = contas[i];
                contas[i] = contas[j];
                contas[j] = temp;
            }
        }
    }

    for (int i = 0; i < total; i++)
    {
        system("cls");
        tela();
        gotoxy(15, 6);
        printf("=== Contas por ordem alfabetica ===");

        gotoxy(07, 7);
        printf("Codigo...............: %d", contas[i].cd_conta);
        gotoxy(07, 9);
        printf("Banco................: %s", contas[i].banco);
        gotoxy(07, 11);
        printf("Agencia..............: %s", contas[i].agencia);
        gotoxy(07, 13);
        printf("Numero da conta......: %s", contas[i].numero_conta);
        gotoxy(07, 15);
        printf("Tipo da conta........: %s", contas[i].tipo_conta);
        gotoxy(07, 17);
        printf("Saldo................: %.2lf", contas[i].vl_saldo);
        gotoxy(07, 19);
        printf("Limite...............: %.2lf", contas[i].vl_limite);
        gotoxy(07, 21);
        printf("Status...............: %s", contas[i].status);

        getch();
    }

    free(contas);
}
void consultar_conta_ordem_cd(Lista_ContaBancaria *lista_contaBancaria)
{
    TipoApontadorConta aux = lista_contaBancaria->Primeiro;
    int n = contador(lista_contaBancaria);

    if (n == 0)
    {
        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Nenhuma conta cadastrada.");
        getch();
        return;
    }

    ContaBancaria *contas = (ContaBancaria *)malloc(n * sizeof(ContaBancaria));

    if (contas == NULL)
    {
        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Erro na alocação de memória.");
        getch();
        return;
    }

    for (int i = 0; aux != NULL; i++)
    {
        contas[i] = aux->conteudo;
        aux = aux->proximo;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (contas[j].cd_conta > contas[j + 1].cd_conta)
            {
                ContaBancaria temp = contas[j];
                contas[j] = contas[j + 1];
                contas[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        system("cls");
        tela();
        gotoxy(15, 6);
        printf("=== Contas em Ordem Crescente dos Codigos ===");

        gotoxy(07, 7);
        printf("Codigo...............: %d", contas[i].cd_conta);
        gotoxy(07, 9);
        printf("Banco................: %s", contas[i].banco);
        gotoxy(07, 11);
        printf("Agencia..............: %s", contas[i].agencia);
        gotoxy(07, 13);
        printf("Numero da conta......: %s", contas[i].numero_conta);
        gotoxy(07, 15);
        printf("Tipo da conta........: %s", contas[i].tipo_conta);
        gotoxy(07, 17);
        printf("Saldo................: %.2lf", contas[i].vl_saldo);
        gotoxy(07, 19);
        printf("Limite...............: %.2lf", contas[i].vl_limite);
        gotoxy(07, 21);
        printf("Status...............: %s", contas[i].status);

        getch();
    }

    // Isso aqui é pra liberar a alocaçao da memoria
    free(contas);
}
