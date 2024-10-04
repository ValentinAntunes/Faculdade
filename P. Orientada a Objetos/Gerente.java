/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

/**
 *
 * @author osmam.souto
 */
public class Gerente extends Funcionarios{
    //Atributos
    private int senha;
    private int quantidadeDeFuncionairosGerenciados;
    //Métodos
    public double getBonificacaoGerente(){
        return this.salario*0.15;
    }
    /**
     * @return the senha
     */
    public int getSenha() {
        return senha;
    }

    /**
     * @param senha the senha to set
     */
    public void setSenha(int senha) {
        this.senha = senha;
    }

    /**
     * @return the quantidadeDeFuncionairosGerenciados
     */
    public int getQuantidadeDeFuncionairosGerenciados() {
        return quantidadeDeFuncionairosGerenciados;
    }

    /**
     * @param quantidadeDeFuncionairosGerenciados the quantidadeDeFuncionairosGerenciados to set
     */
    public void setQuantidadeDeFuncionairosGerenciados(int quantidadeDeFuncionairosGerenciados) {
        this.quantidadeDeFuncionairosGerenciados = quantidadeDeFuncionairosGerenciados;
    }
    
    
}
