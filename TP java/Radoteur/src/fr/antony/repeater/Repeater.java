package fr.antony.repeater;

public class Repeater {

    private final Source source;
    private Event current;

    public Repeater(Source source){
        this.source = source;
    }

    public void repeat(int end){
        int i = 0;
        while(i < end){
            Event next = source.nextEvent();
            if (current == null || current.equals(next)) {
                Event nextEvent = (current == null) ? next : source.nextEvent();
                nextEvent.print();
                current = nextEvent;
                i++;
            }
        }
    }

    public void repeat(){

    }

}
