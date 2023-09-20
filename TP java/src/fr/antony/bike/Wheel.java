package fr.antony.bike;

public class Wheel {

    private final String brand;
    private final int size;
    private float pressure = 3.0f;

    public static final String DEFAULT_BRAND = "Schalbe";

    public Wheel(String brand, int size) {
        this.brand = brand;
        this.size = size;
    }

    public Wheel(int size){
        this(DEFAULT_BRAND, size);
    }

    public void inflate(){
        this.pressure-=0.1f;
    }

    public void deflate(){
        this.pressure+=0.1f;
    }

    public void print(){
        System.out.println(this);
    }

    @Override
    public String toString() {
        return String.format("[%s - %d\" - %d bar]", brand, size, (int)pressure);
    }
}
