#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//struct contendo as informa��es do produto
struct produto {
    int id;
    char nome[30];
    float valor;
    int estoque;
};
//struct contendo informa��es necessarias para venda
struct venda {
    int idProduto;
    int quantidade;
    char data[20];
};
//fun��o que segue a tabela ASC para implementa��o de a�oes coordenadas por teclas expecificas
enum {
    KEY_ESC     = 27,
    KEY_ENTER   = 13,
    ARROW_UP    = 256 + 72,
    ARROW_DOWN  = 256 + 80,
};
//matriz do menu principal
char menuPrincipal[7][100] = {
    "Cadastrar produtos",
    "Ver produtos cadastrados",
    "Alterar estoque",
    "Remover produto",
    "Realizar venda",
    "Ver hist�rico de vendas",
    "Sair"
};
//matriz dos menus, de sim ou nao, internos do sistema
char menuSimNao[2][100] = {
    "Sim",
    "N�o"
};
//defini��o de variaveis
int liberarIds[100];
int numLiberados = 0;
//static usado para que nenhuma outra variavel possa ser definida por esse mesmo nome
//fun��o getch usado para capturar a a��o da tecla pressionada
static int pegarcod(void) {
    int ch = getch();
    if (ch == 0 || ch == 224) {
        ch = 256 + getch();
    }
    return ch;
}
//fun��o void que serve para gerar o menu, que foi definido como matriz no come�o do cod�go, e abaixo a fun��o de sele��o do menu [*] comandado pela teclas pressionadas
void GerarMenu(char menu[][100], int tamanho, int escolha) {
    printf("\n\n\n");
    for (int i = 0; i < tamanho; i++) {
        if (escolha == i) {
            printf("\t[*] %s\n", menu[i]);
        } else {
            printf("\t[ ] %s\n", menu[i]);
        }
    }
}
//fun��o inteira com a gera��o do menu interativo, uma jun��o dos outros comandos do menu, servindo para apagar e gerar uma nova sele��o [*] no menu
int MenuInterativo(char menu[][100], int tamanho) {
    int escolha = 0;
    int tecla;
    while ((tecla = pegarcod()) != KEY_ESC) {
        switch (tecla) {
            case ARROW_UP:

                system("cls");
                if (escolha > 0) {
                    escolha--;
                }
                GerarMenu(menu, tamanho, escolha);
                break;
            case ARROW_DOWN:
                system("cls");
                if (escolha < tamanho - 1) {
                    escolha++;
                }
                GerarMenu(menu, tamanho, escolha);
                break;
            case KEY_ENTER:
                return escolha;
        }
    }
    return -1;
}

