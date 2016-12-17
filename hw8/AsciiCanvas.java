import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class AsciiCanvas extends JTextArea implements java.io.Serializable{
		
		private JTextArea textArea; // initializes the textarea part of JTextArea
		private Node head; // initializes the head of the linked list
		private Node current; // initializes the current node of the linked list

		public AsciiCanvas(){ // default and only constructor
			textArea = new JTextArea(10, 20); // creates a new JTextArea of 10x20
			head = new Node(); // creates a new head
			current = head; // sets current equal to the head so we can start at the beginning
		}
		
		public void prevFrame(){ // gets and displays the previous frame
			if (current.getPrev() != null){ // is false if we run out of previous frames
				current.setInfo(textArea.getText()); // sets the current to what's in the text box
				current = current.getPrev(); // sets the new current to the previous node
				textArea.append(current.getInfo()); // puts what is in the node in the text box
			} else { // if there's no previous node
				textArea.append(""); // puts a blank in the box
			}
		}
		
		public void nextFrame(){ // gets and displays the next frame
			current.setInfo(textArea.getText()); // sets the current node to the textarea
			if (current.getNext() == null){ // if the next node is empty
				Node newNode = new Node(current, null,""); // creates a new node that's blank
				current = newNode; // sets current node to the blank new node
			} else { // if next node is not empty
				current = current.getNext(); // sets current to next
				textArea.append(current.getInfo()); // sets the text area to the node
			}
		
		}
		
		public void save(){ // save function to serialize
			try { // attempt to cleanly serialize out
				FileOutputStream fileOut =
					new FileOutputStream("Animation.ser"); // new output file  with filename "pet.ser"
				ObjectOutputStream out = new ObjectOutputStream(fileOut); // new output stream 
				out.writeObject(head); // writes the object to the output stream
				out.close(); // closes output stream
				fileOut.close(); // closes output file
			}catch(IOException i) { // if something bad happens (e.g. file is not writeable)
				i.printStackTrace(); // prints some stuff the developer might find useful
			}
		}
		
		public void load(){ // load function for serialized node objects
			try {
				FileInputStream fileIn = new FileInputStream("Animation.ser"); // tries to open a previously serialized pet object"
				ObjectInputStream in = new ObjectInputStream(fileIn); // establishes an input stream
				Node current = (Node) in.readObject(); // assigns the input streamed object to userpet
				Node head = current; // also sets head to current
				in.close(); // closes input stream
				fileIn.close(); // closes input file
				
			}catch(IOException i) { // if something bad happens, catches htis specific exception
				i.printStackTrace(); // prints a bunch of stuff that the developer might find useful
			}catch(ClassNotFoundException c) { // if cannot serialize in
				c.printStackTrace(); // prints a bunch of stuff the developer might find usefule
			}
			textArea.append(head.getInfo());// display current node to JTextArea
			
		}
		
		public void anim(){ // the animate function
			if (current.getInfo() != null) { // e.g. if there's text in the node
				textArea.append(current.getInfo()); // shows the current node
				nextFrame(); // calls next frame
			}
		}
		
}
