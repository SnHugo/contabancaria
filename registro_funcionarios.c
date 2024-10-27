#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// Estrutura typedef
typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char cargo[30];
    char telefone[20];
    char dt_admissao[50];
    float salario;
} reg_funcionario;

// Ponteiro
typedef struct TipoItem *TipoApontador;

// Estrutura para armazenar o conteudo
typedef struct TipoItem
{
    reg_funcionario conteudo;
    TipoApontador proximo;
} TipoItem;

// Estrutura para aterrar o ponteiro
typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

// Setar cursor na tela
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Montar a tela
void tela()
{
    int t;
    system("cls");
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(60, 02);
    printf("Estrutura de Dados |");
    gotoxy(66, 03);
    printf("Prof. Rodney");
    gotoxy(01, 03);
    printf("|");
    gotoxy(20, 02);
    printf("Alocamento de Contas Bancarias");
    gotoxy(79, 03);
    printf("|");
    gotoxy(01, 04);
    printf("+-----------------------------------------------------------------------------+");
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(79, t);
        printf("|");
    }
    gotoxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
}
void iniciar_Lista(TipoLista *lista)
{
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
}

// Funcao para imprimir o registro na edicao
void imprimir_Registro(reg_funcionario reg_func)
{
    tela();

    gotoxy(10, 7);
    printf("[1] Codigo.........: %d", reg_func.codigo);
    gotoxy(10, 9);
    printf("[2] Nome.........: %s", reg_func.nome);
    gotoxy(10, 11);
    printf("[3] Endereco.....: %s", reg_func.endereco);
    gotoxy(10, 13);
    printf("[4] Cargo........: %s", reg_func.cargo);
    gotoxy(10, 15);
    printf("[5] Data Admissao: %s", reg_func.dt_admissao);
    gotoxy(10, 17);
    printf("[6] Telefone.....: %s", reg_func.telefone);
    gotoxy(10, 19);
    printf("[7] Salario......: %.2f", reg_func.salario);
}

// Montar a tela dos funcionarios
void tela_funcionario()
{
    gotoxy(07, 7);
    printf("Digite o Codigo do funcionario: ");
    gotoxy(07, 9);
    printf("Digite o nome do funcionario..: ");
    gotoxy(07, 11);
    printf("Digite o endereco.............: ");
    gotoxy(07, 13);
    printf("Digite o cargo................: ");
    gotoxy(07, 15);
    printf("Digite o telefone.............: ");
    gotoxy(07, 17);
    printf("Digite a data de admissao.....: ");
    gotoxy(07, 19);
    printf("Digite o salario..............: ");
}

