import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Send implements Runnable{
    private BufferedReader bufferedReader;
    private DataOutputStream dos;
    private Socket client;
    private boolean running;
    private String name;
    public Send(Socket client,String name){
        this.client = client;
        this.name = name;
        this.running = true;
        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        try {
            dos = new DataOutputStream(client.getOutputStream());
            send(name);
        } catch (IOException e) {
            System.out.println("发送失败！");
            this.release();
        }
    }
    @Override
    public void run() {
        while (running){
            String msg = getdata();
            if (!msg.equals("")){
                send(msg);
            }
        }
    }


    private void send(String msg){
        try {
            dos.writeUTF(msg);
            dos.flush();
        } catch (IOException e) {
            System.out.println("发送错误！");
            release();
        }
    }


    private String getdata(){

        try {
            String msg = bufferedReader.readLine();
            if (msg.equals("Sign Out")){
                release();
                return "";
            }
            else return msg;
        } catch (IOException e) {
            return "";
        }
    }

    private void release(){
        this.running = false;
        Utils.close(dos,client);
    }
}
