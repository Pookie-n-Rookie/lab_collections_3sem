#include <stdio.h>
#include <stdlib.h>
int i,j ;
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
    for (i = 0; i < poly->terms; i++)
    {
        scanf("%d %d", &poly->array[i].coefficient, &poly->array[i].exponent);
    }
}

struct Polynomial *multiplyPolynomials(struct Polynomial *poly1, struct Polynomial *poly2)
{
    int totalTerms = poly1->terms * poly2->terms;
    struct Polynomial *result = createPolynomial(totalTerms);
    result->terms = 0;

    for (i = 0; i < poly1->terms; i++)
    {
        for (j = 0; j < poly2->terms; j++)
        {
            int newExponent = poly1->array[i].exponent + poly2->array[j].exponent;
            int newCoefficient = poly1->array[i].coefficient * poly2->array[j].coefficient;

            int k;
            for (k = 0; k < result->terms; k++)
            {
                if (result->array[k].exponent == newExponent)
                {
                    result->array[k].coefficient += newCoefficient;
                    break;
                }
            }

            if (k == result->terms)
            {
                result->array[result->terms].exponent = newExponent;
                result->array[result->terms].coefficient = newCoefficient;
                result->terms++;
            }
        }
    }

    return result;
}

void printPolynomial(struct Polynomial *poly)
{
    printf("Polynomial: ");
    for (i = 0; i < poly->terms; i++)
    {
        printf("%d x^%d + ", poly->array[i].coefficient, poly->array[i].exponent);
    }
    printf("0\n");
}

int main()
{
    int terms1, terms2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &terms1);
    struct Polynomial *poly1 = createPolynomial(terms1);
    readPolynomial(poly1);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &terms2);
    struct Polynomial *poly2 = createPolynomial(terms2);
    readPolynomial(poly2);

    struct Polynomial *result = multiplyPolynomials(poly1, poly2);
    printPolynomial(result);

    free(poly1->array);
    free(poly1);
    free(poly2->array);
    free(poly2);
    free(result->array);
    free(result);

    return 0;
}


