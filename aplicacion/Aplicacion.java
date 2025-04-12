package aplicacion;
import libcalculadora.CalculadoraAnalisis;

public class Aplicacion{
    CalculadoraAnalisis ca = null;
    static {
        System.loadLibrary("calcanalisis");
    }

    public Aplicacion(){
        double[][] puntos = new double[][]{{0,5}, {5,33}, {8,42}, {9,97}};
        double x = 6;
        this.ca = new  CalculadoraAnalisis();
        System.out.println(ca.interpolacion(puntos, x));
    }

    public static void main(String[] args){
        new Aplicacion();
    }
}
