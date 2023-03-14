//ysh
package com.example.one;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class ggg extends AppCompatActivity {

    Button mBtnButton;
    EditText mEditText;
    public native int Check(String str);

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
                if(Check(input)==1){
                    context = ggg.this.getApplicationContext();
                    str = "RIGHT!";
                } else if(Check(input)==-1){
                    context = ggg.this.getApplicationContext();
                    str = "WRONG FORMAT!";
                }else if(Check(input)==2){
                    context = ggg.this.getApplicationContext();
                    str = "YOU ARE FOOLED!";
                }else{
                    context = ggg.this.getApplicationContext();
                    str = "WRONG!";
                }
                Toast.makeText(context, str, Toast.LENGTH_LONG).show();
            }

        });
    }
}
