/**
 *
 * @author Valentin
 */
package Model;

public class Numeros {
    private double numero1;
    private double numero2;
    private double numero3;

    public double getNumero1() {
        return numero1;
    }

    public void setNumero1(double numero1) {
        this.numero1 = numero1;
    }

    public double getNumero2() {
        return numero2;
    }

    public void setNumero2(double numero2) {
        this.numero2 = numero2;
    }

    public double getNumero3() {
        return numero3;
    }

    public void setNumero3(double numero3) {
        this.numero3 = numero3;
    }

    public double calcularMaior() {
        return Math.max(Math.max(numero1, numero2), numero3);
    }

    public double calcularMenor() {
        return Math.min(Math.min(numero1, numero2), numero3);
    }
}
