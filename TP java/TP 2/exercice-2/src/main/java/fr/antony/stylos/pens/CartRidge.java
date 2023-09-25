package fr.antony.stylos.pens;

import java.awt.*;

public class CartRidge {

    private Color color;
    private int level;

    public CartRidge(Color color, int level) {
        this.color = color;
        this.level = level;
    }

    public boolean hasEnoughInk(int needed){
        return level >= needed;
    }

    public void consume(int ink){
        this.level = Math.max(0, level-Math.abs(ink));
    }

    public void empty(){
        this.level = 0;
    }

    public String colorize(String string) {
        return String.format("(%s color used) %s", color.toString(), string);
    }

    @Override
    public String toString() {
        return "CartRidge{" +
                "color=" + color +
                ", level=" + level +
                '}';
    }
}
