package fr.antony.stylos.pens;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.awt.*;

import static org.junit.jupiter.api.Assertions.*;

class CartRidgeTest {

    private CartRidge cartRidge;

    @BeforeEach
    void setUp() {
        this.cartRidge = new CartRidge(Color.RED, 10);
    }

    @Test
    void hasEnoughInk() {
        assertFalse(cartRidge.hasEnoughInk(11), "hasEnoughInk(11) : false");
        assertTrue(cartRidge.hasEnoughInk(9), "hasEnoughInk(9) : true");
    }

    @Test
    void consume() {
        cartRidge.consume(2);
        assertEquals(cartRidge.getLevel(), 8, "consume 2");
    }

    @Test
    void consomeFarMore() {
        cartRidge.consume(11);
        assertEquals(cartRidge.getLevel(), 0, "consume more that it has");
    }
    @Test
    void consomeNegative() {
        cartRidge.consume(-3);
        assertEquals(cartRidge.getLevel(), 7, "negative consume");
    }

    @Test
    void empty() {
        cartRidge.empty();
        assertEquals(cartRidge.getLevel(), 0, "empty");
    }

    @Test
    void colorize() {
        assertEquals(cartRidge.colorize("test"), ("("+Color.RED.toString()+" color used) test"), "colorize");
    }
}