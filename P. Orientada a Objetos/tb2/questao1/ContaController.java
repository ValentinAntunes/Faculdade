package Controller;

import Model.Conta;
import View.ContaView;

public class ContaController {
    private Conta model;
    private ContaView view;

    public ContaController(Conta model, ContaView view) {
        this.model = model;
        this.view = view;
    }

    public void atualizarSaldoView() {
        view.exibirSaldo(model.getSaldo());
    }

    public void depositar(double valor) {
        model.deposita(valor);
        atualizarSaldoView();
    }

    public void sacar(double valor) {
        model.saca(valor);
        atualizarSaldoView();
    }

    public void atualizarConta(double taxa) {
        model.atualiza(taxa);
        atualizarSaldoView();
    }

    public static void main(String[] args) {
        Conta minhaConta = new Conta(1000.00);

        ContaView view = new ContaView();

        ContaController controller = new ContaController(minhaConta, view);

        controller.atualizarSaldoView();

        controller.depositar(500.00);
        controller.sacar(200.00);
        controller.atualizarConta(10.0);
    }
}
