package fr.leroideskiwis.race;

import fr.leroideskiwis.race.vehicles.Vehicle;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Circuit {

    private int length;
    private static Random random = new Random();
    private final List<Vehicle> participants = new ArrayList<>();

    public Circuit(int length){
        this.length = length;
    }

    public void addVehicle(Vehicle vehicle){
        participants.add(vehicle);
    }

    public void initRace(){

    }

    public void startRace(){

    }

    public void display(){

    }

    public boolean isFinished(){
        return false;
    }

    public Vehicle chooseVehicle(){
        return participants.get(random.nextInt(participants.size()));
    }

}
