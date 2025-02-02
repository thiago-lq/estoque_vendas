## Sistema de gestão de estoque e vendas ##

- Introdução

	Uma aplicação com a finalidade de cadastrar e retirar produtos com suas informações e registrar vendas. Ambas as ações criam arquivos.bin como relatórios para controle de estoque e faturamento.

- Como usar

	O programa necessita de uma IDLE compátivel com a linguagem C para funcionar. Primeiramente, todo o programa é interativo podendo usar as "setas", "enter" e "esc" do teclado para transitar entre os menus. 
	Quando inicializado, uma mensagem de boas vindas será aberta e posteriormente um menu aparecerá para o usuário, o qual poderá transitar entre as opções com as setas do teclado, usando enter como confirmação e esc para finalizar a aplicação.

- Menu e suas funcionalidades

Cadastrar produtos: Ao confirmar, o sistema irá pedir o nome, valor e quantidade do produto para o usuário até o mesmo escolher "não" e voltar para o menu principal. Todos os produtos e suas informações são automaticamente salvos em um arquivo.bin.

Ver produtos cadastrados: Irá ler o arquivo salvo e mostrar os produtos com as suas respectivas informações e ID.

Alterar estoque: A partir da ID do produto, o usuário pode alterar a quantidade do produto no estoque.

Remover produto: A partir da ID do produto, o usuário pode remover um produto já cadastrado. O sistema irá automaticamente liberar a ID do produto removido para ser usada novamente.

Realizar venda: A partir do ID do produto o usuário pode realizar vendas, tendo que indicar a quantidade vendida e a data de venda.

Ver histórico de vendas: O Sistema irá ler o relatório de vendas (arquivo.bin) e irá mostrar qual produto foi vendido, quantidade, e a data de venda.

Sair: Funciona como "esc", e irá fechar o programa quando selecionado.

- Autores

Thiago Lima Queiroz (https://github.com/thiago-lq)
Leandro Moreira Dos Reis Souza (https://github.com/leomreis)