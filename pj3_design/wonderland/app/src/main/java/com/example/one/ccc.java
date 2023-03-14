package com.example.one;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class ccc extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.hhh);

        TextView title = findViewById(R.id.ui_1);
        title.setText(getResources().getString(R.string.mask));
        Button start = findViewById(R.id.ui_2);
        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                TextView state=findViewById(R.id.ui_3);
                state.setTextColor(0xff000000);

                Thread.currentThread();
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                startActivity(new Intent(ccc.this, fff.class));
            }
        });

        start.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                TextView state=findViewById(R.id.ui_3);
                state.setTextColor(0xff000000);
                return true;
            }
        });

        start.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                TextView state=findViewById(R.id.ui_3);
                state.setTextColor(0xff000000);
                return true;
            }
        });


    }


}