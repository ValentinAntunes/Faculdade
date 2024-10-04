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

    public void compararNumeros() {
            numeros.setNumero1(view.solicitarNumero("Digite o primeiro número:"));
            numeros.setNumero2(view.solicitarNumero("Digite o segundo número:"));
            numeros.setNumero3(view.solicitarNumero("Digite o terceiro número:"));

            double maior = numeros.calcularMaior();
            double menor = numeros.calcularMenor();

            view.mostrarMensagem(String.format("O maior número é: %.2f\nO menor número é: %.2f", maior, menor));
    }

    public static void main(String[] args) {
        Numeros numeros = new Numeros();
        Usuario view = new Usuario();
        NumerosController controller = new NumerosController(numeros, view);

        controller.compararNumeros();
    }
}
