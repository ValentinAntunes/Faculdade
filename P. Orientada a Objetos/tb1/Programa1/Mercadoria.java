package Model;

/**
 * @author Valentin
 */
public class Mercadoria {
    private double custo;
    private double frete;
    private double despesa;
    private double venda;

    /**
     * @return the custo
     */
    public double getCusto() {
        return custo;
    }

    /**
     * @param custo the custo to set
     */
    public void setCusto(double custo) {
        this.custo = custo;
    }

    /**
     * @return the frete
     */
    public double getFrete() {
        return frete;
    }

    /**
     * @param frete the frete to set
     */
    public void setFrete(double frete) {
        this.frete = frete;
    }

    /**
     * @return the despesa
     */
    public double getDespesa() {
        return despesa;
    }

    /**
     * @param despesa the despesa to set
     */
    public void setDespesa(double despesa) {
        this.despesa = despesa;
    }

    /**
     * @return the venda
     */
    public double getVenda() {
        return venda;
    }

    /**
     * @param venda the venda to set
     */
    public void setVenda(double venda) {
        this.venda = venda;
    }
    
    public double calcularPercentualLucro() {
        double custoTotal = custo + frete + despesa;
        double lucro = venda - custoTotal;
        return (lucro / custoTotal) * 100;
    }
}
