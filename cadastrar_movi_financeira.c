/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 10/11/2024
Objetivo do trecho: Realizar o cadastro de uma movimentacao financeira
*/

//#include "C:\Trabalho_ControleBancario\funcoes.h"
#include "funcoes.h"


TipoApontadorConta ValidarConta (Lista_ContaBancaria *lista_conta_bancaria, int x, int y)
{
    int codigo;

    do
    {
        gotoxy(8, 23);
        printf("Digite 0 para sair...                                                ");
        gotoxy(x, y);
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

char *ValidarTipoMovi (int x, int y)
{
    int opcao;
    char *tipo_movi = malloc(8 * sizeof(char));

    do
    {
        LimparMensagem();
        gotoxy(x, y);
        printf("1. Debito - 2. Credito");
        gotoxy(23, 18);
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
                LimparMensagem();
        }

    }while(opcao != 1 && opcao != 2);

    gotoxy(23, 18);
    printf("%s", tipo_movi);
    LimparMensagem();

    return tipo_movi;
}

double ValidarValorMovi (MovimentacaoFinanceira reg_movi, TipoApontadorConta conta, int x, int y)
{
    double valor;
    do
    {
        gotoxy(x, y);
        fflush(stdin);
        scanf("%lf", &valor);
        
        if (valor > 0 && (conta-> conteudo.vl_saldo + conta-> conteudo.vl_limite) >= valor)
        {
            if (strcmp(reg_movi.tp_movimentacao, "Debito") == 0)
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
            LimparMensagem();
            gotoxy(23, 20);
            printf("                ");
        }
    }while (TRUE);
}

int ValidarSequencialMovi (ListaMovimentacaoFinanceira *lista_movi)
{
    TipoApontadorMovi pont_movi = lista_movi-> Ultimo;

    if (pont_movi != NULL)
    {
        return pont_movi-> conteudo_movi.sequencial + 1;
    }
    return 1;
}

void SalvarMoviNaLista(ListaMovimentacaoFinanceira *lista_movi, TipoApontadorMovi pont_movi)
{
    if (lista_movi-> Primeiro == NULL)
    {
        pont_movi-> anterior = NULL;
        pont_movi-> proximo = NULL;
        lista_movi-> Primeiro = pont_movi;
    }
    else
    {
        pont_movi-> anterior = lista_movi-> Ultimo;
        pont_movi-> proximo = NULL;
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
    
    TelaCadastroMovimentacao();
    gotoxy(17, 7);
    printf("%d", reg_movi.sequencial = ValidarSequencialMovi(lista_movi_financeira));

    TipoApontadorConta conta = ValidarConta(lista_conta_bancaria, 40, 7);
    
    if (conta != NULL)
    {     
        gotoxy(12, 10);
        printf("%s", conta-> conteudo.banco);
        gotoxy(43, 10);
        printf("%s", conta-> conteudo.agencia);
        gotoxy(63, 10);
        printf("%s", conta-> conteudo.tipo_conta);
        gotoxy(16, 13);
        printf("%s", conta-> conteudo.numero_conta);
        gotoxy(35, 13);
        printf("%.2lf", conta-> conteudo.vl_saldo);
        gotoxy(58, 13);
        printf("%.2lf", conta-> conteudo.vl_limite);
        gotoxy(34, 16);
        printf("%.2lf", conta-> conteudo.vl_saldo + conta-> conteudo.vl_limite);

        strcpy(reg_movi.dt_movimento, ValidarData(lista_movi_financeira, conta-> conteudo.cd_conta, 62, 7));

        strcpy(reg_movi.tp_movimentacao, ValidarTipoMovi(23, 18));

        gotoxy(23, 19);
        fflush(stdin);
        fgets(reg_movi.favorecido, 30, stdin);

        reg_movi.vl_movimento = ValidarValorMovi(reg_movi, conta, 23, 20);

        gotoxy(23, 21);
        printf("%.2lf", (reg_movi.vl_saldo = conta-> conteudo.vl_saldo += (reg_movi.vl_movimento)));

        do
        {
            gotoxy(8, 23);
            printf("Deseja salvar a Movimentacao ? [1] Sim - [2] Nao:");
            gotoxy(58, 23);
            fflush(stdin);
            scanf("%d", &resp_salvar);

            switch (resp_salvar)
            {
                case 1:
                    reg_movi.cd_conta = conta-> conteudo.cd_conta;
                    pont_movi-> conteudo_movi = reg_movi;
                    SalvarMoviNaLista(lista_movi_financeira, pont_movi);
                    break;
                case 2:
                    break;
                default:
                    LimparMensagem();
                    gotoxy(8, 23);
                    printf("Digite uma opcao Valida!!!");
                    getch();
                    break;
            }

        }while (resp_salvar != 1 && resp_salvar != 2);
    }

    do
    {
        gotoxy(8, 23);
        printf("Deseja cadastrar outra Movimentacao ? [1] Sim - [2] Nao:");
        gotoxy(65, 23);
        fflush(stdin);
        scanf("%d", &resp_add);

        switch (resp_add)
        {
            case 1:
                if (resp_add == 1)
                {
                    RealizarMovimentacao(lista_movi_financeira, lista_conta_bancaria);
                }
            case 2:
                break;
            default:
                LimparMensagem();
                gotoxy(8, 23);
                printf("Digite uma opcao Valida!!!");
                getch();
                break;
        }

    }while (resp_add != 1 && resp_add != 2);
}