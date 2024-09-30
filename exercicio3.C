#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

#define MAX_DIAS 31

void ler_dados_faturamento("dados.json", double faturamento[], int *num_dias_validos) {
    FILE *fp = fopen(arquivo, "r");
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *dia;
    struct json_object *valor_faturamento;

    size_t n_dias;
    size_t i;

    fread(buffer, sizeof(char), 1024, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    n_dias = json_object_array_length(parsed_json);

    *num_dias_validos = 0;

    for (i = 0; i < n_dias; i++) {
        dia = json_object_array_get_idx(parsed_json, i);
        valor_faturamento = json_object_object_get(dia, "faturamento");

        double valor = json_object_get_double(valor_faturamento);

        if (valor > 0) {
            faturamento[*num_dias_validos] = valor;
            (*num_dias_validos)++;
        }
    }
}

int main() {
    double faturamento[MAX_DIAS];
    int num_dias_validos;
    double menor_faturamento, maior_faturamento, soma_faturamento = 0;
    int dias_acima_da_media = 0;

    ler_dados_faturamento("faturamento.json", faturamento, &num_dias_validos);

    menor_faturamento = maior_faturamento = faturamento[0];

    for (int i = 0; i < num_dias_validos; i++) {
        if (faturamento[i] < menor_faturamento) {
            menor_faturamento = faturamento[i];
        }
        if (faturamento[i] > maior_faturamento) {
            maior_faturamento = faturamento[i];
        }
        soma_faturamento += faturamento[i];
    }

    double media_faturamento = soma_faturamento / num_dias_validos;

    for (int i = 0; i < num_dias_validos; i++) {
        if (faturamento[i] > media_faturamento) {
            dias_acima_da_media++;
        }
    }

    printf("Menor valor de faturamento: %.2f\n", menor_faturamento);
    printf("Maior valor de faturamento: %.2f\n", maior_faturamento);
    printf("Dias com faturamento acima da média: %d\n", dias_acima_da_media);

    return 0;
}
