/**
 *
 * @author Valentin
 */
package Controller;

import Model.Notas;
import View.Usuario;

public class NotasController {
    private Notas notas;
    private Usuario view;

    public NotasController(Notas notas, Usuario view) {
        this.notas = notas;
        this.view = view;
    }

    public void calcularEMostrarMedia() {
            notas.setNota1(view.solicitarNota("Digite a primeira nota:"));
            notas.setNota2(view.solicitarNota("Digite a segunda nota:"));
            notas.setNota3(view.solicitarNota("Digite a terceira nota:"));
            notas.setNota4(view.solicitarNota("Digite a quarta nota:"));

            double media = notas.calcularMedia();

            view.mostrarMensagem(String.format("A média das notas é: %.2f", media));
    }

    public static void main(String[] args) {
        Notas notas = new Notas();
        Usuario view = new Usuario();
        NotasController controller = new NotasController(notas, view);

        controller.calcularEMostrarMedia();
    }
}
