package fr.antony.robots;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class WorldTest {

    private World world;

    @BeforeEach
    void setUp() {
        Map<Location, Robot> robots = new HashMap<>();
        robots.put(new Location(0, 0), new Robot("test"));

        this.world = new World(robots);
    }

    @Test
    void hasRobotAtLocation() {
        assertTrue(world.hasRobotAtLocation(new Location(0, 0)), "0 0 doesn't contain robot");
        assertFalse(world.hasRobotAtLocation(new Location(5, 0)), "5 0 doesn't contain robot");
        assertFalse(world.hasRobotAtLocation(new Location(0, -1)), "0 -1 doesn't contain robot");
        assertFalse(world.hasRobotAtLocation(new Location(0, -12)), "0 -12 doesn't contain robot");
    }

    @Test
    void addRobot() {
        world.addRobot(new Location(1, 1), new Robot("Luigi"));
        world.addRobot(new Location(5, 1), new Robot("Mario"));
        world.addRobot(new Location(11, 1), new Robot("Mario"));
        world.addRobot(new Location(-5, 1), new Robot("Mario"));
        assertTrue(world.hasRobotAtLocation(new Location(1, 1)), "Robot location 1 1");
        assertTrue(world.hasRobotAtLocation(new Location(5, 1)), "Robot location 5 1");
        assertTrue(world.hasRobotAtLocation(new Location(-5, 1)), "Robot location -5 1");
        assertFalse(world.hasRobotAtLocation(new Location(11, 1)), "No Robot location 11 1");

    }

    @Test
    void shootAt() {
        world.shootAt(new Location(1,1));
        world.shootAt(new Location(0, 0));
        world.addRobot(new Location(1, 1), new Robot("Luigi"));
        assertFalse(world.hasRobotAtLocation(new Location(1, 1)), "1 1 doesn't contain robot");
        assertFalse(world.hasRobotAtLocation(new Location(0, 0)), "0 0 doesn't contain robot");

    }

    @Test
    void moveRobot() {
        world.moveRobot(new Location(0, 0), new Location(5, 5));
        assertFalse(world.hasRobotAtLocation(new Location(0, 0)), "No robot at 0 0");
        assertTrue(world.hasRobotAtLocation(new Location(5, 5)), "Robot at 5 5");
    }
}