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
}
