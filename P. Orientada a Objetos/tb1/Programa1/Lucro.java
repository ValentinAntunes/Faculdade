package Controller;

import Model.Mercadoria;
import View.Usuario;

/**
 *
 * @author Valentin
 */
public class Lucro {
    private Mercadoria produto;
    private Usuario view;

    public Lucro(Mercadoria produto, Usuario view) {
        this.produto = produto;
        this.view = view;
    }

    public void calcularLucro() {
        produto.setCusto(view.solicitarMensagem("Digite o custo da mercadoria:"));
        produto.setFrete(view.solicitarMensagem("Digite o valor do frete:"));
        produto.setDespesa(view.solicitarMensagem("Digite o valor das despesas:"));
        produto.setVenda(view.solicitarMensagem("Digite o valor de venda:"));

        double percentualLucro = produto.calcularPercentualLucro();

        view.mostrarMensagem(String.format("A porcentagem de lucro é: %.2f%%", percentualLucro));
    }
    
    public static void main(String[] args) {
        Mercadoria produto = new Mercadoria();
        Usuario view = new Usuario();
        Lucro controller = new Lucro(produto, view);

        controller.calcularLucro();
    }
}