// Funcao para contar os elementos da lista
int contador(TipoLista *L)
{
    TipoApontador aux;
    int cont = 0;

    aux = L->Primeiro;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

// Funcao para pesquisa
TipoApontador pesquisa(TipoLista *L, reg_funcionario reg_func)
{
    TipoApontador aux = L->Primeiro;

    while (aux != NULL)
    {
        if (aux->conteudo.codigo == reg_func.codigo)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// Cadastro de funcionarios
void cadastrar_funcionario(TipoLista *L, int opc)
{
    TipoApontador p, r;
    reg_funcionario reg_func;
    int resp, resp2 = 1, num;

    do
    {
        system("cls");
        tela();
        tela_funcionario();
        do
        {
            gotoxy(7, 23);
            printf("                                                      ");
            gotoxy(7, 23);
            printf("Digite 0 para sair");
            gotoxy(25, 6);
            printf("                                 ");
            gotoxy(39, 7);
            scanf("%d", &reg_func.codigo);
            getchar();

            if (reg_func.codigo == 0)
            {
                return;
            }

            if (pesquisa(L, reg_func) != NULL)
            {
                gotoxy(7, 23);
                printf("                                       ");
                gotoxy(7, 23);
                printf("O codigo '%d' ja esta cadastrado!", reg_func.codigo);
                getch();
                gotoxy(39, 7);
                printf("                              ");
            }

        } while (pesquisa(L, reg_func) != NULL);

        // Ler o nome
        gotoxy(39, 9);
        fflush(stdin);
        fgets(reg_func.nome, 50, stdin);

        // Ler o endereço
        gotoxy(39, 11);
        fflush(stdin);
        fgets(reg_func.endereco, 50, stdin);

        // Ler o cargo
        gotoxy(39, 13);
        fflush(stdin);
        fgets(reg_func.cargo, 50, stdin);

        // Ler a data de admissão
        gotoxy(39, 15);
        fflush(stdin);
        fgets(reg_func.dt_admissao, 11, stdin);

        // Ler o telefone
        gotoxy(39, 17);
        fflush(stdin);
        fgets(reg_func.telefone, 20, stdin);

        // Ler o salário
        gotoxy(39, 19);
        fflush(stdin);
        scanf("%f", &reg_func.salario);

        // Confirmação de gravação
        gotoxy(7, 23);
        printf("Deseja gravar no sistema?: [1] Sim [2] Nao: ");
        fflush(stdin);
        scanf("%d", &resp);
        getchar();

        if (resp == 1)
        {
            p = (TipoApontador)malloc(sizeof(TipoItem));
            p->conteudo = reg_func;
            p->proximo = NULL;
            if (p == NULL)
            {
                gotoxy(07, 23);
                printf("Erro na alocação da memória!");
                return;
            }
            // Adicionar no final
            if (opc == 2)
            {
                if (L->Primeiro == NULL)
                {
                    L->Primeiro = p;
                    L->Ultimo = p;
                }
                else
                {
                    L->Ultimo->proximo = p;
                    L->Ultimo = p;
                    p->proximo = NULL;
                }
            }
            // Adicionar no inicio
            else if (opc == 1)
            {
                if (L->Primeiro == NULL)
                {
                    L->Primeiro = p;
                    L->Ultimo = p;
                }
                else
                {
                    p->proximo = L->Primeiro;
                    L->Primeiro = p;
                }
            }
            // Adicionar na opcao desejada
            else if (opc == 3)
            {
                if (L->Primeiro != NULL)
                {
                    do
                    {
                        gotoxy(7, 23);
                        printf("                                                    ");
                        gotoxy(7, 23);
                        printf("Digite a posicao para inserir: ");
                        scanf("%d", &num);
                        getchar();

                        if (num < 1 || num > contador(L))
                        {
                            gotoxy(7, 23);
                            printf("Digite uma posicao valida!         ");
                            getch();
                        }
                    } while (num < 1 || num > contador(L));
                }
                if (num == 1)
                {
                    p->proximo = L->Primeiro;
                    L->Primeiro = p;

                    if (L->Ultimo == NULL)
                    {
                        L->Ultimo = p;
                    }
                }
                else
                {
                    r = (TipoApontador)malloc(sizeof(TipoItem));
                    if (r == NULL)
                    {
                        gotoxy(07, 23);
                        printf("Erro na alocação da memoria!");
                        return;
                    }
                    r->conteudo = reg_func;
                    p = L->Primeiro;
                    for (int x = 1; x < num - 1; x++)
                    {
                        p = p->proximo;
                    }
                    r->proximo = p->proximo;
                    p->proximo = r;
                }
            }
        }
        else if (resp != 2)
        {
            gotoxy(7, 23);
            printf("                                           ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
        }

        gotoxy(7, 23);
        printf("                                                    ");
        gotoxy(7, 23);
        printf("Deseja cadastrar outro? [1] Sim [2] Nao: ");
        scanf("%d", &resp2);
        getchar();

        if (resp2 != 1 && resp2 != 2)
        {
            gotoxy(7, 23);
            printf("                                             ");
            gotoxy(7, 23);
            printf("Opcao invalida!");
            getch();
        }

    } while (resp2 == 1);
}

// Remover Funcionario
void remover_funcionario(TipoLista *L, int opc)
{
    TipoApontador p;
    TipoApontador r;
    int resp;
    int num;
    int cont;

    do
    {
        system("cls");
        tela();
        do
        {
            gotoxy(07, 23);
            printf("                                     ");
            gotoxy(07, 23);
            printf("Digite 0 para sair. ");

            // Remover funcionario no inicio
            gotoxy(07, 23);
            printf("Deseja fazer a exclusao? [1]Sim [0]Nao:");
            gotoxy(46, 23);
            scanf("%d", &resp);
            getchar();

            if (resp == 1)
            {
                if (opc == 4)
                {
                    p = L->Primeiro;
                    L->Primeiro = p->proximo;
                    free(p);

                    if (L->Primeiro == NULL)
                    {
                        L->Ultimo = NULL;
                    }

                    gotoxy(07, 23);
                    printf("                                             ");
                    gotoxy(07, 23);
                    printf("Funcionario excluido!");
                    getch();
                }
                // Remover funcionario no final
                else if (opc == 5)
                {
                    if (L->Primeiro->proximo == NULL)
                    {
                        free(L->Primeiro);
                        L->Primeiro = NULL;
                        L->Ultimo = NULL;
                    }
                    r = L->Primeiro;
                    p = r->proximo;
                    while (p->proximo != NULL)
                    {
                        p = p->proximo;
                        r = r->proximo;
                    }
                    free(p);

                    gotoxy(07, 23);
                    printf("Funcionario excluido!");
                    getch();
                }
                // Remover funcionario na posicao
                else if (opc == 6)
                {
                    gotoxy(5, 7);
                    printf("Digite a posicao a ser removida:    ");
                    gotoxy(58, 7);
                    scanf("%d", &num);
                    getch();

                    r = L->Primeiro;
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
                    printf("Funcionario excluido!");
                    getch();
                }
            }
        } while (resp != 0 && resp != 1);

    } while (resp != 0 && resp != 1);
}

// Alterar funcionario cadastrado
void alterar_funcionario(TipoLista *L)
{
    int opcao_alterar;
    int opcao_denovo;
    int opcao_salvar;
    reg_funcionario reg_func;

    TipoApontador resp = (TipoApontador)malloc(sizeof(TipoItem));

    do
    {
        tela();
        do
        {
            gotoxy(07, 23);
            printf("                                                        ");
            gotoxy(07, 23);
            printf("Digite o codigo que deseja alterar: ");
            gotoxy(44, 23);
            fflush(stdin);
            scanf("%d", &reg_func.codigo);

            resp = pesquisa(L, reg_func);

            if (resp == NULL)
            {
                gotoxy(07, 23);
                printf("Erro: Codigo nao encontrado.");
                getch();
                gotoxy(07, 23);
                printf("Deseja digitar novamente ? [1]Sim [2]Nao:");
                gotoxy(43, 23);
                fflush(stdin);
                scanf("%d", &opcao_denovo);

                if (opcao_denovo == 2)
                {
                    return;
                }
            }
        } while (resp == NULL);

        reg_func = resp->conteudo;
        imprimir_Registro(resp->conteudo);

        do
        {
            gotoxy(07, 23);
            printf("Digite qual o numero que deseja alterar:");
            gotoxy(49, 23);
            fflush(stdin);
            scanf("%d", &opcao_alterar);

            switch (opcao_alterar)
            {
            case 1:
                gotoxy(27, 9);
                printf("                                                 ");
                gotoxy(27, 9);
                fflush(stdin);
                fgets(reg_func.nome, 50, stdin);
                break;
            case 2:
                gotoxy(27, 11);
                printf("                                                 ");
                gotoxy(27, 11);
                fflush(stdin);
                fgets(reg_func.endereco, 40, stdin);
                break;
            case 3:
                gotoxy(27, 13);
                printf("                                                 ");
                gotoxy(27, 13);
                fflush(stdin);
                fgets(reg_func.cargo, 40, stdin);
                break;
            case 4:
                gotoxy(27, 15);
                printf("                                                 ");
                gotoxy(27, 15);
                fflush(stdin);
                fgets(reg_func.dt_admissao, 10, stdin);
                break;
            case 5:
                gotoxy(27, 17);
                printf("                                                 ");
                gotoxy(27, 17);
                fflush(stdin);
                fgets(reg_func.telefone, 15, stdin);
                break;
            case 6:
                gotoxy(27, 19);
                printf("                                                 ");
                gotoxy(27, 19);
                fflush(stdin);
                scanf("%f", &reg_func.salario);
                break;
            case 0:
                break;
            default:
                gotoxy(07, 23);
                printf("Opcao invalida.");
                getch();
            }
            gotoxy(07, 23);
            printf("Deseja alterar outro dado ? [1]Sim [2]Nao:  ");
            gotoxy(46, 23);
            fflush(stdin);
            scanf("%d", &opcao_alterar);

        } while (opcao_alterar != 0 && opcao_alterar != 2);

        gotoxy(07, 23);
        printf("                                                        ");
        gotoxy(07, 23);
        printf("Deseja salvar os dados alterados ? [1]Sim [2]Nao:   ");
        gotoxy(62, 23);
        fflush(stdin);
        scanf("%d", &opcao_salvar);

        if (opcao_salvar == 1)
        {
            resp->conteudo = reg_func;
        }

    } while (opcao_alterar != 0 && opcao_alterar != 2);
}

// Mostrar dados cadastrados
void mostrar_funcionarios(TipoLista *L)
{
    TipoApontador p = L->Primeiro;
    if (p == NULL)
    {
        gotoxy(07, 23);
        printf("Nenhum funcionario cadastrado.\n");
        getch();
        return;
    }

    while (p != NULL)
    {
        gotoxy(10, 6);
        printf("[1] Codigo..........:       %d\n", p->conteudo.codigo);
        gotoxy(10, 8);
        printf("[2] Nome............:       %s", p->conteudo.nome);
        gotoxy(10, 10);
        printf("[3] Endereco........:       %s", p->conteudo.endereco);
        gotoxy(10, 12);
        printf("[4] Cargo...........:       %s", p->conteudo.cargo);
        gotoxy(10, 14);
        printf("[5] Telefone........:       %s", p->conteudo.telefone);
        gotoxy(10, 16);
        printf("[6] Data de admissao:       %s", p->conteudo.dt_admissao);
        gotoxy(10, 18);
        printf("[7] Salario.........:       %.2f", p->conteudo.salario);
        getch();
        p = p->proximo;
    }
}
void inserir_NoArquivo(TipoLista *lista, reg_funcionario funcionario)
{
    TipoApontador novo_no = (TipoApontador)malloc(sizeof(TipoItem));

    if (novo_no)
    {
        novo_no->conteudo = funcionario;
        novo_no->proximo = NULL;

        if (lista->Primeiro == NULL)
        {
            lista->Primeiro = novo_no;
        }
        else
        {
            lista->Ultimo->proximo = novo_no;
        }
        lista->Ultimo = novo_no;
    }
    else
    {
        gotoxy(07, 23);
        printf("Erro: Falha ao alocar memoria!");
    }
}

void salvar_Arquivo(TipoLista *lista)
{
    FILE *FOLHA = fopen("FOLHA.dat", "wb");

    if (FOLHA != NULL)
    {
        TipoApontador percorrer = lista->Primeiro;

        while (percorrer != NULL)
        {
            fwrite(&percorrer->conteudo, sizeof(reg_funcionario), 1, FOLHA);
            percorrer = percorrer->proximo;
        }
        gotoxy(07, 23);
        printf("Arquivos Salvos com Sucesso!");
    }
    else
    {
        gotoxy(07, 23);
        printf("Erro: Falha ao abrir arquivo!");
    }

    fclose(FOLHA);
}

TipoLista ler_Arquivo()
{
    reg_funcionario funcionario;
    TipoLista lista;
    iniciar_Lista(&lista); // Inicia a lista

    FILE *FOLHA = fopen("FOLHA.dat", "rb");

    if (FOLHA != NULL)
    {
        while (fread(&funcionario, sizeof(reg_funcionario), 1, FOLHA))
        {
            inserir_NoArquivo(&lista, funcionario);
        }
        gotoxy(07, 23);
        printf("Arquivos Carregados com Sucesso!");
    }
    else
    {
        gotoxy(07, 23);
        printf("Erro: Falha ao abrir arquivo!");
    }

    fclose(FOLHA);
    
    return lista;
}

// Main
int main()
{
    tela();
    TipoLista l;
    l.Primeiro = NULL;
    l.Ultimo = NULL;
    int opc;
    TipoLista lista = ler_Arquivo();

    system("color 06");

    do
    {
        tela();
        gotoxy(20, 8);
        printf("1- Cadastrar funcionario no inicio");
        gotoxy(20, 9);
        printf("2- Cadastrar funcionario no final");
        gotoxy(20, 10);
        printf("3- Cadastrar funcionario na posicao");
        gotoxy(20, 11);
        printf("4- Remover funcionario no inicio");
        gotoxy(20, 12);
        printf("5- Remover funcionario no final");
        gotoxy(20, 13);
        printf("6- Remover funcionario na opcao desejada");
        gotoxy(20, 14);
        printf("7- Editar dados do funcionario");
        gotoxy(20, 15);
        printf("8- Mostrar funcionarios cadastrados");
        gotoxy(20, 16);
        printf("9- Sair do programa");
        gotoxy(07, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
        getchar();

        switch (opc)
        {
        case 1:
            tela_funcionario();
            tela();
            cadastrar_funcionario(&l, opc);
            break;
        case 2:
            tela_funcionario();
            tela();
            cadastrar_funcionario(&l, opc);
            break;
        case 3:
            tela_funcionario();
            tela();
            cadastrar_funcionario(&l, opc);
            break;
        case 4:
            tela();
            remover_funcionario(&l, opc);
            break;
        case 5:
            tela();
            remover_funcionario(&l, opc);
            break;
        case 6:
            tela();
            remover_funcionario(&l, opc);
            break;
        case 7:
            tela();
            alterar_funcionario(&l);
            break;
        case 8:
            tela();
            mostrar_funcionarios(&l);
            break;
        case 9:
            salvar_Arquivo(&lista);
            Sleep(2000);
            break;
        default:
            gotoxy(07, 23);
            printf("Opcao invalida, digite novamente.");
            getch();
            break;
        }
    } while (opc != 9);

    // Saindo do programa
    system("cls");
    tela();
    gotoxy(07, 23);
    printf("Saindo do programa...");

    return 0;
}