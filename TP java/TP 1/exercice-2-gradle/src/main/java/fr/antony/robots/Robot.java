package fr.antony.robots;

public class Robot {

    private final String name;

    public Robot(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}
