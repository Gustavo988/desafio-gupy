#include <stdio.h>

int main() {
    double sp = 67836.43;
    double rj = 36678.66;
    double mg = 29229.88;
    double es = 27165.48;
    double outros = 19849.53;

    double total = sp + rj + mg + es + outros;

    double perc_sp = (sp / total) * 100;
    double perc_rj = (rj / total) * 100;
    double perc_mg = (mg / total) * 100;
    double perc_es = (es / total) * 100;
    double perc_outros = (outros / total) * 100;

    printf("Percentual de representação por estado:\n");
    printf("SP: %.2f%%\n", perc_sp);
    printf("RJ: %.2f%%\n", perc_rj);
    printf("MG: %.2f%%\n", perc_mg);
    printf("ES: %.2f%%\n", perc_es);
    printf("Outros: %.2f%%\n", perc_outros);

    return 0;
}
