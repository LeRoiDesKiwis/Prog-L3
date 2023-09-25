package fr.antony.door;

import java.util.List;

public class Door {

    private boolean opened;

    public static void printDoorList(List<? extends Door> doorList){
        doorList.forEach(System.out::println);
    }

    public void open(){
        this.opened = true;
    }

    public void close(){
        this.opened = false;
    }

    @Override
    public String toString() {
        return String.format("%s is %s", getClass().getSimpleName(), (opened ? "opened" : "closed"));
    }

    public boolean isOpened() {
        return opened;
    }
}
