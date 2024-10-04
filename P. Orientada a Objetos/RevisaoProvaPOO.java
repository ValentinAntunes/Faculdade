/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package Visao;

import Modelo.Gerente;
import Modelo.Professor;

/**
 *
 * @author osmam.souto
 */
public class RevisaoProvaPOO {

    public static void main(String[] args) {
        Gerente gerente = new Gerente();
        gerente.setNome("Paulo");
        gerente.setSenha(12345);
        gerente.setSalario(30000);
        System.out.println(gerente.getNome());
        System.out.println(gerente.getBonificacaoGerente());
        
        Professor professor = new Professor();
        professor.setMatricula(84333);
        professor.setNome("Osmam");
        professor.setSalario(18000);
        System.out.println(professor.getNome());
        System.out.println(professor.getBonificacaoProfessor());
    }
}
