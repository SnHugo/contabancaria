#include "C:\Trabalho_ControleBancario\funcoes.h"



// ListaMovimentacaoFinanceira *BuscarMoviPorCodigo(TipoApontador reg_conta, ListaMovimentacaoFinanceira *lista_movi)
// {
//     TipoApontadorMovi aux_movi = lista_movi-> Primeiro;

//     if (aux_movi != NULL)
//     {

//         while (aux_movi != NULL)
//         {
//             if (reg_conta-> conteudo.cd_conta == aux_movi-> conteudo_movi.cd_conta)
//             {
//                 if (lista_movi_da_conta-> Primeiro == NULL)
//                 {
//                     aux_movi-> anterior = NULL;
//                     aux_movi-> proximo = NULL;
//                     lista_movi_da_conta-> Primeiro = aux_movi;
//                 }
//                 else
//                 {
//                     aux_movi-> anterior = lista_movi_da_conta-> Ultimo;
//                     aux_movi-> proximo = NULL;
//                     aux_movi = lista_movi_da_conta-> Ultimo-> proximo;
//                 }
//                 lista_movi_da_conta-> Ultimo = aux_movi;
//             }
//             aux_movi = aux_movi-> proximo;
//         }
//         return lista_movi_da_conta;
//     }
//     else
//     {
//         gotoxy(8, 23);
//         printf("Erro: Lista Vazia!!!");
//         getch();
//         LimparMensagem();
//     }
//     return NULL;
// }

void ListarMovi(Lista_ContaBancaria *lista_conta, ListaMovimentacaoFinanceira *lista_movi)
{
    TipoApontadorConta conta_selecionada;
    TipoApontadorMovi reg_movi;
    ListaMovimentacaoFinanceira *lista_movi_da_conta;
    int linha = 9;
    int resp_consulta;
    
    TelaExibirContaDasMovimentacoes();

    gotoxy(2, 5);
    printf("Codigo:");
    gotoxy(10, 5);
    conta_selecionada = ValidarConta(lista_conta, 10, 5);

    if (conta_selecionada != NULL)
    {
        gotoxy(13, 5);
        printf("%s", conta_selecionada-> conteudo.banco);
        gotoxy(33, 5);
        printf("Agenc:");
        gotoxy(40, 5);
        printf("%s", conta_selecionada-> conteudo.agencia);
        gotoxy(47, 5);
        printf("Cta:");
        gotoxy(52, 5);
        printf("%s", conta_selecionada-> conteudo.numero_conta);
        gotoxy(61, 5);
        printf("Tp:");
        gotoxy(65, 5);
        printf("%s", conta_selecionada-> conteudo.tipo_conta);
    }
    else
    {
        return;
    }

    // lista_movi_da_conta = BuscarMoviPorCodigo(conta_selecionada, lista_movi);
    reg_movi = lista_movi-> Primeiro;

    if (reg_movi != NULL)
    {
        while (reg_movi != NULL)
        {
            if (conta_selecionada-> conteudo.cd_conta == reg_movi-> conteudo_movi.cd_conta)
            {
                TelaExibirMovimentacoesCadastradas(reg_movi, linha);
                reg_movi = reg_movi-> proximo;
                linha++;
            }
        }
    }
    else
    {
        LimparMensagem();
        gotoxy(8, 23);
        printf("Nao ha Movimentacoes Cadastradas nessa Conta!!!");
        getch();
    }

    LimparMensagem();
    gotoxy(8, 23);
    printf("Deseja Consultar as Movimentacoes de Outra Conta ? [1]Sim [2]Nao:");
    gotoxy(74, 23);
    fflush(stdin);
    scanf("%d", &resp_consulta);

    if (resp_consulta == 1)
    {
        ListarMovi(lista_conta, lista_movi);
    }
}