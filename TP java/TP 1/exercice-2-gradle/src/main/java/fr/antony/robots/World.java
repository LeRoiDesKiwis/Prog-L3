package fr.antony.robots;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Collections;

public class World {

    private final Map<Location, Robot> robots;

    private static List<Location> ALL_LOCS = new ArrayList<>();

    private final List<Location> freeLocs = new ArrayList<>();

    static {
        for(int x = -10; x < 10; x++){
            for(int y = -10; y < 10; y++){
                ALL_LOCS.add(new Location(x, y));
            }
        }
    }

    private static Location pickRandomLocation(List<Location> locations){
        Collections.shuffle(locations);
        return locations.get(0);
    }

    public static Location pickLocation(){
        return pickRandomLocation(ALL_LOCS);
    }

    /**
     *
     * @return Une location libre (sans robot)
     */
    public Location pickFreeLocation(){
        return pickRandomLocation(freeLocs);
    }

    /**
     *
     * @return Une location occupée (avec un robot)
     */
    public Location pickRobotLocation(){
        return pickRandomLocation(new ArrayList<>(robots.keySet()));
    }

    public World(){
        this(new HashMap<>());
    }

    public World(Map<Location, Robot> robots){
        this.robots = new HashMap<>(robots);
        freeLocs.addAll(ALL_LOCS);
    }

    /**
     * Fait apparaître un robot dans le monde
     * @param location L'endroit où le robot doit apparaître
     * @param robot Le robot qui doit apparaître
     */
    public void addRobot(Location location, Robot robot){
        if(freeLocs.contains(location)) robots.put(location, robot);
    }

    /**
     * Vérifie si il y a un robot dans location
     * @param location La location à vérifier
     * @return Si il y a un robot ou pas
     */
    public boolean hasRobotAtLocation(Location location){
        return robots.keySet().stream().anyMatch(location1 -> location1.equals(location));
    }

    /**
     * Détruit l'emplacement désigné par location
     * ATTENTION: détruit le robot présents sur la location
     * @param location Location qui va être détruite
     */
    public void shootAt(Location location){
        robots.keySet().stream().filter(location1 -> location1.equals(location)).findFirst().ifPresent(robots::remove);
        freeLocs.remove(location);
    }

    /**
     * Bouge un robot de from à dest. Si un robot se trouvait sur dest alors c'est tchao pour lui
     * @param from La location d'origine
     * @param dest La destination
     */
    public void moveRobot(Location from, Location dest){
        if(freeLocs.contains(dest)){
            robots.entrySet().stream()
                    .filter(entry -> entry.getKey().equals(from))
                    .findFirst()
                    .ifPresent(entry -> {
                        robots.put(dest, entry.getValue());
                        robots.remove(entry.getKey());
                    });
        }
    }

    /**
     * Affiche le monde<p>
     * Exemple :<p>
     * Le robot 'Luigi' est en position x:1 y:2
     * Le robot 'Mario' est en position x:3 y:5
     */
    public void display(){
        System.out.println("=== MONDE ===");
        for(Map.Entry<Location, Robot> entries : robots.entrySet()){
            System.out.println("Le robot "+entries.getValue()+" est en position "+entries.getKey());
        }
        System.out.println();
    }

}
