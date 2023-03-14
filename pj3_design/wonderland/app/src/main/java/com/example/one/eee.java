package com.example.one;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class eee extends AppCompatActivity {

    private EditText et;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btn = findViewById(R.id.btn_check);
        et = findViewById(R.id.flag);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
             String in=et.getText().toString();
                try {
                    String x=bbb.door(getResources().getString(R.string.type), getResources().getString(R.string.alg),
                            in, bbb.hhh(getResources().getString(R.string.lal)) );
                    if(x.equals(getResources().getString(R.string.nan)))
                        Toast.makeText(eee.this,"Right!", Toast.LENGTH_LONG).show();
                    else
                        Toast.makeText(eee.this,"Wrong!", Toast.LENGTH_LONG).show();

                } catch (Exception e) {
                    e.printStackTrace();
                }


            }
        });



    }
}