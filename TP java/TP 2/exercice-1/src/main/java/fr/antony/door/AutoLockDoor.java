package fr.antony.door;

public class AutoLockDoor extends Door{

    private boolean locked = true;

    @Override
    public void open() {
        if(!this.locked) super.open();
    }

    public void close(){
        this.locked = true;
        super.close();
    }

    public void unlock(){
        this.locked = false;
    }

}
