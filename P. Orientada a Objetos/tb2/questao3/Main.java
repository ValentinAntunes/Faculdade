package Main;

import Model.Conta;
import Model.ContaCorrente;
import Model.ContaPoupanca;
import View.ContaView;
import Controller.ContaController;


// Classe principal - Main.java
public class Main {
    public static void main(String[] args) {
        // Instancia a view
        ContaView view = new ContaView();

        // Instanciando e operando a ContaCorrente
        ContaCorrente contaCorrente = new ContaCorrente(1000.00);
        ContaController controllerCorrente = new ContaController(contaCorrente, view);

        System.out.println("Operações na Conta Corrente:");
        controllerCorrente.atualizarSaldoView();        // Exibe o saldo inicial
        controllerCorrente.depositar(500.00);           // Deposita e aplica a taxa de R$0,10
        controllerCorrente.atualizarConta(10.0);        // Atualiza com o dobro da taxa (10% * 2)

        System.out.println("\n");

        // Instanciando e operando a ContaPoupanca
        ContaPoupanca contaPoupanca = new ContaPoupanca(1000.00);
        ContaController controllerPoupanca = new ContaController(contaPoupanca, view);

        System.out.println("Operações na Conta Poupança:");
        controllerPoupanca.atualizarSaldoView();        // Exibe o saldo inicial
        controllerPoupanca.depositar(500.00);           // Deposita sem taxa
        controllerPoupanca.atualizarConta(10.0);        // Atualiza com o triplo da taxa (10% * 3)
    }
}
