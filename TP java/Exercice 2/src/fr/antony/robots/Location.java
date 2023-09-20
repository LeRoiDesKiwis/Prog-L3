package fr.antony.robots;

public class Location {

    private final int x;
    private final int y;

    public Location(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "x: "+x+" y: "+y;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Location){
            Location location = (Location)obj;
            return location.x == x && location.y == y;
        }
        return false;
    }
}
