package fr.antony.stylos.pens;

import java.util.List;

public class MultiColorPen extends Pen{

    private final List<CartRidge> cartRidges;

    public MultiColorPen(CartRidge cartRidge, List<CartRidge> cartRidges) {
        super(cartRidge);
        this.cartRidges = cartRidges;
    }

    public void chooseColor(int index){
        super.cartRidge = cartRidges.get(index);
    }

    public int cartSize(){
        return cartRidges.size();
    }
}
