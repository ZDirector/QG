package com.example.weather;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;

import database.DatabaseManager;

public class SearchCityActivity extends AppCompatActivity implements View.OnClickListener {

    String url ="https://www.tianqiapi.com/free/day?appid=63143258&appsecret=x1ydGKjZ&city=";
    EditText searchEt;
    ImageView submitIv;
    GridView searchGv;
    String city;
    private ArrayAdapter<String> adapter;
    String[]hotCitys = {"北京","上海","广州","深圳","珠海","佛山","南京","苏州","厦门","长沙","成都","福州",
            "杭州","武汉","青岛","西安","太原","沈阳","重庆","天津","南宁"};


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.search_city);
        searchEt = findViewById(R.id.search_et);
        submitIv = findViewById(R.id.search_iv_submit);
        searchGv = findViewById(R.id.search_gv);

        submitIv.setOnClickListener(this);
        adapter = new ArrayAdapter<String>(this,R.layout.item_hotcity,hotCitys);
        searchGv.setAdapter(adapter);
        setListener();
    }

    private void setListener(){
        searchGv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                city = hotCitys[position];
                isexistence(true);
            }
        });
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.search_iv_submit:
                city = searchEt.getText().toString();
                if (!TextUtils.isEmpty(city)){
                    new Thread(new Runnable() {
                        @Override
                        public void run() {
                            BufferedInputStream in = null;
                            try {
                                HttpURLConnection conn = (HttpURLConnection) new URL(url).openConnection();
                                in = new BufferedInputStream(conn.getInputStream());
                                StringBuilder stringBuilder = new StringBuilder();
                                byte[] bytes = new byte[1024];
                                while(in.read(bytes) != -1){
                                    stringBuilder.append(new String(bytes));
                                }
                                String jsonResponse = stringBuilder.toString();
                                if (jsonResponse.contains("errcode")){
                                    isexistence(false);
                                }
                                else {

                                   isexistence(true);
                                }
                            } catch (IOException e) {
                                e.printStackTrace();
                            }

                        }
                    }).start();
                }else {
                    Toast.makeText(this,"输入的内容不能为空！",Toast.LENGTH_SHORT).show();
                }
                break;
        }
    }

    private void isexistence(boolean isexistence){
        if (!isexistence){
            Toast.makeText(this,"该城市不存在！",Toast.LENGTH_SHORT).show();
        }else {
            DatabaseManager.addCity(city,null,null,null,null,null,null,null,null,null,null);
            Intent intent = new Intent(this,MainActivity.class);
            intent.setFlags(intent.FLAG_ACTIVITY_CLEAR_TASK|intent.FLAG_ACTIVITY_NEW_TASK);
            intent.putExtra("city",city);
            startActivity(intent);
        }
    }
}