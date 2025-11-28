import java.io.*;
import java.net.*;


public class socket_client{ 
	public static void main(String[] a){
		ClientStr cliente = new ClientStr();
		cliente.connetti();
		cliente.comunica();
	}
}	

public class ClientStr {
		public String nomeServer="192.168.1.216";
		public int portaServer=5000;
		public Socket miosocket;
		public BufferedReader tastiera;
		public String stringaUtente;
		public String stringaRicevutaDalServer;
		public DataOutputStream outVersoServer;
		public BufferedReader inDalServer;
	
		public ClientStr () { //costruttore 

		}
	
	public Socket connetti () {
		
		System.out.println("CLIENT in esecuzione");
		try {
			tastiera=new BufferedReader(new InputStreamReader(System.in));

			Socket miosocket = new Socket(nomeServer,portaServer);

			outVersoServer = new DataOutputStream(miosocket.getOutputStream());

			inDalServer = new BufferedReader(new InputStreamReader(miosocket.getInputStream()));

		}
		catch (UnknownHostException e) {
			System.out.println("Host sconosciuto");
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
			System.out.println("Errore di connessione");
			System.exit(1);
		}

		return miosocket;
			
	}

	public void comunica () {

		while(true){
			try {
				System.out.println("Stringa da trasmettere:");
				stringaUtente = tastiera.readLine();
				System.out.println("Invio la stringa");
				outVersoServer.writeBytes(stringaUtente+'\n');

					
			}
			catch (Exception e) {
				System.out.println(e.getMessage());
				System.out.println("Errore di connessione");
				System.exit(1);
			}
		}
	}


}