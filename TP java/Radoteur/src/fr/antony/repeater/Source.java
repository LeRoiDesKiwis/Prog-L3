package fr.antony.repeater;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Source {

    private final List<Event> eventList;
    private Iterator<Event> it;

    public Source(List<Event> events){
        this.eventList = events;
        this.it = events.iterator();
    }

    public Event nextEvent(){
        if(!it.hasNext()) it = eventList.iterator();
        return it.next();
    }

}
