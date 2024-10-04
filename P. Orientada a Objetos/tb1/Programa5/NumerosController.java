/**
 *
 * @author Valentin
 */
package Controller;

import Model.Numeros;
import View.Usuario;

public class NumerosController {
    private Numeros numeros;
    private Usuario view;

    public NumerosController(Numeros numeros, Usuario view) {
        this.numeros = numeros;
        this.view = view;
    }

    public void ordenarEExibirNumeros() {
            numeros.setNumero1(view.solicitarNumero("Digite o primeiro número:"));
            numeros.setNumero2(view.solicitarNumero("Digite o segundo número:"));
            numeros.setNumero3(view.solicitarNumero("Digite o terceiro número:"));

            double[] numerosOrdenados = numeros.ordenarNumeros();

            view.mostrarMensagem(String.format("Os números em ordem crescente são: %.2f, %.2f, %.2f\nOs números em ordem decrescente são: %.2f, %.2f, %.2f",
                numerosOrdenados[0], numerosOrdenados[1], numerosOrdenados[2], numerosOrdenados[2], numerosOrdenados[1], numerosOrdenados[0]));                
    }

    public static void main(String[] args) {
        Numeros numeros = new Numeros();
        Usuario view = new Usuario();
        NumerosController controller = new NumerosController(numeros, view);

        controller.ordenarEExibirNumeros();
    }
}
