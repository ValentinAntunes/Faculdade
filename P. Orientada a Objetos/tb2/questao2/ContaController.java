package Controller;

import Model.Conta;
import Model.ContaCorrente;
import Model.ContaPoupanca;
import View.ContaView;

// ContaController.java
public class ContaController {
    private Conta model;
    private ContaView view;

    // Construtor que inicializa o modelo e a visão
    public ContaController(Conta model, ContaView view) {
        this.model = model;
        this.view = view;
    }

    // Atualiza o saldo na visão
    public void atualizarSaldoView() {
        view.exibirSaldo(model.getSaldo());
    }

    // Realiza um depósito
    public void depositar(double valor) {
        model.deposita(valor);
        atualizarSaldoView();
    }

    // Realiza um saque
    public void sacar(double valor) {
        model.saca(valor);
        atualizarSaldoView();
    }

    // Atualiza o saldo com uma taxa
    public void atualizarConta(double taxa) {
        model.atualiza(taxa);
        atualizarSaldoView();
    }

    // Método main incluído dentro do controller
    public static void main(String[] args) {
        // Criando uma ContaCorrente com saldo inicial de R$1000,00
        ContaCorrente contaCorrente = new ContaCorrente(1000.00);
        ContaView view = new ContaView();
        ContaController controllerCorrente = new ContaController(contaCorrente, view);

        // Realizando operações na ContaCorrente
        System.out.println("Operações na Conta Corrente:");
        controllerCorrente.atualizarSaldoView();
        controllerCorrente.depositar(500.00);  // Deposita e aplica a taxa de R$0,10
        controllerCorrente.atualizarConta(10.0);  // Atualiza com o dobro da taxa (10% * 2)

        // Criando uma ContaPoupanca com saldo inicial de R$1000,00
        ContaPoupanca contaPoupanca = new ContaPoupanca(1000.00);
        ContaController controllerPoupanca = new ContaController(contaPoupanca, view);

        // Realizando operações na ContaPoupanca
        System.out.println("\nOperações na Conta Poupança:");
        controllerPoupanca.atualizarSaldoView();
        controllerPoupanca.depositar(500.00);  // Deposita sem taxa
        controllerPoupanca.atualizarConta(10.0);  // Atualiza com o triplo da taxa (10% * 3)
    }
}
