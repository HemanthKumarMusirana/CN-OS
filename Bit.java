import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Binary data: ");
        String data = sc.next();
        int count = 0;
        String result = "";

        for(int i = 0; i<data.length(); i++) {
            char bit = data.charAt(i);
            result = result + bit;
            
            if(count == 1) {
                count ++;
            }else{
                count = 0;
            }
            
            if (count == 5) {
                result = result + bit;
                count = 0;
            }
            }
            System.out.println("The Stuffed Bit is : " + result);
        }
}
