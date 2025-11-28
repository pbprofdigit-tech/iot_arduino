import java.io.*;
import java.net.*;
import java.util.*;


public class socket_server { 
	public static void main(String[] a){
		ServerStr servente = new ServerStr();
		servente.attendi();
		servente.comunica();
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
	
	public Socket attendi () {
		
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

	public void comunica () {

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