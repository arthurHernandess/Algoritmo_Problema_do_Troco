// algoritmo guloso
// pega a maior quantidade da maior moeda que nao estoura o valor
// se for estourar, tenta uma menor
// até dar o troco

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 10

float caixa[MAX] = {0.05, 0.10, 0.25, 0.50, 1, 2, 5, 10, 20, 50};

typedef struct {
    int quantidade;
    float valor;
} moedas;

int calcularTroco(double cobrado, double pago, moedas troco[]){
    if(pago > cobrado){
        float devendo = pago - cobrado;
        int inserir = 0;
        for(int i = MAX-1; i >= 0; i--){    // roda todas as opções de moedas, indo da mais cara até a mais barata
            if(devendo > 0){    //  ve se ja pagou o troco, se ainda nao pagou tudo continua
                if(caixa[i] <= devendo){    //  a moeda atual (maiores valores primeiro) estoura o tanto que eu ainda devo de troco? se não estoura...
                    int qt = devendo/caixa[i]; // qntas dessa moeda eu consigo pegar sem estourar oq eu devo de troco

                    troco[inserir].quantidade = qt; // atribui ao troco
                    troco[inserir].valor = caixa[i];

                    devendo = devendo - qt*caixa[i]; // desconta isso do que eu devo
                    inserir++;
                }
            }
        }
        return inserir; // retorna o tamanho da resposta pra ser mais facil de exibir
    }
    else{
        return -1;
    }
}

int main(){
    double cobrado = 19.85;
    double pago = 20;
    moedas troco[MAX];  // variavel q vai receber a resposta do troco
    moedas zerar; zerar.quantidade = 0; zerar.valor = 0;
    
    for(int i = 0; i < MAX; i++)
        troco[i] = zerar;

    int tamanhoTroco = calcularTroco(cobrado, pago, troco);
    if(tamanhoTroco == -1){
        printf("nao eh necessario nenhum troco");
    }
    else{
        printf("troco: \n");
        for(int i = 0; i < tamanhoTroco; i++){
            printf("  > %d moedas de %.2f reais \n", troco[i].quantidade, troco[i].valor);
        }
    }
    
    return 0;
}