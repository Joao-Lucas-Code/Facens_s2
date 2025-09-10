resposta = int(input("Quantos numeros deseja adicionar na lista? "))
lista = []
subtracao = 19.990
resultado = []

for c in range(0, resposta):
    numero = float(input("Digite um numero: "))
    lista.append(numero)

for i in lista:
    resultado.append(subtracao - i)

print(f"Lista original: {lista}")
print(f"Lista resultado: {resultado}")

# [65.35, 66.224, 65.823, 66.225, 65.523, 66.208, 65.809, 66.237]
#