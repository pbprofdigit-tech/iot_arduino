import java.io.*;
import java.net.*;
import java.util.*;


public class socket_server { 
	public static void main(String[] a){
		ServerStr server_01 = new ServerStr();
		server_01.Connessione();
		server_01.Comunicazione();
	}
}	

public class ServerStr {

		public ServerSocket server = null;
		public Socket client=null;
		public String stringaRicevuta=null;
		public String stringaModificata=null;
		public BufferedReader inDalClient;
		public DataOutputStream outVersoClient;
	

		public ServerStr () { //costruttore 

		}
	
	public Socket Connessione () {
		
		try {
			server =new ServerSocket(5000);
			
			client=server.accept();
			server.close();
			
			inDalClient=new BufferedReader(new InputStreamReader(client.getInputStream()));
			
			outVersoClient=new DataOutputStream(client.getOutputStream());

		}
		catch (Exception e) {
			System.out.println(e.getMessage());
			System.out.println("Errore istanza server");
			System.exit(1);
		}

		return client;
			
	}

	public void Comunicazione () {

		while (true) {
			try {
				stringaRicevuta = inDalClient.readLine();
				System.out.println("Ricevuto: "+stringaRicevuta);
				

			}
			catch (Exception e) {
				System.out.println(e.getMessage());
				System.out.println("Errore xxx");
				System.exit(1);
			}
		}
	}

}