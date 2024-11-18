#include <stdio.h>
#include <stdlib.h>
int i,j;
struct Term
{
    int coefficient;
    int exponent;
};

struct Polynomial
{
    int terms;
    struct Term *array;
};

struct Polynomial *createPolynomial(int terms)
{
    struct Polynomial *poly = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    poly->terms = terms;
    poly->array = (struct Term *)malloc(terms * sizeof(struct Term));
    return poly;
}

void readPolynomial(struct Polynomial *poly)
{
    printf("Enter coefficients and exponents for %d terms:\n", poly->terms);
    for ( i = 0; i < poly->terms; i++)
    {
        scanf("%d %d", &poly->array[i].coefficient, &poly->array[i].exponent);
    }
}
void printPolynomial(struct Polynomial *poly)
{
    printf("\n the polynomial : \n");
    for ( i = 0; i < poly->terms; i++)
    {
        printf("%dx^%d + ", poly->array[i].coefficient, poly->array[i].exponent);
    }
    printf("0\n");
}
int evaluatePolynomial(struct Polynomial *poly, int x)
{
    int result = 0;
    for ( i = 0; i < poly->terms; i++)
    {
        int termValue = poly->array[i].coefficient;
        for (j = 0; j < poly->array[i].exponent; j++)
        {
            termValue *= x;
        }
        result += termValue;
    }
    return result;
}

int main()
{
    int terms, x;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &terms);
    struct Polynomial *poly = createPolynomial(terms);
    readPolynomial(poly);
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printPolynomial(poly);
 
    int result = evaluatePolynomial(poly, x);
    printf("The value of the polynomial at x = %d is %d\n", x, result);

    free(poly->array);
    free(poly);

    return 0;}
