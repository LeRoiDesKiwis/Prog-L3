package fr.antony.stylos.pens;

public class DisposablePen extends Pen{
    public DisposablePen(CartRidge cartRidge) {
        super(cartRidge);
    }

    @Override
    public void changeCartRidge(CartRidge cartRidge) {
        cartRidge.empty();
    }
}
