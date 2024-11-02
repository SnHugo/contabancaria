#include "funcoes.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

// Funcao para contar os elementos da lista
int contador(Lista_ContaBancaria *L)
{
    TipoApontador aux;
    int cont = 0;

    aux = L->Primeiro;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

// Funcao para pesquisa
TipoApontador pesquisa(Lista_ContaBancaria *L, conta_bancaria reg_conta)
{
    TipoApontador aux = L->Primeiro;

    while (aux != NULL)
    {
        if (aux->conteudo.cd_conta == reg_conta.cd_conta)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void cadastrar_conta(Lista_ContaBancaria *L, int opc)
{
    TipoApontador p, r;
    conta_bancaria reg_conta;
    int resp, resp2 = 1, num;

    do
    {
        system("cls");
        tela();
        tela_CadastroDeContas();
        do
        {
            gotoxy(7, 23);
            printf("                                                      ");
            gotoxy(7, 23);
            printf("Digite 0 para sair");
            gotoxy(25, 6);
            printf("                                 ");
            gotoxy(39, 7);
            scanf("%d", &reg_conta.cd_conta);
            getchar();

            if (reg_conta.cd_conta == 0)
            {
                return;
            }

            if (pesquisa(L, reg_conta) != NULL)
            {
                gotoxy(7, 23);
                printf("                                       ");
                gotoxy(7, 23);
                printf("O codigo '%d' ja esta cadastrado!", reg_conta.cd_conta);
                getch();
                gotoxy(39, 7);
                printf("                              ");
            }

        } while (pesquisa(L, reg_conta) != NULL);

        // Ler o nome do banco
        gotoxy(39, 9);
        fflush(stdin);
        fgets(reg_conta.banco, 50, stdin);

        // Ler a agencia
        gotoxy(39, 11);
        fflush(stdin);
        fgets(reg_conta.agencia, 10, stdin);

        // Ler o numero da conta
        gotoxy(39, 13);
        fflush(stdin);
        fgets(reg_conta.numero_conta, 20, stdin);

        // Ler o tipo da conta
        gotoxy(39, 15);
        fflush(stdin);
        fgets(reg_conta.tipo_conta, 20, stdin);

        // Ler o saldo
        gotoxy(39, 17);
        fflush(stdin);
        scanf("%lf", &reg_conta.vl_saldo);

        // Ler o limite
        gotoxy(39, 19);
        fflush(stdin);
        scanf("%lf", &reg_conta.vl_limite);

        // Definir o status da conta bancaria
        gotoxy(39, 21);
        fflush(stdin);
        scanf(" %s", &reg_conta.status);

        // Confirmação de gravação
        gotoxy(7, 23);
        printf("Deseja gravar no sistema?: [1] Sim [2] Nao: ");
        fflush(stdin);
        scanf("%d", &resp);
        getchar();

        if (resp == 1)
        {
            p = (TipoApontador)malloc(sizeof(ContaBancaria));
            p->conteudo = reg_conta;
            p->proximo = NULL;
            if (p == NULL)
            {
                gotoxy(07, 23);
                printf("Erro na alocação da memória!");
                return;
            }
            // Adicionar no final
            if (opc == 2)
            {
                if (L->Primeiro == NULL)
                {
                    L->Primeiro = p;
                    L->Ultimo = p;
                }
                else
                {
                    L->Ultimo->proximo = p;
                    L->Ultimo = p;
                    p->proximo = NULL;
                }
            }
            // Adicionar no inicio
            else if (opc == 1)
            {
                if (L->Primeiro == NULL)
                {
                    L->Primeiro = p;
                    L->Ultimo = p;
                }
                else
                {
                    p->proximo = L->Primeiro;
                    L->Primeiro = p;
                }
            }
            // Adicionar na opcao desejada
            else if (opc == 3)
            {
                if (L->Primeiro != NULL)
                {
                    do
                    {
                        gotoxy(7, 23);
                        printf("                                                    ");
                        gotoxy(7, 23);
                        printf("Digite a posicao para inserir: ");
                        scanf("%d", &num);
                        getchar();

                        if (num < 1 || num > contador(L))
                        {
                            gotoxy(7, 23);
                            printf("Digite uma posicao valida!         ");
                            getch();
                        }
                    } while (num < 1 || num > contador(L));
                }
                if (num == 1)
                {
                    p->proximo = L->Primeiro;
                    L->Primeiro = p;

                    if (L->Ultimo == NULL)
                    {
                        L->Ultimo = p;
                    }
                }
                else
                {
                    r = (TipoApontador)malloc(sizeof(Lista_ContaBancaria));
                    if (r == NULL)
                    {
                        gotoxy(07, 23);
                        printf("Erro na alocação da memoria!");
                        return;
                    }
                    r->conteudo = reg_conta;
                    p = L->Primeiro;
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
            printf("                                           ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
        }

        gotoxy(7, 23);
        printf("                                                    ");
        gotoxy(7, 23);
        printf("Deseja cadastrar outro? [1] Sim [2] Nao: ");
        scanf("%d", &resp2);
        getchar();

        if (resp2 != 1 && resp2 != 2)
        {
            gotoxy(7, 23);
            printf("                                             ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
            getch();
        }

    } while (resp2 == 1);
}

