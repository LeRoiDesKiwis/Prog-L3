package fr.antony.bike;

import java.awt.*;

public class Bike {

    private final String brand;
    private Color color ;
    private final int size;
    private int speed;
    private final Wheel[] wheels = new Wheel[2];

    private static final String DEFAULT_BRAND = "Scrapper";
    private static final Color DEFAULT_COLOR = Color.BLUE;
    private static final int DEFAULT_SIZE = 26;

    private static final int MAX_SPEED = 60;

    public Bike(String brand, Color color, int size){
        this.brand = brand;
        this.color = color;
        this.size = size;
        this.wheels[0] = new Wheel(size+1);
        this.wheels[1] = new Wheel(size-1);
    }

    public Bike(){
        this(DEFAULT_BRAND, DEFAULT_COLOR, DEFAULT_SIZE);
    }

    public Bike(Bike bike){
        this(bike.brand, bike.color, bike.size);
        this.speed = bike.speed;
    }

    public void print(){
        System.out.printf("[%s - %d\" - %s - (%dkm/h)]\n", brand, size, color, speed);
        System.out.print("- Front Wheel:");
        wheels[0].print();
        System.out.print("- Rear Wheel:");
        wheels[1].print();
    }

    public void accelerate(){
        if(this.speed < MAX_SPEED) this.speed+=1;
    }

    public void brake(){
        if(this.speed > 0) this.speed-=1;
    }

    public void repaint(){
        this.color = DEFAULT_COLOR;
    }

    public void removeWheel(int index){
        this.wheels[index] = null;
    }

    public void replaceWheel(int index, String brand, int size){
        if(Math.abs(this.size-size) <= 2) this.wheels[index] = new Wheel(brand, size);
    }

    public void permuteWheel(){
        Wheel wheel = this.wheels[0];
        this.wheels[0] = this.wheels[1];
        this.wheels[1] = wheel;
    }

    public int countWheels(){
        return wheels.length;
    }

}
