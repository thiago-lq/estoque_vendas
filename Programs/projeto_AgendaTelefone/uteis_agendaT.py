# Variáveis abaixo
agendaT = {}
nums = []
# Função de adicionar contato abaixo
def add():
    cont = input("Digite o nome do contato: ")
    while cont in agendaT:
        print("\nErro, contato já existe")
        cont = input("Digite o nome novamente: ")
    num = int(input("Digite o número do contato: "))
    while num in nums:
        print("\nErro, número já existe na agenda")
        num = int(input("Digite outro número: "))
    agendaT[cont] = num
    nums.append(num)
    print("\nContato salvo!\n")
# Função de busca abaixo
def busca():
    cont = input("Qual contato deseja buscar? ")
    while cont not in agendaT:
        print("\nErro, contato não existe")
        cont = input("Digite o nome novamente: ")
    print(f"\n{agendaT[cont]}\n")
# Função de remover contato
def pop():
    print(agendaT)
    cont = input("Qual contato deseja apagar? ")
    while cont not in agendaT:
        print("\nErro, contato não existe")
        cont = input("Digite o nome novamente: ")
    agendaT.pop(cont)
    print(f"\nContato apagado! \n{agendaT}\n")
# Função de editar número do contato
def editar():
    cont = input("Qual contato deseja editar: ")
    num = int(input("Qual o novo número? "))
    agendaT[cont] = num
