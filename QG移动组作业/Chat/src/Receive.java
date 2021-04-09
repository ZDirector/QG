import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class Receive implements Runnable{
    private DataInputStream dis;
    private Socket client;
    private boolean running;

    public Receive(Socket client){
        this.client = client;
        try {
            dis = new DataInputStream(client.getInputStream());
            running = true;
        } catch (IOException e) {
            release();
        }
    }

    private String receive(){
        String msg = "";
        try {
            msg = dis.readUTF();
        } catch (IOException e) {
            System.out.println("接收错误！");
            release();
        }
        return msg;
    }

    @Override
    public void run() {
        while (running){
            String msg = receive();
            if (!msg.equals("")){
                System.out.println(msg);
            }
        }
    }

    private void release(){
        this.running = false;
        Utils.close(dis,client);
    }
}
