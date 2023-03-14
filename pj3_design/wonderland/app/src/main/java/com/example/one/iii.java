package com.example.one;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class iii extends AppCompatActivity {

    Button mBtnButton;
    EditText mEditText;
    public native boolean Checkstr(String str);

    static{
        System.loadLibrary("one");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mBtnButton = (Button)findViewById(R.id.btn_check);
        mEditText = (EditText)findViewById(R.id.flag);

        mBtnButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Context context;
                String str="";
                String input = mEditText.getText().toString();
                if(Checkstr(input)){
                    context = iii.this.getApplicationContext();
                    str = "RIGHT!";
                }
                else{
                    context = iii.this.getApplicationContext();
                    str = "WRONG!";
                }
                Toast.makeText(context, str, Toast.LENGTH_LONG).show();
            }
        });
    }
}
