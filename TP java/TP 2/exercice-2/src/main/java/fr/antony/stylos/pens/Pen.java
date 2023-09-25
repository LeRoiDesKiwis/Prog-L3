package fr.antony.stylos.pens;

public class Pen {

    protected CartRidge cartRidge;

    public Pen(CartRidge cartRidge) {
        this.cartRidge = cartRidge;
    }

    public void write(String string){
        if(canWrite(string)){
            System.out.println(cartRidge.colorize(string));
            cartRidge.consume(string.length());
        }
    }

    public boolean canWrite(String string){
        return cartRidge.hasEnoughInk(string.length());
    }

    public void changeCartRidge(CartRidge cartRidge){
        this.cartRidge = cartRidge;
    }
}
