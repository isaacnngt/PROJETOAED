
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define FLSH gets(l)

/*-----------------------------------------------------------------------
              TELA INCIAL - CARREGAMENTO DO SISTEMA
------------------------------------------------------------------------*/

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
    printf("Criacao da rota:\n");
    printf("\t 1 - Adicionar Grafo\n"
           "\t 2 - Procura Os Menores Caminhos no Grafo\n"
           "\t CTRL+C para Sair do programa\n");

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
        printf("\nQual o numero de vertices (numero minimo = 2 ): ");
        scanf("%d",&vertices);
    }
    while (vertices < 2 );

    if (!custos)
        free(custos);
    custos = (int *) malloc(sizeof(int)*vertices*vertices);
    for (i = 0; i <= vertices * vertices; i++)
        custos[i] = -1;

    printf("Insira as arestas:\n");
    do
    {
        do
        {
            printf("Origem da aresta (entre 1 e %d ou '0' para sair): ", vertices);
            scanf("%d",&origem);
        }
        while (origem < 0 || origem > vertices);

        if (origem)
        {
            do
            {
                printf("Destino da aresta (entre 1 e %d, menos %d): ", vertices, origem);
                scanf("%d", &destino);
            }
            while (destino < 1 || destino > vertices || destino == origem);

            do
            {
                printf("Custo (positivo) da aresta do vertice %d para o vertice %d: ",
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

        printf("CRIE PRIMEIRO UM GRAFO");
        add();
    }

    printf("Lista dos Menores Caminhos no Grafo Dado: \n");

    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
            dijkstra(vertices, i,j, custos);
        printf("\n");
    }

    printf("ENTER para voltar ao menu inicial>\n");

}


/*------------------------------------------------------------------------------
                     METODO MAIN - FUNCAO PRINCIPAL
------------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
    int i, j;
    //char opcao[3], l[50];
    int opcao;

        frescura();
        cabecalho();


    return 0;
}
