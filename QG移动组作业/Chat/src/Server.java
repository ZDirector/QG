import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.CopyOnWriteArrayList;

public class Server {
    private static CopyOnWriteArrayList<Channel> person = new CopyOnWriteArrayList<Channel>();
    public static void main(String[] args) throws IOException {

        ServerSocket server = new ServerSocket(23333);
        while (true) {
            Socket client = server.accept();
            Channel channel = new Channel(client);
            person.add(channel);
            new Thread(channel).start();
        }
    }






    static class Channel implements Runnable{
        private DataOutputStream dos;
        private DataInputStream dis;
        private Socket client;
        private boolean running;
        private int Rename;
        private String name;
        public Channel(Socket client){
            this.client = client;
            try {
                dos = new DataOutputStream(client.getOutputStream());
                dis = new DataInputStream(client.getInputStream());
                running = true;

                while (true){
                    Rename = 1;
                    this.name = receive();
                    for (Channel other:person) if (other.name.equals(this.name)) Rename++;
                    if (Rename >= 2) this.send("false");
                    else break;
                }

                this.send("");
                this.send("欢迎你来到聊天室");
                this.send("现在聊天室中有"+(person.size()+1)+"人");
                this.sendother(this.name+"来到了聊天室！",true);
                this.sendother("现在聊天室中有"+(person.size()+1)+"人",true);
                receive();
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


        private void send(String msg){
            try {
                dos.writeUTF(msg);
            }catch (IOException e){
                System.out.println("发送错误！");
                release();
            }
        }


        private void sendother(String msg,boolean isSys){
            boolean isPrivate = msg.startsWith("@");
            if (isPrivate){
                String targetname = msg.substring(1,msg.indexOf(":"));
                msg = msg.substring(msg.indexOf(":")+1);
                for (Channel other:person){
                    if (other.name.equals(targetname)){
                        other.send("["+new SimpleDateFormat("HH:mm:ss").format(new Date())+"] "+this.name+"对你说：");
                        other.send(msg);
                        break;
                    }
                }
            }else {
                for (Channel other:person){
                    if (other == this){
                        continue;
                    }
                    if(!isSys){
                        other.send("["+new SimpleDateFormat("HH:mm:ss").format(new Date())+"] "+this.name+"对所有人说：");
                        other.send(msg);
                    }else {
                        other.send(msg);
                    }
                }
            }

        }


        private void release(){
            this.running = false;
            Utils.close(dis,dos,client);
            person.remove(this);
            if (!this.name.equals(null)){
                sendother(this.name+"离开了聊天室",true);
                this.sendother("现在聊天室中有"+person.size()+"人",true);
            }

        }

        @Override
        public void run() {
            while (running){
                String msg = receive();
                if (!msg.equals("")){
                    sendother(msg,false);
                }
            }
        }
    }
}
