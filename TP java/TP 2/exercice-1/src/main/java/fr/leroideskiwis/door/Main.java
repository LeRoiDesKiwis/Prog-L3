package fr.leroideskiwis.door;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Door> doors = new ArrayList<>();
        doors.add(new Door());
        doors.add(new AutoLockDoor());
        doors.add(new SecretCodeDoor(4268));
        doors.add(new ClosedDoor());

        doors.forEach(Door::open);
        Door.printDoorList(doors);

        System.out.println("Opened doors : "+doors.stream().filter(Door::isOpened).count());

        System.out.println("\n==== Portes à code secret ====");

        System.out.println("\n==== Portes ouvertes ====");
        doors.stream().filter(door -> door instanceof AutoLockDoor).forEach(System.out::println);
        doors.stream().filter(Door::isOpened).forEach(System.out::println);

    }
}
