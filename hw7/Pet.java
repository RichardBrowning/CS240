import java.io.*;
import java.util.Scanner;

public class Pet implements java.io.Serializable {
	// the pet has a few fields
	public String name; // String that holds the pet's name
	public int age; // an integer that holds the pet's age
	public String type_of_pet; // string that holds the type of pet, e.g. dog, cat, parakeet, moose

	public static void main(String [] args) { // the main function that runs by default
		Pet userpet = new Pet(); // instantiates a pet
		userpet.printName(); // prints the existing pet name
		userpet.printAge(); // prints the initial pet age
		userpet.printTypeofPet(); // prints the initial type of pet

		userpet.savePrompt(); // Prompts the user about wheter they want to save (serialize out)
		userpet.Birthday(); // prompts the user about whether their pet has had a birthday
		userpet.savePrompt(); // prompts the user again about whether they want to save

		
	}
	public Pet() {
		Scanner reader = new Scanner(System.in); // creates a new command line scanner
		System.out.println("Do you want to load a saved pet? (y/n)"); // prompts the user
		if ((reader.next()).equals("y")) { // if the user inputs a "y" for yes
			try {
				FileInputStream fileIn = new FileInputStream("pet.ser"); // tries to open a previously serialized pet object"
				ObjectInputStream in = new ObjectInputStream(fileIn); // establishes an input stream
				Pet userpet = (Pet) in.readObject(); // assigns the input streamed object to userpet
				in.close(); // closes input stream
				fileIn.close(); // closes input file
				this.name = userpet.name; // assigns the read name to the userpet
				this.age = userpet.age; // assigns the read age to the userpet
				this.type_of_pet = userpet.type_of_pet; // assigns the ype of pet to userpet
			}catch(IOException i) { // if something bad happens, catches htis specific exception
				i.printStackTrace(); // prints a bunch of stuff that the developer might find useful
			}catch(ClassNotFoundException c) { // if cannot serialize in
				System.out.println("Pet class not found"); // tells the user that we cannot open a pet
				c.printStackTrace(); // prints a bunch of stuff the developer might find usefule
			}
		
		} else { // if they don't want to load an existing pet
			System.out.println("What is your pet's name?"); // prompts for name
			this.name = reader.next(); // assigns name to object
			System.out.println("What is your pet's age?"); // prompts for age
			this.age = reader.nextInt(); // assigns age to object
			System.out.println("What type of pet do you have?"); // prompts for pet type
			this.type_of_pet = reader.next(); // assigns type of pet to the object
		}

	}
	public Pet(String startname, int startAge, String typeofpet) { // Constructor
		setName(startname); // sets name to the starter name
		setAge(startAge); // sets age to starter age
		setTypeofPet(typeofpet); // sets type of pet to start type
	}

	public void printAge(){ // print function for age
		System.out.println("Your pet's age is: " + age); // prints out the age to cmdline
	}

	public void printTypeofPet(){ // print function for type of pet
		System.out.println("Your pet's type is: " + type_of_pet); // prints out type to cmdline
	}

	public void printName(){ // print function for name
		System.out.println("Your pet's name is: " + name); // prints out name to cmdline
	}

	public void setName(String newName) { // name setter
		name = newName;
	}

	public void setAge(int newAge) { // age setter
		age = newAge;
	}

	public void setTypeofPet(String newtype) { // pet type setter
		type_of_pet = newtype;
	}

	public void Birthday() { // function that prompts user about whether their pet has had a birthday, and if yes, adds a year to the pet's age
		Scanner reader = new Scanner(System.in); // creates a new input scanner
		System.out.println("Has your pet had a birthday since your last visit? (y/n)"); // prints prompt string to commandline
		if ((reader.next()).equals("y")) { // if the user puts a "y" in
			age += 1; // adds 1 to the age of the pet
			System.out.println("Happy Birthday"); // Prints out a nice message
			this.printAge(); // prints out the new age
		}
	}

	public void serial() { // allows for serialization of the object
		try { // attempt to cleanly serialize out
			FileOutputStream fileOut =
				new FileOutputStream("pet.ser"); // new output file  with filename "pet.ser"
			ObjectOutputStream out = new ObjectOutputStream(fileOut); // new output stream 
			out.writeObject(this); // writes the object to the output stream
			out.close(); // closes output stream
			fileOut.close(); // closes output file
			System.out.println("Serialized data is saved in pet.ser"); // prints a nice message
		}catch(IOException i) { // if something bad happens (e.g. file is not writeable)
			i.printStackTrace(); // prints some stuff the developer might find useful
		}

	}

	public void savePrompt() { // prompts the user about whether they want to save their pet
		System.out.println("Would you like to save your pet? (y/n)"); // prints the prompt
		Scanner reader = new Scanner(System.in); // creates a scanner to capture input
		if ((reader.next()).equals("y")) { // if the user puts a "y" for yes
			this.serial(); // serializes with the serial function
		} 

	}

}

