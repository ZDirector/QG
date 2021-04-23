package database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.example.weather.Weather;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DatabaseManager {
    public static SQLiteDatabase database;
    public static void initDatabase(Context context){
        DatabaseHelper databaseHelper = new DatabaseHelper(context);
        database = databaseHelper.getWritableDatabase();
    }

    public static List<String>queryAllCityName(){
        Cursor cursor = database.query("info",null,null,null,null,null,null);
        List<String>cityList = new ArrayList<>();
        while (cursor.moveToNext()){
            String city = cursor.getString(cursor.getColumnIndex("city"));
            cityList.add(city);
        }
        return cityList;
    }

    public static int updateInfo(String city,
                                 String updateTime,
                                 String wea,
                                 String weaImg,
                                 String tem,
                                 String temDay,
                                 String temNight,
                                 String win,
                                 String winSpeed,
                                 String winMeter,
                                 String air){
        ContentValues values = new ContentValues();
        values.put("update_time",updateTime);
        values.put("wea",wea);
        values.put("wea_img",weaImg);
        values.put("tem",tem);
        values.put("tem_day",temDay);
        values.put("tem_night",temNight);
        values.put("win",win);
        values.put("win_speed",winSpeed);
        values.put("win_meter",winMeter);
        values.put("air",air);
        return database.update("info",values,"city=?",new String[]{city});
    }

    public static long addCity(String city,
                               String updateTime,
                               String wea,
                               String weaImg,
                               String tem,
                               String temDay,
                               String temNight,
                               String win,
                               String winSpeed,
                               String winMeter,
                               String air){
        ContentValues values = new ContentValues();
        values.put("city",city);
        values.put("update_time",updateTime);
        values.put("wea",wea);
        values.put("wea_img",weaImg);
        values.put("tem",tem);
        values.put("tem_day",temDay);
        values.put("tem_night",temNight);
        values.put("win",win);
        values.put("win_speed",winSpeed);
        values.put("win_meter",winMeter);
        values.put("air",air);
        return database.insert("info",null,values);
    }

    public static HashMap<String,String> queryInfoCity(String city){
        Cursor cursor = database.query("info",null,"city=?",new String[]{city},null,null,null);
        HashMap<String,String> data = new HashMap<>();
        while (cursor.moveToNext()) {
            data.put("updateTime",cursor.getString(cursor.getColumnIndex("update_time")));
            data.put("wea",cursor.getString(cursor.getColumnIndex("wea")));
            data.put("weaImg",cursor.getString(cursor.getColumnIndex("wea_img")));
            data.put("tem",cursor.getString(cursor.getColumnIndex("tem")));
            data.put("temDay",cursor.getString(cursor.getColumnIndex("tem_day")));
            data.put("temNight",cursor.getString(cursor.getColumnIndex("tem_night")));
            data.put("win",cursor.getString(cursor.getColumnIndex("win")));
            data.put("winSpeed",cursor.getString(cursor.getColumnIndex("win_speed")));
            data.put("winMeter",cursor.getString(cursor.getColumnIndex("win_meter")));
            data.put("air",cursor.getString(cursor.getColumnIndex("air")));
            return data;
        }
        return null;
    }

    public static List<Weather> queryInfo(){
        Cursor cursor = database.query("info",null,null,null,null,null,null);
        List<Weather>data = new ArrayList<>();
        while (cursor.moveToNext()) {
            Weather weather = new Weather();
            weather.setCity(cursor.getString(cursor.getColumnIndex("city")));
            weather.setUpdateTime(cursor.getString(cursor.getColumnIndex("update_time")));
            weather.setWea(cursor.getString(cursor.getColumnIndex("wea")));
            weather.setWeaImg(cursor.getString(cursor.getColumnIndex("wea_img")));
            weather.setTem(cursor.getString(cursor.getColumnIndex("tem")));
            weather.setTemDay(cursor.getString(cursor.getColumnIndex("tem_day")));
            weather.setTemNight(cursor.getString(cursor.getColumnIndex("tem_night")));
            weather.setWin(cursor.getString(cursor.getColumnIndex("win")));
            weather.setWinSpeed(cursor.getString(cursor.getColumnIndex("win_speed")));
            weather.setWinMeter(cursor.getString(cursor.getColumnIndex("win_meter")));
            weather.setAir(cursor.getString(cursor.getColumnIndex("air")));
            data.add(weather);
        }
        return data;
    }

    public static int deleteInfoCity(String city){
        return database.delete("info","city=?",new String[]{city});
    }

    public static void deleteAllInfo(){
        String sql = "delete from info";
        database.execSQL(sql);
    }
}
