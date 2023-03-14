package com.example.one;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.widget.Toast;

import androidx.annotation.Nullable;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;


public class aaa extends Service {

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    public void onCreate() {
        super.onCreate();
    }


    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Date m=new Date(System.currentTimeMillis());
        SimpleDateFormat   formatter = new SimpleDateFormat(getResources().getString(R.string.form));
        String  str =  formatter.format(m);
        Random r=new Random();
        String hah=new String(r.nextInt(2022)+str.substring(4,str.length()));


         if(!str.equals(hah)){
           Toast.makeText(this,getResources().getString(R.string.hh),Toast.LENGTH_LONG).show();

          }
        else {
            android.os.Process.killProcess(android.os.Process.myPid());
            startActivity(new Intent(aaa.this, eee.class));
        }

        return super.onStartCommand(intent, flags, startId);
    }


    @Override
    public void onDestroy() {
        super.onDestroy();
    }

}
