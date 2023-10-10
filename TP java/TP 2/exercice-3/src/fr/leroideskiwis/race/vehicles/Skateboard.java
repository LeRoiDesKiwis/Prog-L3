package fr.leroideskiwis.race.vehicles;

public class Skateboard extends Vehicle{
    public Skateboard() {
        super(4);
    }

    @Override
    public void specialAction() {
        super.accelerate();
    }
}
