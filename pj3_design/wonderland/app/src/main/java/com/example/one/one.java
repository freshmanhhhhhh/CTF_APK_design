package com.example.one;

public class one {
    static {
        System.loadLibrary("one");
    }
    static  public native String secret();
}
