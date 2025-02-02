# Variáveis
armas = {}
armaduras = {}
consumiveis = {}
materiais = {}
# Função de adicionar
def add():
    tipo = {}
    tipo2 = {}
    atributos = {}
    atributos2 = {}
    itens = input("Qual item deseja armazenar? \n [Arma] [Consumível] [Material] [Armadura] ").upper().strip()
    if itens == "ARMA":
        arma = input("Qual arma deseja armazenar? ")
        while arma in armas:
            print("Erro, arma já existe no inventario...")
            arma = input("Qual arma deseja armazenar? ")
        qnt = int(input("Quantos atributos ela possui? "))
        for i in range(0, qnt):
            status = input("Qual o nome do status? ")
            num = int(input("Quanto desse status ela possui? ")) 
            atributos[status] = num
        armas[arma] = atributos
        print("Arma adicionada")
    elif itens == "CONSUMÍVEL":
        tip = input("Qual o tipo de consumível? ")
        algo = input("Digite o nome do consumivel: ")
        quant = int(input("Qual a quantidade? "))
        tipo[algo] = quant
        consumiveis[tip] = tipo
        print("Consumível adicionado")
    elif itens == "MATERIAL":
        tip = input("Qual o tipo de material? ")
        algo = input("Qual o material? ")
        quant = int(input("Qual a quantidade? "))
        tipo2[algo] = quant
        materiais[tip] = tipo2
        print("Material adicionado")
    elif itens == "ARMADURA":
        arma = input("Qual armadura deseja armazenar? ")
        while arma in armaduras:
            print("Erro, armadura já existe no inventario...")
            arma = input("Qual armadura deseja armazenar? ")
        qnt = int(input("Quantos atributos ela possui? "))
        for i in range(0, qnt):
            status = input("Qual o nome do status? ")
            num = int(input("Quantos desse status ela possui? "))
            atributos2[status] = num
        armaduras[arma] = atributos2
        print("Arma adicionada")
    else:
        None
# Função de busca
def busca():
    escolha = 0
    p = input("Qual item deseja procurar? ")
    if p in armaduras:
        print(armaduras[p])
        while escolha != "NÃO":
            escolha = input("Deseja remover a armadura do inventario? [Sim] [Não] ").upper().strip()
            if escolha == "SIM":
                armaduras.pop(p)
                break
            elif escolha == "NÃO":
                print("Fechando inventario...")
            else:
                print("Escolha uma opção")
    if p in armas:
        print(armas[p])
        while escolha != "NÃO":
            escolha = input("Deseja remover a arma do inventario? [Sim] [Não] ").upper().strip()
            if escolha == "SIM":
                armas.pop(p)
                break
            elif escolha == "NÃO":
                print("Fechando inventario...")
            else:
                print("Escolha uma opção")
    if p in consumiveis:
        print(consumiveis[p])
        while escolha != "NÃO":
            escolha = input("Deseja remover a arma do inventario? [Sim] [Não] ").upper().strip()
            if escolha == "SIM":
                consumiveis.pop(p)
                break
            elif escolha == "NÃO":
                print("Fechando inventario...")
            else:
                print("Escolha uma opção")
    if p in materiais:
        print(materiais[p])
        while escolha != "NÃO":
            escolha = input("Deseja remover a arma do inventario? [Sim] [Não] ").upper().strip()
            if escolha == "SIM":
                materiais.pop(p)
                break
            elif escolha == "NÃO":
                print("Fechando inventario...")
            else:
                print("Escolha uma opção")
# Função de abrir inventário
def inventario():
    print(armas)
    print(armaduras)
    print(consumiveis)
    print(materiais)
# Função de comparação
def comparação():
    escolha = input("O que você deseja comparar? [Arma] [Armadura] ").upper().strip()
    if escolha == "ARMA":
        opcao1 = input("Escolha uma arma: ")
        while opcao1 not in armas:
            print("\nErro, arma não encontrada...\n")
            opcao1 = input("Digite o nome da arma novamente: ")
        status1 = input("Qual status deseja comparar? ")
        while status1 not in armas[opcao1]:
            print("\nErro, arma não possui esse status\n")
            status1 = input("Qual status deseja comparar? ")
        opcao2 = input("Escolha outra arma: ")
        while opcao2 not in armas:
            print("\nErro, arma não encontrada...\n")
            opcao2 = input("Digite o nome da arma novamente: ")
        status2 = input("Qual status deseja comparar? ")
        while status2 not in armas[opcao2]:
            print("\nErro, arma não possui esse status\n")
            status2 = input("Qual status deseja comparar? ")
        if armas[opcao1][status1] < armas[opcao2][status2]:
            print(f"A arma {opcao1 ,armas[opcao1]} é inferior a arma {opcao2 ,armas[opcao2]} em {status1}")
        elif armas[opcao1][status1] > armas[opcao2][status2]:
            print(f"A arma {opcao1, armas[opcao1]} é superior a arma {opcao2 ,armas[opcao2]} em {status2}")
        elif armas[opcao1][status1] == armas[opcao2][status2]:
            print(f"A arma {opcao1, armas[opcao1]} tem o atributo igual a arma {opcao2, armas[opcao2]} em {status1}")
        else:
            print("Erro, nenhuma opção escolhida...")
    elif escolha == "ARMADURA":
        opcao1 = input("Escolha uma armadura: ")
        while opcao1 not in armaduras:
            print("\nErro, armadura não encontrada...\n")
            opcao1 = input("Digite o nome da armadura novamente: ")
        status1 = input("Qual status deseja comparar? ")
        while status1 not in armaduras[opcao1]:
            print("\nErro, armadura não possui esse status\n")
            status1 = input("Qual status deseja comparar? ")
        opcao2 = input("Escolha outra armadura: ")
        while opcao2 not in armaduras:
            print("\nErro, armadura não encontrada...\n")
            opcao2 = input("Digite o nome da armadura novamente ")
        status2 = input("Qual status deseja comparar: ")
        while status2 not in armaduras[opcao2]:
            print("\nErro, armadura não possui esse status\n")
            status2 = input("Qual status deseja comparar? ")
        if armaduras[opcao1][status1] < armaduras[opcao2][status2]:
            print(f"A armadura {opcao1, armaduras[opcao1]} é inferior a armadura {opcao2, armaduras[opcao2]} em {status1}")
        elif armaduras[opcao1][status1] > armaduras[opcao2][status2]:
            print(f"A armadura {opcao1, armaduras[opcao1]} é superior a armadura {opcao2, armaduras[opcao2]} em {status1}")
        else:
            print("Erro, nenhuma opção escolhida...")
    else:
        None
    print("Fechando painel de comparação")
