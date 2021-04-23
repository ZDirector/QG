package com.example.weather;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

import android.text.TextUtils;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;

import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentStatePagerAdapter;
import androidx.viewpager.widget.ViewPager;
import java.util.ArrayList;
import java.util.List;

import database.DatabaseManager;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private CityFragmentPagerAdapter adapter;

    private ImageView addCityIv,moreIv;
    private LinearLayout pointLayout;
    private ViewPager mainVp;

    List<Fragment> fragmentList;
    List<String>cityList;
    List<ImageView>imgList;



    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        DatabaseManager.initDatabase(this);
        addCityIv = this.findViewById(R.id.main_iv_add);
        moreIv = this.findViewById(R.id.main_iv_more);
        pointLayout = this.findViewById(R.id.main_layout_point);
        mainVp = this.findViewById(R.id.main_vp);

        addCityIv.setOnClickListener(this);
        moreIv.setOnClickListener(this);

        fragmentList = new ArrayList<>();
        cityList = DatabaseManager.queryAllCityName();
        imgList = new ArrayList<>();

        if (cityList.size()==0){
            cityList.add("广州");
        }

        Intent intent = getIntent();
        String city = intent.getStringExtra("city");
        if (!cityList.contains(city) && !TextUtils.isEmpty(city)){
            cityList.add(city);
        }
        initPager();
        adapter = new CityFragmentPagerAdapter(getSupportFragmentManager(), FragmentStatePagerAdapter.BEHAVIOR_RESUME_ONLY_CURRENT_FRAGMENT, fragmentList);
        mainVp.setAdapter(adapter);
        initPoint();
        mainVp.setCurrentItem(0);
        setPagerListener();
    }

    @Override
    protected void onRestart() {
        List<String> List = DatabaseManager.queryAllCityName();
        if (List.size() == 0){
            List.add("广州");
        }
        cityList.clear();
        cityList.addAll(List);
        fragmentList.clear();
        initPager();
        adapter.notifyDataSetChanged();
        imgList.clear();
        pointLayout.removeAllViews();
        initPoint();
        mainVp.setCurrentItem(0);
        super.onRestart();
    }


    private void setPagerListener() {
        mainVp.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
            @Override
            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {

            }

            @Override
            public void onPageSelected(int position) {
                for (int i = 0;i<imgList.size();i++){
                    imgList.get(i).setImageResource(R.mipmap.a1);
                }
                imgList.get(position).setImageResource(R.mipmap.a2);
            }

            @Override
            public void onPageScrollStateChanged(int state) {

            }
        });
    }

    private void initPoint() {
        for (int i = 0; i<fragmentList.size();i++){
            ImageView pIv = new ImageView(this);
            pIv.setImageResource(R.mipmap.a1);
            pIv.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT,LinearLayout.LayoutParams.WRAP_CONTENT));
            LinearLayout.LayoutParams lp = (LinearLayout.LayoutParams) pIv.getLayoutParams();
            lp.setMargins(0,0,20,0);
            imgList.add(pIv);
            pointLayout.addView(pIv);
        }
        imgList.get(0).setImageResource(R.mipmap.a2);
    }

    private void initPager() {
        for (int i = 0;i < cityList.size();i++){
            CityWeatherFragment cityFrag = new CityWeatherFragment();
            Bundle bundle = new Bundle();
            bundle.putString("city",cityList.get(i));
            cityFrag.setArguments(bundle);
            fragmentList.add(cityFrag);
        }
    }


    @Override
    public void onClick(View v) {
        Intent intent = new Intent();
        switch (v.getId()){
            case R.id.main_iv_add:
                intent.setClass(this,CityManagerActivity.class);
                startActivity(intent);
                break;
            case R.id.main_iv_more:
                intent.setClass(this,MoreActivity.class);
                startActivity(intent);
                break;
        }
    }

}