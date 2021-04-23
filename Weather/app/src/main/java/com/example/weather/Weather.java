package com.example.weather;

import org.json.JSONException;
import org.json.JSONObject;


public class Weather {


    public static Weather fromJson(String json) throws JSONException {
        JSONObject jsonObject = new JSONObject(json);

        Weather weather = new Weather();
        weather.city = jsonObject.getString("city");
        weather.updateTime = jsonObject.getString("update_time");
        weather.wea = jsonObject.getString("wea");
        weather.weaImg = jsonObject.getString("wea_img");
        weather.tem = jsonObject.getString("tem");
        weather.temDay = jsonObject.getString("tem_day");
        weather.temNight = jsonObject.getString("tem_night");
        weather.win = jsonObject.getString("win");
        weather.winSpeed = jsonObject.getString("win_speed");
        weather.winMeter = jsonObject.getString("win_meter");
        weather.air = jsonObject.getString("air");
        return weather;
    }


    private String city="";
    private String updateTime="";
    private String wea="";
    private String weaImg="";
    private String tem="";
    private String temDay="";
    private String temNight="";
    private String win="";
    private String winSpeed="";
    private String winMeter="";
    private String air="";


    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getUpdateTime() {
        return updateTime;
    }

    public void setUpdateTime(String updateTime) {
        this.updateTime = updateTime;
    }

    public String getWea() {
        return wea;
    }

    public void setWea(String wea) {
        this.wea = wea;
    }

    public String getWeaImg() {
        return weaImg;
    }

    public void setWeaImg(String weaImg) {
        this.weaImg = weaImg;
    }

    public String getTem() {
        return tem;
    }

    public void setTem(String tem) {
        this.tem = tem;
    }

    public String getTemDay() {
        return temDay;
    }

    public void setTemDay(String temDay) {
        this.temDay = temDay;
    }

    public String getTemNight() {
        return temNight;
    }

    public void setTemNight(String temNight) {
        this.temNight = temNight;
    }

    public String getWin() {
        return win;
    }

    public void setWin(String win) {
        this.win = win;
    }

    public String getWinSpeed() {
        return winSpeed;
    }

    public void setWinSpeed(String winSpeed) {
        this.winSpeed = winSpeed;
    }

    public String getWinMeter() {
        return winMeter;
    }

    public void setWinMeter(String winMeter) {
        this.winMeter = winMeter;
    }

    public String getAir() {
        return air;
    }

    public void setAir(String air) {
        this.air = air;
    }
}
