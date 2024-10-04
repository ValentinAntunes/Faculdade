package Model;

// Subclasse - ContaPoupanca.java
public class ContaPoupanca extends Conta {

    // Construtor
    public ContaPoupanca(double saldoInicial) {
        super(saldoInicial);
    }

    // Sobrescrevendo o método atualiza para aplicar o triplo da taxa
    @Override
    public void atualiza(double taxa) {
        saldo += saldo * (taxa / 100) * 3; // Aplicando o triplo da taxa
        System.out.println("Saldo atualizado com o triplo da taxa de " + taxa + "%");
    }
}
