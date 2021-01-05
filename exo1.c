#include<stdio.h>
#include<stdlib.h>

void saisie_tab(int tab[], int *l)
{
    int i;
    do
    {
        printf("entrer la longeur de tableaux:"); scanf("%d", l);
    } while (*l > 50);

     for (i = 0; i <*l; i++)
    {
        printf("tab[%d]=",i);
        scanf("%d",&tab[i]);
    }
}

void afficher_tab(int tab[], int l)
{
    int i;
    printf("\nle tableau: ");
    for ( i = 0; i < l; i++)
    {
        printf("tab[%d]=%d\t",i,tab[i]);
    }

}

void saisie_matrice(int mat[50][50], int *l1, int *c1)
{
    int i,j;
    printf("\nentre le nombre le lignes :"); scanf("%d", l1);
    printf("entre le nombre le colonnes :"); scanf("%d", c1);
    for ( i = 0; i < *l1; i++)
    {
        for ( j = 0; j<*c1; j++){  printf("mat[%d,%d]=",i,j); scanf("%d",&mat[i][j]); }

    }

}

void afficher_mat(int mat[50][50], int l1, int c1)
{
    int i,j;
    printf("\n la matrice :\n");
    for ( i = 0; i <l1; i++)
    {
        for ( j = 0; j<c1; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");

    }

}

void mat_identite(int mat[50][50], int l1, int c1)
{
    int i,j;
    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if(i==j) mat[i][j]=1;
            else mat[i][j]=0;
        }
    }
    afficher_mat(mat, l1, c1);
}

void somme_mat(int mat1[50][50], int l1, int c1, int mat2[50][50], int l2, int c2, int mat3[50][50])
{
    int i,j;
    for ( i = 0; i <l1; i++)
    {
        printf("test");
        for ( j = 0; j<l1; j++)
        {
            printf("test");
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    printf("la somme:");
    afficher_mat(mat3, l1, l1);
}


void multi_mat(int mat1[50][50], int l1, int c1, int mat2[50][50], int l2, int c2, int mat4[50][50])
{
    int i,j,k;
    for ( i = 0; i < l1; i++)
    {
        for ( j = 0; j < c1; j++)
        {
            mat4[i][j]=0;
            for  (k = 0; k < c1; k++)
            {
                mat4[i][j] = mat4[i][j]+(mat1[i][k] * mat2[k][j]);
            }
        }
    }
    printf("la multiplication:");
    afficher_mat(mat4, l1, c1);
}

void est_triangulaire_superieure (int mat[50][50], int l1, int c1)
{
    int i=1,j=0,s,estTrian=1;

 for ( i = 0; i < l1; i++)
 {
     for ( j = 0; j < i; j++)
     {
         if (mat[i][j]!=0)
         {
             estTrian=0;
             printf("\nla matrice est pas triangulaire superieure ");
             return;
         }
     }
 }
 printf("\nla matrice est triangulaire superieure");
}

void est_triangulaire_inferieure (int mat[50][50], int l1, int c1)
{
    int i=1,j=0,s,estTrian=1;

 for ( i = 0; i < l1; i++)
 {
     for ( j = i+1; j <l1; j++)
     {
         if (mat[i][j]!=0)
         {
             estTrian=0;
             printf("\nla matrice est pas triangulaire inferieure ");
             return;
         }
     }
 }
 printf("\nla matrice est triangulaire inferieure ");
}

void est_diagonale(int mat[50][50], int l1, int c1)
{
    int i,j;
    for ( i = 0; i < l1; i++)
    {
        for ( j = 0; j < c1; j++)
        {
            if (i!=j)
            {
                if (mat[i][j]!=0)
                {

                    printf("la matrice n'est pas diagonale ");
                    return;
                }
            }
        }
    }
    printf("\nla matrice est diagonale ");
}

int est_symetrique(int mat[50][50], int l1, int c1)
{
    int i,j;
    for ( i = 0; i < l1; i++)
    {
        for ( j = 0; j < l1; j++)
        {
            if(i!=j)
            {
                if (mat[i][j]!=mat[j][i])
                {
                    printf("la matrice n'est pas symetrique nat[%d,%d] ",i,j);
                    return 0;
                }
            }
        }
    }
    printf("\nla matrice est symetrique ");
}

void tansp(int mat[50][50], int l1, int c1)
{
    int i,j,p,tmat[50][50];
    for ( i = 0; i < l1; i++)
    {
        for ( j = 0; j < l1; j++)
        {
            tmat[j][i]=mat[i][j];
        }
    }
    afficher_mat(tmat,l1,c1);
}

int main()
{
    int tab[50],l=51,z,w;
    int mat1[50][50],l1,c1;
    int mat2[50][50], l2, c2;
    int mat3[50][50];
    int mat4[50][50];
    //saisie_tab(tab, &l);
    //afficher_tab(tab, l);
    printf("matrice 1:");
    saisie_matrice(mat1, &l1, &c1);
    afficher_mat(mat1, l2, c2);
    printf("matrice 2:");
    saisie_matrice(mat2, &l2, &c2);
    afficher_mat(mat2, l2, c2);
    printf("\n**************** MENU *******************");
    printf("\n1 . ----------> afficher la matrice identite ----------------");
    printf("\n2 . ----------> la somme ----------------");
    printf("\n3 . ----------> le produit ----------------");
    printf("\n4 . ----------> tester la matrice triangulaire_superieure  ----------------");
    printf("\n5 . ----------> tester la matrice triangulaire_inferieure  ----------------");
    printf("\n6 . ----------> tester la matrice diagonale  ----------------");
    printf("\n7 . ----------> tester la matrice symetrique  ----------------");
    printf("\n8 . ----------> calculer la transposition  ----------------");
    do{
    printf("\nje veux la :"); scanf("%d",&z);

    switch (z)
    {
    case 1:
        mat_identite(mat1, l1, c1);
        break;
    case 2:
        somme_mat(mat1, l1, c1, mat2, l2, c2, mat3);
        break;
    case 3:
        multi_mat(mat1, l1, c1, mat2, l2, c2, mat4);
        break;
    case 4:
        est_triangulaire_superieure(mat1, l1, c1);
        break;
    case 5:
        est_triangulaire_inferieure(mat1, l1, c1);
        break;
    case 6:
        est_diagonale(mat1, l1, c1);
        break;
    case 7:
        est_symetrique(mat1, l1, c1);
        break;
    case 8:
        tansp(mat1, l1, c1);
        break;
    default :
    break;

    }

    printf("si vous voulez reeseyer tpez '1' sinon'0' :"); scanf("%d",&w);
    }while (w);
    return 0;
}
