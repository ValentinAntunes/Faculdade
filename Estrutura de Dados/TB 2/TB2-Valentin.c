/*obs: o nome do arquivo de texto de entrada usado é arquivo.txt ;
- o arquivo.txt foi colocado dentro da pasta "output" para compilar no VSCode ; */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float X;
    float Y;
} Ponto;

//area do triangulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y))) / 2.0;
}
//area do poligono
float AreaPoligono(Ponto *vertices, int Nvertices) {
    float Area = 0;

    //divisao do poligono em triangulos
    for (int i = 1; i < Nvertices - 1; i++) {
        Area += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    return fabs(Area);
}

int main() {
    FILE *arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) { 
        printf("ERRO\n");
        return 1;
    }

    char Linha[100];
    int Nvertices;
    fgets(Linha, sizeof(Linha), arquivo);
    sscanf(Linha, "%d", &Nvertices);

    if (Nvertices < 3) {
        fclose(arquivo);
        return 1;
    }

    Ponto *vertices = (Ponto *)malloc(Nvertices * sizeof(Ponto));

    for (int i = 0; i < Nvertices; i++) {
        fgets(Linha, sizeof(Linha), arquivo);
        sscanf(Linha, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    //calculo da area do poligono
    float Area = AreaPoligono(vertices, Nvertices);

    free(vertices);

    printf("A área do polígono é %.2f\n", Area);

    return 0;
}