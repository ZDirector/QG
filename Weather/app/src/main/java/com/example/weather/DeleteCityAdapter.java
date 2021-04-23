package com.example.weather;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

public class DeleteCityAdapter extends BaseAdapter {

    Context context;
    List<String>Data;
    List<String>deleteCity;

    public DeleteCityAdapter(Context context, List<String> data,List<String> deleteCity) {
        this.context = context;
        Data = data;
        this.deleteCity = deleteCity;
    }


    @Override
    public int getCount() {
        return Data.size();
    }

    @Override
    public Object getItem(int position) {
        return Data.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;
        if (convertView == null){
            convertView = LayoutInflater.from(context).inflate(R.layout.item_deletercity,null);
            holder = new ViewHolder(convertView);
            convertView.setTag(holder);
        }else {
            holder = (ViewHolder) convertView.getTag();
        }
        String city = Data.get(position);
        holder.tv.setText(city);
        holder.iv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Data.remove(city);
                deleteCity.add(city);
                notifyDataSetChanged();
            }
        });
        return convertView;
    }

    class ViewHolder{
        TextView tv;
        ImageView iv;
        public ViewHolder(View itemView){
            tv = itemView.findViewById(R.id.item_deleter_tv);
            iv = itemView.findViewById(R.id.item_deleter_iv);
        }
    }
}
