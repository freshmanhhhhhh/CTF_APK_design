package com.example.one;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;

public class hhh extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btn = findViewById(R.id.btn_check);
        EditText et = findViewById(R.id.flag);

        btn.setOnClickListener(view -> {
            String s = et.getText().toString();
            try {
                if(getflag(s))
                    Toast.makeText(hhh.this,"Right!",Toast.LENGTH_LONG).show();
                else
                    Toast.makeText(hhh.this,"Wrong!",Toast.LENGTH_LONG).show();

            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public static boolean getflag(String str)
    {
        if( str.charAt(0)!='f'|| str.charAt(1)!='l'|| str.charAt(2)!='a'||str.charAt(3)!='g'||
                str.charAt(4)!='{'|| str.charAt(str.length()-1)!='}')
            return false;
        String s = str.substring(5,str.length()-1);
        byte[] bytes = {97, 0, 116, 114, 115, 116, 100, 0, 0, 0, 0, 102, 97, 111, 111, 0,
                104, 97, 0, 0, 0, 0, 116, 108, 109, 119, 97, 101, 121, 0, 0, 0, 0,
                101, 108, 111, 0, 110, 114, 0, 0, 0, 0, 0, 114, 0, 114, 105, 111, 0};
        byte[] bytes1 = s.getBytes(StandardCharsets.UTF_8);


        int v1 = 0;
        float f = 0;
        int v2 = 5;
        int v3 = bytes1.length / v2 + 4;
        int v4 = 0;
        int v5;
        byte[] bytes2 = new byte[v2 * v3];

        int[] a = {1, 2, 4, 9, 12, 16};
        int v6 = 0;
        int v7 = 0;
        while(true) {
            switch (v7) {
                case 0:
                    if ((bytes1[v4] ^ 0x1f) == 0)
                        v4 += 2;
                    v7 = a[v6 + 1] - a[v6];
                    v6++;
                    break;
                case 1:
                    if (bytes1[v4] == '_') {
                        v1 += 1; f += 2;
                        v4++;
                    }
                    v7 = a[v6 + 2] - a[v6 + 1];
                    v6 += 3;
                    break;
                case 2:
                    return Arrays.toString(bytes2).equals(Arrays.toString(bytes));
                case 3:
                    if(v4 == bytes1.length){
                        v7 = a[v6] * a[v6 - 1];
                        v6 += 2;
                    }
                    else{
                        v7 = a[v6 + 1] / a[v6] / 2;
                    }
                    break;
                case 4:
                    if (v1 < f || v4 < 5) {
                        v1 += 1; f += 2;
                        v4 += v1 / f + f / (4 * v1);
                    } else {
                        v1 += 2; f += 1;
                        v4 += f / (4 * v1);
                    }
                    v7 = a[v6 + 1] / a[v6 - 1];
                    v6 -= 2;
                    break;
                case 5:
                    v5 = easyfunc(v4, v3, v1, f);
                    bytes2[v5] = bytes1[v4];
                    v7 = a[v6 + 1] / a[v6 - 2];
                    v6--;
                    break;
            }
        }

    }

    public static int easyfunc(int i, int j, int x, float y){
        return (i - i / 5 * 5) * j +  x % 5 + (int)(y / 10);
    }

}