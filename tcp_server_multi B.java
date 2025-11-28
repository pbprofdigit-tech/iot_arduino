import java.io.*;
import java.net.*;

public class MultiServer { 

	public static void main(String[] a){
		MultiServer tcpServer = new MultiServer();
		tcpServer.inizio();
	}
	
	public void inizio() {
		try{
			ServerSocket serverSocket = new ServerSocket(5000);
			for(;;) {
				System.out.println("Server in attesa");
				Socket socket = serverSocket.accept();
				System.out.println("Server socket "+ socket);
				ServerThread serverThread = new ServerThread(socket);
				serverThread.start();
			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
			System.out.println("Errore 1");
			System.exit(1);
		}
	}
}	

public class ServerThread extends Thread {

	public ServerSocket server = null;
	public Socket client=null;
	public String stringaRicevuta=null;
	public String stringaModificata=null;
	public BufferedReader inDalClient;
	public DataOutputStream outVersoClient;


	public ServerThread (Socket socket) { 
		this.client=socket;
	}

	public void run() {
		try {
			comunica();
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}
	}

	public void comunica () throws Exception {
		
		inDalClient = new BufferedReader(new InputStreamReader(client.getInputStream()));
		outVersoClient = new DataOutputStream(client.getOutputStream());
		
		while(true) {
			stringaRicevuta=inDalClient.readLine();
			System.out.println("Messaggio ricevuto: "+stringaRicevuta);
		}
	}


}