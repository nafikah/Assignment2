import java.io.*;
import java.lang.*;
import java.util.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;//Add these two imports
import java.io.BufferedReader;

public class stringTobinary{
	public static void main(String[] args) throws Exception {
	
	BufferedReader ois = new BufferedReader(new InputStreamReader("javaReverseInput.txt"));
	DataOutputStream oos = new DataOutputStream(new FileOutputStream("javaBinaryOutput.bin"));
	BufferedReader ois2 = new DataInputStream(new InputStreamReader("javaBinaryOutput.bin"));

//BufferedReader d = new BufferedReader(new InputStreamReader(in));

	FileWriter fw = new FileWriter("javaReverseOutput.txt");
	BufferedWriter bw = new BufferedWriter(fw);
	PrintWriter pw = new PrintWriter(bw);

	String str=null;
	String reverse = null;

	try{
		while((str = ois.readLine()) != null){
			oos.writeChars(new String (str));
		}
		
		while((str = ois2.readLine()) != null){
			for(int i=str.length()-1; i>=0; i--){			
				reverse = reverse + str.charAt(i);
			}
			pw.write(reverse);
		}
	}
	finally{
		if(ois != null){
			ois.close();
		}
		if(pw != null){
			pw.close();
		}
		if(oos != null){
			oos.close();
		}
	}
   }	
}












