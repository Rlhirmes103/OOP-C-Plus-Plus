//Rachel Hirmes 11A1

import javax.swing.JOptionPane;

public class Project0 {
    
    public static void main(String[] args){
        
        String input;
		input = JOptionPane.showInputDialog(null,"Please enter a sentence:");
		//loop which will keep asking for a new input until user types stop
		while(! input.equalsIgnoreCase("stop")){
		    int upperCount = 0, lowerCount = 0, length = input.length();
		    // for loop initializing the count at zero 
		    // and stopping to check for Es/ es until it reaches the end of the sentence
		    for (int i = 0; i<length; i++) {
		        if(input.charAt(i)=='E') upperCount++;
		        if(input.charAt(i)=='e') lowerCount++;
			}
		    // prints results
			JOptionPane.showMessageDialog(null, "Number of lower case e's:" +lowerCount
			                                +"\nNumber of upper case E's:" +upperCount );
			// prompts user to enter a new input keeping the loop going 
			input = JOptionPane.showInputDialog(null,"Enter a sentence:");
		}
		
	}
}