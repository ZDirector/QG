package com.example.weather;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;


import java.util.List;

public class CityManagerAdapter extends BaseAdapter {

    Context context;
    List<Weather>data;

    public CityManagerAdapter(Context context,List<Weather> data){
        this.context = context;
        this.data = data;
    }

    @Override
    public int getCount() {
        return data.size();
    }

    @Override
    public Object getItem(int position) {
        return data.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;
        if (convertView == null){
            convertView = LayoutInflater.from(context).inflate(R.layout.item_city_manager,null);
            holder = new ViewHolder(convertView);
            convertView.setTag(holder);
        }else {
            holder = (ViewHolder) convertView.getTag();
        }
        Weather weather = data.get(position);
        holder.cityTv.setText(weather.getCity());
        holder.winpowerTv.setText(weather.getWinSpeed());
        holder.winconditionTv.setText(weather.getWin());
        holder.tempRangeTv.setText(weather.getTemNight()+"℃-"+weather.getTemDay()+"℃");
        holder.currentTv.setText(weather.getTem());
        holder.conTv.setText(weather.getWea());
        return convertView;
    }

    class ViewHolder{
        TextView cityTv,conTv,currentTv,winconditionTv,winpowerTv,tempRangeTv;
        public ViewHolder(View itemView){
            cityTv = itemView.findViewById(R.id.item_city_tv_city);
            conTv = itemView.findViewById(R.id.item_city_tv_condition);
            currentTv = itemView.findViewById(R.id.item_city_tv_temp);
            winconditionTv = itemView.findViewById(R.id.item_city_wind_condition);
            winpowerTv = itemView.findViewById(R.id.item_city_wind_power);
            tempRangeTv = itemView.findViewById(R.id.item_city_temrange);
        }
    }
}
