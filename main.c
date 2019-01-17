#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define FLSH gets(l)
#define conta_adm "admin"
#define senha_adm "admin"
#include <locale.h>

void login_adm();
void menu_login_inicial();
void login_usuario();
int validar_login_usuario();

/*-----------------------------------------------------------------------
              TELA INCIAL - CARREGAMENTO DO SISTEMA
------------------------------------------------------------------------*/
//OBSERVACAO PARA RODAR CÓDIGO, NECESSÁRIO ESTAR ATIVA A MARCAÇÃO -STD=C99 OR STD-=GNU99 PARA PODER COMPILAR
void frescura()
{
    printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@@@@@@__________@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@@@_____@@@@@@@____@@@@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@_____@@@@@@@@@@@@____@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@____@@@@@@@@@@@@@@@@____@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@____@@@@@@@@@@@@@@@@@@@@@____@@@@@@@@\n");
    printf("\t\t@@@@@@____@@@@@@@@@@@@@@@@@@@@@@@@@____@@@@@@\n");
    printf("\t\t@@@@@___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___@@@@@\n");
    printf("\t\t@@@@____@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___@@@@\n");
    printf("\t\t@@@_______________________________________@@@\n");
    printf("\t\t@@@_______________________________________@@@\n");
    printf("\t\t@@@@___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___@@@@\n");
    printf("\t\t@@@@@___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___@@@@@\n");
    printf("\t\t@@@@@@____@@@@@@@@@@@@@@@@@@@@@@@@@____@@@@@@\n");
    printf("\t\t@@@@@@@@____@@@@@@@@@@@@@@@@@@@@@_____@@@@@@@\n");
    printf("\t\t@@@@@@@@@@_____@@@@@@@@@@@@@@@_____@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@_____@@@@@@@@@@@_____@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@@@@@____@@@@@____@@@@@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@@@@@@@_________@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    printf("\n\n\n\t\t\t..:: SISTEMA DE ROTAS ! ::.. ");


    printf ("\n\n\t\t\tCARREGANDO O SISTEMA: \n\n");

    for (int i = 0; i <= 25; i++)
    {
        printf ("%d%%\r", i*4);
        fflush (stdout);
        for (int j = 0; j < i; j++)
        {
            if (!j) // Da espaco na barra pra nao enconstar na borda da tela
                printf ("\t\t      ");

            printf ("%c", 219);
            Sleep(3);
        }
    }
    printf ("\n\nInicializando sistema...");
    system("cls");
}

/*-----------------------------------------------------------------------
              PARTE DE LOGIN (ADMINISTRADOR E USUARIO)
------------------------------------------------------------------------*/

//Cadastro
struct cadastro
{
    char user[20];
    char pass[20];
    int codigo;
} usuario[1000],admin[50],cadastro_user[1000],cad_admin[50];

//FUNCAO PARA VALIDAR LOGIN DO USUARIO
int validar_login_usuario(int a,int c)
{
    int r;

    if (strcmp(cadastro_user[a].user,usuario[c].user)==0)
    {
        r = 1; //usuario ja existe
    }
    else
        r = 0; //usuario nao existe
    return (r);
}

//FUNCAO PARA VALIDAR LOGIN ADMINISTRADOR
int validar_login_adm(int a,int c)
{
    int r;

    if (strcmp(cad_admin[a].user,admin[c].user)==0)
    {
        r = 1; //usuario ja existe
    }
    else
        r = 0; //usuario nao existe
    return (r);
}

//PROCEDIMENTO PARA CADASTRO DE USUÁRIOS CLIENTES (USUÁRIOS)
void cadastro_cliente(int a)
{
    int b,c;
    system("cls");
usuario_existente:
    usuario[a].codigo = a+1;
    printf("\n\t\t\tCADASTRO %d",usuario[a].codigo);
    puts("\n\n\t\t\tDIGITE O LOGIN: ");
    printf("\t\t\t");
    scanf(" %s",cadastro_user[a].user);
    for (c=0; c<1000; c++)
    {
        b = validar_login_usuario(a,c);
        if (b==1)
            break;
    }
    if (b==0)
    {
        memcpy(usuario[a].user,cadastro_user[a].user,50);
        puts("\t\t\tDIGITE A SENHA: ");
        printf("\t\t\t");
        scanf(" %s",usuario[a].pass);
    }
    else if (b==1)
    {
        printf("\n\t\t\tLOGIN JÁ EXISTENTE\n");
        goto usuario_existente;
    }
    system("cls");
    printf("\n\t\t\tCADASTRO EFETUADO COM SUCESSO!\n");
    printf("\t\t\tPRESSIONE QUALQUER TECLA PARA PROSSEGUIR...");
    getch();
    system("cls");
}

//PROCEDIMENTO PARA CADASTRO DE USUÁRIOS ADMINISTRADORES
void cadastro_administrador(int a)
{
    int b,c;
    system("cls");
admin_existente:
    admin[a].codigo = a+1;
    printf("\n\t\t\tCADASTRO %d",admin[a].codigo);
    puts("\n\n\t\t\tDIGITE O LOGIN: ");
    printf("\t\t\t");
    scanf(" %s",cad_admin[a].user);
    for (c=0; c<50; c++)
    {
        b = validar_login_adm(a,c);
        if (b==1)
            break;
    }
    if (b==0)
    {
        memcpy(admin[a].user,cad_admin[a].user,50);
        puts("\t\t\tDIGITE A SENHA: ");
        printf("\t\t\t");
        scanf(" %s",admin[a].pass);
    }
    else if (b==1)
    {
        printf("\n\t\t\tLOGIN JÁ EXISTENTE!\n");
        goto admin_existente;
    }
    system("cls");
    printf("\n\t\t\tCADASTRO EFETUADO COM SUCESSO!\n");
    printf("\t\t\tPRESSIONE QUALQUER TECLA PARA PROSSEGUIR...");
    getch();
    system("cls");
}

//PROCEDIMENTO RELIZACAO DO LOGIN  DO USUARIO
void logar_usuario()
{
    int c;
    int logado;
    char login[1][20], senha[1][20];
    char fechar_login[] = {"EXIT"}, fechar_senha[] = {"EXIT"};

erro_login:

    printf("\n\tPARA FECHAR DIGITE O USUARIO E A SENHA EXIT (CAPS LOOK ATIVADO)\n");
    printf("\n\tLogon\n");
    printf("\n\tLogin: ");
    scanf(" %s",login[0]);
    printf("\n\tSenha: ");
    scanf(" %s",senha[0]);

    if ((strcmp(login[0],fechar_login)==0)&&(strcmp(senha[0],fechar_senha)==0))
        exit(0);
    else
    {
        for (c=0; c<1000; c++)
        {
            if ((strcmp(login[0],usuario[c].user)!=0) || (strcmp(senha[0],usuario[c].pass)!=0))
            {
                logado = 1; //login e/ou senha incorretos
            }
            else if((strcmp(login[0],usuario[c].user)==0) && (strcmp(senha[0],usuario[c].pass)==0))
            {
                logado = 2; //logado com sucesso
                break;
            }

        }

        if (logado==1)
        {
            system("cls");
            printf("\n\t\t\tLOGIN E/OU SENHA INCORRETO(s)\n");
            printf("\n\t\t\tTENTE NOVAMENTE!\n");
            goto erro_login;
        }
        else if (logado==2)
        {
            system("cls");
            printf("\n\t\t\tLOGADO COM SUCESSO!\n\n\t\t\tBEM-VINDO(A) %s\n",login[0]);
            printf("\t\t\tCODIGO USUARIO: %d\n\n",usuario[c].codigo);
            login_usuario();
        }
    }
}

void login_usuario()
{
    int op_user;

tela_inicial_user:
    printf("\n\t\t\t9- VOLTAR TELA DE LOGIN");
    printf("\n\t\t\tCTRL + C PARA Fechar\n\t");
    scanf("%d",&op_user);

    if (op_user==9)
    {
        system("cls");
        menu_login_inicial();
    }
    else if (op_user==0)
        exit(0);
    else
    {
        system("cls");
        printf("\n\tOPCAO INVALIDA\n");
        goto tela_inicial_user;
    }
}

//PROCEDIMENTO PARA LOGIN DO ADMINISTRADOR
void logar_adm()
{
    int c;
    int logado;
    char login[1][20], senha[1][20];
    char fechar_login[] = {"EXIT"}, fechar_senha[] = {"EXIT"};

erro_login:

    printf("\n\tPARA FECHAR DIGITE O USUARIO E A SENHA EXIT (CAPS LOOK ATIVADO)\n");
    printf("\n\tLogon\n");
    printf("\n\tLogin: ");
    scanf(" %s",login[0]);
    printf("\n\tSenha: ");
    scanf(" %s",senha[0]);

    if ((strcmp(login[0],conta_adm)==0)&&(strcmp(login[0],senha_adm)==0))
        logado = 2;
    else if ((strcmp(login[0],fechar_login)==0)&&(strcmp(senha[0],fechar_senha)==0))
        exit(0);
    else
    {
        for (c=0; c<1000; c++)
        {
            if ((strcmp(login[0],admin[c].user)!=0) || (strcmp(senha[0],admin[c].pass)!=0))
            {
                logado = 1; //login e/ou senha incorretos
            }
            else if((strcmp(login[0],admin[c].user)==0) && (strcmp(senha[0],admin[c].pass)==0))
            {
                logado = 2; //logado com sucesso
                break;
            }

        }
    }

    if (logado==1)
    {
        system("cls");
        printf("\n\t\t\tLOGIN E/OU SENHA INCORRETA(S)\n");
        printf("\n\t\t\tTENTE NOVAMENTE!\n");
        goto erro_login;
    }
    else if (logado==2)
    {
        system("cls");
        printf("\n\t\t\tLOGADO COM SUCESSO!\n\n\t\t\tBEM-VINDO(A) [ADM]%s\n",login[0]);
        printf("\n\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR");
        getch();
        system("cls");
        //NAO DESCOMENTAR PRINTF ABAIXO POIS DA PROBLEMA NA HORA DE EFETUAR LOGIN DO AMDMIN
        //PROCESSO AINDA SER TRABALHADO
        //printf("\t\t\tCODIGO DO ADMIN: %d\n\n",admin[c].codigo);
        login_adm();
    }
}

//MENU_2 PARA LOGIN
void login_adm()
{
    int op_adm;
    int a=0,adm_cad=0,b,c,nc;

tela_inicial_adm:
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\SISTEMA DE ROTAS\n");
    printf("\t\t\t\t\  TELA DE LOGIN\n");
    printf("\t---------------------------------------------------------------\n\n");
    printf("\n\t\t\t1- REALIZAR CADASTRO DE USUARIOS\n");
    printf("\n\t\t\t2- REALIZAR CADASTRO DE ADMINISTRADORES\n");
    printf("\n\t\t\t3- VOLTAR TELA DE LOGIN\n");
    printf("\n\t\t\t4- MENU GRAFOS\n");
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


//MENU INICIAL DO LOGIN
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


/*-------------------------------------------------------------------------------
                       ALGORITMO DE DIJKSTRA - INCIO
--------------------------------------------------------------------------------*/

/*-------------------------
definir variavies
--------------------------*/
int destino, origem, vertices = 0;
int custo, *custos = NULL;


void dijkstra(int vertices,int origem,int destino,int *custos)
{
    int i,v, cont = 0;
    int *ant, *tmp;
    int *z; /* vertices para os quais se conhece o caminho minimo */
    double min;
    double dist[vertices]; /* vetor com os custos dos caminhos */

    /*-------------------------
    Aloca as linhas da matriz
    --------------------------*/
    ant = calloc (vertices, sizeof(int *));
    tmp = calloc (vertices, sizeof(int *));
    if (ant == NULL)
    {
        printf ("** Erro: Memoria Insuficiente **");
        exit(-1);
    }

    z = calloc (vertices, sizeof(int *));
    if (z == NULL)
    {
        printf ("** Erro: Memoria Insuficiente **");
        exit(-1);
    }

    for (i = 0; i < vertices; i++)
    {
        if (custos[(origem - 1) * vertices + i] !=- 1)
        {
            ant[i] = origem - 1;
            dist[i] = custos[(origem-1)*vertices+i];
        }
        else
        {
            ant[i]= -1;
            dist[i] = HUGE_VAL;
        }
        z[i]=0;
    }
    z[origem-1] = 1;
    dist[origem-1] = 0;

    /*-----------------------
       Ciclo principal
    ------------------------*/
    do
    {
        /* Encontra o vertice que deve entrar em z */
        min = HUGE_VAL;
        for (i=0; i<vertices; i++)
            if (!z[i])
                if (dist[i]>=0 && dist[i]<min)
                {
                    min=dist[i];
                    v=i;
                }

        /* Calcula distancias dos novos vizinhos de z */
        if (min != HUGE_VAL && v != destino - 1)
        {
            z[v] = 1;
            for (i = 0; i < vertices; i++)
                if (!z[i])
                {
                    if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i])
                    {
                        dist[i] = dist[v] + custos[v*vertices+i];
                        ant[i] =v;
                    }
                }
        }
    }
    while (v != destino - 1 && min != HUGE_VAL);

    /* Mostra o Resultado da procura */
    printf("\tDe %d para %d: \t", origem, destino);
    if (min == HUGE_VAL)
    {
        printf("Nao Existe\n");
        printf("\tCusto: \t- \n");
    }
    else
    {
        i = destino;
        i = ant[i-1];
        while (i != -1)
        {
            // printf("<-%d",i+1);
            tmp[cont] = i+1;
            cont++;
            i = ant[i];
        }

        for (i = cont; i > 0 ; i--)
        {
            printf("%d -> ", tmp[i-1]);
        }
        printf("%d", destino);

        printf("\n\tCusto: %d\n",(int) dist[destino-1]);
    }
}

