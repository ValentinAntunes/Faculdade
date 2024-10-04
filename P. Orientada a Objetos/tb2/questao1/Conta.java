package Model;

public class Conta {
    private double saldo;

    public Conta(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    public double getSaldo() {
        return saldo;
    }

    public void deposita(double valor) {
        if (valor > 0) {
            saldo += valor;
            System.out.println("Depositado: " + valor);
        } else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    public void saca(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            System.out.println("Sacado: " + valor);
        } else {
            System.out.println("Valor de saque inválido ou saldo insuficiente.");
        }
    }

    public void atualiza(double taxa) {
        if (taxa > 0) {
            saldo += saldo * (taxa / 100);
            System.out.println("Saldo atualizado com a taxa de " + taxa + "%");
        } else {
            System.out.println("Taxa inválida.");
        }
    }
}
