package com.example.weather;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

import database.DatabaseManager;

public class CityManagerActivity extends AppCompatActivity implements View.OnClickListener {

    private ImageView addIv,backIv,deleteIv;
    private ListView cityLv;
    private List<Weather>Data;
    private CityManagerAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.city_manager);
        addIv = findViewById(R.id.city_iv_add);
        backIv = findViewById(R.id.city_iv_back);
        deleteIv = findViewById(R.id.city_iv_delete);
        cityLv = findViewById(R.id.city_lv);
        Data = new ArrayList<>();
        addIv.setOnClickListener(this);
        backIv.setOnClickListener(this);
        deleteIv.setOnClickListener(this);

        adapter = new CityManagerAdapter(this,Data);
        cityLv.setAdapter(adapter);
    }

    @Override
    protected void onResume() {
        super.onResume();
        List<Weather> data = DatabaseManager.queryInfo();
        Data.clear();
        Data.addAll(data);
        adapter.notifyDataSetChanged();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.city_iv_add:
                Intent intent1 = new Intent(this,SearchCityActivity.class);
                startActivity(intent1);
                break;
            case R.id.city_iv_back:
                finish();
                break;
            case R.id.city_iv_delete:
                Intent intent2 = new Intent(this,DeleteCityActivity.class);
                startActivity(intent2);
                break;

        }
    }
}