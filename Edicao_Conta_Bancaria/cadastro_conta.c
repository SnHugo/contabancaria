/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 30/10/2024
Objetivo do trecho: Implementar uma função para que o usuário cadastre contas no inicio, meio e fim da lista
*/

#include "funcoes.h"


// Funcao para contar os elementos da lista
int contador(Lista_ContaBancaria *lista_contaBancaria)
{
    TipoApontador aux;
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
TipoApontador pesquisa(Lista_ContaBancaria *lista_contaBancaria, int codigo)
{
    TipoApontador auxiliar = lista_contaBancaria->Primeiro;
    if (auxiliar != NULL)
    {
        while (auxiliar != NULL)
        {
            if (auxiliar->conteudo.cd_conta == codigo)
            {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
    }
    return NULL;
}

void cadastrar_conta(Lista_ContaBancaria *lista_contaBancaria, int opc)
{
    TipoApontador p, r, validar_codigo;
    conta_bancaria reg_conta;
    int resp, resp2 = 1, num;

    validar_codigo = (TipoApontador)malloc(sizeof(ContaBancaria));

    do
    {
        do
        {
            tela();
            tela_digitacaoContas();
            
            // Ler codigo da conta
            gotoxy(27, 6);
            fflush(stdin);
            scanf("%d", &reg_conta.cd_conta);

            if (reg_conta.cd_conta == 0)
            {
                return;
            }
            else if (reg_conta.cd_conta > 1000000 || reg_conta.cd_conta < 1)
            {
                gotoxy(8, 23);
                printf("Digite um codigo entre os numeros 1.000.000 e 1!");
                getch();
                continue;
            }

            validar_codigo = pesquisa(lista_contaBancaria, reg_conta.cd_conta);
            if (validar_codigo != NULL)
            {
                gotoxy(8, 23);
                printf("                                                                       ");
                gotoxy(8, 23);
                printf("O codigo '%d' ja esta cadastrado!", reg_conta.cd_conta);
                getch();
                continue;
            }

            // Ler o nome do banco
            gotoxy(27, 8);
            fflush(stdin);
            fgets(reg_conta.banco, 50, stdin);

            // Ler a agencia
            gotoxy(27, 10);
            fflush(stdin);
            fgets(reg_conta.agencia, 10, stdin);

            // Ler o numero da conta
            gotoxy(27, 12);
            fflush(stdin);
            fgets(reg_conta.numero_conta, 20, stdin);

            // Ler o tipo da conta
            gotoxy(27, 14);
            fflush(stdin);
            fgets(reg_conta.tipo_conta, 20, stdin);

            // Ler o saldo
            gotoxy(27, 16);
            fflush(stdin);
            scanf("%lf", &reg_conta.vl_saldo);

            // Ler o limite
            gotoxy(27, 18);
            fflush(stdin);
            scanf("%lf", &reg_conta.vl_limite);

            // Definir o status da conta bancaria
            gotoxy(27, 20);
            fflush(stdin);
            fgets(reg_conta.status, 10, stdin);

        } while (validar_codigo != NULL);

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
            // Adicionar no inicio
            if (lista_contaBancaria-> Primeiro == NULL)
            {
                lista_contaBancaria->Primeiro = p;
                lista_contaBancaria->Ultimo = p;
            }
            else
            {
                if (opc == 1)
                {
                    p->proximo = lista_contaBancaria->Primeiro;
                    lista_contaBancaria->Primeiro = p;
                }
                // Adicionar no final
                else if (opc == 2)
                {
                    lista_contaBancaria->Ultimo->proximo = p;
                    lista_contaBancaria->Ultimo = p;
                    p->proximo = NULL;
                }
                // Adicionar na opcao desejada
                else if (opc == 3)
                {
                    do
                    {
                        gotoxy(7, 23);
                        printf("                                                    ");
                        gotoxy(7, 23);
                        printf("Digite a posicao para inserir: ");
                        scanf("%d", &num);
                        getchar();

                        if (num < 1 || num > contador(lista_contaBancaria))
                        {
                            gotoxy(7, 23);
                            printf("Digite uma posicao valida!         ");
                            getch();
                        }
                    } while (num < 1 || num > contador(lista_contaBancaria));

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
                        r = (TipoApontador)malloc(sizeof(Lista_ContaBancaria));
                        if (r == NULL)
                        {
                            gotoxy(07, 23);
                            printf("Erro na alocação da memoria!");
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

void imprimir_listaDasContasBancarias(Lista_ContaBancaria *lista_contaBancaria)
{
    int linha = 10;
    TipoApontador p = lista_contaBancaria-> Primeiro;

    if (p != NULL)
    {
        while (p != NULL)
        {
            tela_contasCadastradas(p->conteudo, linha);
            p = p->proximo;
            linha++;
        }
    }
    else
    {
        gotoxy(8, 23);
        printf("Lista Vazia!");
        getch();
    }
}