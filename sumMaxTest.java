package com.company;


import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class sumMaxTest {

    @Test
    public void sunArrayMax0() {
        int[] array1={};
        assertEquals(0,new sumMax().sunArrayMax(array1));
    }
    @Test
    public void sunArrayMax1(){
        int[] array2={2,11,-4,13,-5,-2};
        assertEquals(22,new sumMax().sunArrayMax(array2));
    }
    @Test
    public void sunArrayMax2(){
        int[] array2={-2,-1,-4,-3,-5,-2};
        assertEquals(0,new sumMax().sunArrayMax(array2));
    }

}