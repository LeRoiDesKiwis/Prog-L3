package fr.leroideskiwis.race.vehicles;

public class Car extends Vehicle{
    public Car() {
        super(8);
    }

    @Override
    public void accelerate() {
        super.speed+=2;
    }
}
