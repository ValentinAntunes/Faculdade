/**
 *
 * @author Valentin
 */
package Model;

public class Parede {
    private double largura;
    private double altura;

    public Parede() {}

    public double getLargura() {
        return largura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public int calcularLatasNecessarias() {
        double area = largura * altura;
        double consumoTinta = area * 0.3;
        double capacidadeLata = 2.0;
        int latas = (int) Math.ceil(consumoTinta / capacidadeLata);
        return latas;
    }
}
