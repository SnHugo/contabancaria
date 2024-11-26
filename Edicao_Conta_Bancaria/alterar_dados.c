/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 23/11/2024
Objetivo do trecho: Funcao para que o usuario altere campos dos dados da conta
*/
#include "C:\Trabalho_ControleBancario\funcoes.h"

void alterar_dados(Lista_ContaBancaria *lista_contaBancaria)
{
    int opcao_alterar;
    int opcao_denovo;
    int opcao_salvar;
    ContaBancaria reg_conta; 

    TipoApontadorConta resp = (TipoApontadorConta)malloc(sizeof(TipoConta));

    do
    {
        tela();
        do
        {
            gotoxy(8, 23);
            printf("Digite o codigo que deseja alterar:            ");
            gotoxy(44, 23);
            fflush(stdin);
            scanf("%d", &reg_conta.cd_conta);

            resp = pesquisa(lista_contaBancaria, reg_conta.cd_conta);

            if (resp == NULL)
            {
                gotoxy(8, 23);
                printf("Erro: Codigo nao encontrado                      ");
                getch();
                gotoxy(8, 23);
                printf("Deseja digitar novamente ? [1]Sim [2]Nao:");
                gotoxy(54, 23);
                fflush(stdin);
                scanf("%d", &opcao_denovo);

                if (opcao_denovo == 2)
                {
                    return;
                }
            }
        } while (resp == NULL);

        reg_conta = resp->conteudo;
        imprimir_Registro(resp->conteudo);

        do
        {
            gotoxy(7, 23);
            printf("Digite qual o numero que deseja alterar: ");
            gotoxy(49, 23);
            fflush(stdin);
            scanf("%d", &opcao_alterar);

            switch (opcao_alterar)
            {
            case 1:
                gotoxy(29, 8);
                printf("                                            ");
                gotoxy(29, 8);
                fflush(stdin);
                fgets(reg_conta.banco, 50, stdin);
                break;
            case 2:
                gotoxy(29, 10);
                printf("                                            ");
                gotoxy(29, 10);
                fflush(stdin);
                fgets(reg_conta.agencia, 10, stdin);
                break;
            case 3:
                gotoxy(29, 12);
                printf("                                            ");
                gotoxy(29, 12);
                fflush(stdin);
                fgets(reg_conta.numero_conta, 20, stdin);
                break;
            case 4:
                gotoxy(29, 14);
                printf("                                             ");
                gotoxy(29, 14);
                fflush(stdin);
                strcpy(reg_conta.tipo_conta, selecionar_tipo_conta());
                break;
            case 5:
                gotoxy(07, 23);
                printf("                                                                  ");
                gotoxy(07, 23);
                printf("O campo 'Saldo' nao pode ser alterado");
                getch();
                break;
            case 6:
                gotoxy(07, 23);
                printf("                                                                  ");
                gotoxy(07, 23);
                printf("O campo 'Limite' nao pode ser alterado");
                getch();
                break;
            case 7:
                gotoxy(07, 23);
                printf("                                                                  ");
                gotoxy(07, 23);
                printf("O campo 'Status' nao pode ser alterado");
                getch();
                break;
            case 0:
                break;
            default:
                gotoxy(07, 23);
                printf("                                                                       ");
                gotoxy(07, 23);
                printf("Opcao invalida.");
                getch();
            }
            gotoxy(07, 23);
            printf("                                                                        ");
            gotoxy(07, 23);
            printf("Deseja alterar outro dado ? [1]Sim [2]Nao: ");
            gotoxy(61, 23);
            fflush(stdin);
            scanf("%d", &opcao_alterar);

        } while (opcao_alterar != 0 && opcao_alterar != 2);

        gotoxy(07, 23);
        printf("                                                                        ");
        gotoxy(07, 23);
        printf("Deseja salvar os dados alterados ? [1]Sim [2]Nao: ");
        gotoxy(62, 23);
        fflush(stdin);
        scanf("%d", &opcao_salvar);

        if (opcao_salvar == 1)
        {
            resp->conteudo = reg_conta;
        }

    } while (opcao_alterar != 0 && opcao_alterar != 2);
}