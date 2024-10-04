package Controller;

import Model.Conta;
import View.ContaView;

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
        // Criando o modelo (Conta) com saldo inicial
        Conta minhaConta = new Conta(1000.00);

        // Criando a visão
        ContaView view = new ContaView();

        // Criando o controlador
        ContaController controller = new ContaController(minhaConta, view);

        // Exibir saldo inicial
        controller.atualizarSaldoView();

        // Realizar algumas operações
        controller.depositar(500.00);
        controller.sacar(200.00);
        controller.atualizarConta(10.0); // Atualiza com uma taxa de 10%
    }
}