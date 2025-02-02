## Sistema de gest�o de estoque e vendas ##

- Introdu��o

	Uma aplica��o com a finalidade de cadastrar e retirar produtos com suas informa��es e registrar vendas. Ambas as a��es criam arquivos.bin como relat�rios para controle de estoque e faturamento.

- Como usar

	O programa necessita de uma IDLE comp�tivel com a linguagem C para funcionar. Primeiramente, todo o programa � interativo podendo usar as "setas", "enter" e "esc" do teclado para transitar entre os menus. 
	Quando inicializado, uma mensagem de boas vindas ser� aberta e posteriormente um menu aparecer� para o usu�rio, o qual poder� transitar entre as op��es com as setas do teclado, usando enter como confirma��o e esc para finalizar a aplica��o.

- Menu e suas funcionalidades

Cadastrar produtos: Ao confirmar, o sistema ir� pedir o nome, valor e quantidade do produto para o usu�rio at� o mesmo escolher "n�o" e voltar para o menu principal. Todos os produtos e suas informa��es s�o automaticamente salvos em um arquivo.bin.

Ver produtos cadastrados: Ir� ler o arquivo salvo e mostrar os produtos com as suas respectivas informa��es e ID.

Alterar estoque: A partir da ID do produto, o usu�rio pode alterar a quantidade do produto no estoque.

Remover produto: A partir da ID do produto, o usu�rio pode remover um produto j� cadastrado. O sistema ir� automaticamente liberar a ID do produto removido para ser usada novamente.

Realizar venda: A partir do ID do produto o usu�rio pode realizar vendas, tendo que indicar a quantidade vendida e a data de venda.

Ver hist�rico de vendas: O Sistema ir� ler o relat�rio de vendas (arquivo.bin) e ir� mostrar qual produto foi vendido, quantidade, e a data de venda.

Sair: Funciona como "esc", e ir� fechar o programa quando selecionado.

- Autores

Thiago Lima Queiroz (https://github.com/thiago-lq)
Leandro Moreira Dos Reis Souza (https://github.com/leomreis)