//fun��o void que cria/abre um arquivo para armazenar os IDs dos prodrutos
void SalvarUltimoId(int ultimoId) {
    FILE *arq = fopen("id.bin", "wb");
    if (arq != NULL) {
        fwrite(&ultimoId, sizeof(int), 1, arq);
        fclose(arq);
    }
}
//fun��o inteira que l� o ultimo ID cadastrado
int LerUltimoId() {
    FILE *arq = fopen("id.bin", "rb");
    int ultimoId = 0;
    if (arq != NULL) {
        fread(&ultimoId, sizeof(int), 1, arq);
        fclose(arq);
    }
    return ultimoId;
}
//fun��o inteira que checa qual ID est� dispon�vel e identifica e salva tal ID no novo produto
int ObterId() {
    if (numLiberados > 0) {
        return liberarIds[--numLiberados];
    } else {
        int ultimoId = LerUltimoId();
        SalvarUltimoId(++ultimoId);
        return ultimoId;
    }
}
/*fun��o void que cria/abre um arquivo para cadastrar um produto, nessa fun��o tambem h� a presen�a das informa��es necessarias para o cadastro dos produtos e a combina��o dessa
interface com os menus de sim e nao que servem para ao final do cadastro mostrar mais op��es funcionais para o usuario*/
void CadastrarProdutos() {
    struct produto p;
    FILE *arq = fopen("produtos.bin", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    do {
        while (getchar() != '\n');
        system("cls");
        printf("Digite o nome do produto: ");
        fgets(p.nome, sizeof(p.nome), stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';  // Remove o \n do final

        printf("Digite o valor do produto: ");
        scanf("%f", &p.valor);
        while (getchar() != '\n');  // Limpa o buffer de entrada

        printf("Digite a quantidade em estoque: ");
        scanf("%d", &p.estoque);
        while (getchar() != '\n');  // Limpa o buffer de entrada

        p.id = ObterId();

        fwrite(&p, sizeof(struct produto), 1, arq);

        printf("Produto cadastrado com sucesso! ID: %d\n", p.id);

        printf("Deseja cadastrar outro produto?\n");
        GerarMenu(menuSimNao, 2, 0);
        int escolha = MenuInterativo(menuSimNao, 2);

        if (escolha != 0) {
            break;
        }

    } while (1);

    fclose(arq);

    printf("Deseja visualizar os produtos cadastrados?\n");
    GerarMenu(menuSimNao, 2, 0);
    int escolhaVisualizar = MenuInterativo(menuSimNao, 2);

    if (escolhaVisualizar == 0) {
        ListarProdutos();
    }
}
//fun��o void que cria/abre um aruqivo que armazena os dados dos produtos
void ListarProdutos() {
    FILE *arq = fopen("produtos.bin", "rb");
    struct produto p;

    system("cls");
    if (arq != NULL) {
        printf("\nProdutos cadastrados:\n");
        while (fread(&p, sizeof(struct produto), 1, arq)) {
            printf("ID: %d | Nome: %s | Valor: %.2f | Estoque: %d\n", p.id, p.nome, p.valor, p.estoque);
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo ou nenhum produto cadastrado.\n");
    }
    printf("Pressione qualquer tecla para voltar...");
    getch();
}
/*fun��o void que abre o arquivo dos produtos, que tem a possibilidade de ser preenchido e lido, possibilitando uma busca por um produto especifico por meio do ID dele e apos
isso pode se alterar a informa��o da quantidade de estoque que esse produto possui */
void AlterarEstoque() {
    int id, novoEstoque;
    struct produto p;
    FILE *arq = fopen("produtos.bin", "r+b");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    printf("Digite o ID do produto para alterar o estoque: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct produto), 1, arq)) {
        if (p.id == id) {
            printf("Estoque atual: %d\n", p.estoque);
            printf("Digite o novo estoque: ");
            scanf("%d", &novoEstoque);
            p.estoque = novoEstoque;

            fseek(arq, -sizeof(struct produto), SEEK_CUR); //FUN��O ESPECIAL USADA PARA ENCONTRAR ESPECIFICAMENTE UMA POSI��O NO ARQUIVO E NO CASO MOVER O PONTEIRO PARA TR�S.
            fwrite(&p, sizeof(struct produto), 1, arq);
            fclose(arq);

            printf("Estoque atualizado com sucesso!\n");
            printf("Pressione qualquer tecla para voltar...");
            getch();
            return;
        }
    }

    printf("Produto n�o encontrado!\n");
    fclose(arq);
    printf("Pressione qualquer tecla para voltar...");
    getch();
}
/*fun��o void que abre o arquivo das informa��es do produto e em seguida cria/abre um arquivo que vai servir para atualizar o anterior, � feito uma busca do produto pelo seu ID,
quando encontrado seu ID � liberado para uso imediato e todas as informa��es atualizadas sao passadas para o arquivo temp e ap�s isso o antigo arquivo de que tinha as informa��es
dos prodrutos � excluido e o arquivo temp atualizado � renomeado para produtos assim fazendo a atualiza��o dos produtos atuais. */
void RemoverProduto() {
    int id;
    struct produto p;
    FILE *arq = fopen("produtos.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    if (arq == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("Digite o ID do produto para remover: ");
    scanf("%d", &id);

    int encontrado = 0;
    while (fread(&p, sizeof(struct produto), 1, arq)) {
        if (p.id != id) {
            fwrite(&p, sizeof(struct produto), 1, temp);
        } else {
            encontrado = 1;
            liberarIds[numLiberados++] = id; // Adiciona o ID � lista de liberados
        }
    }

    fclose(arq);
    fclose(temp);

    remove("produtos.bin");
    rename("temp.bin", "produtos.bin");

    if (encontrado) {
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto n�o encontrado!\n");
    }
    printf("Pressione qualquer tecla para voltar...");
    getch();
}
/*fun��o void que cria/abre um arquivo para armazenar os dados de uma venda, essa fun��o tambem abre o arquivo dos produtos para atualizar o estoque do produto vendido a busca
do produto a ser vendido � feito pelo seu ID, o sistema mostra quanto h� no estoque e se for maior que 0 a venda � autorizada e seu estoque atualizado e tambem surge a op��o
de apresentar a data que o prodruto foi vendido sendo salvo no arquivo de vendas tambem. */
void RealizarVenda() {
    int id, quantidade;
    struct produto p;
    struct venda v;
    FILE *arq = fopen("produtos.bin", "r+b");
    FILE *arqVenda = fopen("vendas.bin", "ab");

    if (arq == NULL || arqVenda == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("Digite o ID do produto para venda: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct produto), 1, arq)) {
        if (p.id == id) {
            printf("Estoque atual: %d\n", p.estoque);
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidade);

            if (quantidade > p.estoque) {
                printf("Quantidade insuficiente no estoque!\n");
            } else {
                p.estoque -= quantidade;

                fseek(arq, -sizeof(struct produto), SEEK_CUR);
                fwrite(&p, sizeof(struct produto), 1, arq);

                v.idProduto = id;
                v.quantidade = quantidade;

                printf("Digite a data da venda (formato DD/MM/AAAA): ");
                scanf("%s", v.data);

                fwrite(&v, sizeof(struct venda), 1, arqVenda);

                printf("Venda realizada com sucesso!\n");
                printf("ID: %d | Quantidade: %d | Data: %s\n", v.idProduto, v.quantidade, v.data);
                printf("Pressione qualquer tecla para voltar...");
                getch();
                fclose(arq);
                fclose(arqVenda);
                return;
            }
        }
    }

    printf("Produto n�o encontrado!\n");
    fclose(arq);
    fclose(arqVenda);
    printf("Pressione qualquer tecla para voltar...");
    getch();
}
//  fun��o void que abre o arquivo de vendas e mostra todas as venda concluidas, sua data, quantidade vendida e informa��es gerais dos produtos vendidos/
void ExibirHistoricoVendas() {
    struct venda v;
    FILE *arqVenda = fopen("vendas.bin", "rb");

    if (arqVenda == NULL) {
        printf("Erro ao abrir o arquivo de vendas!\n");
        return;
    }

    system("cls");
    printf("Hist�rico de Vendas:\n");
    while (fread(&v, sizeof(struct venda), 1, arqVenda)) {
        printf("ID Produto: %d | Quantidade: %d | Data: %s\n", v.idProduto, v.quantidade, v.data);
    }

    fclose(arqVenda);
    printf("Pressione qualquer tecla para voltar...");
    getch();
}
//fun��o void que serve para gerar uma simples interface para a loja que se refere o sistema
void ExibirBoasVindas() {
    system("cls");
    printf("\n\n\n");
    printf("\tBEM VINDO AO SISTEMA DA LOJA\n");
    printf("\n");
    printf("\tPressione qualquer tecla para continuar...\n");
    getch();
}
/*fun��o main, principal, set locale para tornar possivel a utiliza��o de caraceteres especiais, a interface sendo puxada no inicio, while sendo usado para a navega��o entre as
fun��es do menu principal todos sendo controlados pelas teclas como foi mostrado anteriormente. */
int main() {
    setlocale(LC_ALL, "Portuguese");

    ExibirBoasVindas();

    while (1) {
        system("cls");
        printf("\n\n\n");
        printf("\tBEM VINDO!\n");
        GerarMenu(menuPrincipal, 7, 0);
        int opcao = MenuInterativo(menuPrincipal, 7);

        if (opcao == 0) {
            CadastrarProdutos();
        } else if (opcao == 1) {
            ListarProdutos();
        } else if (opcao == 2) {
            AlterarEstoque();
        } else if (opcao == 3) {
            RemoverProduto();
        } else if (opcao == 4) {
            RealizarVenda();
        } else if (opcao == 5) {
            ExibirHistoricoVendas();
        } else if (opcao == 6) {
            printf("Saindo...\n");
            break;
        }
    }

    return 0;
}
