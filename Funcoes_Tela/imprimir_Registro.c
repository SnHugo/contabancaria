/*
Autor: Hugo Cesar Fernandes de Macedo
Data: 23/11/2024
Objetivo do trecho: Imprimir registro das contas selecionadas
*/
#include "C:\Trabalho_ControleBancario\funcoes.h"

void imprimir_Registro(ContaBancaria reg_conta)
{
    tela();

    gotoxy(10, 6);
    printf("Codigo............: %d", reg_conta.cd_conta);
    gotoxy(10, 8);
    printf("[1] Banco........: %s", reg_conta.banco);
    gotoxy(10, 10);
    printf("[2] Agencia......: %s", reg_conta.agencia);
    gotoxy(10, 12);
    printf("[3] Numero conta.: %s", reg_conta.numero_conta);
    gotoxy(10, 14);
    printf("[4] Tipo conta...: %s", reg_conta.tipo_conta);
    gotoxy(10, 16);
    printf("[5] Saldo........: %.2lf", reg_conta.vl_saldo);
    gotoxy(10, 18);
    printf("[6] Limite.......: %.2lf", reg_conta.vl_limite);
    gotoxy(10, 20);
    printf("[7] Status.......: %s", reg_conta.status);
}
