package Model;

import Model.Conta;

// Subclasse - ContaCorrente.java
public class ContaCorrente extends Conta {

    // Construtor
    public ContaCorrente(double saldoInicial) {
        super(saldoInicial);
    }

    // Sobrescrevendo o método deposita para aplicar taxa bancária de 10 centavos
    @Override
    public void deposita(double valor) {
        if (valor > 0) {
            saldo += (valor - 0.10); // Aplicando taxa de 10 centavos
            System.out.println("Depositado: " + valor + " (com taxa de R$0,10)");
        } else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    // Sobrescrevendo o método atualiza para aplicar o dobro da taxa
    @Override
    public void atualiza(double taxa) {
        saldo += saldo * (taxa / 100) * 2; // Aplicando o dobro da taxa
        System.out.println("Saldo atualizado com o dobro da taxa de " + taxa + "%");
    }
}