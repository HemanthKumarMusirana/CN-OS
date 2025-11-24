import java.util.Scanner;

public class CRC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter data bits: ");
        String data = sc.next();

        System.out.print("Enter divisor: ");
        String divisor = sc.next();

        int dataLen = data.length();
        int divLen = divisor.length();

        // Step 1: Append (divLen-1) zeros
        String appended = data + "0".repeat(divLen - 1);
        char[] dividend = appended.toCharArray();
        char[] div = divisor.toCharArray();

        // Step 2: Perform XOR division
        for (int i = 0; i < dataLen; i++) {
            if (dividend[i] == '1') {
                for (int j = 0; j < divLen; j++) {
                    dividend[i + j] = (dividend[i + j] == div[j]) ? '0' : '1';
                }
            }
        }

        // Step 3: Extract remainder
        String remainder = new String(dividend).substring(dataLen);

        System.out.println("CRC Remainder: " + remainder);
    }
}
