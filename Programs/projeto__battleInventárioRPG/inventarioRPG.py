import uteis_InventarioRPG
escolha = 0
opcao = 0
while escolha != "NÃO":
    escolha = input("Deseja entrar no inventario? [Sim] [Não] ").upper().strip()
    if escolha == "SIM":
        while opcao != "SAIR":
            opcao = input("\nO que deseja fazer?\n \n[Adicionar] \n[Buscar] \n[Abrir] \n[Comparar] \n[Sair]\n ").upper().strip()
            if opcao == "ADICIONAR":
                uteis_InventarioRPG.add()
            elif opcao == "BUSCAR":
                uteis_InventarioRPG.busca()
            elif opcao == "ABRIR":
                uteis_InventarioRPG.inventario()
            elif opcao == "COMPARAR":
                uteis_InventarioRPG.comparação()
            elif opcao == "SAIR":
                print("inventario fechado")
            else:
                print("Escolha uma opção")
    elif escolha == "NÃO":
        print("Menu fechado")
    else:
        print("Escolha uma opção")
        