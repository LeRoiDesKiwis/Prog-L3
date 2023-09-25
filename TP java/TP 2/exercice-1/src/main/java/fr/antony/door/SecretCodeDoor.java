package fr.antony.door;

public class SecretCodeDoor extends AutoLockDoor{

    private final int code;

    public SecretCodeDoor(int code){
        this.code = code;
    }

    @Override
    public void unlock() {

    }

    public void unlock(int code){
        if(this.code == code) super.unlock();
    }

}
