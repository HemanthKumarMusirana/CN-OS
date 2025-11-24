import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
System.out.println("Enter the data: ");
String data = sc.nextLine();
String result = "DLESTX";
for (int i = 0; i < data.length(); i++) {
    char ch = data.charAt(i);

    if (data.startsWith("DLE", i)) {
        result += "DLEDLE";
        i += 2;  // Skip 'L' and 'E'
    } else {
        result += ch;
    }
}
result += "DLEETX";
System.out.println("Stuffed Data: " + result);
}
}




