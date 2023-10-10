package fr.leroideskiwis.race.vehicles;

public class Vehicle {

    private int pos;
    int speed;
    private final int speedMax;
    private boolean ready;

    public Vehicle(int speedMax) {
        this.pos = 0;
        this.speed = 0;
        this.speedMax = speedMax;
        this.ready = true;
    }

    public void accelerate(){
        this.speed++;
    }

    public void decelerate(){
        this.speed--;
    }

    public void stop(){
        this.speed = 0;
    }

    public void outOfOrder(){
        this.stop();
        this.ready = false;
    }

    public void displayType(){
        System.out.println("type : "+getClass().getSimpleName());
    }

    public void displayTrip(){
        System.out.println();
    }

    public void forward(){
        this.pos+=speed;
    }

    public int getPos(){
        return pos;
    }

    public void specialAction(){}
}
