package fr.antony.stylos.pens;

public class RetractablePen extends Pen{

    private boolean lead;

    public RetractablePen(CartRidge cartRidge) {
        super(cartRidge);
    }

    public void leadIn(){
        this.lead = false;
    }

    public void leadOut(){
        this.lead = true;
    }

    @Override
    public void write(String string) {
        if(lead) super.write(string);
    }

    @Override
    public boolean canWrite(String string) {
        return lead && super.canWrite(string);
    }
}
