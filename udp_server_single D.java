import java.io.*;
import java.net.*;


public class UDPserver { 
	public static void main(String[] a) throws Exception {
		DatagramSocket serverSocket=new DatagramSocket(5000);
		boolean attivo=true;
		byte[] bufferIN=new byte[1024];
		byte[] bufferOUT=new byte[1024];

		System.out.println("SERVER avviato");
		while (attivo) {
			DatagramPacket receivePacket=new DatagramPacket(bufferIN,bufferIN.length);
			serverSocket.receive(receivePacket);
			
			String ricevuto=new String(receivePacket.getData());
			int numCaratteri=receivePacket.getLength();
			ricevuto=ricevuto.substring(0,numCaratteri);
			
			System.out.println("Ricevuto: "+ricevuto);
			
		}
		serverSocket.close();
	}
}	
