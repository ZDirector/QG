package com.example.weather;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import org.json.JSONException;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;

import database.DatabaseManager;

public class CityWeatherFragment extends Fragment {
    private TextView tempTv,cityTv,conditionTv,wind_directionTv,wind_powerTv,tempRangeTv,dataTv,airTv;
    private ImageView dayIv;
    private ScrollView backIv;
    WhiteWindmills wwBig,wwSmall;
    RoundProgressBar rpbAqi;
    String city;
    String url ="https://www.tianqiapi.com/free/day?appid=63143258&appsecret=8bx0w1AW&city=";


    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.city_weather, container, false);
        initView(view);
        Bundle bundle = getArguments();
        city = bundle.getString("city");
        String URL = url+city;
        loadWeather(URL);
        return view;
    }

    @Override
    public void onDestroyView() {
        wwBig.stop();//停止大风车
        wwSmall.stop();//停止小风车
        super.onDestroyView();
    }

    private void initView(View view) {
        tempTv = view.findViewById(R.id.frag_tv_currenttemp);
        cityTv = view.findViewById(R.id.frag_tv_city);
        conditionTv = view.findViewById(R.id.frag_tv_condition);
        wind_directionTv = view.findViewById(R.id.frag_tv_wind_direction);
        wind_powerTv = view.findViewById(R.id.frag_tv_wind_power);
        tempRangeTv = view.findViewById(R.id.frag_tv_temprange);
        dataTv = view.findViewById(R.id.frag_tv_data);
        dayIv = view.findViewById(R.id.frag_iv_today);
        backIv = view.findViewById(R.id.frag_background);
        wwBig = view.findViewById(R.id.ww_big);
        wwSmall = view.findViewById(R.id.ww_small);
        rpbAqi = view.findViewById(R.id.rpb_aqi);
    }

    private void loadWeather(String url){
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
                    Weather weather = Weather.fromJson(jsonResponse);
                    getActivity().runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            setData(weather);
                            int i = DatabaseManager.updateInfo(city,
                                    weather.getUpdateTime(),
                                    weather.getWea(),
                                    weather.getWeaImg(),
                                    weather.getTem(),
                                    weather.getTemDay(),
                                    weather.getTemNight(),
                                    weather.getWin(),
                                    weather.getWinSpeed(),
                                    weather.getWinMeter(),
                                    weather.getAir());
                            if (i <= 0){
                                DatabaseManager.addCity(city,
                                        weather.getUpdateTime(),
                                        weather.getWea(),
                                        weather.getWeaImg(),
                                        weather.getTem(),
                                        weather.getTemDay(),
                                        weather.getTemNight(),
                                        weather.getWin(),
                                        weather.getWinSpeed(),
                                        weather.getWinMeter(),
                                        weather.getAir());
                            }
                        }
                    });
                } catch (IOException | JSONException e) {
                    HashMap<String,String> data = new HashMap<>();
                    data = DatabaseManager.queryInfoCity(city);
                    setData(data);
                } finally {
                    try{
                        if(in != null){
                            in.close();
                        }
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }

            }
        }).start();
    }

    private void setData(Weather weather){
        tempTv.setText(weather.getTem()+"℃");
        cityTv.setText(weather.getCity());
        conditionTv.setText(weather.getWea());
        wind_directionTv.setText(weather.getWin());
        wind_powerTv.setText(weather.getWinSpeed());
        wwBig.startRotate();
        wwSmall.startRotate();
        tempRangeTv.setText(weather.getTemNight()+"℃-"+weather.getTemDay()+"℃");
        dataTv.setText(new SimpleDateFormat("yyyy-MM-dd").format(new Date(System.currentTimeMillis()))+"  "+weather.getUpdateTime());

        rpbAqi.setMaxProgress(500);//最大进度，用于计算
        rpbAqi.setMinText("0");//设置显示最小值
        rpbAqi.setMinTextSize(32f);
        rpbAqi.setMaxText("500");//设置显示最大值
        rpbAqi.setMaxTextSize(32f);
        rpbAqi.setProgress(Float.valueOf(weather.getAir()));//当前进度
        rpbAqi.setArcBgColor(getResources().getColor(R.color.arc_bg_color));//圆弧的颜色
        rpbAqi.setProgressColor(getResources().getColor(R.color.arc_progress_color));//进度圆弧的颜色
        rpbAqi.setFirstTextSize(44f);
        rpbAqi.setSecondText(weather.getAir());//空气质量值
        rpbAqi.setSecondTextSize(64f);

        rpbAqi.setMinTextColor(getResources().getColor(R.color.arc_progress_color));
        if (weather.getWeaImg().equals("xue")){
            dayIv.setImageResource(R.mipmap.xue);
            backIv.setBackgroundResource(R.mipmap.xueb);
        }
        else if (weather.getWeaImg().equals("lei")){
            dayIv.setImageResource(R.mipmap.leizhenyu);
            backIv.setBackgroundResource(R.mipmap.leizhengb);
        }
        else if (weather.getWeaImg().equals("shachen")){
            dayIv.setImageResource(R.mipmap.shachen);
            backIv.setBackgroundResource(R.mipmap.shachenb);
        }
        else if (weather.getWeaImg().equals("wu")){
            dayIv.setImageResource(R.mipmap.wu);
            backIv.setBackgroundResource(R.mipmap.wub);
        }
        else if (weather.getWeaImg().equals("bingbao")){
            dayIv.setImageResource(R.mipmap.bingbao);
            backIv.setBackgroundResource(R.mipmap.bingbaob);
        }
        else if (weather.getWeaImg().equals("yu")){
            dayIv.setImageResource(R.mipmap.yu);
            backIv.setBackgroundResource(R.mipmap.yub);
        }
        else if (weather.getWeaImg().equals("yin")){
            dayIv.setImageResource(R.mipmap.yin);
            backIv.setBackgroundResource(R.mipmap.yinb);
        }
        else if (weather.getWeaImg().equals("qing")){
            dayIv.setImageResource(R.mipmap.qing);
            backIv.setBackgroundResource(R.mipmap.qingb);
        }
        else if(weather.getWeaImg().equals("yun")){
            dayIv.setImageResource(R.mipmap.yun);
            backIv.setBackgroundResource(R.mipmap.yunb);
        }
    }

    private void setData(HashMap<String,String> data){
        tempTv.setText(data.get("tem"));
        cityTv.setText(data.get("city"));
        conditionTv.setText(data.get("wea"));
        wind_directionTv.setText(data.get("win"));
        wind_powerTv.setText(data.get("winSpeed"));
        tempRangeTv.setText(data.get("temNight")+"℃-"+data.get("temDay")+"℃");
        dataTv.setText(new SimpleDateFormat("yyyy-MM-dd").format(new Date(System.currentTimeMillis()))+"  "+data.get("updateTime"));
        airTv.setText(data.get("air"));
        if (data.get("weaImg").equals("xue")){
            dayIv.setImageResource(R.mipmap.xue);
            backIv.setBackgroundResource(R.mipmap.xueb);
        }
        else if (data.get("weaImg").equals("lei")){
            dayIv.setImageResource(R.mipmap.leizhenyu);
            backIv.setBackgroundResource(R.mipmap.leizhengb);
        }
        else if (data.get("weaImg").equals("shachen")){
            dayIv.setImageResource(R.mipmap.shachen);
            backIv.setBackgroundResource(R.mipmap.shachenb);
        }
        else if (data.get("weaImg").equals("wu")){
            dayIv.setImageResource(R.mipmap.wu);
            backIv.setBackgroundResource(R.mipmap.wub);
        }
        else if (data.get("weaImg").equals("bingbao")){
            dayIv.setImageResource(R.mipmap.bingbao);
            backIv.setBackgroundResource(R.mipmap.bingbaob);
        }
        else if (data.get("weaImg").equals("yu")){
            dayIv.setImageResource(R.mipmap.yu);
            backIv.setBackgroundResource(R.mipmap.yub);
        }
        else if (data.get("weaImg").equals("yin")){
            dayIv.setImageResource(R.mipmap.yin);
            backIv.setBackgroundResource(R.mipmap.yinb);
        }
        else if (data.get("weaImg").equals("qing")){
            dayIv.setImageResource(R.mipmap.qing);
            backIv.setBackgroundResource(R.mipmap.qingb);
        }
        else if (data.get("weaImg").equals("yun")){
            dayIv.setImageResource(R.mipmap.yun);
            backIv.setBackgroundResource(R.mipmap.yunb);
        }
    }
}