/*-------------------------------------------------------------------------------------------
                                        MENU DE OPCOES
--------------------------------------------------------------------------------------------*/
void cabecalho(void)
{
    int opcao;
    printf("\t--------------------------------------------------------------\n");
    printf("\t\t\t\t\SISTEMA DE ROTAS\n");
    printf("\t---------------------------------------------------------------\n\n");
    printf("\t\t\tCRIACAO DA ROTA:\n");
    printf("\t\t\t 1 - ADICIONAR GRAFO\n"
           "\t\t\t 2 - PROCURAR OS MENORES CAMINHOS NO GRAFO\n"
           "\t\t\t CTRL+C PARA SAIR DO PROGRAMA\n\n");
    printf("\t\t\tOPCAO :");
    scanf("%i", &opcao);
    switch (opcao)
    {
    case 1:
        add();
        break;

    case 2:
        procurar();
        break;

    default:
        system("cls");
        printf("\t\t\tVALOR INVALIDO DIGITE 1 OU 2\n");
        printf("\t\t\tPARA SAIR DIGITE CRTL + C\n");
        getch();
        system("cls");
        printf("\n");
        cabecalho();
    }
}

/*--------------------------------------------------------------------------------------------
                      DISTRIBUICAO DOS VERTICES E DAS ARESTAS
---------------------------------------------------------------------------------------------*/
void add(void)
{
    int i, j;

    do
    {
        printf("\n\t\t\tQUAL NUMERO DE VERTICES (numero minimo = 2 ): ");
        scanf("%d",&vertices);
    }
    while (vertices < 2 );

    if (!custos)
        free(custos);
    custos = (int *) malloc(sizeof(int)*vertices*vertices);
    for (i = 0; i <= vertices * vertices; i++)
        custos[i] = -1;

    printf("\t\t\tINSIRA AS ARESTAS:\n");
    do
    {
        do
        {
            printf("\t\t\tORIGEM DA ARESTA (entre 1 e %d ou '0' para sair): ", vertices);
            scanf("%d",&origem);
        }
        while (origem < 0 || origem > vertices);

        if (origem)
        {
            do
            {
                printf("\t\t\tDESTINO DA ARESTA (entre 1 e %d, menos %d): ", vertices, origem);
                scanf("%d", &destino);
            }
            while (destino < 1 || destino > vertices || destino == origem);

            do
            {
                printf("\t\t\tCUSTO (positivo) DA ARESTA DO VERTICE %d PARA O VERTICE %d: ",
                       origem, destino);
                scanf("%d",&custo);
            }
            while (custo < 0);

            custos[(origem-1) * vertices + destino - 1] = custo;
        }
    }
    while (origem);
}


/*----------------------------------------------------------------------------
               PROCURA O MENOR CAMINHO DENTRO DO GRAFICO
-----------------------------------------------------------------------------*/
void procurar(void)
{
    int i, j;
    int *vertices;

    if(vertices == NULL)
    {
        system("cls");
        printf("\t\t\tCRIE PRIMEIRO UM GRAFO...");
        printf("\t\t\tPRESSIONE ENTER PARA CONTINUAR");
        getch();
        add();
    }

    printf("\t\t\tLISTA DOS MENORES CAMINHOS NO GRAFO: \n");

    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
            dijkstra(vertices, i,j, custos);
        printf("\n");
    }

    printf("\t\t\tENTER PARA VOLTAR AO MENU INICIAL DO GRAFO>\n");

}


/*------------------------------------------------------------------------------
                     METODO MAIN - FUNCAO PRINCIPAL
------------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
    //Setando o local para aceitar acentos
    setlocale(LC_ALL,"Portuguese");
    //int i, j;
    //char opcao[3], l[50];
    int opcao;

    frescura();
    menu_login_inicial();
    cabecalho();


    return 0;
}

