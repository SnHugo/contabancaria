/*
Autor: Wesley Nobuyuki Tomimori Waterkemper
Data: 10/11/2024
Objetivo do trecho: Realizar o cadastro de uma movimentacao financeira
*/

#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"


char *InverterData (char *dt_data)
{
    char dia[3];
    char mes[3];
    char ano[5];

    strncpy(dia, dt_data, 2);
    dia[2] = '\0';
    strncpy(mes, dt_data + 3, 2);
    mes[2] = '\0';
    strncpy(ano, dt_data + 6, 4);
    ano[4] = '\0';

    sprintf(dt_data, "%s/%s/%s", ano, mes, dia);

    return dt_data;
}

TipoApontadorConta ValidarConta (Lista_ContaBancaria *lista_conta_bancaria)
{
    int codigo;

    do
    {
        TelaCadastroMovimentacao();
        gotoxy(8, 23);
        printf("Digite 0 para sair...                                                ");
        gotoxy(40, 7);
        fflush(stdin);
        scanf("%d", &codigo);

        if (codigo == 0)
        {
            return NULL;
        }

        TipoApontadorConta pont = pesquisa(lista_conta_bancaria, codigo);

        if (pont != NULL)
        {
            return pont;
        }
        else
        {
            gotoxy(8, 23);
            printf("Conta nao encontrada... Digite Novamente!!!                         ");
            getch();
            gotoxy(8, 23);
            printf("                                                                    ");
            gotoxy(40, 7);
            printf("      ");
        }
    }while (TRUE);
}

char *ValidarTipoMovi ()
{
    int opcao;
    char *tipo_movi = malloc(8 * sizeof(char));

    do
    {
        gotoxy(8, 23);
        printf("                                                                      ");
        gotoxy(8, 23);
        printf("1. Debito - 2. Credito");
        gotoxy(23, 19);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                strcpy(tipo_movi, "Debito");
                break;
            case 2:
                strcpy(tipo_movi, "Credito");
                break;
            default:
                gotoxy(8, 23);
                printf("Digite uma opcao valida");
                getch();
                gotoxy(8, 23);
                printf("                                                                      ");
        }

    }while(opcao != 1 && opcao != 2);

    gotoxy(23, 19);
    printf("%s", tipo_movi);

    return tipo_movi;
}

double ValidarValorMovi (char *tipo_movi)
{
    double valor;
    do
    {

        gotoxy(23, 20);
        scanf("%lf", &valor);
        
        if (valor > 0)
        {
            if (strcmp(tipo_movi, "Debito") < 1)
            {
                return -valor;
            }
            else
            {
                return valor;
            }
        }
        else
        {
            gotoxy(8, 23);
            printf("Valor Invalido ou Saldo Insuficiente!!!                               ");
            getch();
            gotoxy(8, 23);
            printf("                                       ");
            gotoxy(23, 20);
            printf("                ");
        }
    }while (TRUE);
}

void SalvarMoviNaLista(ListaMovimentacaoFinanceira *lista_movi, TipoApontadorMovi pont_movi)
{
    if (lista_movi-> Primeiro == NULL)
    {
        lista_movi-> Primeiro = pont_movi;
        pont_movi-> anterior = NULL;
        pont_movi-> proximo = NULL;
    }
    else
    {
        pont_movi-> anterior = lista_movi-> Ultimo;
        lista_movi-> Ultimo-> proximo = pont_movi;
    }
    lista_movi-> Ultimo = pont_movi;
}

void RealizarMovimentacao(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria)
{
    MovimentacaoFinanceira reg_movi;
    TipoApontadorMovi pont_movi = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));
    int resp_salvar;
    int resp_add;

    pont_movi-> conteudo_movi.sequencial = 1;
    
    TelaCadastroMovimentacao();
    gotoxy(17, 7);
    printf("%d", pont_movi-> conteudo_movi.sequencial);

    TipoApontadorConta conta = ValidarConta(lista_conta_bancaria);
    
    if (conta != NULL)
    {     
        gotoxy(12, 10);
        printf("%s", conta-> conteudo.banco);
        gotoxy(43, 10);
        printf("%s", conta-> conteudo.agencia);
        gotoxy(67, 10);
        printf("%s", conta-> conteudo.tipo_conta);
        gotoxy(16, 13);
        printf("%s", conta-> conteudo.numero_conta);
        gotoxy(35, 13);
        printf("%.2lf", conta-> conteudo.vl_saldo);
        gotoxy(58, 13);
        printf("%.2lf", conta-> conteudo.vl_limite);
        gotoxy(34, 16);
        printf("%.2lf", conta-> conteudo.vl_saldo + conta-> conteudo.vl_limite);

        strcpy(reg_movi.tp_movimentacao, ValidarTipoMovi());

        gotoxy(46, 19);
        fflush(stdin);
        fgets(reg_movi.favorecido, 30, stdin);

        reg_movi.vl_movimento = ValidarValorMovi(reg_movi.tp_movimentacao);

        gotoxy(46, 20);
        printf("%.2lf", (reg_movi.vl_saldo = conta-> conteudo.vl_saldo += (reg_movi.vl_movimento)));

        gotoxy(8, 23);
        printf("Deseja salvar a Movimentacao ? [1] Sim - [2] Nao:");
        gotoxy(58, 23);
        scanf("%d", &resp_salvar);

        if (resp_salvar == 1)
        {
            pont_movi-> conteudo_movi = reg_movi;
            SalvarMoviNaLista(lista_movi_financeira, pont_movi);
        }
    }

    gotoxy(8, 23);
    printf("Deseja cadastrar outra Movimentacao ? [1] Sim - [2] Nao:");
    gotoxy(65, 23);
    fflush(stdin);
    scanf("%d", &resp_add);

    if (resp_add == 1)
    {
        RealizarMovimentacao(lista_movi_financeira, lista_conta_bancaria);
    }
}