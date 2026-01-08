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
        frame.setLayout(new GridLayout(3,1));

		JPanel div4 = new JPanel();
		div4.setLayout(new GridLayout(1,4));

		JPanel div21 = new JPanel();
		div21.setLayout(new GridLayout(1,2));

		JPanel div22 = new JPanel();
		div22.setLayout(new GridLayout(1,2));

        // Creazione dell'icona di domensione 60 x 60 pixel
		ImageIcon headIcon1 = new ImageIcon(new ImageIcon("header_1.jpg").getImage().getScaledInstance(60, 60, Image.SCALE_DEFAULT));
		ImageIcon headIcon2 = new ImageIcon(new ImageIcon("header_2.jpg").getImage().getScaledInstance(60, 60, Image.SCALE_DEFAULT));
		ImageIcon headIcon3 = new ImageIcon(new ImageIcon("header_3.jpg").getImage().getScaledInstance(60, 60, Image.SCALE_DEFAULT));
		ImageIcon headIcon4 = new ImageIcon(new ImageIcon("header_4.jpg").getImage().getScaledInstance(60, 60, Image.SCALE_DEFAULT));
		ImageIcon buttonIcon1 = new ImageIcon(new ImageIcon("pulsante_off.jpg").getImage().getScaledInstance(120, 44, Image.SCALE_DEFAULT));
		ImageIcon buttonIcon2 = new ImageIcon(new ImageIcon("pulsante_on.jpg").getImage().getScaledInstance(120, 44, Image.SCALE_DEFAULT));

		JLabel labelIcon1 = new JLabel(headIcon1);
		JLabel labelIcon2 = new JLabel(headIcon2);
		JLabel labelIcon3 = new JLabel(headIcon3);
		JLabel labelIcon4 = new JLabel(headIcon4);
		JLabel button1 = new JLabel(buttonIcon1);
		JLabel button2 = new JLabel(buttonIcon1);
		JLabel button3 = new JLabel(buttonIcon1);
		JLabel button4 = new JLabel(buttonIcon1);

		labelIcon1.setText("");
		labelIcon2.setText("");
		labelIcon3.setText("");
		labelIcon4.setText("");
		button1.setText("");
		button2.setText("");
		button3.setText("");
		button4.setText("");
		
		// evento click sui pulsanti e invio comandi
		button1.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P1on");
					button1.setIcon(buttonIcon2);
				} else { 
					client.comunica("P1off");
					button1.setIcon(buttonIcon1);
				}
			}
		});

		button2.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P2on");
					button2.setIcon(buttonIcon2);
				} else { 
					client.comunica("P2off");
					button2.setIcon(buttonIcon1);
				}
			}
		});

		button3.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P3on");
					button3.setIcon(buttonIcon2);
				} else { 
					client.comunica("P3off");
					button3.setIcon(buttonIcon1);
				}
			}
		});

		button4.addMouseListener(new MouseAdapter() {
			int k=0;
			public void mouseClicked(MouseEvent e) {
				k=1-k;

				if(k==1) {
					client.comunica("P4on");
					button4.setIcon(buttonIcon2);
				} else { 
					client.comunica("P4off");
					button4.setIcon(buttonIcon1);
				}
			}
		});

        // Aggiunta dei componenti al frame
        frame.add(div4);
        frame.add(div21);
        frame.add(div22);

		div4.add(labelIcon1);
		div4.add(labelIcon2);
		div4.add(labelIcon3);
		div4.add(labelIcon4);
		
		div21.add(button1);
		div21.add(button2);
		div22.add(button3);
		div22.add(button4);

        // Rende visibile la finestra
        frame.setVisible(true);
    }
}

public class ClientStr {
		// ip address del server e porta di comunicazione
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
				System.out.println(e.getMessage());
				System.out.println("Errore di connessione");
				System.exit(1);
			}
		}
}
