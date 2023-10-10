package fr.leroideskiwis.race.vehicles;

public class Tank extends Vehicle{

    private boolean missile;

    public Tank(int speedMax) {
        super(2);
    }

    @Override
    public void specialAction() {
        if(missile){
            missile = false;
        }
    }
}
