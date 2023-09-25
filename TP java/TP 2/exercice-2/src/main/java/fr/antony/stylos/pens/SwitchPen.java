package fr.antony.stylos.pens;

public class SwitchPen extends Pen{

    public SwitchPen(CartRidge cartRidge) {
        super(cartRidge);
    }

    public void write(String string, char c1, char c2){
        super.write(string.replace(c1, c2));
    }

    @Override
    public void write(String string) {
        write(string, 'a', '*');
    }
}
