/**
 *
 * @author Valentin
 */
package Controller;

import Model.Parede;
import View.Usuario;

public class TintaController {
    private Parede parede;
    private Usuario view;

    public TintaController(Parede parede, Usuario view) {
        this.parede = parede;
        this.view = view;
    }

    public void calcularLatas() {
            parede.setLargura(view.solicitarMensagem("Digite a largura da parede em metros:"));
            parede.setAltura(view.solicitarMensagem("Digite a altura da parede em metros:"));

            int latasNecessarias = parede.calcularLatasNecessarias();

            view.mostrarMensagem("Você precisará de " + latasNecessarias + " latas de tinta.");
        
    }

    public static void main(String[] args) {
        Parede parede = new Parede();
        Usuario view = new Usuario();
        TintaController controller = new TintaController(parede, view);

        controller.calcularLatas();
    }
}
