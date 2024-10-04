package Model;

// Classe base - Conta.java
public class Conta {
    protected double saldo;

    // Construtor
    public Conta(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    // Método para obter o saldo
    public double getSaldo() {
        return saldo;
    }

    // Método para depositar na conta
    public void deposita(double valor) {
        if (valor > 0) {
            saldo += valor;
            System.out.println("Depositado: " + valor);
        } else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    // Método para sacar da conta
    public void saca(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            System.out.println("Sacado: " + valor);
        } else {
            System.out.println("Valor de saque inválido ou saldo insuficiente.");
        }
    }

    // Método para atualizar o saldo com uma taxa percentual (será sobrescrito nas subclasses)
    public void atualiza(double taxa) {
        saldo += saldo * (taxa / 100);
        System.out.println("Saldo atualizado com a taxa de " + taxa + "%");
    }
}
