/*
Aluno: Hugo Cesar Fernandes de Macedo
Data: 17/11/2024
Objetivo do trecho: Criar e cadastrar a conta bancária
*/
//#include "C:\Trabalho_ControleBancario\funcoes.h"
#include "funcoes.h"


// Funcao para contar os elementos da lista
int contador(Lista_ContaBancaria *lista_contaBancaria)
{
    TipoApontadorConta aux;
    int cont = 0;

    aux = lista_contaBancaria->Primeiro;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

// Funcao para pesquisa
TipoApontadorConta pesquisa(Lista_ContaBancaria *lista_contaBancaria, int cd_conta)
{
    TipoApontadorConta aux = lista_contaBancaria->Primeiro;

    while (aux != NULL)
    {
        if (aux->conteudo.cd_conta == cd_conta)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc)
{
    TipoApontadorConta p, r;
    ContaBancaria reg_conta;
    int resp, resp2 = 1, num;

    do
    {
        system("cls");
        tela();
        tela_digitacaoContas();
        do
        {
            gotoxy(7, 23);
            printf("                                                                          ");
            gotoxy(7, 23);
            printf("Digite 0 para sair");
            gotoxy(30, 6);
            scanf("%d", &reg_conta.cd_conta);
            getchar();

            if (reg_conta.cd_conta == 0)
            {
                return;
            }

            if (pesquisa(lista_contaBancaria, reg_conta.cd_conta) != NULL)
            {
                gotoxy(7, 23);
                printf("                                                                         ");
                gotoxy(7, 23);
                printf("O codigo '%d' ja esta cadastrado!", reg_conta.cd_conta);
                getch();
                gotoxy(39, 7);
                printf("                              ");
            }

        } while (pesquisa(lista_contaBancaria, reg_conta.cd_conta) != NULL);

        // Ler o nome do banco
        gotoxy(30, 8);
        fflush(stdin);
        fgets(reg_conta.banco, 50, stdin);

        // Ler a agencia
        gotoxy(30, 10);
        fflush(stdin);
        fgets(reg_conta.agencia, 10, stdin);

        // Ler o numero da conta
        gotoxy(30, 12);
        fflush(stdin);
        fgets(reg_conta.numero_conta, 20, stdin);

        // Ler o tipo da conta
        gotoxy(30, 14);
        fflush(stdin);
        strcpy(reg_conta.tipo_conta, selecionar_tipo_conta());

        // Ler o saldo
        gotoxy(30, 16);
        fflush(stdin);
        scanf("%lf", &reg_conta.vl_saldo);

        // Ler o limite
        gotoxy(30, 18);
        fflush(stdin);
        scanf("%lf", &reg_conta.vl_limite);

        // Definir o status da conta bancaria
        gotoxy(30, 20);
        fflush(stdin);
        scanf(" %s", reg_conta.status);

        // Confirmação de gravação
        gotoxy(7, 23);
        printf("                                                                          ");
        gotoxy(7, 23);
        printf("Deseja gravar no sistema?: [1] Sim [2] Nao: ");
        fflush(stdin);
        scanf("%d", &resp);
        getchar();

        if (resp == 1)
        {
            p = (TipoApontadorConta)malloc(sizeof(TipoConta));
            p->conteudo = reg_conta;
            p->proximo = NULL;
            if (p == NULL)
            {
                gotoxy(07, 23);
                printf("Erro na alocação da memória!                                ");
                return;
            }
            // Adicionar no final
            if (opc == 2)
            {
                if (lista_contaBancaria->Primeiro == NULL)
                {
                    lista_contaBancaria->Primeiro = p;
                    lista_contaBancaria->Ultimo = p;
                }
                else
                {
                    lista_contaBancaria->Ultimo->proximo = p;
                    lista_contaBancaria->Ultimo = p;
                    p->proximo = NULL;
                }
            }
            // Adicionar no inicio
            else if (opc == 1)
            {
                if (lista_contaBancaria->Primeiro == NULL)
                {
                    lista_contaBancaria->Primeiro = p;
                    lista_contaBancaria->Ultimo = p;
                }
                else
                {
                    p->proximo = lista_contaBancaria->Primeiro;
                    lista_contaBancaria->Primeiro = p;
                }
            }
            // Adicionar na opcao desejada
            else if (opc == 3)
            {
                if (lista_contaBancaria->Primeiro != NULL)
                {
                    do
                    {
                        gotoxy(7, 23);
                        printf("                                                                       ");
                        gotoxy(7, 23);
                        printf("Digite a posicao para inserir:                      ");
                        scanf("%d", &num);
                        getchar();

                        if (num < 1 || num > contador(lista_contaBancaria))
                        {
                            gotoxy(07, 23);
                            printf("                                                                       ");
                            gotoxy(7, 23);
                            printf("Digite uma posicao valida!");
                            getch();
                        }
                    } while (num < 1 || num > contador(lista_contaBancaria));
                }
                if (num == 1)
                {
                    p->proximo = lista_contaBancaria->Primeiro;
                    lista_contaBancaria->Primeiro = p;

                    if (lista_contaBancaria->Ultimo == NULL)
                    {
                        lista_contaBancaria->Ultimo = p;
                    }
                }
                else
                {
                    r = (TipoApontadorConta)malloc(sizeof(TipoConta));
                    if (r == NULL)
                    {
                        gotoxy(07, 23);
                        printf("Erro na alocação da memoria!                                   ");
                        return;
                    }
                    r->conteudo = reg_conta;
                    p = lista_contaBancaria->Primeiro;
                    for (int x = 1; x < num - 1; x++)
                    {
                        p = p->proximo;
                    }
                    r->proximo = p->proximo;
                    p->proximo = r;
                }
            }
        }
        else if (resp != 2)
        {
            gotoxy(7, 23);
            printf("                                                                       ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
        }

        gotoxy(7, 23);
        printf("                                                                       ");
        gotoxy(7, 23);
        printf("Deseja cadastrar outro? [1] Sim [2] Nao: ");
        scanf("%d", &resp2);
        getchar();

        if (resp2 != 1 && resp2 != 2)
        {
            gotoxy(7, 23);
            printf("                                                                       ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
            getch();
        }

    } while (resp2 == 1);
}