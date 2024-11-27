/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 26/11/2024
Objetivo do trecho: Funcao para reaizar Movimentacao entre duas contas
*/

//include "C:\Trabalho_ControleBancario\funcoes.h"
#include "funcoes.h"


void MoviEntreContas (Lista_ContaBancaria *lista_conta, ListaMovimentacaoFinanceira *lista_movi)
{
    MovimentacaoFinanceira reg_movi;
    TipoApontadorMovi pont_movi = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));
    TipoApontadorConta conta_movi;
    TipoApontadorConta conta_receb;
    int resp_salvar;
    int resp_add;

    tela();
    conta_movi = ValidarConta(lista_conta, 18, 8);
    conta_receb = ValidarConta(lista_conta, 50, 8);
    if (conta_movi != NULL)
    {
        TelaMoviEntreContasMovi(conta_movi);

        if (conta_receb != NULL)
        {
            TelaMoviEntreContasReceb(conta_receb);

            ExibirCampoEContornoDigitavelFrente(3, 20, "Sequencial", 3);
            gotoxy(14, 18);
            printf("%d", reg_movi.sequencial = ValidarSequencialMovi(lista_movi));
            
            strcpy(reg_movi.favorecido, "Debito");
            ExibirCampoEContornoDigitavelFrente(19, 20, "Valor a Traferir", 10);
            reg_movi.vl_movimento = ValidarValorMovi(reg_movi, conta_movi, 36, 18);

            ExibirCampoEContornoDigitavelFrente(48, 20, "Data Tranferencia", 10);
            strcpy(reg_movi.dt_movimento, ValidarData(lista_movi, conta_movi-> conteudo.cd_conta, 66, 18));

            strcpy(reg_movi.favorecido, conta_receb-> conteudo.banco);

            conta_movi-> conteudo.vl_saldo += reg_movi.vl_movimento;
            conta_receb-> conteudo.vl_saldo -= reg_movi.vl_movimento;

            gotoxy(03, 16);
            printf("Novo Saldo: %lf", conta_movi-> conteudo.vl_saldo);
            gotoxy(35, 16);
            printf("Novo Saldo: %lf", conta_receb-> conteudo.vl_saldo);
        }
        
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
                    reg_movi.cd_conta = conta_movi-> conteudo.cd_conta;
                    pont_movi-> conteudo_movi = reg_movi;
                    SalvarMoviNaLista(lista_movi, pont_movi);
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
                    MoviEntreContas(lista_conta, lista_movi);
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