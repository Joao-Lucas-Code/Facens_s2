def cadastro():
    nome = input("Nome do cliente: ")
    saldo = float(input("Saldo inicial: "))
    numero_conta = 1000  # Número fixo da conta
    conta = [nome, saldo]  # Lista com nome e saldo
    print(f"Conta criada com saldo inicial de R${saldo:.2f}")
    print(f"Numero da conta: {numero_conta}")
    return conta, numero_conta


def deposito(conta, numero_conta):
    while True:
        try:
            resposta = int(input("Qual o numero da conta: "))
            if resposta != numero_conta:
                print("Numero da conta incorreto.")
            else:
                break
        except ValueError:
            print("Por favor, digite um numero valido.")

    valor = float(input("Valor do deposito: "))
    conta[1] += valor  # Atualiza o saldo (posição 1 da lista)
    print(f"Deposito de R${valor:.2f} realizado com sucesso!")
    print(f"Saldo atual: R${conta[1]:.2f}")
    return conta


def retirada(conta, numero_conta):
    while True:
        try:
            resposta = int(input("Qual o numero da conta: "))
            if resposta != numero_conta:
                print("Numero da conta incorreto.")
            else:
                break
        except ValueError:
            print("Por favor, digite um numero valido.")

    valor = float(input("Valor da retirada: "))
    if valor > conta[1]:  # Verifica se há saldo suficiente
        print("Saldo insuficiente!")
        print(f"Saldo atual: R${conta[1]:.2f}")
    else:
        conta[1] -= valor
        print(f"Retirada de R${valor:.2f} realizada com sucesso!")
        print(f"Saldo atual: R${conta[1]:.2f}")
    return conta

conta = []
numero_conta = None

opcao = int(input("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOPCAO:"))
while opcao != 4:
    if opcao == 1:
        conta, numero_conta = cadastro()
    elif opcao == 2:
        if len(conta) == 0:
            print("Conta nao cadastrada!")
        else:
            conta = deposito(conta, numero_conta)
    elif opcao == 3:
        if len(conta) == 0:
            print("Conta nao cadastrada!")
        else:
            conta = retirada(conta, numero_conta)
    else:
        print("Opcao invalida!")
    opcao = int(input("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOPCAO:"))
