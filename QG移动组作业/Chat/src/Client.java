import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket client = new Socket("localhost",23333);
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String name = "";
        boolean isRename = true;
        while(isRename) {
            System.out.print("请输入用户名：");
            name = bufferedReader.readLine();
            send(name,client);
            if (receive(client).equals("false")){
                System.out.println("该用户名已存在请重新输入！");
            }
            else isRename = false;
        }
        new Thread(new Send(client,name)).start();
        new Thread(new Receive(client)).start();
    }




    static String receive(Socket client){
        String msg = "";
        try {
            DataInputStream dis = new DataInputStream(client.getInputStream());
            msg = dis.readUTF();
        } catch (IOException e) {
            System.out.println("接收错误！");
        }
        return msg;
    }

    static void send(String msg,Socket client){
        try {
            DataOutputStream dos = new DataOutputStream(client.getOutputStream());
            dos.writeUTF(msg);
        } catch (IOException e) {
            System.out.println("发送错误！");
        }
    }
}
