package fr.antony.stylos.pens;

public class HighLighter extends Pen{

    public HighLighter(CartRidge cartRidge) {
        super(cartRidge);
    }

    public void highlight(String string){
        write(string.toUpperCase());
    }
}
