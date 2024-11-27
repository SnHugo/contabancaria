/*
Autor: Wesley Nobuyuki Tomimori Waterkemper

    Nome: Hugo Cesar Fernandes de Macedo        RA: 161548-2023
    Nome: Wesley Nobuyuki Tomimori Waterkemper  RA: 175944-2024

Data: 10/11/2024
Objetivo do trecho: Telas onde são trabalhadas as Movimentacoes Financeiras
*/

//include "C:\Trabalho_ControleBancario\funcoes.h"
#include "funcoes.h"
void TelaMoviFinanceira(ListaMovimentacaoFinanceira *lista_movi_financeira, Lista_ContaBancaria *lista_conta_bancaria)
{
    int opcao;
    int linha;

    do
    {
        tela();
        gotoxy(17, 10);
        printf("1. Realizar Movimentacao (Debito e Credito)");
        gotoxy(17, 12);
        printf("2. Transferencia entre Contas Bancarias");
        gotoxy(17, 14);
        printf("3. Consultar Movimentacoes Bancarias");
        gotoxy(17, 16);
        printf("4. Voltar ao Menu Principal");
        gotoxy(8, 23);
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                RealizarMovimentacao(lista_movi_financeira, lista_conta_bancaria);
                break;
            case 2:
                MoviEntreContas(lista_conta_bancaria, lista_movi_financeira);
                break;
            case 3:
                ListarMovi(lista_conta_bancaria, lista_movi_financeira);
                break;
            case 4:
                break;
            default:
                gotoxy(8, 23);
                printf("                                                                     ");
                gotoxy(8, 23);
                printf("Opcao Invalida!!!");
                getch();
                break;
        }
    }while (opcao != 4);
}

void TelaCadastroMovimentacao()
{
    tela();
    gotoxy(18, 3);
    printf("    Realizacao De Movimentacao Financeira    ");
    
    // Campos da tela da Conta
    CriarSubTela(2, 5, 78, 17);
    ExibirCampoEContornoDigitavelFrente(4, 7, "Sequencial.:", 4);
    ExibirCampoEContornoDigitavelFrente(31, 7, "Codigo.:", 2);
    ExibirCampoEContornoDigitavelFrente(55, 7, "Data.:", 10);
    ExibirCampoEContornoDigitavelFrente(4, 10, "Banco.:", 20);
    ExibirCampoEContornoDigitavelFrente(34, 10, "Agencia:", 6);
    ExibirCampoEContornoDigitavelFrente(51, 10, "Tipo Conta:", 14);
    ExibirCampoEContornoDigitavelFrente(4, 13, "Num. Conta:", 8);
    ExibirCampoEContornoDigitavelFrente(28, 13, "Saldo:", 12);
    ExibirCampoEContornoDigitavelFrente(50, 13, "Limite:", 12);
    ImprimirLinhaPorTamanho(2, 78, 15);
    gotoxy(4, 16);
    printf("Saldo Total (Saldo + Limite):");

    // Campos da tela Inferior
    // CriarSubTela(2, 18, 78, 21);
    gotoxy(3, 18);
    printf("Tipo Movimentacao.:");
    gotoxy(3, 19);
    printf("Favorecido........:");
    gotoxy(3, 20);
    printf("Valor Movimentacao:");
    gotoxy(3, 21);
    printf("Novo saldo........:");
}

void TelaExibirContaDasMovimentacoes()
{
    tela();
    gotoxy(18, 3);
    printf("    Consulta da Movimentacao Financeira    ");

    ImprimirLinhaPorTamanho(1, 79, 6);
    ImprimirColunaPorTamanho(12, 4, 6);
    ImprimirColunaPorTamanho(32, 4, 6);
    ImprimirColunaPorTamanho(46, 4, 6);
    ImprimirColunaPorTamanho(60, 4, 6);

    ImprimirLinhaPorTamanho(2, 13, 8);
    ImprimirLinhaPorTamanho(13, 35, 8);
    ImprimirLinhaPorTamanho(35, 51, 8);
    ImprimirLinhaPorTamanho(51, 64, 8);
    ImprimirLinhaPorTamanho(65, 78, 8);

    gotoxy(3, 7);
    printf("Data Movi.");
    gotoxy(14, 7);
    printf("Favorecido");
    gotoxy(36, 7);
    printf("Tipo Movi.");
    gotoxy(52, 7);
    printf("Valor Movi.");
    gotoxy(66, 7);
    printf("Valor Saldo");
}

void TelaExibirMovimentacoesCadastradas(TipoApontadorMovi reg_movi, int linha)
{
    gotoxy(3, linha);
    printf("%s", reg_movi-> conteudo_movi.dt_movimento);
    gotoxy(14, linha);
    printf("%s", reg_movi-> conteudo_movi.favorecido);
    gotoxy(36, linha);
    printf("%s", reg_movi-> conteudo_movi.tp_movimentacao);
    gotoxy(52, linha);
    printf("R$ %.2lf", reg_movi-> conteudo_movi.vl_movimento);
    gotoxy(66, linha);
    printf("R$ %.2lf", reg_movi-> conteudo_movi.vl_saldo);
}

void TelaMoviEntreContasMovi (TipoApontadorConta conta_movi)
{
    tela();
    gotoxy(3, 8);
    printf("Codigo....: %d", conta_movi-> conteudo.cd_conta);
    gotoxy(3, 9);
    printf("Banco.....: %s", conta_movi-> conteudo.banco);
    gotoxy(3, 10);
    printf("Agencia...: %s", conta_movi-> conteudo.agencia);
    gotoxy(3, 11);
    printf("Tipo Conta: %s", conta_movi-> conteudo.tipo_conta);
    gotoxy(3, 12);
    printf("Num. Conta: %s", conta_movi-> conteudo.numero_conta);
    gotoxy(3, 13);
    printf("Saldo.....: %lf", conta_movi-> conteudo.vl_saldo);
    gotoxy(3, 14);
    printf("Limite....: %lf", conta_movi-> conteudo.vl_limite);
    gotoxy(3, 15);
    printf("Total.....: %lf", conta_movi-> conteudo.vl_saldo + conta_movi-> conteudo.vl_limite);

    ImprimirColunaPorTamanho(34, 4, 24);
}

void TelaMoviEntreContasReceb (TipoApontadorConta conta_receb)
{
    gotoxy(35, 8);
    printf("Codigo....: %d", conta_receb-> conteudo.cd_conta);
    gotoxy(35, 9);
    printf("Banco.....: %s", conta_receb-> conteudo.banco);
    gotoxy(35, 10);
    printf("Agencia...: %s", conta_receb-> conteudo.agencia);
    gotoxy(35, 11);
    printf("Tipo Conta: %s", conta_receb-> conteudo.tipo_conta);
    gotoxy(35, 12);
    printf("Num. Conta: %s", conta_receb-> conteudo.numero_conta);
    gotoxy(35, 13);
    printf("Saldo.....: %lf", conta_receb-> conteudo.vl_saldo);
    gotoxy(35, 14);
    printf("Limite....: %lf", conta_receb-> conteudo.vl_limite);
    gotoxy(35, 15);
    printf("Total.....: %lf", conta_receb-> conteudo.vl_saldo + conta_receb-> conteudo.vl_limite);

    ImprimirLinhaPorTamanho(1, 79, 18);
}