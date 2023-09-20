package fr.antony.bike;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        List<Wheel> wList = new ArrayList<>();
        for(int i = 0; i < 20; i++) wList.add(new Wheel(i));

        wList.add(2, new Wheel(42));
        //oui on peut ajouter deux fois la même roue :
        Wheel wheel = new Wheel("trgd'rfexdhjtr", 2);
        wList.add(wheel);
        wList.add(wheel);
        wList.forEach(Wheel::print);
        //elle y est deux fois (voir console)

        System.out.println(wList.size());
        System.out.println(wList);

        Set<Wheel> wset = new HashSet<>();

        Wheel wheel1 = new Wheel("uwu", 2);
        wset.add(wheel1);
        wset.add(wheel1);
        wset.forEach(Wheel::print);
        //On voit qu'il n'y a qu'un pneu "uwu" donc non on ne peut pas mettre 2 fois la même roue

        /*Bike b1 = new Bike("yo", Color.yellow, 26);
        b1.accelerate();
        Bike b2 = new Bike(b1);
        b2.brake();
        b2.repaint();
        b2.permuteWheel();
        b2.print();
        for(int i = 20; i < 30; i++) {
            System.out.println("==== WITH " + i + " ====");
            b2.replaceWheel(0, "tsrtgf", i);
            b2.print();
            System.out.println();
        }

        b1.print();

        b1=b2;
        b1.accelerate();
        b1.print();
        b2.print();
        L'objet référencé par b1 a été balayé par le garbage collector tout simplement
        */



    }
}