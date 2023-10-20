package fr.antony.repeater;

public class Main {
    public static void main(String[] args) {

        Repeater repeater = new Repeater(Char.generateSource("Tu fais répéteur et voilà"));
        repeater.repeat(1000);
    }
}