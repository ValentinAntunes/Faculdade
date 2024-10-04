package Model;

public class Conta {
    private double saldo;

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

    // Método para atualizar o saldo com uma taxa percentual
    public void atualiza(double taxa) {
        if (taxa > 0) {
            saldo += saldo * (taxa / 100);
            System.out.println("Saldo atualizado com a taxa de " + taxa + "%");
        } else {
            System.out.println("Taxa inválida.");
        }
    }
}