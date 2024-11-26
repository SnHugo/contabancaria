/*
Autor: Wesley Nobuyuki Tomimori Waterkemper
Data: 25/11/2024
Objetivo do trecho: Listar as movimentações financeiras
*/

//#include "C:\Trabalho_ControleBancario\funcoes.h"
#include "C:\Trabalho_ControleBancario\funcoes.h"
void LiberarMemoriaLista(ListaMovimentacaoFinanceira *lista_movi)
{
    TipoApontadorMovi pont = lista_movi-> Primeiro;
    TipoApontadorMovi prox;

    while (pont != NULL)
    {
        prox = pont-> proximo;
        free(pont);
        pont = prox;
    }
    free(lista_movi);
}

ListaMovimentacaoFinanceira *BuscarMoviPorCodigo(int codigo_conta, ListaMovimentacaoFinanceira *lista_movi)
{
    TipoApontadorMovi aux_movi = lista_movi-> Primeiro;
    ListaMovimentacaoFinanceira *lista_movi_da_conta;
    lista_movi_da_conta-> Primeiro = NULL;
    lista_movi_da_conta-> Ultimo = NULL;
    
    if (aux_movi != NULL)
    {
        while (aux_movi != NULL)
        {
            if (codigo_conta == aux_movi-> conteudo_movi.cd_conta)
            {
                TipoApontadorMovi novo_movi = (TipoApontadorMovi)malloc(sizeof(TipoMovimentacao));
                
                novo_movi-> conteudo_movi = aux_movi-> conteudo_movi;
                if (lista_movi_da_conta-> Primeiro == NULL)
                {
                    novo_movi-> anterior = NULL;
                    novo_movi-> proximo = NULL;
                    lista_movi_da_conta-> Primeiro = novo_movi;
                }
                else
                {
                    novo_movi-> anterior = lista_movi_da_conta-> Ultimo;
                    novo_movi-> proximo = NULL;
                    lista_movi_da_conta-> Ultimo-> proximo = novo_movi;
                }
                lista_movi_da_conta-> Ultimo = novo_movi;
            }
            aux_movi = aux_movi-> proximo;
        }
        return lista_movi_da_conta;
    }
    else
    {
        gotoxy(8, 23);
        printf("Erro: Lista Vazia!!!");
        getch();
        LimparMensagem();
    }
    return NULL;
}

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

    lista_movi_da_conta = BuscarMoviPorCodigo(conta_selecionada-> conteudo.cd_conta, lista_movi);
    reg_movi = lista_movi_da_conta-> Primeiro;

    if (reg_movi != NULL)
    {
        while (reg_movi != NULL)
        {
            TelaExibirMovimentacoesCadastradas(reg_movi, linha);
            reg_movi = reg_movi-> proximo;
            if (linha == 21)
            {
                gotoxy(8, 23);
                printf("Pressione qualquer tecla para ver as proximas Movimentacoes...");
                getch();
                LimparPosicaoNaTela(3, 8, 77, 21);
                linha = 8;
            }
            else
            {
                linha++;
            }
        }
        LiberarMemoriaLista(lista_movi_da_conta);
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

    switch (resp_consulta)
    {
        case 1:
            if (resp_consulta == 1)
            {
                ListarMovi(lista_conta, lista_movi);
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
}