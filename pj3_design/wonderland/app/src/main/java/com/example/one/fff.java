package com.example.one;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class fff extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.wonderland);
        Button g1 = findViewById(R.id.guess1);
        Button g2 = findViewById(R.id.guess2);
        Button g3 = findViewById(R.id.guess3);
        Button g4 = findViewById(R.id.guess4);
        Button g5 = findViewById(R.id.guess5);
        Button g6 = findViewById(R.id.guess6);
        Button g7 = findViewById(R.id.guess7);

        g1.setOnClickListener(new View.OnClickListener() {//wnx
            @Override
            public void onClick(View view) {
              startService(new Intent(fff.this, aaa.class));
            }
        });
        g2.setOnClickListener(new View.OnClickListener() {//ysh
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, lll.class));
            }
        });
        g3.setOnClickListener(new View.OnClickListener() {//ldq
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, hhh.class));
            }
        });
        g4.setOnClickListener(new View.OnClickListener() {//ysh
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, ggg.class));
            }
        });
        g5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, jjj.class));
            }
        });
        g6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, kkk.class));
            }
        });
        g7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(fff.this, iii.class));
            }
        });


    }


}
