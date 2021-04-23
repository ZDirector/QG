package com.example.weather;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.ImageView;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

import database.DatabaseManager;

public class DeleteCityActivity extends AppCompatActivity implements View.OnClickListener {

    ImageView cancelIv,confirmIv;
    ListView deleteLv;
    List<String>city;
    List<String>deleterCity;
    private DeleteCityAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.delete_city);

        cancelIv = findViewById(R.id.delete_iv_cancel);
        confirmIv = findViewById(R.id.delete_iv_confirm);
        deleteLv = findViewById(R.id.delete_lv);

        city = DatabaseManager.queryAllCityName();
        deleterCity = new ArrayList<>();

        cancelIv.setOnClickListener(this);
        confirmIv.setOnClickListener(this);


        adapter = new DeleteCityAdapter(this, city, deleterCity);
        deleteLv.setAdapter(adapter);
    }


    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.delete_iv_cancel:
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle("提示信息").setMessage("您确定要舍弃更改吗？").setPositiveButton("舍弃更改", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        finish();
                    }
                });
                builder.setNegativeButton("取消",null);
                builder.create().show();
                break;
            case R.id.delete_iv_confirm:
                for (int i = 0;i<deleterCity.size();i++){
                    String city = deleterCity.get(i);
                    DatabaseManager.deleteInfoCity(city);
                }
                finish();
                break;
        }
    }
}