package database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String CREATE_BOOK = "create table info(id integer primary key autoincrement,"
            +"city varchar(20) unique not null,"
            +"update_time text,"
            +"wea text,"
            +"wea_img text,"
            +"tem text,"
            +"tem_day text,"
            +"tem_night text,"
            +"win text,"
            +"win_speed text,"
            +"win_meter text,"
            +"air text)";

    public DatabaseHelper(Context context){
        super(context,"WeatherData.db",null,1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_BOOK);
        Log.d("Database","创建成功！");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
