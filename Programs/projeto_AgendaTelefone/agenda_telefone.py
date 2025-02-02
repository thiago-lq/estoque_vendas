import uteis_agendaT
escolha = 0
while escolha != "SAIR":
    escolha = input("O que deseja fazer na sua agenda telefônica?\n \
                \n[Adicionar contato] \n[Buscar contato] \n[Apagar contato] \
                 \n[Editar contato] \n[Abrir agenda] \n[Sair]\n ").upper().strip()
    if escolha == "ADICIONAR CONTATO":
        uteis_agendaT.add()
    elif escolha == "BUSCAR CONTATO":
        uteis_agendaT.busca()
    elif escolha == "APAGAR CONTATO":
        uteis_agendaT.pop()
    elif escolha == "EDITAR CONTATO":
        uteis_agendaT.editar()
    elif escolha == "ABRIR AGENDA":
        print(f"Sua agenda telefônica \n{uteis_agendaT.agendaT}\n")
    elif escolha == "SAIR":
        print("Agenda fechada")
    else:
        print("\nEscolha uma das opções acima\n")
