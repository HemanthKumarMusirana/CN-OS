 
import java.util.Scanner; 
 
public class GoBackNARQ { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
 
        System.out.print("Enter window size: "); 
        int n = sc.nextInt(); 
 
        System.out.print("Enter number of frames to transmit: "); 
        int nf = sc.nextInt(); 
 
        int i = 1; 
        while (i <= nf) { 
            int k = 0; 
            while (k < n && i <= nf) { 
                System.out.println("Sent Frame " + i); 
                i++; 
                k++; 
            } 
            System.out.println("Acknowledgment for all above frames received\n"); 
        } 
 
        sc.close(); 
    } 
}
