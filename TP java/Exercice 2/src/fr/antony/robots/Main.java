package fr.antony.robots;

public class Main {
    public static void main(String[] args) {

        World world = new World();
        world.addRobot(new Location(1, 1), new Robot("Luigi"));
        world.addRobot(new Location(5, 1), new Robot("Mario"));
        world.addRobot(world.pickFreeLocation(), new Robot("test"));
        System.out.println(world.hasRobotAtLocation(new Location(5, 1)));
        System.out.println(world.hasRobotAtLocation(new Location(1, 1)));
        System.out.println(world.hasRobotAtLocation(new Location(5, 5)));
        System.out.println(world.pickRobotLocation());
        world.display();
        world.moveRobot(new Location(1,1), new Location(6, 6));
        world.display();
        world.shootAt(new Location(1,1));
        world.display();
        world.shootAt(new Location(6, 6));
        world.display();

    }
}