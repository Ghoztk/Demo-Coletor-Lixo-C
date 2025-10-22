#include <stdio.h>
#include <stdlib.h>
#include "gc-8.2.10/include/gc.h"

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* LerArvore(FILE* arq){
    char c;
    int num;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if(num == -1){
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else{
        Tree* a = GC_malloc(sizeof(Tree));
        a->data = num;
        a->left = LerArvore(arq);
        a->right = LerArvore(arq);
        fscanf(arq, "%c", &c);
        return a;
    }
}

Tree* makeNode(int data){
    Tree* new_node = GC_malloc(sizeof(Tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void printPreOrder(Tree* node){
    if(node == NULL)
        return;
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(Tree* node){
    if(node == NULL)
        return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

void printPostOrder(Tree* node){
    if(node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

void printLevel(Tree* node, int cont, int lvl){
    if(node != NULL){
        if(cont == lvl){
            printf("%d ", node->data);
        }
        else{
            printLevel(node->left, cont+1, lvl);
            printLevel(node->right, cont+1, lvl);
        }
    }
}

int treeHeight(Tree* node){
    if(node == NULL)
        return 0;
    else{
        int heightLeft = treeHeight(node->left);
        int heightRight = treeHeight(node->right);

        if(heightLeft > heightRight)
            return heightLeft+1;
        else
            return heightRight+1;
    }
}

int existNode(Tree* node, int data){
    if(node == NULL)
        return 0;
    else if(node->data == data)
        return 1;
    else if(node->data >= data)
        return existNode(node->left, data);
    else
        return existNode(node->right, data);
}

int findNodeLevel(Tree* node, int data, int level){
    if(node == NULL)
        return -1;
    else if(node->data == data)
        return level;
    else if(node->data >= data)
        return findNodeLevel(node->left, data, level+1);
    else
        return findNodeLevel(node->right, data, level+1);
}

void printLowerNodesInOrder(Tree* node, int data){
    if(node == NULL)
        return;
    printLowerNodesInOrder(node->left, data);

    if(node->data < data){
        printf("%d ", node->data);
    }

    printLowerNodesInOrder(node->right, data);
}

Tree* insertNode(Tree* node, int data){
    if(node == NULL){
        return makeNode(data);
    }

    else if(node->data >= data){
        node->left = insertNode(node->left, data);
    }
    else{
        node->right = insertNode(node->right, data);
    }

    return node;
}

Tree* removeNode(Tree* node, int data){
    if(node != NULL){
        if(node->data == data){
            //caso 1: Sem folhas.
            if(node->left == NULL && node->right == NULL){
                return NULL;
            }
            //caso 2: Duas folhas.
            else if(node->left != NULL && node->right != NULL){
                Tree* aux = node->left;
                while(aux->right != NULL)
                    aux = aux->right;
                node->data = aux->data;
                node->left = removeNode(node->left, aux->data);
            }
            //caso 3: Folha única.
            else if(node->left != NULL || node->right != NULL){
                Tree* aux = node->left != NULL ? node->left : node->right;
                return aux;
            }
        }

        if(node->data >= data)
            node->left = removeNode(node->left, data);
        else
            node->right = removeNode(node->right, data);
    }
    return node;
}


int main(){
    Tree* root = NULL;
    char arqName[201];
    int option;
    int isRunning = 1;
    printf("Digite o arquivo nome do arquivo da arvore que deseja ler: ");
    scanf(" %s", arqName);
    while (getchar() != '\n');
    FILE* arq = fopen(arqName, "rt");

    if(arq != NULL){
        root = LerArvore(arq);
        fclose(arq);
        printf("\n\nLeitura do arquivo foi completada!");

        printf("\n\nPressione <ENTER> para acessar o menu de opcoes.");
        getchar();
    }
    else{
        printf("\n\nAlgo de errado aconteceu...");
        isRunning = 0;
    }

    while(isRunning){

        system("clear");

        printf("Escolha uma das opcoes abaixo de acordo com seu respectivo numero:");
        printf("\n\n\t1 - Imprimir arvore.");
        printf("\n\t2 - Verificar se um elemento X existe na arvore.");
        printf("\n\t3 - Imprimir o nivel de um no X.");
        printf("\n\t4 - Imprimir as folhas menores que um valor X.");
        printf("\n\t5 - Inserir um no X na arvore.");
        printf("\n\t6 - Remover um no X da arvore.");
        printf("\n\t7 - Sair.");
        printf("\n\nDigite o numero escolhido aqui: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                system("clear");
                int option2;
                printf("Qual opcao de impressao deseja?");
                printf("\n\n\t1 - Pre-ordem.");
                printf("\n\t2 - Em-ordem.");
                printf("\n\t3 - Pos-ordem.");
                printf("\n\t4 - Em largura.");
                printf("\n\nDigite o numero escolhido aqui: ");
                scanf("%d", &option2);
                while (getchar() != '\n');
                system("clear");
                switch(option2){
                    case 1:
                        printPreOrder(root);
                        break;
                    case 2:
                        printInOrder(root);
                        break;
                    case 3:
                        printPostOrder(root);
                        break;
                    case 4:{
                        int height = treeHeight(root);
                        for(int i = 0; i < height; i++)
                            printLevel(root, 0, i);
                        break;
                    }

                }

                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 2:
                system("clear");
                int data, exists;
                printf("Digite o numero que deseja verificar: ");
                scanf("%d", &data);
                while (getchar() != '\n');
                exists = existNode(root, data);
                if(exists)
                    printf("\n\nO numero %d existe na arvore!", data);
                else
                    printf("\n\nO numero %d nao existe na arvore...", data);

                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 3:
                system("clear");
                int level;
                printf("Digite o numero que deseja saber o nivel: ");
                scanf("%d", &data);
                while (getchar() != '\n');

                level = findNodeLevel(root, data, 0);

                if(level >= 0)
                    printf("\n\nO numero %d esta no nivel %d da arvore", data, level);
                else
                    printf("\n\nNumero nao encontrado...");

                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 4:
                system("clear");
                printf("Digite um valor para que eu imprima todas as folhas menores que ele (em-ordem): ");
                scanf("%d", &data);
                while (getchar() != '\n');
                printf("\n\n");
                printLowerNodesInOrder(root, data);
                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 5:
                system("clear");
                printf("Digite o valor que deseja inserir da arvore: ");
                scanf("%d", &data);
                while (getchar() != '\n');
                root = insertNode(root, data);
                printf("\n\nNumero inserido com sucesso!");
                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 6:
                system("clear");
                printf("Digite o valor que deseja remover da arvore: ");
                scanf("%d", &data);
                while (getchar() != '\n');

                exists = existNode(root, data);

                if(exists){
                    root = removeNode(root, data);
                    printf("\n\nNumero removido com sucesso!");
                }
                else
                    printf("\n\nNumero nao existe...");
                printf("\n\nPressione <ENTER> para voltar ao menu.");
                getchar();
                break;

            case 7:
                isRunning = 0;
        }
    }

}
