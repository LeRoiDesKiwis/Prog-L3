package fr.antony.repeater;

import java.util.ArrayList;
import java.util.List;

public class Char implements Event {

    private final char c;

    public Char(char c) {
        this.c = c;
    }

    public static Source generateSource(String string){
        List<Event> chars = new ArrayList<>();
        for(char c : string.toCharArray()){
            chars.add(new Char(c));
        }
        return new Source(chars);
    }

    @Override
    public boolean equals(Event event) {
        if(event instanceof Char eventChar){
            return eventChar.c == c;
        }
        return false;
    }

    @Override
    public void print() {
        System.out.print(c);
    }
}
