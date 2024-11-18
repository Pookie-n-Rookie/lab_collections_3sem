#include <stdio.h>
#include <stdlib.h>

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
    int i;
    printf("Enter coefficients and exponents for %d terms:\n", poly->terms);
    for (i = 0; i < poly->terms; i++)
    {
        scanf("%d %d", &poly->array[i].coefficient, &poly->array[i].exponent);
    }
}
 struct Polynomial *addPolynomials(struct Polynomial *poly1, struct Polynomial *poly2)
{
    int i = 0, j = 0, k = 0;
    int totalTerms = poly1->terms + poly2->terms;
    struct Polynomial *result = createPolynomial(totalTerms);

    while (i < poly1->terms && j < poly2->terms)
    {
        if (poly1->array[i].exponent > poly2->array[j].exponent)
        {
            result->array[k] = poly1->array[i];
            i++;
        }
        else if (poly1->array[i].exponent < poly2->array[j].exponent)
        {
            result->array[k] = poly2->array[j];
            j++;
        }
        else
        {
            result->array[k].exponent = poly1->array[i].exponent;
            result->array[k].coefficient = poly1->array[i].coefficient + poly2->array[j].coefficient;
            i++;
            j++;
        }
        k++;
    }

    while (i < poly1->terms)
    {
        result->array[k] = poly1->array[i];
        i++;
        k++;
    }

    while (j < poly2->terms)
    {
        result->array[k] = poly2->array[j];
        j++;
        k++;
    }

    result->terms = k;
    return result;
}

void printPolynomial(struct Polynomial *poly)
{
    int i;
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
    printf("The first polynomial is: ");
    printPolynomial(poly1);
    printf("The second polynomial is :");
    printPolynomial(poly2);
    printf("SUMMATION : ");
    struct Polynomial *result = addPolynomials(poly1, poly2);
    printPolynomial(result);

    free(poly1->array);
    free(poly1);
    free(poly2->array);
    free(poly2);
    free(result->array);
    free(result);

    return 0;
}



