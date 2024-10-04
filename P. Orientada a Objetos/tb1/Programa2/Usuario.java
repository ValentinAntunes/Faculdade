/**
 *
 * @author Valentin
 */
package View;

import javax.swing.JOptionPane;

public class Usuario {

    public double solicitarMensagem(String mensagem) {
        String input = JOptionPane.showInputDialog(mensagem);
        return Double.parseDouble(input);
    }

    public void mostrarMensagem(String mensagem) {
        JOptionPane.showMessageDialog(null, mensagem);
    }
}
