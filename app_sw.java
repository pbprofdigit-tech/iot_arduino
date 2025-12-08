import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DuePulsantiSwing {
    public static void main(String[] args) {
		// Inizializza la rete lan
		ClientStr client = new ClientStr();
		client.connetti();

        // Creazione della finestra
        JFrame frame = new JFrame("Demo per interfaccia grafica");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(320, 400);
        frame.setLayout(new GridLayout(3,2));


        // Creazione dell'icona di domensione 60 x 60 pixel
		ImageIcon headIcon1 = new ImageIcon(new ImageIcon("header_sx.jpg").getImage().getScaledInstance(160, 58, Image.SCALE_DEFAULT));
		ImageIcon headIcon2 = new ImageIcon(new ImageIcon("header_dx.jpg").getImage().getScaledInstance(160, 58, Image.SCALE_DEFAULT));
		ImageIcon buttonIcon1 = new ImageIcon(new ImageIcon("pulsante_off.jpg").getImage().getScaledInstance(120, 44, Image.SCALE_DEFAULT));
		ImageIcon buttonIcon2 = new ImageIcon(new ImageIcon("pulsante_on.jpg").getImage().getScaledInstance(120, 44, Image.SCALE_DEFAULT));
		JLabel labelIcon1 = new JLabel(headIcon1);
		JLabel labelIcon2 = new JLabel(headIcon2);
		JLabel labelIcon3 = new JLabel(buttonIcon1);
		JLabel labelIcon4 = new JLabel(buttonIcon1);
		JLabel labelIcon5 = new JLabel(buttonIcon1);
		JLabel labelIcon6 = new JLabel(buttonIcon1);
		labelIcon1.setText("");
		labelIcon2.setText("");
		labelIcon3.setText("");
		labelIcon4.setText("");
		labelIcon5.setText("");
		labelIcon6.setText("");

		labelIcon3.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P1on");
					labelIcon3.setIcon(buttonIcon2);
				} else { 
					client.comunica("P1off");
					labelIcon3.setIcon(buttonIcon1);
				}
			}
		});

		labelIcon4.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P2on");
					labelIcon4.setIcon(buttonIcon2);
				} else { 
					client.comunica("P2off");
					labelIcon4.setIcon(buttonIcon1);
				}
			}
		});

		labelIcon5.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P3on");
					labelIcon5.setIcon(buttonIcon2);
				} else { 
					client.comunica("P3off");
					labelIcon5.setIcon(buttonIcon1);
				}
			}
		});

		labelIcon6.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P4on");
					labelIcon6.setIcon(buttonIcon2);
				} else { 
					client.comunica("P4off");
					labelIcon6.setIcon(buttonIcon1);
				}
			}
		});

        // Aggiunta dei componenti al frame
        frame.add(labelIcon1);
        frame.add(labelIcon2);
        frame.add(labelIcon3);
        frame.add(labelIcon4);
        frame.add(labelIcon5);
        frame.add(labelIcon6);

        // Rende visibile la finestra
        frame.setVisible(true);
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

	public void comunica (String com1) {
			try {
				stringaUtente = com1;
				outVersoServer.writeBytes(stringaUtente+'\n');
			}
			catch (Exception e) {
				//stampa su label
				System.out.println(e.getMessage());
				System.out.println("Errore di connessione");
				System.exit(1);
			}
		}



}