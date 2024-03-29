#define FLSH gets(l)
#define conta_adm "admin"
#define senha_adm "admin"
#include "menus.h"

void login_adm();
void menu_login_inicial();
void login_usuario();
int validar_login_usuario();

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
            printf("\n\t\t\tLOGADO COM SUCESSO!\n\n\t\t\tBEM-VINDO(A): %s\n",login[0]);
            printf("\t\t\tCODIGO USUARIO: %d\n\n",usuario[c].codigo);
            printf("\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR... \n");
            getch();
            login_usuario();
        }
    }
}

void login_usuario()
{
    int op_user;

tela_inicial_user:
    //printf("\n\t\t\t9- VOLTAR TELA DE LOGIN");
    system("cls");
    cabecalho();
    /*printf("\n\t\t\tCTRL + C PARA Fechar\n\t");
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
    }*/
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
        printf("\n\t\t\tLOGADO COM SUCESSO!\n\n\t\t\tBEM-VINDO(A): [ADM]%s\n",login[0]);
        printf("\n\t\t\tPRESSIONE QUALQUER TECLA PARA CONTINUAR");
        getch();
        system("cls");
        //NAO DESCOMENTAR PRINTF ABAIXO POIS DA PROBLEMA NA HORA DE EFETUAR LOGIN DO AMDMIN
        //PROCESSO AINDA SER TRABALHADO
        //printf("\t\t\tCODIGO DO ADMIN: %d\n\n",admin[c].codigo);
        login_adm();
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
    //Variaveis
    int i, j;
    int opcao;

    frescura();
    menu_login_inicial();
    cabecalho();


    return 0;
}
