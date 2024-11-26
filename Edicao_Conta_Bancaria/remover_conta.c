
/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 21/11/2024
Objetivo do trecho: Remoção das contas bancárias enquanto não há uma movimentação entre as mesmas.
*/

#include "C:\Trabalho_ControleBancario\funcoes.h"//#include "C:\Trabalho_ControleBancario\funcoes.h"


void remover_conta(Lista_ContaBancaria *lista_contaBancaria, int opc)
{
    TipoApontadorConta p;
    TipoApontadorConta r;
    ContaBancaria reg_conta;
    int resp;
    int num;
    int cont;

    do
    {
        do
        {
            tela();
            do
            {
                gotoxy(07, 23);
                printf("                                     ");
                gotoxy(07, 23);
                printf("Digite 0 para sair. ");

                // Remover conta no inicio
                gotoxy(07, 23);
                printf("Deseja fazer a exclusao? [1]Sim [0]Nao:");
                gotoxy(46, 23);
                scanf("%d", &resp);
                getchar();

                if (resp == 1)
                {
                    if (opc == 4)
                    {
                        if (lista_contaBancaria->Primeiro->proximo == NULL)
                        {
                            free(lista_contaBancaria->Primeiro);
                            lista_contaBancaria->Primeiro = NULL;
                            lista_contaBancaria->Ultimo = NULL;
                        }
                        else
                        {
                            lista_contaBancaria->Primeiro = p->proximo;

                            free(p);
                        }
                        gotoxy(07, 23);
                        printf("                                             ");
                        gotoxy(07, 23);
                        printf("Conta excluida!");
                        getch();
                    }
                    // Remover conta no final
                    else if (opc == 5)
                    {
                        if (lista_contaBancaria->Primeiro->proximo == NULL)
                        {
                            free(lista_contaBancaria->Primeiro);
                            lista_contaBancaria->Primeiro = NULL;
                            lista_contaBancaria->Ultimo = NULL;
                        }
                        r = lista_contaBancaria->Primeiro;
                        p = r->proximo;
                        while (p->proximo != NULL)
                        {
                            p = p->proximo;
                            r = r->proximo;
                        }
                        free(p);

                        gotoxy(07, 23);
                        printf("Conta excluida!");
                        getch();
                    }
                    // Remover conta na posicao
                    else if (opc == 6)
                    {
                        gotoxy(5, 7);
                        printf("Digite o numero do codigo cadastrado para remove-lo: ");
                        gotoxy(58, 7);
                        scanf("%d", &reg_conta.cd_conta);
                        getch();

                        r = lista_contaBancaria->Primeiro;
                        p = r->proximo;
                        cont = 1;
                        while (cont < num - 1)
                        {
                            cont = cont + 1;
                            p = p->proximo;
                            r = r->proximo;
                        }
                        r->proximo = p->proximo;
                        free(p);

                        gotoxy(07, 23);
                        printf("Conta excluida!");
                        getch();
                    }
                }
            } while (resp != 0 && resp != 1);

        } while (resp != 0 && resp != 1);
    }while (/*movimentacao_financeira()*/1 == 0);
}
