#include <stdio.h>

int main(void)
{
    double daphne = 100.0, deirdre = 100.0;
    int year;

    for (year = 0; deirdre <= daphne; year++)
    {
        daphne += 100.0 * 0.1;
        deirdre *= 1 + 0.05;
    }
    printf("After %d years, Dairdre richer than Daphne.\n", year);
    printf("Deirdre: %f\nDaphne: %f\n", deirdre, daphne);

    return 0;
}
