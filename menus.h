#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
/*-----------------------------------------------------------------------
              #1 TELA INCIAL - CARREGAMENTO DO SISTEMA
------------------------------------------------------------------------*/
//OBSERVACAO PARA RODAR CÓDIGO, NECESSÁRIO ESTAR ATIVA A MARCAÇÃO -STD=C99 OR STD-=GNU99 PARA PODER COMPILAR
void frescura()
{

    printf("\t\t\t                / _____ \                  \n");
    printf("\t\t\t          _____/ /     \ \_____            \n");
    printf("\t\t\t         / _____/ WAYZE \_____ \           \n");
    printf("\t\t\t   _____/ /     \       /     \ \_____     \n");
    printf("\t\t\t  / _____/  221  \_____/  412  \_____ \    \n");
    printf("\t\t\t / /     \       /     \       /     \ \   \n");
    printf("\t\t\t/ /  131  \_____/  322  \_____/  513  \ \  \n");
    printf("\t\t\t\ \       /     \       /     \       / /  \n");
    printf("\t\t\t \ \_____/  232  \_____/  423  \_____/ /   \n");
    printf("\t\t\t / /     \       /     \       /     \ \   \n");
    printf("\t\t\t/ /  142  \_____/ WAYZE \_____/  524  \ \  \n");
    printf("\t\t\t\ \       /     \       /     \       / /  \n");
    printf("\t\t\t \ \_____/  243  \_____/  434  \_____/ /   \n");
    printf("\t\t\t / /     \       /     \       /     \ \   \n");
    printf("\t\t\t/ /  153  \_____/  344  \_____/  535  \ \  \n");
    printf("\t\t\t\ \       /     \       /     \       / /  \n");
    printf("\t\t\t \ \_____/  254  \_____/  445  \_____/ /   \n");
    printf("\t\t\t  \_____ \       /     \       / _____/    \n");
    printf("\t\t\t        \ \_____/  355  \_____/ /          \n");
    printf("\t\t\t         \_____ \       / _____/           \n");
    printf("\t\t\t               \ \_____/ /                 \n");

    printf("\n\n\n\t\t\t..::: WAYZE SISTEMA DE ROTAS  :::.. ");


    printf ("\n\n\t\t\t\tCARREGANDO O SISTEMA: \n\n");

    for (int i = 0; i <= 25; i++)
    {
        printf (" %d%%\r", i*4);
        fflush (stdout);
        for (int j = 0; j < i; j++)
        {
            if (!j) // Da espaco na barra pra nao enconstar na borda da tela
                printf ("\t\t\t     ");

            printf ("%c", 219);
            Sleep(3);
        }
    }
    printf ("\n\nInicializando sistema...");
    system("cls");
}
/*-----------------------------------------------------------------------
              #2.1 TELA INCIAL - MENU INICIAL
------------------------------------------------------------------------*/
void menu_login_inicial()
{
    int op_login;

menu_de_login:
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\SISTEMA DE ROTAS\n");
    printf("\t\t\t\t\  TELA DE LOGIN\n");
    printf("\t---------------------------------------------------------------\n\n");
    printf("\t\t\t1 - Login de USUARIO\n");
    printf("\t\t\t2 - Login de ADMINISTRADOR\n");
    printf("\t\t\tCTRL + C - FECHAR\n");
    printf("\t\t\tOpcao: ");
    scanf(" %d",&op_login);
    if (op_login==1)
        logar_usuario();
    else if (op_login==2)
        logar_adm();
    else if (op_login==0)
        exit(0);
    else
    {
        system("cls");
        printf("\t\t\t\tOPCAO INVALIDA!\n");
        printf("\t\t\tPRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
        printf("\t\t\t");
        getch();
        system("cls");
        goto menu_de_login;
    }
}
/*-----------------------------------------------------------------------
              #2.2 TELA INCIAL - LOGIN ADMIN
------------------------------------------------------------------------*/
void login_adm()
{
    int op_adm;
    int a=0,adm_cad=0,b,c,nc;

tela_inicial_adm:
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\SISTEMA DE ROTAS\n");
    printf("\t\t\t\t\  TELA DE LOGIN\n");
    printf("\t---------------------------------------------------------------\n\n");
    printf("\n\t\t\t1. REALIZAR CADASTRO DE USUARIOS\n");
    printf("\n\t\t\t2. REALIZAR CADASTRO DE ADMINISTRADORES\n");
    printf("\n\t\t\t3. VOLTAR TELA DE LOGIN\n");
    printf("\n\t\t\t4. MENU GRAFOS\n");
    printf("\n\t\t\tCTRL + C PARA FECHAR\n");
    printf("\t\t\tOPCAO:\t");
    scanf("%d", &op_adm);
    system("cls");
    if (op_adm == 1)
    {
        printf("\n\t\t\tDESEJA REALIZAR QUANTOS CADASTROS ?\n");
        printf("\t\t\tQUANTIDADE:");
        scanf("%d",&nc);
        if (a==0)
        {
            for (a=0; a<nc; a++)
            {
                cadastro_cliente(a);
            }
            goto tela_inicial_adm;
        }
        else if (a!=0)
        {
            b = a;
            c = a+nc-1;
            printf("\n%d\n",a);
            for (a=b; a<=c; a++)
            {
                cadastro_cliente(a);
            }
            goto tela_inicial_adm;
        }
    }
    else if (op_adm == 2)
    {
        printf("\n\t\t\tDESEJA REALIZAR QUANTOS CADASTROS ?\n");
        printf("\t\t\tQUANTIDADE:");
        scanf("%d",&nc);
        if (adm_cad==0)
        {
            for (adm_cad=0; adm_cad<nc; adm_cad++)
            {
                cadastro_administrador(adm_cad);
            }
            goto tela_inicial_adm;
        }
        else if (adm_cad!=0)
        {
            b = adm_cad;
            c = adm_cad+nc-1;
            printf("\n%d\n",a);
            for (adm_cad=b; adm_cad<=c; adm_cad++)
            {
                cadastro_administrador(adm_cad);
            }
            goto tela_inicial_adm;
        }
    }
    else if (op_adm == 0)
        exit(0);
    else if (op_adm == 3)
        menu_login_inicial();
    else if (op_adm == 4)
        cabecalho();
}

/*-------------------------------------------------------------------------------------------
                                        MENU DE OPCOES
--------------------------------------------------------------------------------------------*/
void cabecalho(void)
{

    //Variável para o Menu
    int opcao_principal = 0;

    //While para voltar sempre para o Menu
    while(opcao_principal==0)
    {
        int opcao_menu;
        //Menu Principal

        printf("\t--------------------------------------------------------------\n");
        printf("\t\t\t\t\ SISTEMA DE ROTAS\n");
        printf("\t\t\t\-------  MENU ROTAS  -------\n");
        printf("\t---------------------------------------------------------------\n\n");
        printf("\t\t\t CRIACAO DA ROTA:\n");
        printf("\t\t\t 1. ADICIONAR GRAFO\n"
               "\t\t\t 2. PROCURAR OS MENORES CAMINHOS NO GRAFO\n"
               "\t\t\t 3. VOLTAR MENU DE LOGIN\n"
               "\t\t\t CTRL+C PARA SAIR DO PROGRAMA\n\n");
        printf("\t\t\tDigite o nº da opção desejada: ");
        scanf(" %d", &opcao_menu);


        switch(opcao_menu)
        {

        case 1:
            add();
            break;
        case 2:
            procurar();
            break;
        case 3:
            system("cls");
            menu_login_inicial();
            break;
        default:
            system("cls");
            printf("Opção INVALIDA\n");
            break;
        }
    }
}

#endif // MENUS_H_INCLUDED
