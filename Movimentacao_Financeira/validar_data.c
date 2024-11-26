/*
Aluno: Wesley Nobuyuki Tomimori Waterkemper
Data: 20/11/2024
Objetivo do trecho: Validar a data para evitar o bug do milênio
*/

//#include "C:\Trabalho_ControleBancario\funcoes.h"
#include "C:\Users\User\Documents\Tudo em C\Estrutura de dados\funcoes.h"

TipoApontadorMovi BuscarUltimaData(ListaMovimentacaoFinanceira *lista_movi, int codigo)
{
    TipoApontadorMovi pont_movi = lista_movi->Ultimo;

    if (pont_movi != NULL)
    {
        while (pont_movi != NULL)
        {
            if (pont_movi->conteudo_movi.cd_conta == codigo)
            {
                return pont_movi;
            }
            pont_movi = pont_movi-> anterior;
        }
    }

    return NULL;
}

char *InverterData (char *dt_data)
{
    char *data_invertida = malloc(11 * sizeof(char));
    char dia[3];
    char mes[3];
    char ano[5];

    strncpy(dia, dt_data, 2);
    dia[2] = '\0';

    strncpy(mes, dt_data + 3, 2);
    mes[2] = '\0';

    strncpy(ano, dt_data + 6, 4);
    ano[4] = '\0';

    sprintf(data_invertida, "%s/%s/%s", ano, mes, dia);

    return data_invertida;
}

char *ValidarData (ListaMovimentacaoFinanceira *lista_movi, int codigo)
{
    char *dt_data = malloc(sizeof(char) * 11);
    char dt_inserida[11];
    char dt_ultima[11];
    int ano_inserido, mes_inserido, dia_inserido;
    int ultimo_ano, ultimo_mes, ultimo_dia;

    TipoApontadorMovi pont_movi = BuscarUltimaData(lista_movi, codigo);

    do
    {
        gotoxy(62, 7);
        printf("          ");
        gotoxy(62, 7);
        fflush(stdin);
        fgets(dt_data, 11, stdin);

        strcpy(dt_inserida, InverterData(dt_data));

        ano_inserido = atoi(dt_inserida);
        mes_inserido = atoi(&dt_inserida[5]);
        dia_inserido = atoi(&dt_inserida[8]);

        if (dt_inserida[4] != '/' && dt_inserida[7] != '/')
        {
            gotoxy(8, 23);
            printf("Erro: Formato Invalido!!! (DD/MM/AAAA)");
            getch();
            gotoxy(8, 23);
            LimparMensagem();
            continue;
        }

        if (pont_movi != NULL)
        {
            strcpy(dt_ultima, InverterData(pont_movi-> conteudo_movi.dt_movimento));
        
            if (strcmp(dt_inserida, dt_ultima) < 0)
            {
                gotoxy(8, 23);
                printf("Erro: Digite uma data maior ou igual a %s", pont_movi-> conteudo_movi.dt_movimento);
                getch();
                gotoxy(8, 23);
                LimparMensagem();
                continue;
            }
        }

        if (ano_inserido < 2024 || ano_inserido > 2025)
        {
            gotoxy(8, 23);
            printf("Erro: Digite uma data no ano de 2024 a 2025!!!");
            getch();
            gotoxy(8, 23);
            LimparMensagem();
            continue;
        }

        if (mes_inserido > 12 || mes_inserido < 0)
        {
            gotoxy(8, 23);
            printf("Erro: Digite um mes valido!!!");
            getch();
            gotoxy(8, 23);
            LimparMensagem();
            continue;
        }

        if (dia_inserido > 31 || dia_inserido < 0)
        {
            gotoxy(8, 23);
            printf("Erro: Digite um dia valido!!!");
            getch();
            gotoxy(8, 23);
            LimparMensagem();
            continue;
        }
        break;
    }while (TRUE);

    return dt_data;
}